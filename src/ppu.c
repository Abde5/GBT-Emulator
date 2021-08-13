#include "ppu.h"
#include <string.h>
#include "groups/transfer.h"


unsigned int palette[4] = {0xffe0f8d0, 0xff88c070, 0xff346856, 0xff081820};


void create_window(struct PPU* ppu){

     SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

     // Create an application window with the following settings:
     (*ppu).window =SDL_CreateWindow(
          "GBT",                  // window title
          SDL_WINDOWPOS_UNDEFINED,           // initial x position
          SDL_WINDOWPOS_UNDEFINED,           // initial y position
          PPU_X*SCALE,                               // width, in pixels
          PPU_Y*SCALE,                               // height, in pixels
          SDL_WINDOW_OPENGL                  // flags - see below
          );

     memset((*ppu).pixels, 0x00, RES*sizeof(unsigned int));

     (*ppu).renderer = SDL_CreateRenderer((*ppu).window, -1, 0);

     SDL_RenderSetScale((*ppu).renderer,
                        SCALE, SCALE);

     (*ppu).texture = SDL_CreateTexture((*ppu).renderer,
                                               SDL_PIXELFORMAT_ARGB8888,
                                               SDL_TEXTUREACCESS_STREAMING,
                                               PPU_X,
                                               PPU_Y);
     if ((*ppu).window == NULL) {
          // In the case that the window could not be made...
          printf("Could not create window: %s\n", SDL_GetError());
     }

     (*ppu).timer = 0;
     (*ppu).mode = 0;
}

void destroy_ppu(struct PPU* ppu){
     // Close and destroy the window
     SDL_DestroyWindow((*ppu).window);

     // Clean up
     SDL_Quit();
}

void update_scroll(struct PPU* ppu, unsigned char sx, unsigned char sy){
     (*ppu).SX = sx;
     (*ppu).SX = sy;
}

void update_background(struct PPU* ppu, unsigned int* pixels){
     memcpy((*ppu).background, pixels, BACKGROUND_RES*sizeof(unsigned int));
}

void update_line(struct PPU* ppu, unsigned char line){
     unsigned int i;

     unsigned int offset = (((*ppu).SY+line)%256)*256;
     for(i = 0; i < PPU_X; ++i){
          (*ppu).pixels[line*PPU_X + i] = (*ppu).background[(offset+(((*ppu).SX+i)%256))];
     }
}

void update_screen(struct PPU* ppu){
     SDL_UpdateTexture((*ppu).texture, NULL, (*ppu).pixels,  PPU_X* sizeof(unsigned int));
     SDL_RenderClear((*ppu).renderer);
     SDL_RenderCopy((*ppu).renderer, (*ppu).texture, NULL, NULL);
     SDL_RenderPresent((*ppu).renderer);
}

void execute_ppu(struct PPU* ppu, struct MMU* mmu, struct CPU* cpu){
     // 4 MODES

     // begin at MODE 2

     //mode 0: update screen after 1 line drawn
     //mode 1: Vblank (wait 10 lines)
     //mode 2: read line
     //mode 3: write line
     unsigned char current_line;
     switch((*ppu).mode){
          // H Blank
     case 0x00:
          if((*ppu).timer >= 204){
               (*ppu).timer = 0;

               current_line = mmu_read(mmu, 0xff44);
               mmu_write(mmu, 0xff44, ++current_line);

               if(current_line == 143){
                    // Enter vblank
                    (*ppu).mode = 0x01;
                    update_screen(ppu);

                    // GENERATE interrupt VBlank
                    printf("V-blank interrupt!\n");
                    Push(&(*cpu).PC, cpu, mmu);
                    (*cpu).PC = 0x40;
               }
               else{
                    (*ppu).mode = 0x02;
               }
          }
          break;
     case 0x01:
          if((*ppu).timer >= 456)
          {
               (*ppu).timer = 0;
               current_line = mmu_read(mmu, 0xff44);
               mmu_write(mmu, 0xff44, ++current_line);
               if(current_line > 153)
               {
                    // Restart scanning modes
                    (*ppu).mode = 2;
                    mmu_write(mmu, 0xff44, 0);
                    load_background_sprites(ppu, mmu);
               }
          }
          break;
     case 0x02:
          if((*ppu).timer >= 80){
               // Enter scanline mode 3
               (*ppu).timer = 0x00;
               (*ppu).mode = 0x03;
          }
          break;
     case 0x03:
          if((*ppu).timer >= 172){
               // Enter hblank
               (*ppu).timer = 0x00;
               (*ppu).mode = 0x00;

               // Write a scanline to the framebuffer
               unsigned char current_line = mmu_read(mmu, 0xff44);
               update_line(ppu, current_line);
          }
          break;
     }
}

void load_sprite(struct MMU* mmu, unsigned char sprite_nb, unsigned int* sprite){
    // TETRIS -> address after 8000
    unsigned int offset = 0x8000+sprite_nb*16;
    unsigned char i,j;
    unsigned char color;
    for (i = 0; i < 8; ++i){
        // linea por linea
         unsigned char first = mmu_read(mmu, offset + i*2);
         unsigned char second = mmu_read(mmu, offset + i*2 +1);
        for (j = 0; j < 8; ++j){
             if(first & second & (1 << (7-j))){
                  sprite[i*8+j] = palette[0x03];
             }
             else if(first & ~second & (1 << (7-j))){
                  sprite[i*8+j] = palette[0x02];
             }
             else if(~first & second & (1 << (7-j))){
                   sprite[i*8+j] = palette[0x01];
             }
             else {
                   sprite[i*8+j] = palette[0x00];
             }
        }
    }
}

void update_background_sprite(struct PPU* ppu, struct MMU* mmu, unsigned char sprite_nb, unsigned int position){

    unsigned int sprite[64];
    load_sprite(mmu,sprite_nb,sprite);

    unsigned int i,j;
    unsigned int pos_y = (position/32)*8;
    unsigned int pos_x = (position%32)*8;
    unsigned int offset = pos_y*32*8 + pos_x;
    //printf("SPRITE NUMBER: %d, pos_x: %d, pos_y: %d\n", position, pos_x, pos_y);
    for(i = 0; i < 8; ++i){
         for(j = 0; j < 8; ++j){
              (*ppu).background[offset+i*32*8+j] = sprite[i*8+j];
         }
    }
}

/*
 * Loads sprite number in BACKGROUND MAP TILE (0x9800 - 0x9BFF).
 */
void load_background_sprites(struct PPU* ppu, struct MMU* mmu){

    unsigned int i;
    unsigned char sprite_nb;
    for(i = 0; i < 1024; ++i){
        sprite_nb = mmu_read(mmu, 0x9800+i);
        update_background_sprite(ppu, mmu, sprite_nb, i);
        //if(sprite_nb != 0) printf("SPRITE_NB %d\n", sprite_nb);
    }
}

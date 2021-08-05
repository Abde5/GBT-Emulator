#include "ppu.h"
#include <string.h>

#define SCALE 5

unsigned int palette[4] = {0xffe0f8d0, 0xff88c070, 0xff346856, 0xff081820};


void create_window(struct PPU* ppu){

     SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

     // Create an application window with the following settings:
     (*ppu).window =SDL_CreateWindow(
          "GBT",                  // window title
          SDL_WINDOWPOS_UNDEFINED,           // initial x position
          SDL_WINDOWPOS_UNDEFINED,           // initial y position
          160*SCALE,                               // width, in pixels
          144*SCALE,                               // height, in pixels
          SDL_WINDOW_OPENGL                  // flags - see below
          );

     memset((*ppu).pixels, 0x00, RES*sizeof(unsigned int));

     (*ppu).renderer = SDL_CreateRenderer((*ppu).window, -1, 0);

     SDL_RenderSetScale((*ppu).renderer,
                        SCALE, SCALE);

     (*ppu).texture = SDL_CreateTexture((*ppu).renderer,
                                               SDL_PIXELFORMAT_ARGB8888,
                                               SDL_TEXTUREACCESS_STATIC,
                                               160,
                                               144);
     if ((*ppu).window == NULL) {
          // In the case that the window could not be made...
          printf("Could not create window: %s\n", SDL_GetError());
     }
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
     memcpy((*ppu).background, pixels, BACKGROUND_RES);
}

void update_line(struct PPU* ppu, unsigned char line){
     unsigned int i;

     unsigned int offset = (((*ppu).SY+line)%256)*256;
     for(i = 0; i < PPU_X; ++i){
         (*ppu).pixels[line*PPU_X + i] = (*ppu).background[(offset+((*ppu).SX+i)%256)];

         if((offset+((*ppu).SX+i)%256) > 255*255){
              printf("\nhey que nos hemos pasao, SX=%d, SY=%d,line=%d i=%d",(*ppu).SX,(*ppu).SY,line,i);
         }
     }
}

void update_ppu(struct PPU* ppu){

     //printf("before UpdateTexture\n");
     SDL_UpdateTexture((*ppu).texture, NULL, (*ppu).pixels, 160 * sizeof(unsigned int));
     //printf("after UpdateTexture\n");
     SDL_RenderClear((*ppu).renderer);
     //printf("after RenderClear\n");
     SDL_RenderCopy((*ppu).renderer, (*ppu).texture, NULL, NULL);
     //printf("after RenderCopy\n");
     SDL_RenderPresent((*ppu).renderer);
     //printf("after RenderPresent\n");
}

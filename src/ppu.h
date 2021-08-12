
#ifndef _PPU_
#define _PPU_

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "mmu.h"


#define PPU_X 160
#define PPU_Y 144
#define RES  PPU_X*PPU_Y
#define BACKGROUND_RES 65536
#define SCALE 5

struct PPU {
     SDL_Window* window;
     SDL_Renderer* renderer;
     SDL_Texture* texture;
     unsigned int pixels[RES];
     unsigned int background[BACKGROUND_RES];
     unsigned char SY;
     unsigned char SX;
};

unsigned int palette[4];

void create_window(struct PPU*);
void destroy_ppu(struct PPU*);
void update_scroll(struct PPU*, unsigned char, unsigned char);
void update_background(struct PPU*, unsigned int*);
void update_line(struct PPU*, unsigned char);
void update_ppu(struct PPU*);

//-- sprite methods --
void update_background_sprite(struct PPU*, struct MMU*, unsigned char sprite_nb, unsigned char position);
void load_background_sprites(struct PPU*, struct MMU*);
#endif

#include "ppu.h"

#define SCALE 5

SDL_Window* create_window(){

     SDL_Window *window;

     SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

     // Create an application window with the following settings:
     window =SDL_CreateWindow(
          "GBT",                  // window title
          SDL_WINDOWPOS_UNDEFINED,           // initial x position
          SDL_WINDOWPOS_UNDEFINED,           // initial y position
          160*SCALE,                               // width, in pixels
          144*SCALE,                               // height, in pixels
          SDL_WINDOW_OPENGL                  // flags - see below
          );
     unsigned int palette[4] = {0xffe0f8d0, 0xff88c070, 0xff346856, 0xff081820};

     unsigned int* pixels = calloc(160*144,sizeof(unsigned int));

int i, j; for (i = 0; i < 144; ++i)
               for (j = 0; j < 160; ++j)
                    if (j < 40) pixels[i*160+j] = palette[0];
                    else if (j < 80) pixels[i*160+j] = palette[1];
                    else if (j < 120) pixels[i*160+j] = palette[2];
                    else pixels[i*160+j] = palette[3];

     SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

     SDL_RenderSetScale(renderer,
                        SCALE, SCALE);

     SDL_Texture * texture = SDL_CreateTexture(renderer,
                                               SDL_PIXELFORMAT_ARGB8888,
                                               SDL_TEXTUREACCESS_STATIC,
                                               160,
                                               144);

     if (window == NULL) {
          // In the case that the window could not be made...
          printf("Could not create window: %s\n", SDL_GetError());
          return NULL;
     }

     SDL_UpdateTexture(texture, NULL, pixels, 160 * sizeof(Uint32));

     SDL_RenderClear(renderer);
     SDL_RenderCopy(renderer, texture, NULL, NULL);
     SDL_RenderPresent(renderer);

     SDL_Delay(30000);  // Pause execution for 3000 milliseconds, for example

     // Close and destroy the window
     SDL_DestroyWindow(window);

     // Clean up
     SDL_Quit();

     return window;
}

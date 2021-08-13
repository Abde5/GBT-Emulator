//#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "tools.h"
#include "cpu.h"
#include "mmu.h"
#include "ppu.h"
#include "groups/transfer.h"


#define TETRIS_SIZE 32768

void patches(struct CPU* cpu, struct MMU* mmu) {
     //if (cpu->PC == 0x0064) mmu_write(mmu, 0xff44, 0x90);
     if (cpu->PC == 0x0233) mmu_write(mmu, 0xff44, 0x94);
     else if (cpu->PC == 0x2828) mmu_write(mmu, 0xff44, 0x91);
}

/*
 * Main routine of our program.
 *
 * ONLY FOR TESTING PURPOSES.
 *
 * - Args:
 *     1.- gameboy ROM path.
 */
int main(int argc, char *argv[]) {
    unsigned char* cartridge = read_file(argv[1]);

    struct PPU ppu;
    struct CPU cpu;
    struct MMU mmu;

    // TETRIS copied into memory
    memcpy(mmu.mem,cartridge,TETRIS_SIZE);

    ///// CPU initialization //////
    cpu.A = 0x00;
    cpu.B = 0x00;
    cpu.F = 0x00; // carry flag = 1
    cpu.BC = 0x00;
    cpu.DE = 0x00;
    cpu.HL = 0x00;

    cpu.SP = 0xE000;
    cpu.PC = 0x0100;
    cpu.tick = 0;
    cpu.interrupt = 1;

    //////////////////////////////


    unsigned int * new_background = calloc(256*256, sizeof(unsigned int));

    ppu.SX = 0;
    ppu.SY = 0;

    // create cross in background
    int i,j;
    /*for(i = 0; i < 256; ++i){
         for(j = 0; j < 256; ++j){
              if((i == 128) || (j == 128)) new_background[j*256+i] = palette[2];
              if((i == j) || (255-i == j)) new_background[j*256+i] = palette[0];
              if((i == (j+5)) || (255-i == j+5)) new_background[j*256+i] = palette[1];
              if((i == (j-5)) || (255-i == j-5)) new_background[j*256+i] = palette[1];
         }
         }*/

    for (i=0; i < 1024; ++i){
         update_background_sprite(&ppu, &mmu, i, i);
    }

    unsigned int sprite[64];
    load_sprite(&mmu,0,sprite);

    create_window(&ppu);

    unsigned char pos = 0;
    pos = 0;
    double inc = 0;
    SDL_Event evt;
    unsigned int instruction_nb;
    unsigned int current_ticks;
    unsigned int updated_ticks;
    // -------- MAIN LOOP --------
    while(1){
        current_ticks = cpu.tick;
        instruction_nb ++;
#ifdef DEBUG
        printf("%04x: ", cpu.PC);
#endif
        unsigned char next_opcode = CPU_fetch(&cpu, &mmu);
        CPU_decode_execute(next_opcode, &cpu, &mmu);
#ifdef DEBUG
        printf("\n");
#endif
        updated_ticks = cpu.tick - current_ticks;
        ppu.timer += updated_ticks;
//#ifdef DEBUG
//        printf("DEBUG: Value of HL: %04x\n", cpu.HL);
//#endif
        //printf("\tB register: %x\n", cpu.B);
        patches(&cpu,&mmu);

        // GRAPHICAL
        while(SDL_PollEvent(&evt)){
            /* Handle event */
        }
        //printf("Color in 0x8002: %04x\n", mmu_read(&mmu, 0x8002));
        //load_background_sprites(&ppu, &mmu);
        //ppu.SY = (unsigned char)((sin(inc)+1)*128);
        //ppu.SX = (unsigned char)((cos(inc)+1)*128);
        // frame

        // update line each time

        execute_ppu(&ppu, &mmu, &cpu);

        //SDL_Delay(30);
        pos++;
        inc += 0.02;
    }
    return  0;
}

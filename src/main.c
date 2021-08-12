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


#define TETRIS_SIZE 32768

void patches(struct CPU* cpu, struct MMU* mmu) {
     if (cpu->PC == 0x0064) mmu_write(mmu, 0xff44, 0x90);
     else if (cpu->PC == 0x0233) mmu_write(mmu, 0xff44, 0x94);
     else if (cpu->PC == 0x2828) mmu_write(mmu, 0xff44, 0x91);
}

/*
 * Main routine of our program.
 *
 * ONLY FOR TESTING PURPOSES.
 *y
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
    cpu.tick= 0;

    //////////////////////////////


    unsigned int * new_background = calloc(256*256, sizeof(unsigned int));

    ppu.SX = 0;
    ppu.SY = 0;

    // create cross in background
    int i,j;
    for(i = 0; i < 256; ++i){
         for(j = 0; j < 256; ++j){
              if((i == 128) || (j == 128)) new_background[j*256+i] = palette[2];
              if((i == j) || (255-i == j)) new_background[j*256+i] = palette[0];
              if((i == (j+5)) || (255-i == j+5)) new_background[j*256+i] = palette[1];
              if((i == (j-5)) || (255-i == j-5)) new_background[j*256+i] = palette[1];
         }
    }

    update_background(&ppu, new_background);

    create_window(&ppu);

    unsigned char pos = 0;
    pos = 0;
    double inc = 0;
    SDL_Event evt;
    unsigned int instruction_nb;

    // -------- MAIN LOOP --------
    while(1){
        instruction_nb ++;
        unsigned char next_opcode = CPU_fetch(&cpu, &mmu);
        CPU_decode_execute(next_opcode, &cpu, &mmu);

#ifdef DEBUG
        printf("DEBUG: Value of HL: %04x\n", cpu.HL);
#endif
        //printf("\tB register: %x\n", cpu.B);
        patches(&cpu,&mmu);


        // GRAPHICAL
        while(SDL_PollEvent(&evt)){
            /* Handle event */
        }
        ppu.SY = (unsigned char)((sin(inc)+1)*128);
        ppu.SX = (unsigned char)((cos(inc)+1)*128);
        // frame
        for(i = 0; i < PPU_Y; ++i){
             //ppu.SX = (sin(i*5)+1);
             update_line(&ppu, i);
        }
        update_ppu(&ppu);

        SDL_Delay(30);
        pos++;
        inc += 0.02;
    }
    return  0;
}

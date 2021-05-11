#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tools.h"
#include "cpu.h"
#include "mmu.h"


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
 *
 * - Args:
 *     1.- gameboy ROM path.
 */
int main(int argc, char *argv[]) {
    unsigned char* cartridge = read_file(argv[1]);

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

    char* var;
    int instruction_nb = 0;
    // TESTING instructions
    while(1){
        instruction_nb ++;
        printf("%x: ",cpu.PC);
        unsigned char next_opcode = CPU_fetch(&cpu, &mmu);
        //printf("%x: ",next_opcode);
        //printf("\nPC: %x", cpu.PC);
        //printf("\nDecoded instruction: %x", next_opcode);
        //printf("\nNumber of instruction: %x", instruction_nb);
        CPU_decode_execute(next_opcode, &cpu, &mmu);
        usleep(30000);
        printf("\n");
        patches(&cpu,&mmu);
        scanf(var);
    }
    //printf("\nResult in BC: %x", cpu.BC);
    //printf("\nResult in DE: %x", cpu.DE);
    //printf("\nResult in HL: %x", cpu.HL);
    return  0;
}

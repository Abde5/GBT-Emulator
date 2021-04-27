#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "cpu.h"
#include "mmu.h"

#define TETRIS_SIZE 32768

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
    // JR 0xFE
    mmu_write(&mmu, 0x100, 0x18);
    mmu_write(&mmu, 0x101, 0xFE);


    ///// CPU initialization //////
    cpu.A = 0x00;
    cpu.B = 0x01;
    cpu.F = 0x00; // carry flag = 1
    cpu.BC = 0x01;
    cpu.DE = 0x02;
    cpu.HL = 0x03;

    cpu.SP = 0xE000;
    cpu.PC = 0x0100;
    cpu.tick= 0;

    //////////////////////////////

    int instruction_nb = 0;
    // TESTING instructions
    while(1){
        instruction_nb ++;
        unsigned char next_opcode = CPU_fetch(&cpu, &mmu);
        //printf("\nPC: %x", cpu.PC);
        //printf("\nDecoded instruction: %x", next_opcode);
        //printf("\nNumber of instruction: %x", instruction_nb);
        CPU_decode_execute(next_opcode, &cpu, &mmu);
    }
    //printf("\nResult in BC: %x", cpu.BC);
    //printf("\nResult in DE: %x", cpu.DE);
    //printf("\nResult in HL: %x", cpu.HL);
    return  0;
}

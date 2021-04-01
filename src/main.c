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

    ///// CPU initialization //////
    cpu.A = 0x05;
    cpu.F = 0x00;
    cpu.BC = 0;
    cpu.B = 0x06;
    cpu.DE = 0;
    cpu.HL = 0x159;

    cpu.SP = 0;
    cpu.PC = 0x100;
    cpu.tick= 0;

    //////////////////////////////

    // TESTING instructions
    //unsigned char next_opcode = CPU_fetch(&cpu, &mmu);

    CPU_decode_execute(0xA6, &cpu, &mmu);

    printf("\nResult in A: %x", cpu.A);
    printf("\nTicks: %d", cpu.tick);
    printf("\nResult in F: %x", cpu.F);
    return  0;
}

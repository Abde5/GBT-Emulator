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
    cpu.A = 0x00;
    cpu.F = 0x00;
    cpu.BC = 0;
    cpu.DE = 0;
    cpu.HL = 0;

    cpu.SP = 0;
    cpu.PC = 0x100;

    //////////////////////////////

    // TESTING instructions
    unsigned char next_opcode = CPU_fetch(&cpu, &mmu);

    printf("Next opcode: %x\n", next_opcode);

    CPU_decode_execute(next_opcode, &cpu, &mmu);
    printf("\nopcode with prefix: ");
    CPU_decode_execute_prefix(0x9A, &cpu, &mmu);


    return  0;
}

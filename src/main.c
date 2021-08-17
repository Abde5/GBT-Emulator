#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#include "tools.h"
#include "cpu.h"
#include "mmu.h"
/*
#include "ppu.h"
#include "groups/tansfer.h"
*/

/* Prints the usage of the executable */
void error_usage(const char* message) {
	fprintf(stderr, "%s\nGBT Emulator:\nUsage: ./gbt [ROM_PATH]\n", 
			message);
	exit(1);
}

void patches(CPU* cpu, MMU* mmu) {
	// if (cpu->PC == 0x0064) mmu_write(mmu, 0xff44, 0x90);
    if (cpu->PC == 0x0233) mmu_write(mmu, 0xff44, 0x94);
    else if (cpu->PC == 0x2828) mmu_write(mmu, 0xff44, 0x91);
}

/* Main routine of the program.
 * - Args: 
 *   1) Gameboy ROM path.
 */
int main(int argc, char** argv) {
	// Retrieve the bytes of the cartidge
	if (argc < 2) { error_usage(""); }
	size_t cartridge_len = 0;
	uint8_t* cartridge = read_file(argv[1], &cartridge_len);

	// Write them to the stdout
	fwrite(cartridge, cartridge_len, 1, stdout);

	MMU mmu = {0};

	memcpy(mmu.mem, cartridge, cartridge_len);

	CPU cpu = {
		.A = 0x00,
		.B = 0x00,
		.F = 0x00, // Carry flag = 1
		.BC = 0x00,
		.ED = 0x00,
		.HL = 0x00,

		.SP = 0xE000,
		.PC = 0x1000,
		.tick = 0,
		.interrupt = 1
	};

	return 0;
}

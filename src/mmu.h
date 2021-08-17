#ifndef MMU_H
#define MMU_H

#include <stdint.h>

#define MMU_SIZE 65536

/* Structure that defines the internal structure of
 * memory addressable by the CPU.
 *
 * In our implementation, the MMU is an array of the size
 * of the addressable space
 */
typedef struct MMU MMU;
struct MMU {
	// NOTE(cdecompilador): Maybe using an vector data structure for no
	// overallocation since all will be cached the performance might be similar
	// to stack allocated
	uint8_t mem[MMU_SIZE];
};

/* Byte(8 bit) reading and writing to memory */
uint8_t mmu_read(const MMU* mmu, uint16_t address);
void mmu_write(MMU* mmu, uint16_t address, uint8_t value);

/* Word(16 bit) reading and writing to memory */
uint16_t mmu_read_16(const MMU* mmu, uint16_t address);
void mmu_write_16(MMU* mmu, uint16_t address, uint16_t value);

#endif

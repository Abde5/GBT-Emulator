#include "mmu.h"

uint8_t mmu_read(const MMU* mmu, uint16_t address) {
	return mmu->mem[address];
}

void mmu_write(MMU* mmu, uint16_t address, uint8_t value) {
	// NOTE(cdecompilador): Because the type is unigned no need to check 
	// negative numbers
	if (address >= 0x8000) {
#ifdef NDEBUG
	printf("Error OOB: Writting in %04x", address);
#endif
		return;
	}

	mmu->mem[address] = value;
}

uint16_t mmu_read_16(const MMU* mmu, uint16_t address) {
	return *((uint16_t*)&(mmu->mem[address]));
}

void mmu_write_16(MMU* mmu, uint16_t address, uint16_t value){
	// NOTE(cdecompilador): Because the type is unigned no need to check 
	// negative numbers
	if (address >= 0x8000) {
#ifdef NDEBUG
	printf("Error OOB: Writting in %04x", address);
#endif
		return;
	}

	*((uint16_t*)&(mmu->mem[address])) = value;
}


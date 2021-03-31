#include "mmu.h"

unsigned char mmu_read(struct MMU* mmu, unsigned short addr){
    return (*mmu).mem[addr];
}

void mmu_write(struct MMU* mmu, unsigned char addr, unsigned char value){
        (*mmu).mem[addr] = value;
}

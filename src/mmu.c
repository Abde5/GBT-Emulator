#include "mmu.h"

unsigned char mmu_read(struct MMU* mmu, unsigned short addr){
    return (*mmu).mem[addr];
}

unsigned short mmu_read_16(struct MMU* mmu, unsigned short addr){
     return *((unsigned short *)&((*mmu).mem[addr]));
}

void mmu_write(struct MMU* mmu, unsigned short addr, unsigned char value){
    (*mmu).mem[addr] = value;
}

void mmu_write_16(struct MMU* mmu, unsigned short addr, unsigned short value){
     *((unsigned short *)&((*mmu).mem[addr])) = value;
}

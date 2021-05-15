#include "mmu.h"
#include <stdio.h>

unsigned char mmu_read(struct MMU* mmu, unsigned short addr){
    return (*mmu).mem[addr];
}

unsigned short mmu_read_16(struct MMU* mmu, unsigned short addr){
     return *((unsigned short *)&((*mmu).mem[addr]));
}

void mmu_write(struct MMU* mmu, unsigned short addr, unsigned char value){
    if(addr >= 0x0000 && addr < 0x8000){
#ifdef DEBUG
        printf("\nDEBUG: Writing in %04x",addr);
#endif
        return;
    }
    (*mmu).mem[addr] = value;
}

void mmu_write_16(struct MMU* mmu, unsigned short addr, unsigned short value){
     if(addr >= 0x0000 && addr < 0x8000){
#ifdef DEBUG
          printf("\nDEBUG: Writing in %04x\n",addr);
#endif
          return;
     }
     *((unsigned short *)&((*mmu).mem[addr])) = value;
}

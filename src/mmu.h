#ifndef _MMU_
#define _MMU_

#define MMU_SIZE 65536

/*
 * Structure that defines the internal structure of
 * memory addressable by the CPU.
 *
 * In our implementation, the MMU is an array of the size
 * of the addressable space.
 */
struct MMU {

    unsigned char mem[MMU_SIZE];

};

unsigned char mmu_read(struct MMU*, unsigned short);
void mmu_write(struct MMU*, unsigned char, unsigned char);

#endif

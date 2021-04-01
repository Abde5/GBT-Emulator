#ifndef _CPU_
#define _CPU_

#include <stdio.h>
#include "mmu.h"

/*
 * Structure that represents the internal state of our CPU.
 */
struct CPU {
    union {
        struct{
            unsigned char F;
            unsigned char A;
        };
        unsigned short AF;
    };
    union {
        struct{
            unsigned char C;
            unsigned char B;
        };
        unsigned short BC;
    };

    union {
        struct{
            unsigned char D;
            unsigned char E;
        };
        unsigned short DE;
    };

    union {
        struct{
            unsigned char L;
            unsigned char H;
        };
        unsigned short HL;
    };

    unsigned short SP;
    unsigned short PC;

    unsigned short tick;
};

const unsigned char Z_flag;
const unsigned char N_flag;
const unsigned char H_flag;
const unsigned char C_flag;

// ------- FETCH - DECODE - EXECUTE LOOP functions -------
unsigned char CPU_fetch(struct CPU*, struct MMU*);
void CPU_decode_execute(unsigned char opcode, struct CPU* cpu, struct MMU* mmu);
void CPU_decode_execute_prefix(unsigned char opcode, struct CPU* cpu, struct MMU* mmu);

#endif

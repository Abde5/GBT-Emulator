#include "branch.h"

void Jr18(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR r8, Length: 2
    // Cycles: 12, (Z N H C): - - - -
    printf("Not implemented! (Jr18)");
}

void Jr20(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR NZ,r8, Length: 2
    // Cycles: 12/8, (Z N H C): - - - -
    printf("Not implemented! (Jr20)");
}

void Jr28(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR Z,r8, Length: 2
    // Cycles: 12/8, (Z N H C): - - - -
    printf("Not implemented! (Jr28)");
}

void Jr30(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR NC,r8, Length: 2
    // Cycles: 12/8, (Z N H C): - - - -
    printf("Not implemented! (Jr30)");
}

void Jr38(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR C,r8, Length: 2
    // Cycles: 12/8, (Z N H C): - - - -
    printf("Not implemented! (Jr38)");
}

void RetC0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET NZ, Length: 1
    // Cycles: 20/8, (Z N H C): - - - -
    printf("Not implemented! (RetC0)");
}

void RetC8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET Z, Length: 1
    // Cycles: 20/8, (Z N H C): - - - -
    printf("Not implemented! (RetC8)");
}

void RetC9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RetC9)");
}

void RetD0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET NC, Length: 1
    // Cycles: 20/8, (Z N H C): - - - -
    printf("Not implemented! (RetD0)");
}

void RetD8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET C, Length: 1
    // Cycles: 20/8, (Z N H C): - - - -
    printf("Not implemented! (RetD8)");
}

void JpC2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP NZ,a16, Length: 3
    // Cycles: 16/12, (Z N H C): - - - -
    printf("Not implemented! (JpC2)");
}

void JpC3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP a16, Length: 3
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (JpC3)");
}

void JpCA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP Z,a16, Length: 3
    // Cycles: 16/12, (Z N H C): - - - -
    printf("Not implemented! (JpCA)");
}

void JpD2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP NC,a16, Length: 3
    // Cycles: 16/12, (Z N H C): - - - -
    printf("Not implemented! (JpD2)");
}

void JpDA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP C,a16, Length: 3
    // Cycles: 16/12, (Z N H C): - - - -
    printf("Not implemented! (JpDA)");
}

void JpE9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP (HL), Length: 1
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (JpE9)");
}

void CallC4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL NZ,a16, Length: 3
    // Cycles: 24/12, (Z N H C): - - - -
    printf("Not implemented! (CallC4)");
}

void CallCC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL Z,a16, Length: 3
    // Cycles: 24/12, (Z N H C): - - - -
    printf("Not implemented! (CallCC)");
}

void CallCD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL a16, Length: 3
    // Cycles: 24, (Z N H C): - - - -
    printf("Not implemented! (CallCD)");
}

void CallD4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL NC,a16, Length: 3
    // Cycles: 24/12, (Z N H C): - - - -
    printf("Not implemented! (CallD4)");
}

void CallDC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL C,a16, Length: 3
    // Cycles: 24/12, (Z N H C): - - - -
    printf("Not implemented! (CallDC)");
}

void RstC7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 00H, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RstC7)");
}

void RstCF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 08H, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RstCF)");
}

void RstD7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 10H, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RstD7)");
}

void RstDF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 18H, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RstDF)");
}

void RstE7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 20H, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RstE7)");
}

void RstEF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 28H, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RstEF)");
}

void RstF7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 30H, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RstF7)");
}

void RstFF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 38H, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RstFF)");
}

void RetiD9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RETI, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (RetiD9)");
}


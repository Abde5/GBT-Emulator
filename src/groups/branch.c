#include "branch.h"
#include "transfer.h"

void Jr18(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR r8, Length: 2
#ifdef DEBUG
    printf("JR r8");
#endif
    // Cycles: 12, (Z N H C): - - - -
    signed char d8 = mmu_read(mmu,(*cpu).PC);
    (*cpu).PC += 1;
    (*cpu).PC += d8;
    (*cpu).tick += 12;
}

void Jr20(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR NZ,r8, Length: 2
#ifdef DEBUG
    printf("JR NZ,r8");
#endif
    // Cycles: 12/8, (Z N H C): - - - -
    if (((*cpu).F & Z_flag) != Z_flag){
         signed short d8 = mmu_read(mmu,(*cpu).PC);
         (*cpu).PC += 1;
         (*cpu).PC += d8;
         (*cpu).tick += 12;
    } else {
         (*cpu).PC += 1;
         (*cpu).tick += 8;
    }
}

void Jr28(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR Z,r8, Length: 2
#ifdef DEBUG
    printf("JR Z,r8");
#endif
    // Cycles: 12/8, (Z N H C): - - - -
    if (((*cpu).F & Z_flag) == Z_flag){
         signed short d8 = mmu_read(mmu,(*cpu).PC);
         (*cpu).PC += 1;
         (*cpu).PC += d8;
         (*cpu).tick += 12;
    } else {
         (*cpu).PC += 1;
         (*cpu).tick += 8;
    }
}

void Jr30(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR NC,r8, Length: 2
#ifdef DEBUG
    printf("JR NC,r8");
#endif
    // Cycles: 12/8, (Z N H C): - - - -
    if (((*cpu).F & C_flag) != C_flag){
         signed short d8 = mmu_read(mmu,(*cpu).PC);
         (*cpu).PC += 1;
         (*cpu).PC += d8;
         (*cpu).tick += 12;
    } else {
         (*cpu).PC += 1;
         (*cpu).tick += 8;
    }
    (*cpu).PC += 1;
}

void Jr38(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JR C,r8, Length: 2
#ifdef DEBUG
    printf("JR C,r8");
#endif
    // Cycles: 12/8, (Z N H C): - - - -
    if (((*cpu).F & C_flag) == C_flag){
         signed short d8 = mmu_read(mmu,(*cpu).PC);
         (*cpu).PC += 1;
         (*cpu).PC += d8;
         (*cpu).tick += 12;
    } else {
         (*cpu).PC += 1;
         (*cpu).tick += 8;
    }
    (*cpu).PC += 1;
}

void RetC0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET NZ, Length: 1
#ifdef DEBUG
    printf("RET NZ");
#endif
    // Cycles: 20/8, (Z N H C): - - - -
    if (((*cpu).F & Z_flag) != Z_flag){
         Pop(&(*cpu).PC, cpu, mmu);

         (*cpu).tick += 20;
    } else {
         (*cpu).tick += 8;
    }
}

void RetC8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET Z, Length: 1
#ifdef DEBUG
    printf("RET Z");
#endif
    // Cycles: 20/8, (Z N H C): - - - -
    if (((*cpu).F & Z_flag) == Z_flag){
         Pop(&(*cpu).PC, cpu, mmu);

         (*cpu).tick += 20;
    } else {
         (*cpu).tick += 8;
    }
}

void RetC9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET, Length: 1
#ifdef DEBUG
    printf("RET");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Pop(&(*cpu).PC, cpu, mmu);
    (*cpu).tick += 16;
}

void RetD0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET NC, Length: 1
#ifdef DEBUG
    printf("RET NC");
#endif
    // Cycles: 20/8, (Z N H C): - - - -
    if (((*cpu).F & C_flag) != C_flag){
         Pop(&(*cpu).PC, cpu, mmu);
         (*cpu).tick += 20;
    } else {
         (*cpu).tick += 8;
    }
}

void RetD8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RET C, Length: 1
#ifdef DEBUG
    printf("RET C");
#endif
    // Cycles: 20/8, (Z N H C): - - - -
    if (((*cpu).F & C_flag) == C_flag){
         Pop(&(*cpu).PC, cpu, mmu);
         (*cpu).tick += 20;
    } else {
         (*cpu).tick += 8;
    }
}

void JpC2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP NZ,a16, Length: 3
#ifdef DEBUG
    printf("JP NZ,a16");
#endif
    // Cycles: 16/12, (Z N H C): - - - -
    if (((*cpu).F & Z_flag) != Z_flag){
         unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
         (*cpu).PC = d16;
         (*cpu).tick += 16;
    } else {
         (*cpu).PC += 2;
         (*cpu).tick += 12;
    }
}

void JpC3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP a16, Length: 3
#ifdef DEBUG
    printf("JP a16");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
    (*cpu).PC = d16;
    (*cpu).tick += 16;
}

void JpCA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP Z,a16, Length: 3
#ifdef DEBUG
    printf("JP Z,a16");
#endif
    // Cycles: 16/12, (Z N H C): - - - -
    if (((*cpu).F & Z_flag) == Z_flag){
        unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
        (*cpu).PC = d16;
        (*cpu).tick += 16;
    } else {
        (*cpu).PC += 2;
        (*cpu).tick += 12;
    }
}

void JpD2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP NC,a16, Length: 3
#ifdef DEBUG
    printf("JP NC,a16");
#endif
    // Cycles: 16/12, (Z N H C): - - - -
    if (((*cpu).F & C_flag) != C_flag){
         unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
         (*cpu).PC = d16;
         (*cpu).tick += 16;
    } else {
         (*cpu).PC += 2;
         (*cpu).tick += 12;
    }
}

void JpDA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP C,a16, Length: 3
#ifdef DEBUG
    printf("JP C,a16");
#endif
    // Cycles: 16/12, (Z N H C): - - - -
    if (((*cpu).F & C_flag) == C_flag){
         unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
         (*cpu).PC = d16;
         (*cpu).tick += 16;
    } else {
         (*cpu).PC += 2;
         (*cpu).tick += 12;
    }
}

void JpE9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: JP (HL), Length: 1
#ifdef DEBUG
    printf("JP (HL)");
#endif
    // Cycles: 4, (Z N H C): - - - -
    (*cpu).PC = (*cpu).HL;
    (*cpu).tick += 4;
}

void CallC4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL NZ,a16, Length: 3
#ifdef DEBUG
    printf("CALL NZ,a16");
#endif
    // Cycles: 24/12, (Z N H C): - - - -
    if (((*cpu).F & Z_flag) != Z_flag){
         Push(&(*cpu).PC, cpu, mmu);
         unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
         (*cpu).PC = d16;
         (*cpu).tick += 24;
    } else {
         (*cpu).PC += 2;
         (*cpu).tick += 12;
    }

}

void CallCC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL Z,a16, Length: 3
#ifdef DEBUG
    printf("CALL Z,a16");
#endif
    // Cycles: 24/12, (Z N H C): - - - -
    if (((*cpu).F & Z_flag) == Z_flag){
         Push(&(*cpu).PC, cpu, mmu);
         unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
         (*cpu).PC = d16;
         (*cpu).tick += 24;
    } else {
         (*cpu).PC += 2;
         (*cpu).tick += 12;
    }
}

void CallCD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL a16, Length: 3
#ifdef DEBUG
    printf("CALL a16");
#endif
    // Cycles: 24, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
    (*cpu).PC = d16;
    (*cpu).PC += 2;
}

void CallD4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL NC,a16, Length: 3
#ifdef DEBUG
    printf("CALL NC,a16");
#endif
    // Cycles: 24/12, (Z N H C): - - - -
    if (((*cpu).F & C_flag) != C_flag){
         Push(&(*cpu).PC, cpu, mmu);
         unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
         (*cpu).PC = d16;
         (*cpu).tick += 24;
    } else {
         (*cpu).PC += 2;
         (*cpu).tick += 12;
    }
}

void CallDC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CALL C,a16, Length: 3
#ifdef DEBUG
    printf("CALL C,a16");
#endif
    // Cycles: 24/12, (Z N H C): - - - -
    if (((*cpu).F & C_flag) == C_flag){
         Push(&(*cpu).PC, cpu, mmu);
         unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
         (*cpu).PC = d16;
         (*cpu).tick += 24;
    } else {
         (*cpu).PC += 2;
         (*cpu).tick += 12;
    }
}

void RstC7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 00H, Length: 1
#ifdef DEBUG
    printf("RST 00H");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    (*cpu).PC = 0x0000;
    (*cpu).tick += 16;
}

void RstCF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 08H, Length: 1
#ifdef DEBUG
    printf("RST 08H");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    (*cpu).PC = 0x0008;
    (*cpu).tick += 16;
}

void RstD7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 10H, Length: 1
#ifdef DEBUG
    printf("RST 10H");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    (*cpu).PC = 0x0010;
    (*cpu).tick += 16;
}

void RstDF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 18H, Length: 1
#ifdef DEBUG
    printf("RST 18H");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    (*cpu).PC = 0x0018;
    (*cpu).tick += 16;
}

void RstE7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 20H, Length: 1
#ifdef DEBUG
    printf("RST 20H");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    (*cpu).PC = 0x0020;
    (*cpu).tick += 16;
}

void RstEF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 28H, Length: 1
#ifdef DEBUG
    printf("RST 28H");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    (*cpu).PC = 0x0028;
    (*cpu).tick += 16;
}

void RstF7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 30H, Length: 1
#ifdef DEBUG
    printf("RST 30H");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    (*cpu).PC = 0x0030;
    (*cpu).tick += 16;
}

void RstFF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RST 38H, Length: 1
#ifdef DEBUG
    printf("RST 38H");
#endif
    // Cycles: 16, (Z N H C): - - - -
    Push(&(*cpu).PC, cpu, mmu);
    (*cpu).PC = 0x0038;
    (*cpu).tick += 16;
}

void RetiD9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RETI, Length: 1
#ifdef DEBUG
    printf("RETI");
#endif
    // Cycles: 16, (Z N H C): - - - -
    // TODO
    printf("Not implemented! (RetiD9)");
}


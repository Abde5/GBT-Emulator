#ifndef PREFIX_H
#define PREFIX_H

#include "../cpu.h"
#include "../mmu.h"

/*
 * Rotate left through carry.
 */
void Rlc00(struct CPU* cpu, struct MMU* mmu);
void Rlc01(struct CPU* cpu, struct MMU* mmu);
void Rlc02(struct CPU* cpu, struct MMU* mmu);
void Rlc03(struct CPU* cpu, struct MMU* mmu);
void Rlc04(struct CPU* cpu, struct MMU* mmu);
void Rlc05(struct CPU* cpu, struct MMU* mmu);
void Rlc06(struct CPU* cpu, struct MMU* mmu);
void Rlc07(struct CPU* cpu, struct MMU* mmu);

/*
 * Rotate right through carry.
 */
void Rrc08(struct CPU* cpu, struct MMU* mmu);
void Rrc09(struct CPU* cpu, struct MMU* mmu);
void Rrc0A(struct CPU* cpu, struct MMU* mmu);
void Rrc0B(struct CPU* cpu, struct MMU* mmu);
void Rrc0C(struct CPU* cpu, struct MMU* mmu);
void Rrc0D(struct CPU* cpu, struct MMU* mmu);
void Rrc0E(struct CPU* cpu, struct MMU* mmu);
void Rrc0F(struct CPU* cpu, struct MMU* mmu);

/*
 * Rotate left.
 */
void Rl10(struct CPU* cpu, struct MMU* mmu);
void Rl11(struct CPU* cpu, struct MMU* mmu);
void Rl12(struct CPU* cpu, struct MMU* mmu);
void Rl13(struct CPU* cpu, struct MMU* mmu);
void Rl14(struct CPU* cpu, struct MMU* mmu);
void Rl15(struct CPU* cpu, struct MMU* mmu);
void Rl16(struct CPU* cpu, struct MMU* mmu);
void Rl17(struct CPU* cpu, struct MMU* mmu);

/*
 * Rotate right.
 */
void Rr18(struct CPU* cpu, struct MMU* mmu);
void Rr19(struct CPU* cpu, struct MMU* mmu);
void Rr1A(struct CPU* cpu, struct MMU* mmu);
void Rr1B(struct CPU* cpu, struct MMU* mmu);
void Rr1C(struct CPU* cpu, struct MMU* mmu);
void Rr1D(struct CPU* cpu, struct MMU* mmu);
void Rr1E(struct CPU* cpu, struct MMU* mmu);
void Rr1F(struct CPU* cpu, struct MMU* mmu);

/*
 * Shift left into carry.
 */
void Sla20(struct CPU* cpu, struct MMU* mmu);
void Sla21(struct CPU* cpu, struct MMU* mmu);
void Sla22(struct CPU* cpu, struct MMU* mmu);
void Sla23(struct CPU* cpu, struct MMU* mmu);
void Sla24(struct CPU* cpu, struct MMU* mmu);
void Sla25(struct CPU* cpu, struct MMU* mmu);
void Sla26(struct CPU* cpu, struct MMU* mmu);
void Sla27(struct CPU* cpu, struct MMU* mmu);

/*
 * Shift right into carry.
 */
void Sra28(struct CPU* cpu, struct MMU* mmu);
void Sra29(struct CPU* cpu, struct MMU* mmu);
void Sra2A(struct CPU* cpu, struct MMU* mmu);
void Sra2B(struct CPU* cpu, struct MMU* mmu);
void Sra2C(struct CPU* cpu, struct MMU* mmu);
void Sra2D(struct CPU* cpu, struct MMU* mmu);
void Sra2E(struct CPU* cpu, struct MMU* mmu);
void Sra2F(struct CPU* cpu, struct MMU* mmu);

/*
 * Swap operations.
 */
void Swap30(struct CPU* cpu, struct MMU* mmu);
void Swap31(struct CPU* cpu, struct MMU* mmu);
void Swap32(struct CPU* cpu, struct MMU* mmu);
void Swap33(struct CPU* cpu, struct MMU* mmu);
void Swap34(struct CPU* cpu, struct MMU* mmu);
void Swap35(struct CPU* cpu, struct MMU* mmu);
void Swap36(struct CPU* cpu, struct MMU* mmu);
void Swap37(struct CPU* cpu, struct MMU* mmu);

/*
 * Shift right.
 */
void Srl38(struct CPU* cpu, struct MMU* mmu);
void Srl39(struct CPU* cpu, struct MMU* mmu);
void Srl3A(struct CPU* cpu, struct MMU* mmu);
void Srl3B(struct CPU* cpu, struct MMU* mmu);
void Srl3C(struct CPU* cpu, struct MMU* mmu);
void Srl3D(struct CPU* cpu, struct MMU* mmu);
void Srl3E(struct CPU* cpu, struct MMU* mmu);
void Srl3F(struct CPU* cpu, struct MMU* mmu);

/*
 * SET bit operations.
 */
void Bit40(struct CPU* cpu, struct MMU* mmu);
void Bit41(struct CPU* cpu, struct MMU* mmu);
void Bit42(struct CPU* cpu, struct MMU* mmu);
void Bit43(struct CPU* cpu, struct MMU* mmu);
void Bit44(struct CPU* cpu, struct MMU* mmu);
void Bit45(struct CPU* cpu, struct MMU* mmu);
void Bit46(struct CPU* cpu, struct MMU* mmu);
void Bit47(struct CPU* cpu, struct MMU* mmu);
void Bit48(struct CPU* cpu, struct MMU* mmu);
void Bit49(struct CPU* cpu, struct MMU* mmu);
void Bit4A(struct CPU* cpu, struct MMU* mmu);
void Bit4B(struct CPU* cpu, struct MMU* mmu);
void Bit4C(struct CPU* cpu, struct MMU* mmu);
void Bit4D(struct CPU* cpu, struct MMU* mmu);
void Bit4E(struct CPU* cpu, struct MMU* mmu);
void Bit4F(struct CPU* cpu, struct MMU* mmu);
void Bit50(struct CPU* cpu, struct MMU* mmu);
void Bit51(struct CPU* cpu, struct MMU* mmu);
void Bit52(struct CPU* cpu, struct MMU* mmu);
void Bit53(struct CPU* cpu, struct MMU* mmu);
void Bit54(struct CPU* cpu, struct MMU* mmu);
void Bit55(struct CPU* cpu, struct MMU* mmu);
void Bit56(struct CPU* cpu, struct MMU* mmu);
void Bit57(struct CPU* cpu, struct MMU* mmu);
void Bit58(struct CPU* cpu, struct MMU* mmu);
void Bit59(struct CPU* cpu, struct MMU* mmu);
void Bit5A(struct CPU* cpu, struct MMU* mmu);
void Bit5B(struct CPU* cpu, struct MMU* mmu);
void Bit5C(struct CPU* cpu, struct MMU* mmu);
void Bit5D(struct CPU* cpu, struct MMU* mmu);
void Bit5E(struct CPU* cpu, struct MMU* mmu);
void Bit5F(struct CPU* cpu, struct MMU* mmu);
void Bit60(struct CPU* cpu, struct MMU* mmu);
void Bit61(struct CPU* cpu, struct MMU* mmu);
void Bit62(struct CPU* cpu, struct MMU* mmu);
void Bit63(struct CPU* cpu, struct MMU* mmu);
void Bit64(struct CPU* cpu, struct MMU* mmu);
void Bit65(struct CPU* cpu, struct MMU* mmu);
void Bit66(struct CPU* cpu, struct MMU* mmu);
void Bit67(struct CPU* cpu, struct MMU* mmu);
void Bit68(struct CPU* cpu, struct MMU* mmu);
void Bit69(struct CPU* cpu, struct MMU* mmu);
void Bit6A(struct CPU* cpu, struct MMU* mmu);
void Bit6B(struct CPU* cpu, struct MMU* mmu);
void Bit6C(struct CPU* cpu, struct MMU* mmu);
void Bit6D(struct CPU* cpu, struct MMU* mmu);
void Bit6E(struct CPU* cpu, struct MMU* mmu);
void Bit6F(struct CPU* cpu, struct MMU* mmu);
void Bit70(struct CPU* cpu, struct MMU* mmu);
void Bit71(struct CPU* cpu, struct MMU* mmu);
void Bit72(struct CPU* cpu, struct MMU* mmu);
void Bit73(struct CPU* cpu, struct MMU* mmu);
void Bit74(struct CPU* cpu, struct MMU* mmu);
void Bit75(struct CPU* cpu, struct MMU* mmu);
void Bit76(struct CPU* cpu, struct MMU* mmu);
void Bit77(struct CPU* cpu, struct MMU* mmu);
void Bit78(struct CPU* cpu, struct MMU* mmu);
void Bit79(struct CPU* cpu, struct MMU* mmu);
void Bit7A(struct CPU* cpu, struct MMU* mmu);
void Bit7B(struct CPU* cpu, struct MMU* mmu);
void Bit7C(struct CPU* cpu, struct MMU* mmu);
void Bit7D(struct CPU* cpu, struct MMU* mmu);
void Bit7E(struct CPU* cpu, struct MMU* mmu);
void Bit7F(struct CPU* cpu, struct MMU* mmu);

/*
 * Reset bit operations.
 */
void Res80(struct CPU* cpu, struct MMU* mmu);
void Res81(struct CPU* cpu, struct MMU* mmu);
void Res82(struct CPU* cpu, struct MMU* mmu);
void Res83(struct CPU* cpu, struct MMU* mmu);
void Res84(struct CPU* cpu, struct MMU* mmu);
void Res85(struct CPU* cpu, struct MMU* mmu);
void Res86(struct CPU* cpu, struct MMU* mmu);
void Res87(struct CPU* cpu, struct MMU* mmu);
void Res88(struct CPU* cpu, struct MMU* mmu);
void Res89(struct CPU* cpu, struct MMU* mmu);
void Res8A(struct CPU* cpu, struct MMU* mmu);
void Res8B(struct CPU* cpu, struct MMU* mmu);
void Res8C(struct CPU* cpu, struct MMU* mmu);
void Res8D(struct CPU* cpu, struct MMU* mmu);
void Res8E(struct CPU* cpu, struct MMU* mmu);
void Res8F(struct CPU* cpu, struct MMU* mmu);
void Res90(struct CPU* cpu, struct MMU* mmu);
void Res91(struct CPU* cpu, struct MMU* mmu);
void Res92(struct CPU* cpu, struct MMU* mmu);
void Res93(struct CPU* cpu, struct MMU* mmu);
void Res94(struct CPU* cpu, struct MMU* mmu);
void Res95(struct CPU* cpu, struct MMU* mmu);
void Res96(struct CPU* cpu, struct MMU* mmu);
void Res97(struct CPU* cpu, struct MMU* mmu);
void Res98(struct CPU* cpu, struct MMU* mmu);
void Res99(struct CPU* cpu, struct MMU* mmu);
void Res9A(struct CPU* cpu, struct MMU* mmu);
void Res9B(struct CPU* cpu, struct MMU* mmu);
void Res9C(struct CPU* cpu, struct MMU* mmu);
void Res9D(struct CPU* cpu, struct MMU* mmu);
void Res9E(struct CPU* cpu, struct MMU* mmu);
void Res9F(struct CPU* cpu, struct MMU* mmu);
void ResA0(struct CPU* cpu, struct MMU* mmu);
void ResA1(struct CPU* cpu, struct MMU* mmu);
void ResA2(struct CPU* cpu, struct MMU* mmu);
void ResA3(struct CPU* cpu, struct MMU* mmu);
void ResA4(struct CPU* cpu, struct MMU* mmu);
void ResA5(struct CPU* cpu, struct MMU* mmu);
void ResA6(struct CPU* cpu, struct MMU* mmu);
void ResA7(struct CPU* cpu, struct MMU* mmu);
void ResA8(struct CPU* cpu, struct MMU* mmu);
void ResA9(struct CPU* cpu, struct MMU* mmu);
void ResAA(struct CPU* cpu, struct MMU* mmu);
void ResAB(struct CPU* cpu, struct MMU* mmu);
void ResAC(struct CPU* cpu, struct MMU* mmu);
void ResAD(struct CPU* cpu, struct MMU* mmu);
void ResAE(struct CPU* cpu, struct MMU* mmu);
void ResAF(struct CPU* cpu, struct MMU* mmu);
void ResB0(struct CPU* cpu, struct MMU* mmu);
void ResB1(struct CPU* cpu, struct MMU* mmu);
void ResB2(struct CPU* cpu, struct MMU* mmu);
void ResB3(struct CPU* cpu, struct MMU* mmu);
void ResB4(struct CPU* cpu, struct MMU* mmu);
void ResB5(struct CPU* cpu, struct MMU* mmu);
void ResB6(struct CPU* cpu, struct MMU* mmu);
void ResB7(struct CPU* cpu, struct MMU* mmu);
void ResB8(struct CPU* cpu, struct MMU* mmu);
void ResB9(struct CPU* cpu, struct MMU* mmu);
void ResBA(struct CPU* cpu, struct MMU* mmu);
void ResBB(struct CPU* cpu, struct MMU* mmu);
void ResBC(struct CPU* cpu, struct MMU* mmu);
void ResBD(struct CPU* cpu, struct MMU* mmu);
void ResBE(struct CPU* cpu, struct MMU* mmu);
void ResBF(struct CPU* cpu, struct MMU* mmu);

/*
 * Set bit operations.
 */
void SetC0(struct CPU* cpu, struct MMU* mmu);
void SetC1(struct CPU* cpu, struct MMU* mmu);
void SetC2(struct CPU* cpu, struct MMU* mmu);
void SetC3(struct CPU* cpu, struct MMU* mmu);
void SetC4(struct CPU* cpu, struct MMU* mmu);
void SetC5(struct CPU* cpu, struct MMU* mmu);
void SetC6(struct CPU* cpu, struct MMU* mmu);
void SetC7(struct CPU* cpu, struct MMU* mmu);
void SetC8(struct CPU* cpu, struct MMU* mmu);
void SetC9(struct CPU* cpu, struct MMU* mmu);
void SetCA(struct CPU* cpu, struct MMU* mmu);
void SetCB(struct CPU* cpu, struct MMU* mmu);
void SetCC(struct CPU* cpu, struct MMU* mmu);
void SetCD(struct CPU* cpu, struct MMU* mmu);
void SetCE(struct CPU* cpu, struct MMU* mmu);
void SetCF(struct CPU* cpu, struct MMU* mmu);
void SetD0(struct CPU* cpu, struct MMU* mmu);
void SetD1(struct CPU* cpu, struct MMU* mmu);
void SetD2(struct CPU* cpu, struct MMU* mmu);
void SetD3(struct CPU* cpu, struct MMU* mmu);
void SetD4(struct CPU* cpu, struct MMU* mmu);
void SetD5(struct CPU* cpu, struct MMU* mmu);
void SetD6(struct CPU* cpu, struct MMU* mmu);
void SetD7(struct CPU* cpu, struct MMU* mmu);
void SetD8(struct CPU* cpu, struct MMU* mmu);
void SetD9(struct CPU* cpu, struct MMU* mmu);
void SetDA(struct CPU* cpu, struct MMU* mmu);
void SetDB(struct CPU* cpu, struct MMU* mmu);
void SetDC(struct CPU* cpu, struct MMU* mmu);
void SetDD(struct CPU* cpu, struct MMU* mmu);
void SetDE(struct CPU* cpu, struct MMU* mmu);
void SetDF(struct CPU* cpu, struct MMU* mmu);
void SetE0(struct CPU* cpu, struct MMU* mmu);
void SetE1(struct CPU* cpu, struct MMU* mmu);
void SetE2(struct CPU* cpu, struct MMU* mmu);
void SetE3(struct CPU* cpu, struct MMU* mmu);
void SetE4(struct CPU* cpu, struct MMU* mmu);
void SetE5(struct CPU* cpu, struct MMU* mmu);
void SetE6(struct CPU* cpu, struct MMU* mmu);
void SetE7(struct CPU* cpu, struct MMU* mmu);
void SetE8(struct CPU* cpu, struct MMU* mmu);
void SetE9(struct CPU* cpu, struct MMU* mmu);
void SetEA(struct CPU* cpu, struct MMU* mmu);
void SetEB(struct CPU* cpu, struct MMU* mmu);
void SetEC(struct CPU* cpu, struct MMU* mmu);
void SetED(struct CPU* cpu, struct MMU* mmu);
void SetEE(struct CPU* cpu, struct MMU* mmu);
void SetEF(struct CPU* cpu, struct MMU* mmu);
void SetF0(struct CPU* cpu, struct MMU* mmu);
void SetF1(struct CPU* cpu, struct MMU* mmu);
void SetF2(struct CPU* cpu, struct MMU* mmu);
void SetF3(struct CPU* cpu, struct MMU* mmu);
void SetF4(struct CPU* cpu, struct MMU* mmu);
void SetF5(struct CPU* cpu, struct MMU* mmu);
void SetF6(struct CPU* cpu, struct MMU* mmu);
void SetF7(struct CPU* cpu, struct MMU* mmu);
void SetF8(struct CPU* cpu, struct MMU* mmu);
void SetF9(struct CPU* cpu, struct MMU* mmu);
void SetFA(struct CPU* cpu, struct MMU* mmu);
void SetFB(struct CPU* cpu, struct MMU* mmu);
void SetFC(struct CPU* cpu, struct MMU* mmu);
void SetFD(struct CPU* cpu, struct MMU* mmu);
void SetFE(struct CPU* cpu, struct MMU* mmu);
void SetFF(struct CPU* cpu, struct MMU* mmu);

#endif // PREFIX_H

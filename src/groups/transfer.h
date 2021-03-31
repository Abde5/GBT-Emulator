#ifndef TRANSFER_H
#define TRANSFER_H

#include "../cpu.h"
#include "../mmu.h"

/*
 * LOAD operations.
 */
void Ld01(struct CPU* cpu, struct MMU* mmu);
void Ld02(struct CPU* cpu, struct MMU* mmu);
void Ld06(struct CPU* cpu, struct MMU* mmu);
void Ld08(struct CPU* cpu, struct MMU* mmu);
void Ld0A(struct CPU* cpu, struct MMU* mmu);
void Ld0E(struct CPU* cpu, struct MMU* mmu);
void Ld11(struct CPU* cpu, struct MMU* mmu);
void Ld12(struct CPU* cpu, struct MMU* mmu);
void Ld16(struct CPU* cpu, struct MMU* mmu);
void Ld1A(struct CPU* cpu, struct MMU* mmu);
void Ld1E(struct CPU* cpu, struct MMU* mmu);
void Ld21(struct CPU* cpu, struct MMU* mmu);
void Ld22(struct CPU* cpu, struct MMU* mmu);
void Ld26(struct CPU* cpu, struct MMU* mmu);
void Ld2A(struct CPU* cpu, struct MMU* mmu);
void Ld2E(struct CPU* cpu, struct MMU* mmu);
void Ld31(struct CPU* cpu, struct MMU* mmu);
void Ld32(struct CPU* cpu, struct MMU* mmu);
void Ld36(struct CPU* cpu, struct MMU* mmu);
void Ld3A(struct CPU* cpu, struct MMU* mmu);
void Ld3E(struct CPU* cpu, struct MMU* mmu);
void Ld40(struct CPU* cpu, struct MMU* mmu);
void Ld41(struct CPU* cpu, struct MMU* mmu);
void Ld42(struct CPU* cpu, struct MMU* mmu);
void Ld43(struct CPU* cpu, struct MMU* mmu);
void Ld44(struct CPU* cpu, struct MMU* mmu);
void Ld45(struct CPU* cpu, struct MMU* mmu);
void Ld46(struct CPU* cpu, struct MMU* mmu);
void Ld47(struct CPU* cpu, struct MMU* mmu);
void Ld48(struct CPU* cpu, struct MMU* mmu);
void Ld49(struct CPU* cpu, struct MMU* mmu);
void Ld4A(struct CPU* cpu, struct MMU* mmu);
void Ld4B(struct CPU* cpu, struct MMU* mmu);
void Ld4C(struct CPU* cpu, struct MMU* mmu);
void Ld4D(struct CPU* cpu, struct MMU* mmu);
void Ld4E(struct CPU* cpu, struct MMU* mmu);
void Ld4F(struct CPU* cpu, struct MMU* mmu);
void Ld50(struct CPU* cpu, struct MMU* mmu);
void Ld51(struct CPU* cpu, struct MMU* mmu);
void Ld52(struct CPU* cpu, struct MMU* mmu);
void Ld53(struct CPU* cpu, struct MMU* mmu);
void Ld54(struct CPU* cpu, struct MMU* mmu);
void Ld55(struct CPU* cpu, struct MMU* mmu);
void Ld56(struct CPU* cpu, struct MMU* mmu);
void Ld57(struct CPU* cpu, struct MMU* mmu);
void Ld58(struct CPU* cpu, struct MMU* mmu);
void Ld59(struct CPU* cpu, struct MMU* mmu);
void Ld5A(struct CPU* cpu, struct MMU* mmu);
void Ld5B(struct CPU* cpu, struct MMU* mmu);
void Ld5C(struct CPU* cpu, struct MMU* mmu);
void Ld5D(struct CPU* cpu, struct MMU* mmu);
void Ld5E(struct CPU* cpu, struct MMU* mmu);
void Ld5F(struct CPU* cpu, struct MMU* mmu);
void Ld60(struct CPU* cpu, struct MMU* mmu);
void Ld61(struct CPU* cpu, struct MMU* mmu);
void Ld62(struct CPU* cpu, struct MMU* mmu);
void Ld63(struct CPU* cpu, struct MMU* mmu);
void Ld64(struct CPU* cpu, struct MMU* mmu);
void Ld65(struct CPU* cpu, struct MMU* mmu);
void Ld66(struct CPU* cpu, struct MMU* mmu);
void Ld67(struct CPU* cpu, struct MMU* mmu);
void Ld68(struct CPU* cpu, struct MMU* mmu);
void Ld69(struct CPU* cpu, struct MMU* mmu);
void Ld6A(struct CPU* cpu, struct MMU* mmu);
void Ld6B(struct CPU* cpu, struct MMU* mmu);
void Ld6C(struct CPU* cpu, struct MMU* mmu);
void Ld6D(struct CPU* cpu, struct MMU* mmu);
void Ld6E(struct CPU* cpu, struct MMU* mmu);
void Ld6F(struct CPU* cpu, struct MMU* mmu);
void Ld70(struct CPU* cpu, struct MMU* mmu);
void Ld71(struct CPU* cpu, struct MMU* mmu);
void Ld72(struct CPU* cpu, struct MMU* mmu);
void Ld73(struct CPU* cpu, struct MMU* mmu);
void Ld74(struct CPU* cpu, struct MMU* mmu);
void Ld75(struct CPU* cpu, struct MMU* mmu);
void Ld77(struct CPU* cpu, struct MMU* mmu);
void Ld78(struct CPU* cpu, struct MMU* mmu);
void Ld79(struct CPU* cpu, struct MMU* mmu);
void Ld7A(struct CPU* cpu, struct MMU* mmu);
void Ld7B(struct CPU* cpu, struct MMU* mmu);
void Ld7C(struct CPU* cpu, struct MMU* mmu);
void Ld7D(struct CPU* cpu, struct MMU* mmu);
void Ld7E(struct CPU* cpu, struct MMU* mmu);
void Ld7F(struct CPU* cpu, struct MMU* mmu);
void LdE2(struct CPU* cpu, struct MMU* mmu);
void LdEA(struct CPU* cpu, struct MMU* mmu);
void LdF2(struct CPU* cpu, struct MMU* mmu);
void LdF8(struct CPU* cpu, struct MMU* mmu);
void LdF9(struct CPU* cpu, struct MMU* mmu);
void LdFA(struct CPU* cpu, struct MMU* mmu);

/*
 * POP operations.
 */
void PopC1(struct CPU* cpu, struct MMU* mmu);
void PopD1(struct CPU* cpu, struct MMU* mmu);
void PopE1(struct CPU* cpu, struct MMU* mmu);
void PopF1(struct CPU* cpu, struct MMU* mmu);

/*
 * PUSH operations.
 */
void PushC5(struct CPU* cpu, struct MMU* mmu);
void PushD5(struct CPU* cpu, struct MMU* mmu);
void PushE5(struct CPU* cpu, struct MMU* mmu);
void PushF5(struct CPU* cpu, struct MMU* mmu);

/*
 * Upper RAM load operations.
 */
void LdhE0(struct CPU* cpu, struct MMU* mmu);
void LdhF0(struct CPU* cpu, struct MMU* mmu);

#endif // TRANSFER_H

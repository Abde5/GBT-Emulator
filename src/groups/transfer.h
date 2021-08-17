#ifndef TRANSFER_H
#define TRANSFER_H

#include "../cpu.h"
#include "../mmu.h"

/*
 * LOAD operations.
 */
void Ld01(CPU* cpu, MMU* mmu);
void Ld02(CPU* cpu, MMU* mmu);
void Ld06(CPU* cpu, MMU* mmu);
void Ld08(CPU* cpu, MMU* mmu);
void Ld0A(CPU* cpu, MMU* mmu);
void Ld0E(CPU* cpu, MMU* mmu);
void Ld11(CPU* cpu, MMU* mmu);
void Ld12(CPU* cpu, MMU* mmu);
void Ld16(CPU* cpu, MMU* mmu);
void Ld1A(CPU* cpu, MMU* mmu);
void Ld1E(CPU* cpu, MMU* mmu);
void Ld21(CPU* cpu, MMU* mmu);
void Ld22(CPU* cpu, MMU* mmu);
void Ld26(CPU* cpu, MMU* mmu);
void Ld2A(CPU* cpu, MMU* mmu);
void Ld2E(CPU* cpu, MMU* mmu);
void Ld31(CPU* cpu, MMU* mmu);
void Ld32(CPU* cpu, MMU* mmu);
void Ld36(CPU* cpu, MMU* mmu);
void Ld3A(CPU* cpu, MMU* mmu);
void Ld3E(CPU* cpu, MMU* mmu);
void Ld40(CPU* cpu, MMU* mmu);
void Ld41(CPU* cpu, MMU* mmu);
void Ld42(CPU* cpu, MMU* mmu);
void Ld43(CPU* cpu, MMU* mmu);
void Ld44(CPU* cpu, MMU* mmu);
void Ld45(CPU* cpu, MMU* mmu);
void Ld46(CPU* cpu, MMU* mmu);
void Ld47(CPU* cpu, MMU* mmu);
void Ld48(CPU* cpu, MMU* mmu);
void Ld49(CPU* cpu, MMU* mmu);
void Ld4A(CPU* cpu, MMU* mmu);
void Ld4B(CPU* cpu, MMU* mmu);
void Ld4C(CPU* cpu, MMU* mmu);
void Ld4D(CPU* cpu, MMU* mmu);
void Ld4E(CPU* cpu, MMU* mmu);
void Ld4F(CPU* cpu, MMU* mmu);
void Ld50(CPU* cpu, MMU* mmu);
void Ld51(CPU* cpu, MMU* mmu);
void Ld52(CPU* cpu, MMU* mmu);
void Ld53(CPU* cpu, MMU* mmu);
void Ld54(CPU* cpu, MMU* mmu);
void Ld55(CPU* cpu, MMU* mmu);
void Ld56(CPU* cpu, MMU* mmu);
void Ld57(CPU* cpu, MMU* mmu);
void Ld58(CPU* cpu, MMU* mmu);
void Ld59(CPU* cpu, MMU* mmu);
void Ld5A(CPU* cpu, MMU* mmu);
void Ld5B(CPU* cpu, MMU* mmu);
void Ld5C(CPU* cpu, MMU* mmu);
void Ld5D(CPU* cpu, MMU* mmu);
void Ld5E(CPU* cpu, MMU* mmu);
void Ld5F(CPU* cpu, MMU* mmu);
void Ld60(CPU* cpu, MMU* mmu);
void Ld61(CPU* cpu, MMU* mmu);
void Ld62(CPU* cpu, MMU* mmu);
void Ld63(CPU* cpu, MMU* mmu);
void Ld64(CPU* cpu, MMU* mmu);
void Ld65(CPU* cpu, MMU* mmu);
void Ld66(CPU* cpu, MMU* mmu);
void Ld67(CPU* cpu, MMU* mmu);
void Ld68(CPU* cpu, MMU* mmu);
void Ld69(CPU* cpu, MMU* mmu);
void Ld6A(CPU* cpu, MMU* mmu);
void Ld6B(CPU* cpu, MMU* mmu);
void Ld6C(CPU* cpu, MMU* mmu);
void Ld6D(CPU* cpu, MMU* mmu);
void Ld6E(CPU* cpu, MMU* mmu);
void Ld6F(CPU* cpu, MMU* mmu);
void Ld70(CPU* cpu, MMU* mmu);
void Ld71(CPU* cpu, MMU* mmu);
void Ld72(CPU* cpu, MMU* mmu);
void Ld73(CPU* cpu, MMU* mmu);
void Ld74(CPU* cpu, MMU* mmu);
void Ld75(CPU* cpu, MMU* mmu);
void Ld77(CPU* cpu, MMU* mmu);
void Ld78(CPU* cpu, MMU* mmu);
void Ld79(CPU* cpu, MMU* mmu);
void Ld7A(CPU* cpu, MMU* mmu);
void Ld7B(CPU* cpu, MMU* mmu);
void Ld7C(CPU* cpu, MMU* mmu);
void Ld7D(CPU* cpu, MMU* mmu);
void Ld7E(CPU* cpu, MMU* mmu);
void Ld7F(CPU* cpu, MMU* mmu);
void LdE2(CPU* cpu, MMU* mmu);
void LdEA(CPU* cpu, MMU* mmu);
void LdF2(CPU* cpu, MMU* mmu);
void LdF8(CPU* cpu, MMU* mmu);
void LdF9(CPU* cpu, MMU* mmu);
void LdFA(CPU* cpu, MMU* mmu);

/*
 * POP operations.
 */
void Pop(unsigned short *reg, CPU* cpu, MMU* mmu);
void PopC1(CPU* cpu, MMU* mmu);
void PopD1(CPU* cpu, MMU* mmu);
void PopE1(CPU* cpu, MMU* mmu);
void PopF1(CPU* cpu, MMU* mmu);

/*
 * PUSH operations.
 */
void Push(unsigned short *reg, CPU* cpu, MMU* mmu);
void PushC5(CPU* cpu, MMU* mmu);
void PushD5(CPU* cpu, MMU* mmu);
void PushE5(CPU* cpu, MMU* mmu);
void PushF5(CPU* cpu, MMU* mmu);

/*
 * Upper RAM load operations.
 */
void LdhE0(CPU* cpu, MMU* mmu);
void LdhF0(CPU* cpu, MMU* mmu);

#endif // TRANSFER_H

#include "cpu.h"
#include "groups/misc.h"
#include "groups/aritmetic.h"
#include "groups/branch.h"
#include "groups/prefix.h"
#include "groups/transfer.h"

const unsigned char Z_flag = 0x1<<7;
const unsigned char N_flag = 0x1<<6;
const unsigned char H_flag = 0x1<<5;
const unsigned char C_flag = 0x1<<4;

unsigned char CPU_fetch(struct CPU* cpu, struct MMU* mmu){
        return mmu_read(mmu, (*cpu).PC++);
}

/*
 * Function that emulates the decode and execute
 */
void CPU_decode_execute(unsigned char opcode, struct CPU* cpu, struct MMU* mmu){
        switch(opcode){
        case 0x00:
		        Nop00(cpu,mmu);
                break;
        case 0x07:
                Rlca07(cpu,mmu);
                break;
        case 0x0f:
                Rrca0F(cpu,mmu);
                break;
        case 0x10:
                Stop10(cpu,mmu);
                break;
        case 0x17:
                Rla17(cpu,mmu);
                break;
        case 0x1f:
                Rra1F(cpu,mmu);
                break;
        case 0x76:
                Halt76(cpu,mmu);
                break;
        case 0xf3:
                DiF3(cpu,mmu);
                break;
        case 0xfb:
                EiFB(cpu,mmu);
                break;
        case 0x01:
                Ld01(cpu,mmu);
                break;
        case 0x02:
                Ld02(cpu,mmu);
                break;
        case 0x06:
                Ld06(cpu,mmu);
                break;
        case 0x08:
                Ld08(cpu,mmu);
                break;
        case 0x0a:
                Ld0A(cpu,mmu);
                break;
        case 0x0e:
                Ld0E(cpu,mmu);
                break;
        case 0x11:
                Ld11(cpu,mmu);
                break;
        case 0x12:
                Ld12(cpu,mmu);
                break;
        case 0x16:
                Ld16(cpu,mmu);
                break;
        case 0x1a:
                Ld1A(cpu,mmu);
                break;
        case 0x1e:
                Ld1E(cpu,mmu);
                break;
        case 0x21:
                Ld21(cpu,mmu);
                break;
        case 0x22:
                Ld22(cpu,mmu);
                break;
        case 0x26:
                Ld26(cpu,mmu);
                break;
        case 0x2a:
                Ld2A(cpu,mmu);
                break;
        case 0x2e:
                Ld2E(cpu,mmu);
                break;
        case 0x31:
                Ld31(cpu,mmu);
                break;
        case 0x32:
                Ld32(cpu,mmu);
                break;
        case 0x36:
                Ld36(cpu,mmu);
                break;
        case 0x3a:
                Ld3A(cpu,mmu);
                break;
        case 0x3e:
                Ld3E(cpu,mmu);
                break;
        case 0x40:
                Ld40(cpu,mmu);
                break;
        case 0x41:
                Ld41(cpu,mmu);
                break;
        case 0x42:
                Ld42(cpu,mmu);
                break;
        case 0x43:
                Ld43(cpu,mmu);
                break;
        case 0x44:
                Ld44(cpu,mmu);
                break;
        case 0x45:
                Ld45(cpu,mmu);
                break;
        case 0x46:
                Ld46(cpu,mmu);
                break;
        case 0x47:
                Ld47(cpu,mmu);
                break;
        case 0x48:
                Ld48(cpu,mmu);
                break;
        case 0x49:
                Ld49(cpu,mmu);
                break;
        case 0x4a:
                Ld4A(cpu,mmu);
                break;
        case 0x4b:
                Ld4B(cpu,mmu);
                break;
        case 0x4c:
                Ld4C(cpu,mmu);
                break;
        case 0x4d:
                Ld4D(cpu,mmu);
                break;
        case 0x4e:
                Ld4E(cpu,mmu);
                break;
        case 0x4f:
                Ld4F(cpu,mmu);
                break;
        case 0x50:
                Ld50(cpu,mmu);
                break;
        case 0x51:
                Ld51(cpu,mmu);
                break;
        case 0x52:
                Ld52(cpu,mmu);
                break;
        case 0x53:
                Ld53(cpu,mmu);
                break;
        case 0x54:
                Ld54(cpu,mmu);
                break;
        case 0x55:
                Ld55(cpu,mmu);
                break;
        case 0x56:
                Ld56(cpu,mmu);
                break;
        case 0x57:
                Ld57(cpu,mmu);
                break;
        case 0x58:
                Ld58(cpu,mmu);
                break;
        case 0x59:
                Ld59(cpu,mmu);
                break;
        case 0x5a:
                Ld5A(cpu,mmu);
                break;
        case 0x5b:
                Ld5B(cpu,mmu);
                break;
        case 0x5c:
                Ld5C(cpu,mmu);
                break;
        case 0x5d:
                Ld5D(cpu,mmu);
                break;
        case 0x5e:
                Ld5E(cpu,mmu);
                break;
        case 0x5f:
                Ld5F(cpu,mmu);
                break;
        case 0x60:
                Ld60(cpu,mmu);
                break;
        case 0x61:
                Ld61(cpu,mmu);
                break;
        case 0x62:
                Ld62(cpu,mmu);
                break;
        case 0x63:
                Ld63(cpu,mmu);
                break;
        case 0x64:
                Ld64(cpu,mmu);
                break;
        case 0x65:
                Ld65(cpu,mmu);
                break;
        case 0x66:
                Ld66(cpu,mmu);
                break;
        case 0x67:
                Ld67(cpu,mmu);
                break;
        case 0x68:
                Ld68(cpu,mmu);
                break;
        case 0x69:
                Ld69(cpu,mmu);
                break;
        case 0x6a:
                Ld6A(cpu,mmu);
                break;
        case 0x6b:
                Ld6B(cpu,mmu);
                break;
        case 0x6c:
                Ld6C(cpu,mmu);
                break;
        case 0x6d:
                Ld6D(cpu,mmu);
                break;
        case 0x6e:
                Ld6E(cpu,mmu);
                break;
        case 0x6f:
                Ld6F(cpu,mmu);
                break;
        case 0x70:
                Ld70(cpu,mmu);
                break;
        case 0x71:
                Ld71(cpu,mmu);
                break;
        case 0x72:
                Ld72(cpu,mmu);
                break;
        case 0x73:
                Ld73(cpu,mmu);
                break;
        case 0x74:
                Ld74(cpu,mmu);
                break;
        case 0x75:
                Ld75(cpu,mmu);
                break;
        case 0x77:
                Ld77(cpu,mmu);
                break;
        case 0x78:
                Ld78(cpu,mmu);
                break;
        case 0x79:
                Ld79(cpu,mmu);
                break;
        case 0x7a:
                Ld7A(cpu,mmu);
                break;
        case 0x7b:
                Ld7B(cpu,mmu);
                break;
        case 0x7c:
                Ld7C(cpu,mmu);
                break;
        case 0x7d:
                Ld7D(cpu,mmu);
                break;
        case 0x7e:
                Ld7E(cpu,mmu);
                break;
        case 0x7f:
                Ld7F(cpu,mmu);
                break;
        case 0xe2:
                LdE2(cpu,mmu);
                break;
        case 0xea:
                LdEA(cpu,mmu);
                break;
        case 0xf2:
                LdF2(cpu,mmu);
                break;
        case 0xf8:
                LdF8(cpu,mmu);
                break;
        case 0xf9:
                LdF9(cpu,mmu);
                break;
        case 0xfa:
                LdFA(cpu,mmu);
                break;
        case 0xc1:
                PopC1(cpu,mmu);
                break;
        case 0xd1:
                PopD1(cpu,mmu);
                break;
        case 0xe1:
                PopE1(cpu,mmu);
                break;
        case 0xf1:
                PopF1(cpu,mmu);
                break;
        case 0xc5:
                PushC5(cpu,mmu);
                break;
        case 0xd5:
                PushD5(cpu,mmu);
                break;
        case 0xe5:
                PushE5(cpu,mmu);
                break;
        case 0xf5:
                PushF5(cpu,mmu);
                break;
        case 0xe0:
                LdhE0(cpu,mmu);
                break;
        case 0xf0:
                LdhF0(cpu,mmu);
                break;
        case 0x03:
                Inc03(cpu,mmu);
                break;
        case 0x04:
                Inc04(cpu,mmu);
                break;
        case 0x0c:
                Inc0C(cpu,mmu);
                break;
        case 0x13:
                Inc13(cpu,mmu);
                break;
        case 0x14:
                Inc14(cpu,mmu);
                break;
        case 0x1c:
                Inc1C(cpu,mmu);
                break;
        case 0x23:
                Inc23(cpu,mmu);
                break;
        case 0x24:
                Inc24(cpu,mmu);
                break;
        case 0x2c:
                Inc2C(cpu,mmu);
                break;
        case 0x33:
                Inc33(cpu,mmu);
                break;
        case 0x34:
                Inc34(cpu,mmu);
                break;
        case 0x3c:
                Inc3C(cpu,mmu);
                break;
        case 0x05:
                Dec05(cpu,mmu);
                break;
        case 0x0b:
                Dec0B(cpu,mmu);
                break;
        case 0x0d:
                Dec0D(cpu,mmu);
                break;
        case 0x15:
                Dec15(cpu,mmu);
                break;
        case 0x1b:
                Dec1B(cpu,mmu);
                break;
        case 0x1d:
                Dec1D(cpu,mmu);
                break;
        case 0x25:
                Dec25(cpu,mmu);
                break;
        case 0x2b:
                Dec2B(cpu,mmu);
                break;
        case 0x2d:
                Dec2D(cpu,mmu);
                break;
        case 0x35:
                Dec35(cpu,mmu);
                break;
        case 0x3b:
                Dec3B(cpu,mmu);
                break;
        case 0x3d:
                Dec3D(cpu,mmu);
                break;
        case 0x09:
                Add09(cpu,mmu);
                break;
        case 0x19:
                Add19(cpu,mmu);
                break;
        case 0x29:
                Add29(cpu,mmu);
                break;
        case 0x39:
                Add39(cpu,mmu);
                break;
        case 0x80:
                Add80(cpu,mmu);
                break;
        case 0x81:
                Add81(cpu,mmu);
                break;
        case 0x82:
                Add82(cpu,mmu);
                break;
        case 0x83:
                Add83(cpu,mmu);
                break;
        case 0x84:
                Add84(cpu,mmu);
                break;
        case 0x85:
                Add85(cpu,mmu);
                break;
        case 0x86:
                Add86(cpu,mmu);
                break;
        case 0x87:
                Add87(cpu,mmu);
                break;
        case 0xc6:
                AddC6(cpu,mmu);
                break;
        case 0xe8:
                AddE8(cpu,mmu);
                break;
        case 0x27:
                Daa27(cpu,mmu);
                break;
        case 0x2f:
                Cpl2F(cpu,mmu);
                break;
        case 0x37:
                Scf37(cpu,mmu);
                break;
        case 0x3f:
                Ccf3F(cpu,mmu);
                break;
        case 0x88:
                Adc88(cpu,mmu);
                break;
        case 0x89:
                Adc89(cpu,mmu);
                break;
        case 0x8a:
                Adc8A(cpu,mmu);
                break;
        case 0x8b:
                Adc8B(cpu,mmu);
                break;
        case 0x8c:
                Adc8C(cpu,mmu);
                break;
        case 0x8d:
                Adc8D(cpu,mmu);
                break;
        case 0x8e:
                Adc8E(cpu,mmu);
                break;
        case 0x8f:
                Adc8F(cpu,mmu);
                break;
        case 0xce:
                AdcCE(cpu,mmu);
                break;
        case 0x90:
                Sub90(cpu,mmu);
                break;
        case 0x91:
                Sub91(cpu,mmu);
                break;
        case 0x92:
                Sub92(cpu,mmu);
                break;
        case 0x93:
                Sub93(cpu,mmu);
                break;
        case 0x94:
                Sub94(cpu,mmu);
                break;
        case 0x95:
                Sub95(cpu,mmu);
                break;
        case 0x96:
                Sub96(cpu,mmu);
                break;
        case 0x97:
                Sub97(cpu,mmu);
                break;
        case 0xd6:
                SubD6(cpu,mmu);
                break;
        case 0x98:
                Sbc98(cpu,mmu);
                break;
        case 0x99:
                Sbc99(cpu,mmu);
                break;
        case 0x9a:
                Sbc9A(cpu,mmu);
                break;
        case 0x9b:
                Sbc9B(cpu,mmu);
                break;
        case 0x9c:
                Sbc9C(cpu,mmu);
                break;
        case 0x9d:
                Sbc9D(cpu,mmu);
                break;
        case 0x9e:
                Sbc9E(cpu,mmu);
                break;
        case 0x9f:
                Sbc9F(cpu,mmu);
                break;
        case 0xde:
                SbcDE(cpu,mmu);
                break;
        case 0xa0:
                AndA0(cpu,mmu);
                break;
        case 0xa1:
                AndA1(cpu,mmu);
                break;
        case 0xa2:
                AndA2(cpu,mmu);
                break;
        case 0xa3:
                AndA3(cpu,mmu);
                break;
        case 0xa4:
                AndA4(cpu,mmu);
                break;
        case 0xa5:
                AndA5(cpu,mmu);
                break;
        case 0xa6:
                AndA6(cpu,mmu);
                break;
        case 0xa7:
                AndA7(cpu,mmu);
                break;
        case 0xe6:
                AndE6(cpu,mmu);
                break;
        case 0xa8:
                XorA8(cpu,mmu);
                break;
        case 0xa9:
                XorA9(cpu,mmu);
                break;
        case 0xaa:
                XorAA(cpu,mmu);
                break;
        case 0xab:
                XorAB(cpu,mmu);
                break;
        case 0xac:
                XorAC(cpu,mmu);
                break;
        case 0xad:
                XorAD(cpu,mmu);
                break;
        case 0xae:
                XorAE(cpu,mmu);
                break;
        case 0xaf:
                XorAF(cpu,mmu);
                break;
        case 0xee:
                XorEE(cpu,mmu);
                break;
        case 0xb0:
                OrB0(cpu,mmu);
                break;
        case 0xb1:
                OrB1(cpu,mmu);
                break;
        case 0xb2:
                OrB2(cpu,mmu);
                break;
        case 0xb3:
                OrB3(cpu,mmu);
                break;
        case 0xb4:
                OrB4(cpu,mmu);
                break;
        case 0xb5:
                OrB5(cpu,mmu);
                break;
        case 0xb6:
                OrB6(cpu,mmu);
                break;
        case 0xb7:
                OrB7(cpu,mmu);
                break;
        case 0xf6:
                OrF6(cpu,mmu);
                break;
        case 0xb8:
                CpB8(cpu,mmu);
                break;
        case 0xb9:
                CpB9(cpu,mmu);
                break;
        case 0xba:
                CpBA(cpu,mmu);
                break;
        case 0xbb:
                CpBB(cpu,mmu);
                break;
        case 0xbc:
                CpBC(cpu,mmu);
                break;
        case 0xbd:
                CpBD(cpu,mmu);
                break;
        case 0xbe:
                CpBE(cpu,mmu);
                break;
        case 0xbf:
                CpBF(cpu,mmu);
                break;
        case 0xfe:
                CpFE(cpu,mmu);
                break;
        case 0x18:
                Jr18(cpu,mmu);
                break;
        case 0x20:
                Jr20(cpu,mmu);
                break;
        case 0x28:
                Jr28(cpu,mmu);
                break;
        case 0x30:
                Jr30(cpu,mmu);
                break;
        case 0x38:
                Jr38(cpu,mmu);
                break;
        case 0xc0:
                RetC0(cpu,mmu);
                break;
        case 0xc8:
                RetC8(cpu,mmu);
                break;
        case 0xc9:
                RetC9(cpu,mmu);
                break;
        case 0xd0:
                RetD0(cpu,mmu);
                break;
        case 0xd8:
                RetD8(cpu,mmu);
                break;
        case 0xc2:
                JpC2(cpu,mmu);
                break;
        case 0xc3:
                JpC3(cpu,mmu);
                break;
        case 0xca:
                JpCA(cpu,mmu);
                break;
        case 0xd2:
                JpD2(cpu,mmu);
                break;
        case 0xda:
                JpDA(cpu,mmu);
                break;
        case 0xe9:
                JpE9(cpu,mmu);
                break;
        case 0xc4:
                CallC4(cpu,mmu);
                break;
        case 0xcc:
                CallCC(cpu,mmu);
                break;
        case 0xcd:
                CallCD(cpu,mmu);
                break;
        case 0xd4:
                CallD4(cpu,mmu);
                break;
        case 0xdc:
                CallDC(cpu,mmu);
                break;
        case 0xc7:
                RstC7(cpu,mmu);
                break;
        case 0xcf:
                RstCF(cpu,mmu);
                break;
        case 0xd7:
                RstD7(cpu,mmu);
                break;
        case 0xdf:
                RstDF(cpu,mmu);
                break;
        case 0xe7:
                RstE7(cpu,mmu);
                break;
        case 0xef:
                RstEF(cpu,mmu);
                break;
        case 0xf7:
                RstF7(cpu,mmu);
                break;
        case 0xff:
                RstFF(cpu,mmu);
                break;
        case 0xd9:
                RetiD9(cpu,mmu);
                break;
        }
}


void CPU_decode_execute_prefix(unsigned char opcode, struct CPU* cpu, struct MMU* mmu){
        switch(opcode){
        case 0x00:
            Rlc00(cpu,mmu);
            break;
        case 0x01:
            Rlc01(cpu,mmu);
            break;
        case 0x02:
            Rlc02(cpu,mmu);
            break;
        case 0x03:
            Rlc03(cpu,mmu);
            break;
        case 0x04:
            Rlc04(cpu,mmu);
            break;
        case 0x05:
            Rlc05(cpu,mmu);
            break;
        case 0x06:
            Rlc06(cpu,mmu);
            break;
        case 0x07:
            Rlc07(cpu,mmu);
            break;
        case 0x08:
            Rrc08(cpu,mmu);
            break;
        case 0x09:
            Rrc09(cpu,mmu);
            break;
        case 0x0a:
            Rrc0A(cpu,mmu);
            break;
        case 0x0b:
            Rrc0B(cpu,mmu);
            break;
        case 0x0c:
            Rrc0C(cpu,mmu);
            break;
        case 0x0d:
            Rrc0D(cpu,mmu);
            break;
        case 0x0e:
            Rrc0E(cpu,mmu);
            break;
        case 0x0f:
            Rrc0F(cpu,mmu);
            break;
        case 0x10:
            Rl10(cpu,mmu);
            break;
        case 0x11:
            Rl11(cpu,mmu);
            break;
        case 0x12:
            Rl12(cpu,mmu);
            break;
        case 0x13:
            Rl13(cpu,mmu);
            break;
        case 0x14:
            Rl14(cpu,mmu);
            break;
        case 0x15:
            Rl15(cpu,mmu);
            break;
        case 0x16:
            Rl16(cpu,mmu);
            break;
        case 0x17:
            Rl17(cpu,mmu);
            break;
        case 0x18:
            Rr18(cpu,mmu);
            break;
        case 0x19:
            Rr19(cpu,mmu);
            break;
        case 0x1a:
            Rr1A(cpu,mmu);
            break;
        case 0x1b:
            Rr1B(cpu,mmu);
            break;
        case 0x1c:
            Rr1C(cpu,mmu);
            break;
        case 0x1d:
            Rr1D(cpu,mmu);
            break;
        case 0x1e:
            Rr1E(cpu,mmu);
            break;
        case 0x1f:
            Rr1F(cpu,mmu);
            break;
        case 0x20:
            Sla20(cpu,mmu);
            break;
        case 0x21:
            Sla21(cpu,mmu);
            break;
        case 0x22:
            Sla22(cpu,mmu);
            break;
        case 0x23:
            Sla23(cpu,mmu);
            break;
        case 0x24:
            Sla24(cpu,mmu);
            break;
        case 0x25:
            Sla25(cpu,mmu);
            break;
        case 0x26:
            Sla26(cpu,mmu);
            break;
        case 0x27:
            Sla27(cpu,mmu);
            break;
        case 0x28:
            Sra28(cpu,mmu);
            break;
        case 0x29:
            Sra29(cpu,mmu);
            break;
        case 0x2a:
            Sra2A(cpu,mmu);
            break;
        case 0x2b:
            Sra2B(cpu,mmu);
            break;
        case 0x2c:
            Sra2C(cpu,mmu);
            break;
        case 0x2d:
            Sra2D(cpu,mmu);
            break;
        case 0x2e:
            Sra2E(cpu,mmu);
            break;
        case 0x2f:
            Sra2F(cpu,mmu);
            break;
        case 0x30:
            Swap30(cpu,mmu);
            break;
        case 0x31:
            Swap31(cpu,mmu);
            break;
        case 0x32:
            Swap32(cpu,mmu);
            break;
        case 0x33:
            Swap33(cpu,mmu);
            break;
        case 0x34:
            Swap34(cpu,mmu);
            break;
        case 0x35:
            Swap35(cpu,mmu);
            break;
        case 0x36:
            Swap36(cpu,mmu);
            break;
        case 0x37:
            Swap37(cpu,mmu);
            break;
        case 0x38:
            Srl38(cpu,mmu);
            break;
        case 0x39:
            Srl39(cpu,mmu);
            break;
        case 0x3a:
            Srl3A(cpu,mmu);
            break;
        case 0x3b:
            Srl3B(cpu,mmu);
            break;
        case 0x3c:
            Srl3C(cpu,mmu);
            break;
        case 0x3d:
            Srl3D(cpu,mmu);
            break;
        case 0x3e:
            Srl3E(cpu,mmu);
            break;
        case 0x3f:
            Srl3F(cpu,mmu);
            break;
        case 0x40:
            Bit40(cpu,mmu);
            break;
        case 0x41:
            Bit41(cpu,mmu);
            break;
        case 0x42:
            Bit42(cpu,mmu);
            break;
        case 0x43:
            Bit43(cpu,mmu);
            break;
        case 0x44:
            Bit44(cpu,mmu);
            break;
        case 0x45:
            Bit45(cpu,mmu);
            break;
        case 0x46:
            Bit46(cpu,mmu);
            break;
        case 0x47:
            Bit47(cpu,mmu);
            break;
        case 0x48:
            Bit48(cpu,mmu);
            break;
        case 0x49:
            Bit49(cpu,mmu);
            break;
        case 0x4a:
            Bit4A(cpu,mmu);
            break;
        case 0x4b:
            Bit4B(cpu,mmu);
            break;
        case 0x4c:
            Bit4C(cpu,mmu);
            break;
        case 0x4d:
            Bit4D(cpu,mmu);
            break;
        case 0x4e:
            Bit4E(cpu,mmu);
            break;
        case 0x4f:
            Bit4F(cpu,mmu);
            break;
        case 0x50:
            Bit50(cpu,mmu);
            break;
        case 0x51:
            Bit51(cpu,mmu);
            break;
        case 0x52:
            Bit52(cpu,mmu);
            break;
        case 0x53:
            Bit53(cpu,mmu);
            break;
        case 0x54:
            Bit54(cpu,mmu);
            break;
        case 0x55:
            Bit55(cpu,mmu);
            break;
        case 0x56:
            Bit56(cpu,mmu);
            break;
        case 0x57:
            Bit57(cpu,mmu);
            break;
        case 0x58:
            Bit58(cpu,mmu);
            break;
        case 0x59:
            Bit59(cpu,mmu);
            break;
        case 0x5a:
            Bit5A(cpu,mmu);
            break;
        case 0x5b:
            Bit5B(cpu,mmu);
            break;
        case 0x5c:
            Bit5C(cpu,mmu);
            break;
        case 0x5d:
            Bit5D(cpu,mmu);
            break;
        case 0x5e:
            Bit5E(cpu,mmu);
            break;
        case 0x5f:
            Bit5F(cpu,mmu);
            break;
        case 0x60:
            Bit60(cpu,mmu);
            break;
        case 0x61:
            Bit61(cpu,mmu);
            break;
        case 0x62:
            Bit62(cpu,mmu);
            break;
        case 0x63:
            Bit63(cpu,mmu);
            break;
        case 0x64:
            Bit64(cpu,mmu);
            break;
        case 0x65:
            Bit65(cpu,mmu);
            break;
        case 0x66:
            Bit66(cpu,mmu);
            break;
        case 0x67:
            Bit67(cpu,mmu);
            break;
        case 0x68:
            Bit68(cpu,mmu);
            break;
        case 0x69:
            Bit69(cpu,mmu);
            break;
        case 0x6a:
            Bit6A(cpu,mmu);
            break;
        case 0x6b:
            Bit6B(cpu,mmu);
            break;
        case 0x6c:
            Bit6C(cpu,mmu);
            break;
        case 0x6d:
            Bit6D(cpu,mmu);
            break;
        case 0x6e:
            Bit6E(cpu,mmu);
            break;
        case 0x6f:
            Bit6F(cpu,mmu);
            break;
        case 0x70:
            Bit70(cpu,mmu);
            break;
        case 0x71:
            Bit71(cpu,mmu);
            break;
        case 0x72:
            Bit72(cpu,mmu);
            break;
        case 0x73:
            Bit73(cpu,mmu);
            break;
        case 0x74:
            Bit74(cpu,mmu);
            break;
        case 0x75:
            Bit75(cpu,mmu);
            break;
        case 0x76:
            Bit76(cpu,mmu);
            break;
        case 0x77:
            Bit77(cpu,mmu);
            break;
        case 0x78:
            Bit78(cpu,mmu);
            break;
        case 0x79:
            Bit79(cpu,mmu);
            break;
        case 0x7a:
            Bit7A(cpu,mmu);
            break;
        case 0x7b:
            Bit7B(cpu,mmu);
            break;
        case 0x7c:
            Bit7C(cpu,mmu);
            break;
        case 0x7d:
            Bit7D(cpu,mmu);
            break;
        case 0x7e:
            Bit7E(cpu,mmu);
            break;
        case 0x7f:
            Bit7F(cpu,mmu);
            break;
        case 0x80:
            Res80(cpu,mmu);
            break;
        case 0x81:
            Res81(cpu,mmu);
            break;
        case 0x82:
            Res82(cpu,mmu);
            break;
        case 0x83:
            Res83(cpu,mmu);
            break;
        case 0x84:
            Res84(cpu,mmu);
            break;
        case 0x85:
            Res85(cpu,mmu);
            break;
        case 0x86:
            Res86(cpu,mmu);
            break;
        case 0x87:
            Res87(cpu,mmu);
            break;
        case 0x88:
            Res88(cpu,mmu);
            break;
        case 0x89:
            Res89(cpu,mmu);
            break;
        case 0x8a:
            Res8A(cpu,mmu);
            break;
        case 0x8b:
            Res8B(cpu,mmu);
            break;
        case 0x8c:
            Res8C(cpu,mmu);
            break;
        case 0x8d:
            Res8D(cpu,mmu);
            break;
        case 0x8e:
            Res8E(cpu,mmu);
            break;
        case 0x8f:
            Res8F(cpu,mmu);
            break;
        case 0x90:
            Res90(cpu,mmu);
            break;
        case 0x91:
            Res91(cpu,mmu);
            break;
        case 0x92:
            Res92(cpu,mmu);
            break;
        case 0x93:
            Res93(cpu,mmu);
            break;
        case 0x94:
            Res94(cpu,mmu);
            break;
        case 0x95:
            Res95(cpu,mmu);
            break;
        case 0x96:
            Res96(cpu,mmu);
            break;
        case 0x97:
            Res97(cpu,mmu);
            break;
        case 0x98:
            Res98(cpu,mmu);
            break;
        case 0x99:
            Res99(cpu,mmu);
            break;
        case 0x9a:
            Res9A(cpu,mmu);
            break;
        case 0x9b:
            Res9B(cpu,mmu);
            break;
        case 0x9c:
            Res9C(cpu,mmu);
            break;
        case 0x9d:
            Res9D(cpu,mmu);
            break;
        case 0x9e:
            Res9E(cpu,mmu);
            break;
        case 0x9f:
            Res9F(cpu,mmu);
            break;
        case 0xa0:
            ResA0(cpu,mmu);
            break;
        case 0xa1:
            ResA1(cpu,mmu);
            break;
        case 0xa2:
            ResA2(cpu,mmu);
            break;
        case 0xa3:
            ResA3(cpu,mmu);
            break;
        case 0xa4:
            ResA4(cpu,mmu);
            break;
        case 0xa5:
            ResA5(cpu,mmu);
            break;
        case 0xa6:
            ResA6(cpu,mmu);
            break;
        case 0xa7:
            ResA7(cpu,mmu);
            break;
        case 0xa8:
            ResA8(cpu,mmu);
            break;
        case 0xa9:
            ResA9(cpu,mmu);
            break;
        case 0xaa:
            ResAA(cpu,mmu);
            break;
        case 0xab:
            ResAB(cpu,mmu);
            break;
        case 0xac:
            ResAC(cpu,mmu);
            break;
        case 0xad:
            ResAD(cpu,mmu);
            break;
        case 0xae:
            ResAE(cpu,mmu);
            break;
        case 0xaf:
            ResAF(cpu,mmu);
            break;
        case 0xb0:
            ResB0(cpu,mmu);
            break;
        case 0xb1:
            ResB1(cpu,mmu);
            break;
        case 0xb2:
            ResB2(cpu,mmu);
            break;
        case 0xb3:
            ResB3(cpu,mmu);
            break;
        case 0xb4:
            ResB4(cpu,mmu);
            break;
        case 0xb5:
            ResB5(cpu,mmu);
            break;
        case 0xb6:
            ResB6(cpu,mmu);
            break;
        case 0xb7:
            ResB7(cpu,mmu);
            break;
        case 0xb8:
            ResB8(cpu,mmu);
            break;
        case 0xb9:
            ResB9(cpu,mmu);
            break;
        case 0xba:
            ResBA(cpu,mmu);
            break;
        case 0xbb:
            ResBB(cpu,mmu);
            break;
        case 0xbc:
            ResBC(cpu,mmu);
            break;
        case 0xbd:
            ResBD(cpu,mmu);
            break;
        case 0xbe:
            ResBE(cpu,mmu);
            break;
        case 0xbf:
            ResBF(cpu,mmu);
            break;
        case 0xc0:
            SetC0(cpu,mmu);
            break;
        case 0xc1:
            SetC1(cpu,mmu);
            break;
        case 0xc2:
            SetC2(cpu,mmu);
            break;
        case 0xc3:
            SetC3(cpu,mmu);
            break;
        case 0xc4:
            SetC4(cpu,mmu);
            break;
        case 0xc5:
            SetC5(cpu,mmu);
            break;
        case 0xc6:
            SetC6(cpu,mmu);
            break;
        case 0xc7:
            SetC7(cpu,mmu);
            break;
        case 0xc8:
            SetC8(cpu,mmu);
            break;
        case 0xc9:
            SetC9(cpu,mmu);
            break;
        case 0xca:
            SetCA(cpu,mmu);
            break;
        case 0xcb:
            SetCB(cpu,mmu);
            break;
        case 0xcc:
            SetCC(cpu,mmu);
            break;
        case 0xcd:
            SetCD(cpu,mmu);
            break;
        case 0xce:
            SetCE(cpu,mmu);
            break;
        case 0xcf:
            SetCF(cpu,mmu);
            break;
        case 0xd0:
            SetD0(cpu,mmu);
            break;
        case 0xd1:
            SetD1(cpu,mmu);
            break;
        case 0xd2:
            SetD2(cpu,mmu);
            break;
        case 0xd3:
            SetD3(cpu,mmu);
            break;
        case 0xd4:
            SetD4(cpu,mmu);
            break;
        case 0xd5:
            SetD5(cpu,mmu);
            break;
        case 0xd6:
            SetD6(cpu,mmu);
            break;
        case 0xd7:
            SetD7(cpu,mmu);
            break;
        case 0xd8:
            SetD8(cpu,mmu);
            break;
        case 0xd9:
            SetD9(cpu,mmu);
            break;
        case 0xda:
            SetDA(cpu,mmu);
            break;
        case 0xdb:
            SetDB(cpu,mmu);
            break;
        case 0xdc:
            SetDC(cpu,mmu);
            break;
        case 0xdd:
            SetDD(cpu,mmu);
            break;
        case 0xde:
            SetDE(cpu,mmu);
            break;
        case 0xdf:
            SetDF(cpu,mmu);
            break;
        case 0xe0:
            SetE0(cpu,mmu);
            break;
        case 0xe1:
            SetE1(cpu,mmu);
            break;
        case 0xe2:
            SetE2(cpu,mmu);
            break;
        case 0xe3:
            SetE3(cpu,mmu);
            break;
        case 0xe4:
            SetE4(cpu,mmu);
            break;
        case 0xe5:
            SetE5(cpu,mmu);
            break;
        case 0xe6:
            SetE6(cpu,mmu);
            break;
        case 0xe7:
            SetE7(cpu,mmu);
            break;
        case 0xe8:
            SetE8(cpu,mmu);
            break;
        case 0xe9:
            SetE9(cpu,mmu);
            break;
        case 0xea:
            SetEA(cpu,mmu);
            break;
        case 0xeb:
            SetEB(cpu,mmu);
            break;
        case 0xec:
            SetEC(cpu,mmu);
            break;
        case 0xed:
            SetED(cpu,mmu);
            break;
        case 0xee:
            SetEE(cpu,mmu);
            break;
        case 0xef:
            SetEF(cpu,mmu);
            break;
        case 0xf0:
            SetF0(cpu,mmu);
            break;
        case 0xf1:
            SetF1(cpu,mmu);
            break;
        case 0xf2:
            SetF2(cpu,mmu);
            break;
        case 0xf3:
            SetF3(cpu,mmu);
            break;
        case 0xf4:
            SetF4(cpu,mmu);
            break;
        case 0xf5:
            SetF5(cpu,mmu);
            break;
        case 0xf6:
            SetF6(cpu,mmu);
            break;
        case 0xf7:
            SetF7(cpu,mmu);
            break;
        case 0xf8:
            SetF8(cpu,mmu);
            break;
        case 0xf9:
            SetF9(cpu,mmu);
            break;
        case 0xfa:
            SetFA(cpu,mmu);
            break;
        case 0xfb:
            SetFB(cpu,mmu);
            break;
        case 0xfc:
            SetFC(cpu,mmu);
            break;
        case 0xfd:
            SetFD(cpu,mmu);
            break;
        case 0xfe:
            SetFE(cpu,mmu);
            break;
        case 0xff:
            SetFF(cpu,mmu);
            break;
        }
}

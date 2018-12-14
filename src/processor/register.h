#include "stdafx.h"

namespace reg
{
    struct status
    {
        // Constructor
        status() : C(0), Z(0), I(0), D(0), X(0), M(0), V(0), N(0) {}

        auto operator =(uint_8& data)
        {
            C = data.bit<0>();
            Z = data.bit<1>();
            I = data.bit<2>();
            D = data.bit<3>();
            X = data.bit<4>();
            M = data.bit<5>();
            V = data.bit<6>();
            N = data.bit<7>();
        }

        // Data
        // Carry status, 1 == carry
        // This can also set the emulation mode e, which determines either native or 6502 (8-bit) emulation
        // 1 == native mode
        // We regard this e bit as a "phantom" bit which cannot be directly tested, set or cleared.
        // It overlays the carry bit, and there is a special instruction XCE that exchanges the contents of the two flags.
        // This allows the trapdoor through which emulation mode is entered and exited.
        bool C;
        // Zero status, 1 == result 0
        bool Z;
        // IRQ Enabled/Disabled, 1 = disabled
        bool I;
        // Decimal mode, 1 == decimal, 0 == binary
        bool D;

        // If both X and M are set, 8-bit register architecture of the 6502 is in force.
        // While similar to emulation mode, some differences are highlighted:
        //      - BRK vector is available in native mode (interrupt processing is different between emulation and native)
        //      - 16 bit processing can be called up with a single instruction
        // To switch between 8-bit and 16-bit modes, use the following instructions:
        //      - SEP (set P), can be used to set any bit(s) in the P status register
        //      - REP (reset P), can be used to reset any bit(s) in the P status register
        // Index Register Select mode
        // Indicates the size of X Y registers
        // If X == 1, index registers are in 8-bit mode
        // If X == 0, index registers are in 16-bit mode
        bool X;

        // Memory/Accumulator Select mode
        // This also indicates the size and memory accesses
        // If M == 1, Accumulator is 8-bit mode
        // If M == 0, Accumulator is 16-bit mode
        // When switching from 16-bit to 8-bit, the low byte becomes the 8-bit A accumulator.
        // The high byte becomes the 8-bit "hidden" B accumulator.
        // B can be seen as an annex to A, which is accessible only through a new instruction that exchanges the contents of A and B. B can be seen as temporary storage for A.
        // When switching from 8-bits to 16-bits, 8-bit A becomes the low byte and 8-bit B becomes the high byte.
        // Some instructions can transfer the acccumulator to or from other 16-bit registers refer to the 16-bit accumulator as C.
        // This is to emphasize that all 16-bit accumulator bits will be referenced regardless of whether the accumulator is set to 8-bit or 16-bit mode.
        bool M;

        // Overflow status, 1 == overflow
        bool V;
        // Negative status, 1 == negative
        bool N;
    };

    // See Pg46
    struct proc_65c816_reg
    {
        proc_65c816_reg() : A_(0), X_(0), Y_(0), S_(0), DB_(0), DP_(0), PB_(0), P_(), PC_(0) {}

        // https://en.wikipedia.org/wiki/WDC_65816/65802
        // Accumulator
        // Tied to the M flag in the status register
        // Primary user register, generally holds one of the operands as well as the result (of any basic data-manipulation instruction)
        // We can either use the low 8 bits or high 8 bits, or all 16 bits, depending on which mode we're running (native or 6502 emulation).
        // Emua
        uint16_t A_;

        // Index Registers
        // Tied to the X flag in the status register
        uint16_t X_;
        uint16_t Y_;

        // Stack Pointer
        // Can float anywhere in bank 0
        // Real layout is 0 0 0 0 0 0 0 0 (S 16 bits) => 24 bit address with default high 8 bits as 0
        uint16_t S_;

        // Direct Page (D)
        // Real layout is 0 0 0 0 0 0 0 0 (DP 16 bits) => 24 bit address with default high 8 bits as 0
        // Thus limited to bank 0
        // Used to set any 256 byte page starting on any byte boundary within bank 0
        // If direct page register is set to 0, direct page memory is the zero page and direct page addressing is operationally identical to 0 page addressing.
        // One effect of having a direct page register is that you can set up and alternate between multiple direct page areas, giving each subroutine or task 
        // its own private direct page of memory.
        // Rememebr when using this to direct page into memory, it's contents of DP + operand together.
        uint16_t DP_;

        //-----------------------------------------------------------------------------------------
        // We use the following 2 registers for 24-bit addressing
        // A bank of memory is much like a page. A bank is a range of memory that can be defined by 16 bits.
        // The 65816 partitions its memory range into 64k banks. The data bank indexs into which bank of 64k memory we are accessing.
        //-----------------------------------------------------------------------------------------

        // Data Bank (DBR / B)
        // Defines the default bank to be used for reading / writing when the addressing mode specifies only the 16 bit address to be used.
        // For example, absolute, indirect or index instructions. The DB 8 bits are concatenated to the 16-bit to form a 24-bit address.
        // Unlike the program bank, the data bank can be temporarily incremented by instructions. Bank boundaries do not confine indexing.
        // Direct page (DP) and stack (S) based values are always accessed in bank 0, however indirect addressed pulled out of the direct page / stack
        // (when used with addressing modes that do not specify bank value) point to locations in the current data bank.
        uint8_t DB_;

        // Program Bank (PBR / K)
        // PC is concatenated to the PB, to allow 24-bit addressing.
        // In many ways, net effect is a 24 bit PC. If an interrupt happens, both PC and PB are pushed, and conversely, we pop both 16 bit and 8 bit registers.
        // You can't branch across bank boundaries. Program segments can't cross bank boundaries.
        // If a PC increments past 0xFFFF, it rolls back to 0x0000 without incrementing the program counter bank.
        // Example instructions that transfer control between banks:
        //      - jump absolute long (jump to specified 24-bit address)
        //      - jump indirect long (operand is an absolute address in bank 0 pointing to a 24-bit address)
        //      - jump to subroutine long (to a specified 24-bit address, with current PC and PB pushed to stack first)
        // The program bank register can only be changed when the program counter is changed to avoid changing only the bank.
        uint8_t PB_;

        // Processor Status
        status P_;

        // Program Counter
        uint16_t PC_;
    };
}
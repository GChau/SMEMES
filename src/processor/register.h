#include "../utils/utils.h"
#include "dll_export.h"

namespace reg 
{
    struct status
    {
        // Constructor
        status() : C(0), Z(0), I(1), D(0), X(1), M(1), V(0), N(0) {}
        auto operator =(uint8& data)
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
        // Carry status
        bool C;
        // Zero status
        bool Z;
        // IRQ Enabled/Disabled
        bool I;
        // Decimal mode
        bool D;
        // Index mode
        bool X;
        // Memory/Accumulator mode
        bool M;
        // Overflow status
        bool V;
        // Negative status
        bool N;
    };

    struct internal_reg
    {
        internal_reg() : A_(0), X_(0), S_(0), DRB_(0), D_(0), PB_(0), P_(), PC_(0) {}

        // Accumulator
        uint8_t A_;
        // Index
        uint8_t X_;
        // Stack Pointer
        uint8_t S_;
        // Databank
        uint8_t DRB_;
        // Direct Page
        uint8_t D_;
        // Program Bank
        uint8_t PB_;
        // Processor Status
        status P_;
        // Program Counter
        uint8_t PC_;
    };
}
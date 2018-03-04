#include "../utils/utils.h"
#include "dll_export.h"


namespace processor {

    struct status {
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

        auto operator =(uint8 data)
        {
            C = data.bit(0);
            Z = data.bit(1);
            I = data.bit(2);
            D = data.bit(3);
            X = data.bit(4);
            M = data.bit(5);
            V = data.bit(6);
            N = data.bit(7);
        }
        // Initial status
        status() { C = 0; Z = 0; I = 1; D = 0; X = 1; M = 1; V = 0; N = 0; }
    };

    struct internal_registers {
        // Accumulator
        char A_;

        // Index
        char X_;

        // Stack Pointer
        char S_;

        // Databank
        char DRB_;

        // Direct Page
        char D_;

        // Program Bank
        char PB_;

        // Processor Status
        status P_;

        // Program Counter
        char PC_;
    };

     PROCESSORExport void test();
};
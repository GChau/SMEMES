#include "dll_export.h"

namespace processor {
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
        char P_;

        // Program Counter
        char PC_;
    };

    struct status {
        // Carry status
        char C;

        // Zero status
        char Z;

        // IRQ Enabled/Disabled
        char I;

        // Decimal mode
        char D;

        // Index mode
        char X;

        // Memory/Accumulator mode
        char M;

        // Overflow status
        char V;

        // Negative status
        char N;

        // Initial status
        status() { C = 0; Z = 0; I = 1; D = 0; X = 1; M = 1; V = 0; N = 0; }
    };

     PROCESSORExport void test();
};
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

     PROCESSORExport void test();
};
#include "dll_export.h"

#include "register.h"

namespace processor
{
    class proc_65816
    {
        proc_65816() :
            reg_()
        {
        }

        // Data
        reg::internal_reg reg_;
    };

    PROCESSORExport void test();
};
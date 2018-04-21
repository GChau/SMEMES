#include "stdafx.h"

#include "proc_65c816.h"

namespace processor {
    namespace imp
    {
        template<typename Processor, typename AddressMode>
        uint16_t add_with_carry(Processor* proc, AddressMode& am, const uint16_t value, uint32_t& cycles) {
            proc->get_reg()->A_ += am.resolve(value);
            return 1;
        }
    }
}
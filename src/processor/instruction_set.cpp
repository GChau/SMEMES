#include "instruction_set.h"

namespace processor {

    uint16_t proc_65c816::add_with_carry(const address_mode_e& address_mode, const uint16_t value, uint32_t& cycles) {
        switch (address_mode) {
        case address_mode_e::immediate: 
            imp::add_with_carry(this, am_immediate_, value, cycles);
            break;
        case address_mode_e::absolute_addressing_ct:
            imp::add_with_carry(this, am_absolute_addressing_ct_, value, cycles);
            break;
        case address_mode_e::absolute_addressing_dt:
            imp::add_with_carry(this, am_absolute_addressing_dt_, value, cycles);
            break;
        default:
            // Insert error here
            break;
        }
        return 0;
    }

}
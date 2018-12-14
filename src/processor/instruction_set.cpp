#include "instruction_set.h"

namespace processor {

    uint32_t proc_65c816::add_with_carry(const address_mode_e& address_mode, const uint16_t operand) {

        uint32_t cycles = 0;

        switch (address_mode) {
        case address_mode_e::immediate: 
            imp::add_with_carry<immediate_addressing_t>(this, operand);
            cycles = 2 + (get_reg()->P_.M ? 0 : 1);
            break;
        case address_mode_e::absolute_addressing_ct:
            imp::add_with_carry<absolute_addressing_ct_t>(this, operand);
            cycles = 4 + (get_reg()->P_.M ? 0 : 1);
            break;
        case address_mode_e::absolute_addressing_dt:
            imp::add_with_carry<absolute_addressing_dt_t>(this, operand);
            cycles = 4 + (get_reg()->P_.M ? 0 : 1);
            break;
        default:
            // Insert error here
            break;
        }
        return cycles;
    }

}
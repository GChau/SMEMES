#include "stdafx.h"

#include "register.h"
#include "address_mode.h"

namespace processor
{
    // https://en.wikipedia.org/wiki/WDC_65816/65802
    // https://wiki.superfamicom.org/65816-reference
    class PROCESSORExport proc_65c816
    {
    public:
        // Constructor etc.
        proc_65c816();

    public:
        std::shared_ptr<reg::proc_65c816_reg> get_reg();
        std::shared_ptr<std::vector<uint16_t>> get_mem();

    public:
        // Instructions
        // ADC
        uint32_t add_with_carry(const address_mode_e& address_mode, const uint16_t value);


    private:
        // Data
        std::shared_ptr<reg::proc_65c816_reg> reg_;
        std::shared_ptr<std::vector<uint16_t>> mem_;

    public:
        using reg_t = decltype(reg_);
        using mem_t = decltype(mem_);
        using immediate_addressing_t = immediate<reg_t, mem_t, uint16_t>;
        using absolute_addressing_ct_t = absolute_addressing<reg_t, mem_t, uint16_t, transfer_type_e, transfer_type_e::control_transfer>;
        using absolute_addressing_dt_t = absolute_addressing<reg_t, mem_t, uint16_t, transfer_type_e, transfer_type_e::data_transfer>;

    }; // proc_65c816
}; // processor
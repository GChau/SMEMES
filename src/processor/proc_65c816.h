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
        /*
        // Helper
        template<typename address_mode>
        uint16_t resolve(const uint16_t value);
        */
        // Instructions
        // ADC
        uint16_t add_with_carry(const address_mode_e& address_mode, const uint16_t value, uint32_t& cycles);

    private:
        // Data
        std::shared_ptr<reg::proc_65c816_reg> reg_;
        std::shared_ptr<std::vector<uint16_t>> mem_;

    public:
        // Memory accessors
        immediate<reg::proc_65c816_reg, uint16_t> am_immediate_;
        absolute_addressing<reg::proc_65c816_reg, uint16_t, transfer_type_e, transfer_type_e::control_transfer> am_absolute_addressing_ct_;
        absolute_addressing<reg::proc_65c816_reg, uint16_t, transfer_type_e, transfer_type_e::data_transfer> am_absolute_addressing_dt_;

    }; // proc_65c816
}; // processor
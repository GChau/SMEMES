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
        /*
        // Helper
        template<typename address_mode>
        uint16_t resolve(const uint16_t value);
        */
        // Instructions
        // ADC
        template<typename address_mode>
        uint16_t add_with_carry(const uint16_t value, uint32_t& cycles);

    private:
        // Data
        std::shared_ptr<reg::proc_65c816_reg> reg_;
        std::shared_ptr<std::vector<uint16_t>> mem_;

    private:
        // Memory accessors
        dp_indexed_indirect<reg::proc_65c816_reg, uint16_t> dp_indexed_indirect_;

    }; // proc_65c816
}; // processor
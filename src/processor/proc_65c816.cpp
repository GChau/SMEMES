#include "proc_65c816.h"

using namespace processor;

proc_65c816::proc_65c816() :
    reg_(std::make_shared<reg::proc_65c816_reg>()),
    mem_(std::make_shared<std::vector<uint16_t>>(1024))
{
}

template<typename address_mode>
uint16_t proc_65c816::add_with_carry(const uint16_t value, uint32_t& cycles)
{
    reg_.A_ += reg_.X_ + address_mode(reg_, mem_).resolve(value);
    return 6;
}
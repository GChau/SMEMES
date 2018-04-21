#include "proc_65c816.h"

using namespace processor;

proc_65c816::proc_65c816() :
    reg_(std::make_shared<reg::proc_65c816_reg>()),
    mem_(std::make_shared<std::vector<uint16_t>>(1024)),
    am_immediate_(reg_, mem_),
    am_absolute_addressing_ct_(reg_, mem_),
    am_absolute_addressing_dt_(reg_, mem_)
{
}

std::shared_ptr<reg::proc_65c816_reg> proc_65c816::get_reg() {
    return reg_;
}

std::shared_ptr<std::vector<uint16_t>> proc_65c816::get_mem() {
    return mem_;
}
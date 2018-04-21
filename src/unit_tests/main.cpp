#include "stdafx.h"

#include "proc_65c816.h"

// Not really a unit test but good to mess around in
int main (int argc, char *argv[]) {
    std::cout << "--- UNIT TEST ---" << std::endl;

    auto proc = std::make_unique<processor::proc_65c816>();

    uint32_t cycles = 0;
    //auto ret_1 = proc->add_with_carry(processor::address_mode_e::immediate, (uint16_t)1, cycles);

    return 0;
}
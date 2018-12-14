#include "stdafx.h"
#include "proc_65c816.h"

TEST_CASE("My First Test Case", "[processor]") {
    auto proc = std::make_unique<processor::proc_65c816>();

    REQUIRE(proc != nullptr);

    SECTION("address mode returns the correct number of cycles") {
        REQUIRE(proc->add_with_carry(processor::address_mode_e::immediate, (uint16_t)1) == 3);
        REQUIRE(proc->add_with_carry(processor::address_mode_e::absolute_addressing_ct, (uint16_t)1) == 5);
        REQUIRE(proc->add_with_carry(processor::address_mode_e::absolute_addressing_dt, (uint16_t)1) == 5);
    }

    SECTION("computes the correct value") {

        const auto& registers = proc->get_reg();

        // Check that accumulation register is 0
        REQUIRE(registers->A_ == 0);

        SECTION("computes the correct value") {
            proc->add_with_carry(processor::address_mode_e::immediate, (uint16_t)15);
            // Check that accumulation register is 15
            REQUIRE(registers->A_ == 15);
        }
      //  REQUIRE(proc->add_with_carry(processor::address_mode_e::absolute_addressing_ct, (uint16_t)1) == 4);
       // REQUIRE(proc->add_with_carry(processor::address_mode_e::absolute_addressing_dt, (uint16_t)1) == 4);
    }
}
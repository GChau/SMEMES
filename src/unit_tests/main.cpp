#include "stdafx.h"

#include "proc_65c816.h"

// Not really a unit test but good to mess around in
int main (int argc, char *argv[]) {
    std::cout << "--- UNIT TEST ---" << std::endl;

    auto proc = std::make_unique<processor::proc_65c816>();

    uint8 a = 0;
    uint8_t b = 10;
    uint8 c;
    uint8 d = 11;
    c = a + b;
    a = b + c;
    c = c + d;
    a = a + 5;
    a += 10;
    a += c;

    printf("%d %d ", c, a);
    if (a == b)
    {
        printf("Ok\n");
    }
    else if (b == a)
    {
        printf("woah\n");
    }
    int ddd;
    std::cin >> ddd;

    uint32_t cycles = 0;
    //proc->add_with_carry<processor::address_mode::dp_indexed_indirect>(1, cycles);

    return 0;
}
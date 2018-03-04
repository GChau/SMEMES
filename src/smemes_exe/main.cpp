#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "smemes_config.h"
#include "processor.h"

int main (int argc, char *argv[]) {
    std::cout << "Version Number: " << SMEMES_VERSION_MAJOR << "." << SMEMES_VERSION_MINOR << std::endl;

    processor::test();

    return 0;
}
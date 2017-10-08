// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SMEMESConfig.h"
#include <iostream>

int main (int argc, char *argv[])
{
    if (argc < 2) {
      fprintf(stdout,"Usage: %s, Version: %d.%d\n",argv[0], SMEMES_VERSION_MAJOR, SMEMES_VERSION_MINOR);
      return 1;
    }
    return 0;
}
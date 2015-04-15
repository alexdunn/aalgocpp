#include "gtest/gtest.h"

void *p;

int main (int argc, char *argv[])
{
    p = malloc(7);
    p = 0; // The memory is leaked here.

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


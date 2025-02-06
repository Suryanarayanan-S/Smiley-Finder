#include <iostream>

#include <gtest/gtest.h>

int
main(int argc, char** argv)
{
    std::cout << "Started running unit test..." << std::endl;
    testing::InitGoogleTest(&argc, argv);  // GoogleTest init

    return RUN_ALL_TESTS();
}

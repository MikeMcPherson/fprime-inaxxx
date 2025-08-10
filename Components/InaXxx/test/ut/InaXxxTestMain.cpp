// ======================================================================
// \title  InaXxxTestMain.cpp
// \author kq9p
// \brief  cpp file for InaXxx component test main function
// ======================================================================

#include "InaXxxTester.hpp"

TEST(Nominal, toDo) {
    InaXxx::InaXxxTester tester;
    tester.toDo();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

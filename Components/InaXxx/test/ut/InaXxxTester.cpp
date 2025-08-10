// ======================================================================
// \title  InaXxxTester.cpp
// \author kq9p
// \brief  cpp file for InaXxx component test harness implementation class
// ======================================================================

#include "InaXxxTester.hpp"

namespace InaXxx {

// ----------------------------------------------------------------------
// Construction and destruction
// ----------------------------------------------------------------------

InaXxxTester ::InaXxxTester() : InaXxxGTestBase("InaXxxTester", InaXxxTester::MAX_HISTORY_SIZE), component("InaXxx") {
    this->initComponents();
    this->connectPorts();
}

InaXxxTester ::~InaXxxTester() {}

// ----------------------------------------------------------------------
// Tests
// ----------------------------------------------------------------------

void InaXxxTester ::toDo() {
    // TODO
}

}  // namespace InaXxx

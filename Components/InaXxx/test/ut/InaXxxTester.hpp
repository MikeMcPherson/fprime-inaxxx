// ======================================================================
// \title  InaXxxTester.hpp
// \author kq9p
// \brief  hpp file for InaXxx component test harness implementation class
// ======================================================================

#ifndef InaXxx_InaXxxTester_HPP
#define InaXxx_InaXxxTester_HPP

#include "Components/InaXxx/InaXxx.hpp"
#include "Components/InaXxx/InaXxxGTestBase.hpp"

namespace InaXxx {

class InaXxxTester final : public InaXxxGTestBase {
  public:
    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    // Maximum size of histories storing events, telemetry, and port outputs
    static const FwSizeType MAX_HISTORY_SIZE = 10;

    // Instance ID supplied to the component instance under test
    static const FwEnumStoreType TEST_INSTANCE_ID = 0;

    // Queue depth supplied to the component instance under test
    static const FwSizeType TEST_INSTANCE_QUEUE_DEPTH = 10;

  public:
    // ----------------------------------------------------------------------
    // Construction and destruction
    // ----------------------------------------------------------------------

    //! Construct object InaXxxTester
    InaXxxTester();

    //! Destroy object InaXxxTester
    ~InaXxxTester();

  public:
    // ----------------------------------------------------------------------
    // Tests
    // ----------------------------------------------------------------------

    //! To do
    void toDo();

  private:
    // ----------------------------------------------------------------------
    // Helper functions
    // ----------------------------------------------------------------------

    //! Connect ports
    void connectPorts();

    //! Initialize components
    void initComponents();

  private:
    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The component under test
    InaXxx component;
};

}  // namespace InaXxx

#endif

// ======================================================================
// \title  InaXxx.cpp
// \author kq9p
// \brief  cpp file for InaXxx component implementation class
// ======================================================================

#include "Components/InaXxx/InaXxx.hpp"
#include "Drv/LinuxI2cDriver/LinuxI2cDriver.hpp"

namespace InaXxx {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  InaXxx ::
    InaXxx(const char* const compName) :
      InaXxxComponentBase(compName)
  {
    
  }

  InaXxx ::
    ~InaXxx()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for typed input ports
  // ----------------------------------------------------------------------

  void InaXxx ::
    run_handler(
        FwIndexType portNum,
        U32 context
    )
  {
    // TODO
  }

}

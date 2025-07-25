// ======================================================================
// \title  InaXxx.hpp
// \author kq9p
// \brief  hpp file for InaXxx component implementation class
// ======================================================================

#ifndef InaXxx_InaXxx_HPP
#define InaXxx_InaXxx_HPP

#include "Components/InaXxx/InaXxxComponentAc.hpp"

namespace InaXxx {

  class InaXxx :
    public InaXxxComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct InaXxx object
      InaXxx(
          const char* const compName //!< The component name
      );

      //! Destroy InaXxx object
      ~InaXxx();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for run
      //!
      //! Port to receive calls from the rate group
      void run_handler(
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      ) override;

  };

}

#endif

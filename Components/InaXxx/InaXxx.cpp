// ======================================================================
// \title  InaXxx.cpp
// \author Mike McPherson
// \brief  cpp file for InaXxx component implementation class
// ======================================================================

#include "Components/InaXxx/InaXxx.hpp"

namespace InaXxx {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

InaXxx ::InaXxx(const char* const compName) : InaXxxComponentBase(compName) {}

InaXxx ::~InaXxx() {}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void InaXxx ::
    CONFIGURE_INAXXX_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        const Fw::CmdStringArg& device_name,
        U32 i2c_address,
        U8 range,
        U8 gain,
        U8 bus_resolution,
        U8 bus_samples,
        U8 shunt_resolution,
        U8 shunt_samples) 
    {
        // TODO
        this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
    }

void InaXxx ::
    READ_INAXXX_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        const Fw::CmdStringArg& device_name,
        U32 i2c_address) 
    {
        // this->writeRead_out(i2c_address, 0x40, m_i2cWriteBuffer[0], m_i2cReadBuffer[0]); // Example write/read operation
        // this->tlmWrite_voltage(12.5); // Example telemetry write operation
        this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
    }

}  // namespace InaXxx

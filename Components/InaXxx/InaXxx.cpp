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
        U16 device_id,
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
        U16 device_id,
        U32 i2c_address) 
    {
        this->writeRead_out(0, i2c_address, m_i2cWriteBuffer[0], m_i2cReadBuffer[0]); // Example write/read operation
        m_sample.set_device_id(device_id);
        m_sample.set_data(5);
        this->tlmWrite_inaxxx_sample(m_sample); // Example telemetry write operation
        this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
    }

}  // namespace InaXxx

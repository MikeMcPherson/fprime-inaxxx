// ======================================================================
// \title  InaXxx.hpp
// \author Mike McPherson
// \brief  hpp file for InaXxx component implementation class
// ======================================================================

#ifndef InaXxx_InaXxx_HPP
#define InaXxx_InaXxx_HPP

// ----------------------------------------------------------------------
// Defines for INA219 registers
// ----------------------------------------------------------------------
#define REGISTER_CONFIG          0x00           // Configuration register (R/W)
#define REGISTER_SHUNTVOLTAGE    0x01           // Shunt voltage register (R)
#define REGISTER_BUSVOLTAGE      0x02           // Bus voltage register (R)
#define REGISTER_POWER           0x03           // Power register (R)
#define REGISTER_CURRENT         0x04           // Current register (R)
#define REGISTER_CALIBRATION     0x05           // Calibration register (R/W)
#define RST                     (0x0001 << 15)  // Reset device
#define RANGE_16V               (0x0000 << 13)  // BRNG: Range 0-16 volts
#define RANGE_32V               (0x0001 << 13)  // BRNG: Range 0-32 volts (DEFAULT)
#define GAIN_1_40MV             (0x0000 << 11)  // PGx: Maximum shunt voltage 40mV
#define GAIN_2_80MV             (0x0001 << 11)  // PGx: Maximum shunt voltage 80mV
#define GAIN_4_160MV            (0x0002 << 11)  // PGx: Maximum shunt voltage 160mV
#define GAIN_8_320MV            (0x0003 << 11)  // PGx: Maximum shunt voltage 320mV (DEFAULT)
#define BUS_ADC_9BIT            (0x0000 << 7)   // BADC: 9-bit, 1 sample, conversion time  84us.
#define BUS_ADC_10BIT           (0x0001 << 7)   // BADC: 10-bit, 1 sample, conversion time 148us.
#define BUS_ADC_11BIT           (0x0002 << 7)   // BADC: 11-bit, 1 sample, conversion time 2766us.
#define BUS_ADC_12BIT           (0x0003 << 7)   // BADC: 12-bit, 1 sample, conversion time 532us. (DEFAULT)
#define BUS_ADC_1SAMPLE         (0x0008 << 7)   // BADC: 12-bit, 1 sample, conversion time 532us.
#define BUS_ADC_2SAMPLES        (0x0009 << 7)   // BADC: 12-bit, 2 samples, conversion time 1.06 ms
#define BUS_ADC_4SAMPLES        (0x000A << 7)   // BADC: 12-bit, 4 samples, conversion time 2.13 ms
#define BUS_ADC_8SAMPLES        (0x000B << 7)   // BADC: 12-bit, 8 samples, conversion time 4.26 ms
#define BUS_ADC_16SAMPLES       (0x000C << 7)   // BADC: 12-bit, 16 samples, conversion time 8.51 ms
#define BUS_ADC_32SAMPLES       (0x000D << 7)   // BADC: 12-bit, 32 samples, conversion time 17.02 ms
#define BUS_ADC_64SAMPLES       (0x000E << 7)   // BADC: 12-bit, 64 samples, conversion time 34.05 ms
#define BUS_ADC_128SAMPLES      (0x000F << 7)   // BADC: 12-bit, 128 samples, conversion time 68.10 ms
#define SHUNT_ADC_9BIT          (0x0000 << 3)   // SADC: 9-bit, 1 sample, conversion time  84us.
#define SHUNT_ADC_10BIT         (0x0001 << 3)   // SADC: 10-bit, 1 sample, conversion time 148us.
#define SHUNT_ADC_11BIT         (0x0002 << 3)   // SADC: 11-bit, 1 sample, conversion time 2766us.
#define SHUNT_ADC_12BIT         (0x0003 << 3)   // SADC: 12-bit, 1 sample, conversion time 532us. (DEFAULT)
#define SHUNT_ADC_1SAMPLE       (0x0008 << 3)   // SADC: 12-bit, 1 sample, conversion time 532us.
#define SHUNT_ADC_2SAMPLES      (0x0009 << 3)   // SADC: 12-bit, 2 samples, conversion time 1.06 ms
#define SHUNT_ADC_4SAMPLES      (0x000A << 3)   // SADC: 12-bit, 4 samples, conversion time 2.13 ms
#define SHUNT_ADC_8SAMPLES      (0x000B << 3)   // SADC: 12-bit, 8 samples, conversion time 4.26 ms
#define SHUNT_ADC_16SAMPLES     (0x000C << 3)   // SADC: 12-bit, 16 samples, conversion time 8.51 ms
#define SHUNT_ADC_32SAMPLES     (0x000D << 3)   // SADC: 12-bit, 32 samples, conversion time 17.02 ms
#define SHUNT_ADC_64SAMPLES     (0x000E << 3)   // SADC: 12-bit, 64 samples, conversion time 34.05 ms
#define SHUNT_ADC_128SAMPLES    (0x000F << 3)   // SADC: 12-bit, 128 samples, conversion time 68.10 ms
#define MODE_POWER_DOWN         (0x0000)        // Power down
#define MODE_ADC_OFF            (0x0004)        // ADC off
#define MODE_FLAG_TRIGGERED     (0x0000)        // Triggered
#define MODE_FLAG_CONTINUOUS    (0x0004)        // Continuous (DEFAULT)
#define MODE_SHUNT_VOLTAGE      (0x0001)        // Shunt voltage
#define MODE_BUS_VOLTAGE        (0x0002)        // Bus voltage
#define MODE_SHUNT_BUS_VOLTAGE  (0x0003)        // Shunt and bus voltage (DEFAULT)

#define BIT_MASK_OVF            (0x0001)
#define BIT_MASK_CNVR           (0x0002)
#define SHUNT_MV_LSB            0.01            // 10uV
#define BUS_MV_LSB              4               // 4mV

#define DEFAULT_CONFIG (RANGE_32V | GAIN_8_320MV | BUS_ADC_12BIT | SHUNT_ADC_12BIT | MODE_FLAG_CONTINUOUS | MODE_SHUNT_BUS_VOLTAGE)

#include "Components/InaXxx/InaXxxComponentAc.hpp"
#include "Fw/FPrimeBasicTypes.hpp"

namespace InaXxx {

class InaXxx final : public InaXxxComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct InaXxx object
    InaXxx(const char* const compName  //!< The component name
    );

    //! Destroy InaXxx object
    ~InaXxx();

  private:
      Fw::Buffer m_i2cWriteBuffer[4]; //!< Buffer for I2C write operations
      Fw::Buffer m_i2cReadBuffer[4]; //!< Buffer for I2C read operations

    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command CONFIGURE_INAXXX
    //!
    //! Command: initial configuration of the INAxxx device
    void CONFIGURE_INAXXX_cmdHandler(
      FwOpcodeType opCode,  //!< The opcode
      U32 cmdSeq,           //!< The command sequence number
      const Fw::CmdStringArg& device_name,
      U32 i2c_address,
      U8 range,
      U8 gain,
      U8 bus_resolution,
      U8 bus_samples,
      U8 shunt_resolution,
      U8 shunt_samples
    ) override;

    //! Handler implementation for command READ_INAXXX
    //!
    //! Command: read data from the INAxxx device
    void READ_INAXXX_cmdHandler(
      FwOpcodeType opCode,  //!< The opcode
      U32 cmdSeq,           //!< The command sequence number
      const Fw::CmdStringArg& device_name,
      U32 i2c_address
    ) override;
};

}  // namespace InaXxx

#endif

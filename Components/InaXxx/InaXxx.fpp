module InaXxx {
    @ Manager component for Texas Instruments INAxxx voltage/current sensors
    active component InaXxx {

        @ Command: initial configuration of the INAxxx device
        async command CONFIGURE_INAXXX(
                        device_name: string, 
                        i2c_address: U32, 
                        range: U8, 
                        gain: U8, 
                        bus_resolution: U8, 
                        bus_samples: U8, 
                        shunt_resolution: U8, 
                        shunt_samples: U8)

        @ Command: read data from the INAxxx device
        async command READ_INAXXX(
                        device_name: string, 
                        i2c_address: U32)


        @ Event: error initializing INAxxx device
        event InaXxxDeviceInitFailure(error: Drv.I2cStatus) \
            severity fatal format "INAxxx device initialization failed: {}"

        @ Event: data acquisition failure
        event DataAcquisitionFailure(i2c_address: U8, error: Drv.I2cStatus) \
            severity fatal format "Data acquisition failed for I2C address {}: {}"

        @ Port: read data from device
        output port read: Drv.I2c

        @ Port: write data to device
        output port write: Drv.I2c

        @ Port: write, then read data from device
        output port writeRead: Drv.I2cWriteRead

        # @ Example parameter
        # param PARAMETER_NAME: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}
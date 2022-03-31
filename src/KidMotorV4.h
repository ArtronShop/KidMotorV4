#ifndef __KIDMOTORV4_H__
#define __KIDMOTORV4_H__

#include "Arduino.h"
#include "Wire.h"

#define MODE_INPUT 0
#define MODE_OUTPUT 1

class KidMotorV4 {
    private:
        TwoWire *_wire;

        void write(uint8_t address, uint8_t data) ;
        void write(uint8_t address, uint8_t *data, int len) ;
        uint8_t read(uint8_t address) ;
        uint8_t read_bytes(uint8_t address, uint8_t *buff, int n) ;
        uint8_t transfer(uint8_t address, uint8_t *data_write, int len_write, uint8_t *data_read, int len_read) ;

    public:
        const uint8_t D1 = 0;
        const uint8_t D2 = 1;
        const uint8_t D3 = 2;
        const uint8_t D4 = 3;
        const uint8_t D5 = 4;

        const uint8_t SV1 = 5;
        const uint8_t SV2 = 6;
        const uint8_t SV3 = 7;

        const uint8_t A1 = 3;
        const uint8_t A2 = 4;

        const uint8_t CH1 = 1;
        const uint8_t CH2 = 2;

        const uint8_t FORWARD = 1;
        const uint8_t BACKWARD = 0;
        
        KidMotorV4(TwoWire *wire = &Wire) ;

        void setMotor(uint8_t ch, uint8_t dir, uint8_t speed) ;
        void pinMode(uint8_t ch, uint8_t mode) ;
        void digitalWrite(uint8_t ch, uint8_t val) ;
        int digitalRead(uint8_t ch) ;
        int analogRead(uint8_t ch) ;
        void analogWrite(uint8_t ch, uint16_t val) ;

        void servoAngle(uint8_t ch, uint8_t angle) ;
        void servoUnlock(uint8_t ch) ;

        int distance(uint8_t trig_ch, uint8_t echo_ch) ;

};

#endif

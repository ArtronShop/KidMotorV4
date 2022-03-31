#include <Arduino.h>
#include "Wire.h"
#include "KidMotorV4.h"

KidMotorV4 kidMotor;

void setup() {
  Serial.begin(115200);
  
  Wire.begin(4, 5); // Uncomment if use KidBright
  // Wire.begin();

  kidMotor.pinMode(kidMotor.D1, OUTPUT);
}

void loop() {
  for (uint16_t light=0;light<65535;light+=6553) {
    kidMotor.analogWrite(kidMotor.D1, light);
    delay(300);
  }
}

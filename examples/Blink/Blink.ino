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
  kidMotor.digitalWrite(kidMotor.D1, HIGH);
  delay(1000);
  kidMotor.digitalWrite(kidMotor.D1, LOW);
  delay(1000);
}

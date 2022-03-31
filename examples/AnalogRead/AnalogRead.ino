#include <Arduino.h>
#include "Wire.h"
#include "KidMotorV4.h"

KidMotorV4 kidMotor;

void setup() {
  Serial.begin(115200);
  
  // Wire.begin(4, 5); // Uncomment if use KidBright
  Wire.begin();

  kidMotor.pinMode(kidMotor.D4, INPUT); // analogRead support only D4, D5
}

void loop() {
  Serial.println(kidMotor.analogRead(kidMotor.D4));
  delay(100);
}

#include <Arduino.h>
#include "Wire.h"
#include "KidMotorV4.h"

KidMotorV4 kitMotor;

void setup() {
  Serial.begin(115200);
  
  // Wire.begin(4, 5); // Uncomment if use KidBright
  Wire.begin();
}

void loop() {
  kitMotor.servoAngle(kitMotor.SV1, 0); // กำหนดเซอร์โวมอเตอร์ขา SV1 หมุน 0 องศา
  delay(2000);
  kitMotor.servoAngle(kitMotor.SV1, 90); // กำหนดเซอร์โวมอเตอร์ขา SV1 หมุน 90 องศา
  delay(2000);
  kitMotor.servoAngle(kitMotor.SV1, 180); // กำหนดเซอร์โวมอเตอร์ขา SV1 หมุน 180 องศา
  delay(2000);
  // kitMotor.servoUnlock(kitMotor.SV1);
  // delay(2000);
}

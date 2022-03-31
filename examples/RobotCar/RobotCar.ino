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
  kitMotor.move(kitMotor.FORWARD, 40); // เดินหน้าด้วยความเร็ว 40%
  delay(3000); // 3 วินาที
  kitMotor.move(kitMotor.TURN_LEFT, 25); // เลี้ยวซ้ายด้วยความเร็ว 25%
  delay(300); // 0.3 วินาที
}

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
  kitMotor.setMotor(kitMotor.CH1, kitMotor.FORWARD, 50); // กำหนดมอเตอร์ช่อง 1 หมุนตามเข็มด้วยความเร็ว 50%
  delay(500);
  kitMotor.setMotor(kitMotor.CH1, kitMotor.FORWARD, 100); // กำหนดมอเตอร์ช่อง 1 หมุนตามเข็มด้วยความเร็ว 100%
  delay(500);
  kitMotor.setMotor(kitMotor.CH1, kitMotor.BACKWARD, 50); // กำหนดมอเตอร์ช่อง 1 หมุนทวนเข็มด้วยความเร็ว 50%
  delay(500);
  kitMotor.setMotor(kitMotor.CH1, kitMotor.BACKWARD, 100); // กำหนดมอเตอร์ช่อง 1 หมุนทวนเข็มด้วยความเร็ว 100%
  delay(500);
  kitMotor.setMotor(kitMotor.CH2, kitMotor.FORWARD, 50); // กำหนดมอเตอร์ช่อง 2 หมุนตามเข็มด้วยความเร็ว 50%
  delay(500);
  kitMotor.setMotor(kitMotor.CH2, kitMotor.FORWARD, 100); // กำหนดมอเตอร์ช่อง 2 หมุนตามเข็มด้วยความเร็ว 100%
  delay(500);
  kitMotor.setMotor(kitMotor.CH2, kitMotor.BACKWARD, 50); // กำหนดมอเตอร์ช่อง 2 หมุนทวนเข็มด้วยความเร็ว 50%
  delay(500);
  kitMotor.setMotor(kitMotor.CH2, kitMotor.BACKWARD, 100); // กำหนดมอเตอร์ช่อง 2 หมุนทวนเข็มด้วยความเร็ว 100%
  delay(500);
}
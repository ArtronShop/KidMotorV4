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
  Serial.print("Distance: ");
  Serial.print(kitMotor.distance(kitMotor.D1, kitMotor.D2));
  Serial.print(" cm");
  Serial.println();
  delay(500);
}

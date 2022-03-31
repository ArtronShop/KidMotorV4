# KidMotorV4-Arduino

ไลบารี่ Arduino สำหรับบอร์ด KidMotor V4 ใช้สั่งงานมอเตอร์ เซอร์โวมอเตอร์ และขา I/O รองรับการอ่านค่าจากเซ็นเซอร์ดิจิทัล แอนะล็อก และอัลตร้าโซนิค (HC-SR04P)

## คำสั่งที่มีให้ใช้งาน

```c++
KidMotorV4(TwoWire *wire = &Wire) ;

void setMotor(uint8_t ch, uint8_t dir, uint8_t speed) ;
void move(uint8_t dir, uint8_t speed = 0) ;

void pinMode(uint8_t ch, uint8_t mode) ;
void digitalWrite(uint8_t ch, uint8_t val) ;
int digitalRead(uint8_t ch) ;
int analogRead(uint8_t ch) ;
void analogWrite(uint8_t ch, uint16_t val) ;

void servoAngle(uint8_t ch, uint8_t angle) ;
void servoUnlock(uint8_t ch) ;

int distance(uint8_t trig_ch, uint8_t echo_ch) ;
```

### void KidMotorV4::setMotor(ch, dir, speed)

ใช้กำหนดทิศทางการหมุนของมอเตอร์ และความเร็วของมอเตอร์

#### พารามิเตอร์

 * (uint8_t) ch - หมายเลขของมอเตอร์ กำหนดได้ 2 ค่า คือ 1 หรือ 2
 * (uint8_t) dir - ทิศทางการหมุนของมอเตอร์ กำหนดได้ 2 ค่า คือ FORWARD และ BACKWARD
 * (uint8_t) speed - ความเร็วของมอเตอร์ กำหนดได้ 0 ถึง 100 หน่วย %

#### ค่าส่งกลับ

*ไม่มี (void)*

### void KidMotorV4::move(dir, speed)

ใช้กรณีนำบอร์ด KidMotor ไปทำหุ่นยนต์วิ่งตามเส้น รถบังคับ รถ 2 ล้อ ใช้กำหนดทิศทางการวิ่ง

#### พารามิเตอร์

 * (uint8_t) dir - ทิศทางการวิ่ง กำหนดได้
   * FORWARD - รถวิ่งเดินหน้า
   * BACKWARD - รถวิ่งถอยหลัง
   * TURN_LEFT - รถเลี้ยวซ้าย
   * TURN_RIGHT - รถเลี้ยวขวา
   * SPIN_LEFT - หมุนซ้าย
   * SPIN_RIGHT - หมุนขวา
   * STOP - รถหยุดวิ่ง
 * (uint8_t) speed - ความเร็วของมอเตอร์ กำหนดได้ 0 ถึง 100 หน่วย %

#### ค่าส่งกลับ

*ไม่มี (void)*

### void KidMotorV4::pinMode(uint8_t ch, uint8_t mode)

ใช้กำหนดโหมดใช้งานขาดิจิทัล D1 ถึง D5

#### พารามิเตอร์

 * (uint8_t) ch - ขาที่ต้องการกำหนดทิศทาง กำหนดได้ D1 ถึง D5
 * (uint8_t) mode - กำหนดได้ 2 ค่า คือ INPUT และ OUTPUT

#### ค่าส่งกลับ

*ไม่มี (void)*


### void KidMotorV4::digitalWrite(uint8_t ch, uint8_t val)

ใช้สั่งให้ D1 ถึง D5 มีสถานะเอาต์พุตลอจิก 0 หรือ 1

#### พารามิเตอร์

 * (uint8_t) ch - ขาที่ต้องการกำหนดสถานะลอจิก กำหนดได้ D1 ถึง D5
 * (uint8_t) val - ลอจิกที่ต้องการกำหนด (กำหนดได้ 0 หรือ 1 หรือ LOW หรือ HIGH)

#### ค่าส่งกลับ

*ไม่มี (void)*

### int KidMotorV4::digitalRead(uint8_t ch)

ใช้อ่านสถานะลอจิกที่ขา D1 ถึง D5

#### พารามิเตอร์

 * (uint8_t) ch - ขาที่ต้องการอ่านสถานะลอจิก กำหนดได้ D1 ถึง D5

#### ค่าส่งกลับ

(int) สถานะลอจิกที่อ่านได้ เป็น 0 หรือ 1

### int KidMotorV4::analogRead(uint8_t ch) ;

ใช้อ่านค่าแอนะล็อกจากขา A0 ถึง A1 ให้ค่าเป็น 0 ถึง 4095

#### พารามิเตอร์

 * (uint8_t) ch - ขาที่ต้องการอ่านสถานะลอจิก กำหนดได้ A0 หรือ A1

#### ค่าส่งกลับ

(int) ค่าแอนะล็อกที่อ่านได้ 0 ถึง 4095

### void KidMotorV4::analogWrite(uint8_t ch, uint16_t val) ;

ใช้สั่งให้ D1 ถึง D5 ส่งสัญญาณ PMW

#### พารามิเตอร์

 * (uint8_t) ch - ขาที่ต้องการกำหนดสถานะลอจิก กำหนดได้ D1 ถึง D5
 * (uint16_t) val - ค่า PWM ที่ต้องการสั่งงาน กำหนดได้ 0 ถึง 65535

#### ค่าส่งกลับ

*ไม่มี (void)*

### void KidMotorV4::servoAngle(uint8_t ch, uint8_t angle)

ใช้สั่งงานเซอร์โวมอเตอร์ ขา SV1 ถึง SV3

#### พารามิเตอร์

 * (uint8_t) ch - เซอร์โวมอเตอร์ที่ต้องการกำหนดองศา กำหนดได้ SV1 ถึง SV3
 * (uint8_t) angle - องศาของเซอร์โวมอเตอร์

#### ค่าส่งกลับ

*ไม่มี (void)*

### void KidMotorV4::servoUnlock(uint8_t ch)

ใช้สั่งปลดล็อกเซอร์โวมอเตอร์ (ไม่ปล่อยสัญญาณ PWM)

#### พารามิเตอร์

 * (uint8_t) ch - เซอร์โวมอเตอร์ที่ต้องการปลดล็อก กำหนดได้ SV1 ถึง SV3

#### ค่าส่งกลับ

*ไม่มี (void)*

### int KidMotorV4::distance(uint8_t trig_ch, uint8_t echo_ch)

ใช้อ่านค่าระยะห่างระหว่างวัตถุกับหน้าเซ็นเซอร์อัลตร้าโซนิค

#### พารามิเตอร์

 * (uint8_t) trig_ch - ขาที่ต่อกับเซ็นเซอร์อัลตร้าโซนิคขา Trig กำหนดได้ D1 หรือ D5
 * (uint8_t) echo_ch - ขาที่ต่อกับเซ็นเซอร์อัลตร้าโซนิคขา Echo กำหนดได้ D1 หรือ D5

#### ค่าส่งกลับ

(int) ค่าระยะห่างที่วัดได้ หน่วย เซ็นติเมตร

## ตัวอย่างการใช้งาน

 * [Motor](examples/Motor/Motor.ino) - ตัวอย่างการสั่งงานมอเตอร์แยกช่อง
 * [RobotCar](examples/RobotCar/RobotCar.ino) - ตัวอย่างการสั่งงานหุ่นยนต์ 2 ล้อ
 * [Blink](examples/Blink/Blink.ino) - ตัวอย่างโปรแกรมไฟกระพริบ
 * [AnalogWrite](examples/AnalogWrite/AnalogWrite.ino) - ตัวอย่างสั่งงานอุปกรณ์แบบ PWM
 * [AnalogRead](examples/AnalogRead/AnalogRead.ino) - ตัวอย่างการอ่านค่าแอนะล็อก
 * [Servo](examples/Servo/Servo.ino) - ตัวอย่างการสั่งงานเซอร์โวมอเตอร์
 * [Ultrasonic](examples/Ultrasonic/Ultrasonic.ino) - ตัวอย่างการอ่านค่าระยะทางจากเซ็นเซอร์อัลตร้าโซนิค



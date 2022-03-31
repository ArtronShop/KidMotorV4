#include "KidMotorV4.h"

#define ADDR 0x08

KidMotorV4::KidMotorV4(TwoWire *wire) {
    _wire = wire;
}

void KidMotorV4::write(uint8_t address, uint8_t data) {
  _wire->beginTransmission(ADDR);
  _wire->write(address);
  _wire->write(data);
  int error = _wire->endTransmission();
  if (error != 0) {
    Serial.println(error);
  }
}

void KidMotorV4::write(uint8_t address, uint8_t *data, int len) {
  _wire->beginTransmission(ADDR);
  _wire->write(address);
  _wire->write(data, len);
  int error = _wire->endTransmission();
  if (error != 0) {
    Serial.println(error);
  }
}

uint8_t KidMotorV4::read(uint8_t address) {
  _wire->beginTransmission(ADDR);
  _wire->write(address);
  int error = _wire->endTransmission();
  if (error != 0) {
    Serial.println(error);
    return 0;
  }

  int n = _wire->requestFrom(ADDR, 1);
  if (n < 1) {
    Serial.println("Read data error");
    return 0;
  }

  return _wire->read();
}

uint8_t KidMotorV4::read_bytes(uint8_t address, uint8_t *buff, int n) {
  _wire->beginTransmission(ADDR);
  _wire->write(address);
  int error = _wire->endTransmission();
  if (error != 0) {
    Serial.println(error);
    return 0;
  }

  _wire->flush();
  
  int len = _wire->requestFrom(ADDR, n);
  if (len < n) {
    return 0;
  }
  
  return _wire->readBytes(buff, n);
}

uint8_t KidMotorV4::transfer(uint8_t address, uint8_t *data_write, int len_write, uint8_t *data_read, int len_read) {
  _wire->beginTransmission(ADDR);
  _wire->write(data_write, len_write);
  int error = _wire->endTransmission();
  if (error != 0) {
    Serial.println(error);
    return 0;
  }

  _wire->flush();
  
  int len = _wire->requestFrom(ADDR, len_read);
  if (len < len_read) {
    return 0;
  }
  
  return _wire->readBytes(data_read, len_read);
}

void KidMotorV4::setMotor(uint8_t ch, uint8_t dir, uint8_t speed) {
  ch = ch - 1;
  speed = speed * (80.0 / 100.0);
  this->write(ch == 0 ? 0x00 : 0x01, (dir << 7) | (speed & 0x7F));
}

void KidMotorV4::pinMode(uint8_t ch, uint8_t mode) {
  static uint8_t mode_tmp = 0;
  if (mode == 1) {
    mode_tmp |= 1 << ch;
  } else {
    mode_tmp &= ~(1 << ch);
  }
  this->write(0x02, mode_tmp);
}

void KidMotorV4::digitalWrite(uint8_t ch, uint8_t val) {
  // this->mode(ch, MODE_OUTPUT);
  static uint8_t out_tmp = 0;
  if (val) {
    out_tmp |= 1 << ch;
  } else {
    out_tmp &= ~(1 << ch);
  }
  this->write(0x04, out_tmp);
}

int KidMotorV4::digitalRead(uint8_t ch) {
  // this->mode(ch, MODE_INPUT);
  return (this->read(0x03) & (1 << ch)) ? 1 : 0;
}

int KidMotorV4::analogRead(uint8_t ch) {
  this->write(0x05, 0x80 | (ch & 0x07)); // Write ADC ch and set FLAG
  do {
    delay(1);
  } while((this->read(0x05) & 0x80) != 0);
  uint8_t buff[2];
  this->read_bytes(0x06, buff, 2);
  return (buff[0] << 8) | buff[1];
}

void KidMotorV4::analogWrite(uint8_t ch, uint16_t val) {
  // this->mode(ch, MODE_OUTPUT);
  uint8_t out_tmp[2] = {
    val >> 8,
    val & 0xFF
  };
  this->write(0x10 + (ch * 2), out_tmp, 2);
}

void KidMotorV4::servoAngle(uint8_t ch, uint8_t angle) {
  this->write(0x20 + ch, angle);
}

void KidMotorV4::servoUnlock(uint8_t ch) {
  this->write(0x20 + ch, 255);
}

int KidMotorV4::distance(uint8_t trig_ch, uint8_t echo_ch) {
  this->write(0x30, 0x80 | (trig_ch << 3) | (echo_ch & 0x07)); // Write trig, echo pin and set START flag
  do {
    delay(1);
  } while((this->read(0x30) & 0x80) != 0);
  uint8_t buff[2];
  this->read_bytes(0x31, buff, 2);
  return (buff[0] << 8) | buff[1];
}

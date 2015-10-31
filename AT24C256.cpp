#include <Wire.h>
#include "AT24C256.h"

AT24C256::AT24C256(int deviceAddress) {
  this->m_deviceAddress = deviceAddress;
}

byte AT24C256::read(unsigned int eeaddress) {
  byte rdata = 0xFF;

  Wire.beginTransmission(this->m_deviceAddress);
  Wire.write((int)(eeaddress >> 8));
  Wire.write((int)(eeaddress & 0xFF));
  Wire.endTransmission();
  Wire.requestFrom(this->m_deviceAddress, 1);
  if (Wire.available()) {
    rdata = Wire.read();
  }
  return rdata;
}

void AT24C256::write(unsigned int eeaddress, byte data) {
  int rdata = data;

  Wire.beginTransmission(this->m_deviceAddress);
  Wire.write((int)(eeaddress >> 8));
  Wire.write((int)(eeaddress & 0xFF));
  Wire.write(rdata);
  Wire.endTransmission();
  delay(5);
}

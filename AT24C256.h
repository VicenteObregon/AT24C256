#include <Arduino.h>

//+---u---+
//|A0 |VCC|
//|A1 |WP |
//|?? |SCL|
//|GND|SDA|
//+---+---+

class AT24C256 {
  protected:
    int m_deviceAddress;

  public:
    AT24C256(int deviceAddress);
    byte read(unsigned int eeaddress);
    void write(unsigned int eeaddress, byte data);
};

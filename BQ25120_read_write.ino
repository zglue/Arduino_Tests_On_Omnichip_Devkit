// I2C Digital Potentiometer
// by Nicholas Zambetti <http://www.zambetti.com>
// and Shawn Bonkowski <http://people.interaction-ivrea.it/s.bonkowski/>

// Demonstrates use of the Wire library
// Controls AD5171 digital potentiometer via I2C/TWI

// Created 31 March 2006

// This example code is in the public domain.

// This example code is in the public domain.


#include <Wire.h>

byte val = 0xAA;
byte val1 = 0x00;
byte val2 = 0x02;

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(115200);


  Wire.beginTransmission(0x6A); // device address is specified in datasheet
  Wire.write(byte(0x06));            // sends instruction byte  
  Wire.write(val);               
  Wire.endTransmission();     // stop transmitting
  delay(500);

/////////////////////////////LDO change///////////////


  Wire.beginTransmission(0x6A); 
  Wire.write(byte(0x07));            // sends instruction byte  
  Wire.write(0x1C);             // change LDO 
  Wire.endTransmission();     // stop transmitting
  delay(500);

  Wire.beginTransmission(0x6A); 
  Wire.write(byte(0x07));            // sends instruction byte  
  Wire.write(0x9C);             // ENABLE LDO  
  Wire.endTransmission();     // stop transmitting
  delay(500);



}


void loop()
{

}

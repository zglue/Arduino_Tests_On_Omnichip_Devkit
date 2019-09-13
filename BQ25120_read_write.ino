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


  Wire.beginTransmission(0x6A); // transmit to device #44 (0x2c)                             // device address is specified in datasheet
  Wire.write(byte(0x06));            // sends instruction byte  
  Wire.write(val);             // sends potentiometer value byte  
  Wire.endTransmission();     // stop transmitting
  delay(500);
/*
  byte d;
  Wire.requestFrom(0x06, 2); //reading to see if the data has been written or not.
  while(Wire.available());
  {
   d = Wire.read();
   Serial.println(d, HEX);
  }
 delay(500);
*/

/////////////////////////////LDO change///////////////

 // pinMode(31, INPUT); 
  //digitalWrite(31, LOW); //disable LSCTRL


  Wire.beginTransmission(0x6A); // transmit to device #44 (0x2c)
  Wire.write(byte(0x07));            // sends instruction byte  
  Wire.write(0x1C);             // change LDO 
  Wire.endTransmission();     // stop transmitting
  delay(500);

  Wire.beginTransmission(0x6A); // transmit to device #44 (0x2c)
  Wire.write(byte(0x07));            // sends instruction byte  
  Wire.write(0x9C);             // ENABLE LDO  
  Wire.endTransmission();     // stop transmitting
  delay(500);

//digitalWrite(31, HIGH);

}


void loop()
{

}

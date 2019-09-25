/*
   TMP108_Example.ino
   Created: July 1st 2017

   This sketch is released AS-IS into the public domain, no guarantee or warranty is given.
   This code is not supported by Texas Instruments or Sparkfun.

   Description: This sketch shows how to use the TMP102 to read the curent temperature and print
   it to a standard 1602 LCD Display. Please see the associated schematic file.

   Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

      Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

      Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the
      distribution.

      Neither the name of Texas Instruments Incorporated nor the names of
      its contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <Wire.h>


void setup()
{
  Serial.begin(115200);
  Wire.begin();


}

void loop()
{
  //call the sensorRead function to retrieve the temperature
  double temperature = sensorRead();
  //wait 1/2 second
  delay(500);
  Serial.print(temperature);
  Serial.println(" C");
}


double sensorRead(void)
{
  //temp holds the two bytes of data read back from the TMP102
  uint8_t temp[2];
  byte reg = 0x00; //set the temp for configuration.
  //tempc holds the modified combination of bytes
  int16_t tempc;

  //Point to device 0x48
  Wire.beginTransmission(72);
  //Point to register 0x00 (Temperature Register)
  Wire.write(reg);
  //Relinquish master control of I2C line
  Wire.endTransmission();
  //delay to allow for sufficient conversion time
  //delay(10);

  //Request temperature data
  Wire.requestFrom(0x48, 2);

  //if the two bytes are sucessfully returned
  if (2 <= Wire.available())
  {
    //read out the data
    temp[0]  = Wire.read();
    temp[1] = Wire.read();

    //ignore the lower 4 bits of byte 2
    temp[1] = temp[1] >> 4;
    //combine to make one 12 bit binary number
    tempc = ((temp[0] << 4) | temp[1]);

    //Convert to celcius (0.0625C resolution) and return
    return tempc * 0.0625;
  }
}

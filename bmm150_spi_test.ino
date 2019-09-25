#include <SPI.h>


int CS = 16;
byte data = 0x00;

void setup()
{

pinMode(CS, OUTPUT);
digitalWrite(CS, HIGH);
Serial.begin(9600);
SPI.begin();
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE0); //BMM150 is compatible with modes 0 and 3.
Serial.println("BMM150 Example Code");

}

void loop() {



digitalWrite(CS, LOW);
SPI.transfer(0x4B); ///control bit is enabled
SPI.transfer(0x01);
digitalWrite(CS, HIGH);

delay(100);

digitalWrite(CS, LOW);
SPI.transfer(0xC0); ////register where chip ID is stored is 0x40. since it's being read there is a 1 on the MSB. so 40 is C0. (check chip datasheet for read and write instructions).
data = SPI.transfer(0x00); //reading from register 0x40
digitalWrite(CS, HIGH);
delay(100);

Serial.println(data, HEX);

digitalWrite(CS, LOW);
SPI.transfer(0xCB);  //reading from 0x4B, the control bit register. to just check if it's written correctly.
data = SPI.transfer(0x00);
digitalWrite(CS, HIGH);
delay(100);

Serial.println(data, HEX);
}

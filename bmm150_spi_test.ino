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
SPI.setDataMode(SPI_MODE0);
Serial.println("BMM150 Example Code");

}

void loop() {



digitalWrite(CS, LOW);
SPI.transfer(0x4B);
SPI.transfer(0x01);
digitalWrite(CS, HIGH);

delay(100);

digitalWrite(CS, LOW);
SPI.transfer(0xC0);
data = SPI.transfer(0x00);
digitalWrite(CS, HIGH);
delay(100);

Serial.println(data, HEX);

digitalWrite(CS, LOW);
SPI.transfer(0xCB);
data = SPI.transfer(0x00);
digitalWrite(CS, HIGH);
delay(100);

Serial.println(data, HEX);
}

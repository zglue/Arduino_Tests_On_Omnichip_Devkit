#include <SPI.h>

//spi Slave select pin
const int MAX = 15;

////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  pinMode (MAX, OUTPUT);
  digitalWrite(MAX, HIGH);

 //iNITIALIZE spi
SPI.begin();
SPI.setDataMode(SPI_MODE3);
SPI.setBitOrder(MSBFIRST);
//SPI.setClockDivider(SPI_CLOCK_DIV16);

Serial.println("MAX86140 SPI Sample Code");
}
byte val = 0x00;
///////////////////////////////////////////////////////////
void loop() 
{
/*
//SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
digitalWrite(MAX, LOW);
SPI.transfer(0xF2); //memory control register 0xF2
SPI.transfer(0x02); //enable write access to memory through SPI. Page86 in datasheet
digitalWrite(MAX, HIGH);
//SPI.endTransaction();
delay(100);
*/

//SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
digitalWrite(MAX, LOW);
SPI.transfer(0xFF); //first byte: 0xFF address where Part ID is stored
SPI.transfer(0x80); //second byte: read command byte 1000 0000
unsigned int reg_val = SPI.transfer(0); //third byte: read from register
digitalWrite(MAX, HIGH);
//SPI.endTransaction();
delay(100);

Serial.println(reg_val, HEX); //expected ID is 0x24
}

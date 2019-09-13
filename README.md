# Arduino_Tests_On_Omnichip_Devkit
Used bootloader firmware on nrf52832 on MPW ompnichip devkit. Tested sensors using arduino sketch.

MC3672:
MC36XX_demo is the arduino IDE sketch to test MC3672 Chip.
download MC36XX_demo, MC36XX.cpp and MC36XX.h in one folder before programming the sketch.

BQ25120:
Attached is the arduino IDE sketch to test the BQ25120. You can change the BQ_SYS and LDO outputs by configuring the registers. (Note: battery Management Studio was used to know what registers to chnage and to what address. Datasheet could be used to do the smae.)
Important: To change LDO, LSCTRL (turns LDO switch on or off) and LDO_EN pins should be disabled first. Then change the LDO output. Then enable the LSCTRL and LDO enable pins. 
The LSCTRL pin form the BQ side was brought out on a bonpad and manually given a low when programming the sketch then a high after programming. 
Also make sure that BQ25120A_VINLS_QFN (Input to LS/LDO) is connected to BQ25120A_SYS_QFN.


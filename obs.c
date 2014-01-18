#include <REG51.H>
#include <lcd.h>

//Sensor Section
sbit SENSOR_1 = P3^0;
sbit SENSOR_2 = P3^1;
sbit SENSOR_3 = P3^2;

//Motor Section
sbit PORT1_0 = P1^0;				//Enable1 pin
sbit PORT1_1 = P1^1;				//Enable2 pin
sbit PORT1_2 = P1^2;				//I-O1 Left motor forward
sbit PORT1_3 = P1^3;				//I-O2 Left motor backward
sbit PORT1_4 = P1^4;				//I-O3 Right motor forward
sbit PORT1_5 = P1^5;				//I-O4 Right motor backward
			
//LCD Sesction
sbit D0 = P0^0;
sbit D1 = P0^1;
sbit D2 = P0^2;
sbit D3 = P0^3;
sbit D4 = P0^4;
sbit D5 = P0^5;
sbit D6 = P0^6;
sbit D7 = P0^7;

//LCD Register Section
sbit RS = P3^3;
sbit EN = P3^4;

void main (void) {
		
	
		char *A=49;
		
		P3 = 0x00;		//Clear Port 3
		P1 = 0x00;		//Clear Port 1
		
		Lcd8_Init();
		Lcd_Delay(100);
		Lcd8_Set_Cursor(1,1);
		Lcd8_Write_String(A);
	
		while (1) {
		
			if (SENSOR_3 == 1 && SENSOR_1 == 0)
				{
					PORT1_0 = 1;
					PORT1_1 = 0;
					PORT1_2 = 1;
					PORT1_3 = 0;
					PORT1_4 = 1;
					PORT1_5 = 1;						
				}
			else if (SENSOR_1 == 1 && SENSOR_3 == 0) 
				{
					PORT1_0 = 0;
					PORT1_1 = 1;
					PORT1_2 = 1;
					PORT1_3 = 1;
					PORT1_4 = 1;
					PORT1_5 = 0;
				}
			else if (SENSOR_1 == 1 && SENSOR_2 == 1 && SENSOR_3 == 1)
				{	
					PORT1_0 = 1;
					PORT1_1 = 1;
					PORT1_2 = 0; 
					PORT1_3 = 1;
					PORT1_4 = 1;
					PORT1_5 = 0;
				}
			else
				{
					PORT1_0 = 1;
					PORT1_1 = 1;
					PORT1_2 = 1; 
					PORT1_3 = 0;
					PORT1_4 = 1; 
					PORT1_5 = 0;		  
			}
		}	 
}
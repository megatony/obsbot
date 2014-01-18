#include <reg51.h>
#include <lcd.h>

sbit RS = P2^7;
sbit EN = P2^6;

sbit D0 = P1^0;
sbit D1 = P1^1;
sbit D2 = P1^2;
sbit D3 = P1^3;
sbit D4 = P1^4;
sbit D5 = P1^5;
sbit D6 = P1^6;
sbit D7 = P1^7;

sbit R = P3^1;
sbit W = P3^2;

void main(){

Lcd8_Init();

Lcd8_Set_Cursor(1,1);
Lcd8_Write_Char("U");

	while(1){
	
	R=1;
	W=0;
	Lcd_Delay(100);
	R=0;
	W=1;
	Lcd_Delay(100);
	
	
}	
}
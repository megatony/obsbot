#include <reg51.h>
#include <lcd.h>

sbit RS = P2^3;
sbit EN = P2^2;

sbit D0 = P0^0;
sbit D1 = P0^1;
sbit D2 = P0^2;
sbit D3 = P0^3;
sbit D4 = P0^4;
sbit D5 = P0^5;
sbit D6 = P0^6;
sbit D7 = P0^7;

void main(){

	while(1){

		Lcd8_Init();

		Lcd8_Set_Cursor(2,10);
		Lcd8_Write_Char("a");

}
}
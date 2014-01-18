#include <reg51.h>

//DC Motor Pin Block
sbit EN1 = P1^0;
sbit EN2 = P1^1;
sbit IN1 = P1^2;
sbit IN2 = P1^3;
sbit IN3 = P1^4;
sbit IN4 = P1^5;

//LED Block
sbit RED = P3^7;
sbit YELLOW = P3^6;
sbit GREEN = P3^5;

//ADC Read/Write/INT Block
sbit W = P3^0;
sbit R = P3^1;
sbit INT = P3^2;

//INT Control Block
sbit C = P1^7;

void main()
{

int i = 0;														    //An integer for the loops
int BII = 0;															//BII port control integer
BII = P2;															

R = 1;																		//Reads sensor.
for(i = 0; i<10000; i++ );
W = 0;																		
for(i = 0; i<10000; i++ );
W = 1;																		//With the rising edge of W (from 0 to 1) ADC0804 starts conversion process.
for(i = 0; i<10000; i++ );								//After conversion done ADC0804 produce low signal at ~INTR that means conversion done.
	

	while(INT == 0)													//With this "while" statement microprocessor controls ~INTR. If data is ready P2(means ~INTR=0) starts comparing process.
	{
		

		C = 0;																//Signal for loop. 
																					//When you see BLUE LED blinking, it means that processor gets the digital input form P2 than starts to comparing.
	
		
																					//Beginning of comparing. Sharp GP2D120's maximum distances is 30 cm, minimum distance is 4 cm.
																					//This code got 3 modes.
																					//1- Belove 10cm behavior.
																					//2- Between 10cm and 20cm behavior.
																					//3- Between 20cm and 30cm behavior.
		
		
			if (BII >= 139)											//1- Belove 10cm behavior. 
				{																	//When sensor range at 10cm ADC produces binary 10001011 = 139.
					RED = 0;												//We control whole P2 port in if statement with "BII >= 139".
					YELLOW = 1;											//This statement means that range is 10cm or belove.
					GREEN = 1;							
					EN1 = 1;
					EN2 = 1;
					IN1 = 1;
					IN2 = 0;
					IN3 = 0;			
					IN4 = 1;			
				}
				
			 
			
			
			
				
			 else if (BII < 139 & BII >= 73)			//2- Between 10cm and 20cm behavior.
				{																		//When sensor range at 20cm ADC produces binary 01001001 = 73.
					RED = 1;													//We control whole P2 port in if statement with "BII < 139 & BII >= 73".
					YELLOW = 0;												//This statement means that range is 10cm or belove
					GREEN = 1;
					EN1 = 1;
					EN2 = 1;
					IN1 = 1;
					IN2 = 0;
					IN3 = 1;			
					IN4 = 0;
				}
				
			 
			
			
			
				
			else if (BII < 73 & BII >=51)					//3- Between 20cm and 30cm behavior.
				{																		//When sensor range at 20cm ADC produces binary 00110011 = 73.
					RED = 1;													//We control whole P2 port in if statement with "BII < 139 & BII >= 73".
					YELLOW = 1;												//This statement means that range is 10cm or belove
					GREEN = 0;
					EN1 = 1;
					EN2 = 1;
					IN1 = 1;
					IN2 = 0;
					IN3 = 1;			
					IN4 = 0;
				}
			
		
		
R = 0;
for(i = 0; i<10000; i++ );	
	}

C = 1;


}
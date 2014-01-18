#include <REG51.H>

sbit SENSOR_1 = P3^0;
sbit SENSOR_2 = P3^1;
sbit SENSOR_3 = P3^2;
sbit PORT1_0 = P1^0;
sbit PORT1_1 = P1^1;
sbit PORT1_2 = P1^2;
sbit PORT1_3 = P1^3;
sbit PORT1_4 = P1^4;
sbit PORT1_5 = P1^5;
sbit PORT1_6 = P1^6;

void main (void) {
	unsigned int i;
	unsigned switch_enable = 0;
	SENSOR_1 = 0;
	SENSOR_2 = 0;
	SENSOR_3 = 0;
  while (1) {
		
		if (SENSOR_3 == 1 && SENSOR_1 == 0){
		
		PORT1_0 = 1;
		PORT1_1 = 0;
		PORT1_4 = 1; //Firstly stop the right motor if its working
	  PORT1_5 = 1;
    for(i=0;i<200;i++);
		PORT1_2 = 1; //We'll going to run left motor according to datasheet of L293D
		PORT1_3 = 0;	
		}
		else if (SENSOR_1 == 1 && SENSOR_3 == 0) {
			PORT1_0 = 0;
		  PORT1_1 = 1;
			PORT1_2 = 1; //Stop the left motor
			PORT1_3 = 1;
			for(i=0;i<200;i++);
			PORT1_4 = 1; //Values to start right motor
			PORT1_5 = 0;
		}
		else if (SENSOR_1 == 1 && SENSOR_2 == 1 && SENSOR_3 == 1)
		{
			PORT1_0 = 1;
		  PORT1_1 = 1;
			PORT1_2 = 0; //Reverse to direction of left motor
			PORT1_3 = 1;
			for(i=0;i<200;i++);
			PORT1_4 = 1;
			PORT1_5 = 0;
		}
		else
		{
			PORT1_0 = 1;
		  PORT1_1 = 1;
			PORT1_2 = 1; //We'll going to run left motor according to datasheet of L293D
      PORT1_3 = 0;
			PORT1_4 = 1; //Values to start right motor
			PORT1_5 = 0;		  
		}
		}	 
}
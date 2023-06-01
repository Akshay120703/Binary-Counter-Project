#include <REGX51.H>
#define segment P2
sbit dis1_cc = P3^0; //cc
sbit dis2_cc = P3^1; //cc

sbit Entrance_sensor = P1^0; //Entrance push_button
sbit Exit_sensor     = P1^1; //Exit push_button

void dely(unsigned int dly);

void main(void)
{ 
                      	/* 0    1    2    3    4    5    6    7    8   9*/
unsigned int nums[10] ={0x3F,0x06, 0X5B,0X4F,0x66,0X6D,0X7D,0X07,0X7F,0X6F};
unsigned int loop=0, loop2=0;
Entrance_sensor = 0;
Exit_sensor   = 0;

 while(1) 
	{
      if(Entrance_sensor == 1)
			{
				dely(80);
				(loop >= 400) ? (loop = 400) : (loop++);  
			}
		  else
		  {
			   /* do nothing */ 
		  }
			
		  if(Exit_sensor == 1)
			{
				dely(80);
				(loop != 0) ? (loop--) : (loop = 0); 
			}
		  else
		  {
			 /* do nothing */
		  }
		
			loop2 = loop % 10; // 12%10 =2
			
			dis1_cc = 1; //off
			dis2_cc = 0;//on
      segment = nums[loop2];
			dely(80);
			
			loop2 = loop / 10; //12/10= 1
			dis1_cc = 0;//on
			dis2_cc = 1;//off
      segment = nums[loop2];
		  dely(80);
			
		
		

	}

}
void dely(unsigned int dly)
{
	unsigned int loop =0;
	unsigned int delay_gen =0;
	for(loop =0; loop < dly; loop++)
	for(delay_gen =0; delay_gen < 1000; delay_gen++); 
}
#include <reg52.h>   

sbit beep=P2^0;//有源蜂鸣器
sbit sounder = P3^7;//无源蜂鸣器	
//延时函数
void Delay_10us(unsigned int time)
{
	while(time--);
}
 


int main()
{	
	beep=0;
	while(1)
	{
		beep = ~beep;       
		Delay_10us(50000); 
		sounder=~sounder;
		Delay_10us(1000); 
	}
}

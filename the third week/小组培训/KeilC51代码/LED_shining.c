#include  <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit led0=P0^0;
sbit led1=P0^1;
sbit led2=P0^2;
sbit led3=P0^3;
sbit led4=P0^4;
sbit led5=P0^5;
sbit led6=P0^6;
sbit led7=P0^7;

void delay (u16 i)
{
	while (i--);
	
}

void main ()
{
    while (1)
		{
		
			led0=0;
			led1=1;
			delay (60000);
			led0=1;
			led1=0;
			delay (60000);
			led1=1;
			
			led2=0;
			led3=1;
			delay (60000);
			led2=1;
			led3=0;
			delay (60000);
			led3=1;
			
			led4=0;
			led5=1;
			delay (60000);
			led4=1;
			led5=0;
			delay (60000);
			led5=1;
			
			led6=0;
			led7=1;
			delay (60000);
			led6=1;
			led7=0;
			delay (60000);
			led7=1;
			delay (60000);
		}
}

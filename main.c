#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "OLED.h"

void Delayus(uint32_t xus)
{
	SysTick->LOAD = 72 * xus;				//设置定时器重装值
	SysTick->VAL = 0x00;					//清空当前计数值
	SysTick->CTRL = 0x00000005;				//设置时钟源为HCLK，启动定时器
	while(!(SysTick->CTRL & 0x00010000));	//等待计数到0
	SysTick->CTRL = 0x00000004;				//关闭定时器
}
void Delayms(uint32_t xms)
{
	while(xms--)
	{
		Delayus(1000);
	}
}
 
int main (void)
{
	OLED_Init();
	
	OLED_ShowChar(1, 1, 'A');

	
	while(1){
		
	}
	
}

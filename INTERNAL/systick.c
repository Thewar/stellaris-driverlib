/* 
* systick.c
*
* Giovanni Cimolin da Silva
* 
* 12.08.2014
*/


#include "inc/lm4f120h5qr.h"
#include "systick.h"

unsigned long systick_count = 0;

void systick_init(void)
{
  NVIC_ST_CTRL_R = 0;                   
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  
  NVIC_ST_CURRENT_R = 0;                
  
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE + NVIC_ST_CTRL_CLK_SRC;
}

//20ns delay with 50MHz main clock
void systick_delay(unsigned long delay)
{
  volatile unsigned long kalan_zaman;
  unsigned long baslama_zamani = NVIC_ST_CURRENT_R;
  
  do
  {
    kalan_zaman = (baslama_zamani - NVIC_ST_CURRENT_R) & 0x00FFFFFF;
  }
  while(kalan_zaman <= delay);
}

void systick_delay_us(unsigned long delay)
{
  unsigned long i;
  
  for(i=0; i<delay; i++)
    systick_delay(50); 		//1uS
}

void systick_delay_ms(unsigned long delay)
{
  unsigned long i;
  
  for(i=0; i<delay; i++)
    systick_delay(50000);  // 1mS
}

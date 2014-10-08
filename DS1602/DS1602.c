
#include "inc/lm4f120h5qr.h"
#include "DS1602.h"
#include "systick.h"

void lcd_putch(char c)
{
  LCD_RS(1); 
  
  delay_ms(2);       
  
  LCD_DATA = ((c & 0xF0) >> 4);
  EN_DATA();
  LCD_DATA =  (c & 0x0F);
  EN_DATA();
}

void lcd_cmd(unsigned char c)
{
  LCD_RS(0);
  
  delay_ms(2);      
  
  LCD_DATA = ((c & 0xF0) >> 4);
  EN_DATA();
  LCD_DATA =  (c & 0x0F);
  EN_DATA();
}

void lcd_clear(void)
{  
  lcd_cmd(0x01);
  delay_ms(10);
}

void lcd_puts(const char* s)
{ 
  while(*s)
    lcd_putch(*s++);
}

void lcd_goto(char x, char y)
{ 
  if(x==1)
    lcd_cmd(0x80+((y-1)%16));
  else
    lcd_cmd(0xC0+((y-1)%16));
}
	
void lcd_init()
{
  SYSCTL_RCGC2_R     |=  SYSCTL_RCGC2_GPIOB;	//Activate clock for port B
  GPIO_PORTB_DIR_R   |=  0x03;          
  GPIO_PORTB_AFSEL_R &= ~0x03;          
  GPIO_PORTB_DEN_R   |=  0x03;          
  GPIO_PORTB_PCTL_R   =  0xFFFFFF00;    
  GPIO_PORTB_AMSEL_R &=  0x03;          

  SYSCTL_RCGC2_R     |=  SYSCTL_RCGC2_GPIOD;	//Activate clock for port D
  GPIO_PORTD_DIR_R   |=  0x0F;          
  GPIO_PORTD_AFSEL_R &= ~0x0F;          
  GPIO_PORTD_DEN_R   |=  0x0F;          
  GPIO_PORTD_PCTL_R  &=  0xFFFF0000;    
  GPIO_PORTD_AMSEL_R &= ~0x0F;          

  LCD_RS(0);
  LCD_EN(0);

  lcd_cmd(0x28);  //Set 4 bit LCD mode
  lcd_cmd(0x0C); 
  lcd_cmd(0x06);  
  lcd_cmd(0x80);  
  lcd_cmd(0x28);  
  lcd_clear();  
}

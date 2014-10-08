/*
	DS1602.h

	DS1602 Display Driver

	By Giovanni Cimolin da Silva

*/
/*
	
*/
/*
Control pins:
RS -> PB0
EN -> PB1
Data pins:
D4 -> PD0
D5 -> PD1
D6 -> PD2
D7 -> PD3
*/

#define delay_us(x)     systick_delay_us(x)
#define delay_ms(x)     systick_delay_ms(x)

#define LCD_DATA        GPIO_PORTD_DATA_R
#define LCD_CONTROL     GPIO_PORTB_DATA_R
#define	EN_DATA()     LCD_EN(1),LCD_EN(0)

#define	LCD_RS(x)       ( (x) ? (LCD_CONTROL |= 0x01) : (LCD_CONTROL &= ~0x01) )
#define LCD_EN(x)       ( (x) ? (LCD_CONTROL |= 0x02) : (LCD_CONTROL &= ~0x02) )


void lcd_cmd    (unsigned char); 
void lcd_clear  (void);          
void lcd_puts   (const char*);   
void lcd_goto   (char,char);     
void lcd_init   (void);          
void lcd_putch  (char);         
//lab32
// LCD_led_lcd_keypad
//

#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "LCD.h"
#include "Seven_Segment.h"
#include "Scankey.h"

void show_7seg(int PC7_v, int PC6_v, int PC5_v, int PC4_v)
{
	ShowSevenSegment(3,PC7_v);	
	ShowSevenSegment(2,PC6_v);
	ShowSevenSegment(1,PC5_v);
	ShowSevenSegment(0,PC4_v);	
}
void showled(void){
    for(i=0;i<2;i++){
			PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 	
		
			PC12 =1; PC13 =1;PC14 =1; PC15 =1; // turn on LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 
		}

}


int main(void)
{
	char Text[16] = "keypad:         ";
	uint16_t keyin;
    int value[4] = {0, 0, 0, 0};
	int i,flag=0;
	
	SYS_Init();
	  
	init_LCD();
	clear_LCD();
	
    GPIO_SetMode(PC, (BIT12|BIT13|BIT14|BIT15), GPIO_MODE_OUTPUT);
	OpenSevenSegment();
	OpenKeyPad();	              // initialize 3x3 keypad
	print_Line(0,"LCD_Keypad"); // print title
	 
	while(1)
	{
	  keyin = ScanKey(); 	         // scan keypad to input
		sprintf(Text+8,"%d", keyin); // print scankey input to string			  
		print_Line(1, Text);         // display string on LCD
		CLK_SysTickDelay(5000); 	   // delay 																	 
	}
}

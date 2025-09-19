//demo1
// GPIO_LED : GPIO output to control an on-board red LED
// 
// EVB : Nu-LB-NUC140
// MCU : NUC140VE3CN
// PC12 =0; // 12¥ªÃäturn on LED
// low-active output control by GPC12

#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
/*int main(void)
{
    SYS_Init(); 
    GPIO_SetMode(PC, BIT12, GPIO_MODE_OUTPUT);
	
    while(1) {
	  PC12 =0; // turn on LED
	  CLK_SysTickDelay(100000);	 // Delay 
	  PC12 =1; // turn off LED
	  CLK_SysTickDelay(100000);	 // Delay 			
		}
}
*/
int main(void)
{
		int i;
    SYS_Init(); 
    GPIO_SetMode(PC, (BIT12|BIT13|BIT14|BIT15), GPIO_MODE_OUTPUT);
	
    while(1) {
		
		PC15 =0; // turn off LED
	  CLK_SysTickDelay(300000);	 // 0.3Delay
		PC15 =1; // turn on LED
	  PC14 =0; // turn off LED
	  CLK_SysTickDelay(300000);	 // 0.3Delay
		PC14 =1; // turn on LED
	  PC13 =0; // turn off LED
	  CLK_SysTickDelay(300000);	 // 0.3Delay
		PC13 =1; // turn on LED
	  PC12 =0; // turn off LED
	  CLK_SysTickDelay(300000);	 // 0.3Delay
		PC12 =1; // turn on LED
		
		for(i=0;i<2;i++){
			PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 	
		
			PC12 =1; PC13 =1;PC14 =1; PC15 =1; // turn on LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 
		}
		PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
		
		PC12 =0; // turn off LED
	  CLK_SysTickDelay(300000);	 // 0.3Delay
		PC12 =1; // turn on LED
	  PC13 =0; // turn off LED
	  CLK_SysTickDelay(300000);	 // 0.3Delay
		PC13 =1; // turn on LED
	  PC14 =0; // turn off LED
	  CLK_SysTickDelay(300000);	 // 0.3Delay
		PC14 =1; // turn on LED
	  PC15 =0; // turn off LED
	  CLK_SysTickDelay(300000);	 // 0.3Delay
		PC15 =1; // turn on LED
		
		for(i=0;i<2;i++){
			PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 	
		
			PC12 =1; PC13 =1;PC14 =1; PC15 =1; // turn on LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 
		}
		PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
		CLK_SysTickDelay(300000);	 // 0.3Delay
		
			
		}
}


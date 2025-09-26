//LCD & LCD_keypad & LCD_7seg_keypad


//
// LCD: display Text on LCD
//
// EVB : Nu-LB-NUC140
// MCU : NUC140VE3CN  (LQPF-100)
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "LCD.h"

int main(void)
{
	SYS_Init();
	init_LCD();
	clear_LCD();
	
  print_Line(0, "Nu-LB-NUC140    ");
  print_Line(1, "Cortex-M0 @50MHz");//不能超過16bits
  print_Line(2, "128KB Flash ROM ");
  print_Line(3, "32KB  SRAM      ");	
}


//===================================================

//
// LCD_keypad : 3x3 keypad input and display on LCD
//
// EVB : Nu-LB-NUC140
// MCU : NUC140VE3CN  (LQPF-100)
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "LCD.h"
#include "Scankey.h"

int main(void)
{
	char Text[16] = "keypad:         ";//只能置入16bits
	uint8_t keyin;
	
	SYS_Init();
	  
	init_LCD();
	clear_LCD();
	
	OpenKeyPad();	              // initialize 3x3 keypad
	print_Line(0,"LCD_Keypad"); // print title
	 
	while(1)
	{
	  keyin = ScanKey(); 	         // scan keypad to input
		sprintf(Text+8,"%d", keyin); // print scankey input to string，因為"keypad:" : 0~6			  
		print_Line(1, Text);         // display string on LCD
		CLK_SysTickDelay(5000); 	   // delay 																	 
	}
}

//===========================================

// lab31
// LCD_7seg_keypad
//

#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "LCD.h"
#include "Scankey.h"
#include "Seven_Segment.h"



void show7seg(int a, int b){
    CloseSevenSegment();
    ShowSevenSegment(3,a);//left
    CLK_SysTickDelay(10000);

    CloseSevenSegment();
    ShowSevenSegment(0,b);//right
    CLK_SysTickDelay(10000);
}

int main(void)
{
	uint8_t keyin;
 
    int i,flag = 0;
    int A = 0;
    int B = 0;
    int A_keyin = 0;//確認現在若要輸入A時，A_keyin = 1
    int B_keyin = 0;
    char line1[16] = "                ";
    char line2[16] = "                ";
    char line3[16] = "                ";
    char line4[16] = "                ";

    int showlcd = 1;

	SYS_Init();//systerm初始化
	  
	init_LCD();//LCD 初始化
	clear_LCD();//清除
	
	OpenKeyPad();
    OpenSevenSegment();
	//print_Line(0,"LCD_Keypad");
	 
	while(1)
	{
        keyin = ScanKey();
        switch(keyin){
            
            case 1://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 1;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 1;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;//flag = 1，在鬆開時迴圈會使其讀到case 0
                }
                break;
            
            case 2://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 2;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 2;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;
                }
                break;
            
            case 3://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 3;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 3;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;
                }
                break;
            
            case 4://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 4;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 4;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;
                }
                break;
            
            case 5://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 5;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 5;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;
                }
                break;
            
            case 6://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 6;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 6;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;
                }
                break;
            
            case 7://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 7;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 7;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;
                }
                break;
            
            case 8://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 8;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 8;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;
                }
                break;
            
            case 9://input 1時
                if(flag == 0){
                    if(A_keyin == 0){//因為A_keyin = 0得知是first num
                        A = 9;
                        A_keyin = 1;
                        B_keyin = 0;
                    }
                    else if(A_keyin == 1){//否則A_keyin = 1得知是second num
                        B = 9;
                        B_keyin = 1;
                        A_keyin = 0;
                    }
                    flag = 1;
                }
                break;

            case 0://沒觸發 或 點擊後，將flag = 0
                if(flag == 1){
                    flag == 0;
                }
                break;
        }
        show7seg(A,B);
        if(B_keyin ==1){
            if(showlcd == 1){//此if可避免迴圈重複執行時，造成的閃爍
                sprintf(line1,"%d + %d = %d",A,B,A+B);
                sprintf(line2,"%d - %d = %d",A,B,A-B);
                sprintf(line3,"%d * %d = %d",A,B,A*B);
                sprintf(line4,"%d / %d = %d",A,B,A/B);
                print_Line(0,line1);
                print_Line(1,line2);
                print_Line(2,line3);
                print_Line(3,line4);
                showlcd = 0;
            }

            
        }
        else if(A_keyin == 1 && B_keyin == 0){
            B = 0;
            if(showlcd == 0){
                clear_LCD();
                showlcd = 1;
            }
            
        }
	}
}


//=================================
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

//==================
//lab32_2
// LCD_led_lcd_keypad
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "LCD.h"
#include "Seven_Segment.h"
#include "Scankey.h"

int password_dis = 0;
int count_input = 0;//input :4 bits
int rand_array[4];
int input_array[4];

void show_7seg(int PC7_v, int PC6_v, int PC5_v, int PC4_v)
{
	ShowSevenSegment(3,PC7_v);	
	ShowSevenSegment(2,PC6_v);
	ShowSevenSegment(1,PC5_v);
	ShowSevenSegment(0,PC4_v);	
}
void showled(void){
    int i;
    for(i=0;i<2;i++){
			PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 	
		
			PC12 =1; PC13 =1;PC14 =1; PC15 =1; // turn on LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 
		}
    PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
}

void showled_delay(void){
    int i;
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
    PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
}

void clear_input(void){
    clear_LCD();
    for(int i = 0; i < 4; i++) {
        input_array[i] = 0;
    }
}

void check_inputarray_randarray(int password_dis){
    int i;
    int match = 1;//set true
    int input_num = 0;//是否input

    for (i = 0; i < 4; i++) {
        if (input_array[i] != 0) {
            input_num = 1;
            break;
        }
    }

    if(input_num == 0) printS(10*8,password_dis,"NULL");

    
    for (i = 0; i < 4; i++) {//CHECK
        if (input_array[i] != rand_array[i]) {
            match = 0;
            break;
        }
    }

    if(match){
        printS(10*8,password_dis,"PASS");
        showled_delay();
    }
    else{
        printS(10*8,password_dis,"ERROR");
        showled();
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
	    keyin = ScanKey();
        
        
		if (keyin != 0) {
			if (flag == 0) {
                if(keyin<7 && count_input < 4){
                    input_array[count_input] = keyin;
                    printC(i*8,password_dis,input_array[i]);
                    count_input++;
                }
                
                for (int i = 0; i < 4; i++) {
                    input_array[i] = keyin;
                    printC(i*8,password_dis,input_array[i]);
                }
				if (keyin == 7) {
                    CloseSevenSegment();
                    //srand(time(NULL));
                    srand(TIMER2->TDR); // 設定時間為亂數種子
                    for (int i = 0; i < 4; i++) {
                        rand_array[i] = rand() % 6 + 1;
                    }
                    show_7seg(rand_array[0], rand_array[1], rand_array[2], rand_array[3]);
                }
				if (keyin == 8) {
                    clear_input();
                    password_dis = 0;
                    count_input = 0;
                }
				if (keyin == 9){
                    check_inputarray_randarray(password_dis);
                    password_dis += 16;
                }
				
				flag = 1;
			}
		} else {
			if (flag == 1) flag = 0;
		}


		//sprintf(Text+8,"%d", keyin); // print scankey input to string			  
		//print_Line(1, Text);         // display string on LCD
		//CLK_SysTickDelay(5000); 	   // delay 																	 
	    
    }

}





//====================
//LED
/*
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"


void showled(void){
    for(i=0;i<2;i++){
			PC12 =0; PC13 =0; PC14 =0; PC15 =0; // turn off LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 	
		
			PC12 =1; PC13 =1;PC14 =1; PC15 =1; // turn on LED
			CLK_SysTickDelay(300000);	 // 0.3Delay 
		}

]


int main(void)
{
	int i;
    SYS_Init(); 
    GPIO_SetMode(PC, (BIT12|BIT13|BIT14|BIT15), GPIO_MODE_OUTPUT);
	
    while(1) {
        
    }

}
*/
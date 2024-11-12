#include <reg51.h>
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
void lcd_init();
void lcd_cmd(unsigned char c);
void lcd_data(unsigned char c);
void string(char *c);
void delay(int c);
void lcd_init(){
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0xc5);
}
void lcd_cmd(unsigned char c){
	P2=c;
	rs=0;
	rw=0;
	en=1;
	delay(10);
	en=0;
}
void lcd_data(unsigned char c){
	P2=c;
	rs=1;
	rw=0;
	en=1;
	delay(10);
	en=0;
}
void string(char *c){
	int k=0;
	while(c[k]!='\0'){
		lcd_data(c[k]);
		k++;
	}
}
void delay(int c){
	int i,j;
	for(i=0;i<c;i++){
		for(j=0;j<1275;j++){
		}
	}
}
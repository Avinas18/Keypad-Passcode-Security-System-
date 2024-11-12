#include <reg51.h>
#include <string.h> 
#include <ulti.h>
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
sbit rc=P3^4;
sbit g=P3^5;
sbit r=P3^6;
char a[]={"1234"};
char b[4];
int n=0;
int val;
int count=0;
void main(){
	rc=g=r=0;
	lcd_init();
	while(1){
		if(n<=3){
		r1=r2=r3=r4=c1=c2=c3=1;
		r1=0;
		if(c1==0){
			lcd_data('1');
			b[n]='1';
			n++;
			delay(50);
		}
		else if(c2==0){
			lcd_data('2');
			b[n]='2';
			n++;
			delay(50);
		}
		else if(c3==0){
			lcd_data('3');
			b[n]='3';
			n++;
			delay(50);
		}
		r1=r2=r3=r4=c1=c2=c3=1;
		r2=0;
		if(c1==0){
			lcd_data('4');
			b[n]='4';
			n++;
			delay(50);
		}
		else if(c2==0){
			lcd_data('5');
			b[n]='5';
			n++;
			delay(50);
		}
		else if(c3==0){
			lcd_data('6');
			b[n]='6';
			n++;
			delay(50);
		}
		r1=r2=r3=r4=c1=c2=c3=1;
		r3=0;
		if(c1==0){
			lcd_data('7');
			b[n]='7';
			n++;
			delay(50);
		}
		else if(c2==0){
			lcd_data('8');
			b[n]='8';
			n++;
			delay(50);
		}
		else if(c3==0){
			lcd_data('9');
			b[n]='9';
			n++;
			delay(50);
		}
		r1=r2=r3=r4=c1=c2=c3=1;
		r4=0;
		if(c1==0){
			lcd_data('*');
			b[n]='*';
			n++;
			delay(50);
		}
		else if(c2==0){
			lcd_data('0');
			b[n]='0';
			n++;
			delay(50);
		}
		else if(c3==0){
			lcd_data('#');
			b[n]='#';
			n++;
			delay(50);
		}
	}
	else {
    val = strncmp(a, b, 4);
    if (val == 0) {
				rc=g=1;
				r=0;
        lcd_cmd(0x80);
        string("Access Granted");
				delay(100);
    } else {
				count++;
				r=1;
				rc=g=0;
        lcd_cmd(0x80);
        string("Access Denied");
				delay(100);
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				string("Try Again");
				n=0;
				lcd_cmd(0xc5);
				if(count>=3){
					lcd_cmd(0x01);
					lcd_cmd(0x85);
					string("Blocked");
					delay(1000);
					lcd_cmd(0x01);
					lcd_cmd(0x80);
					string("Try Again");
					lcd_cmd(0xc5);
				}
    }
    n = 0; // Reset the input count
    memset(b, 0, sizeof(b)); // Clear the password array
}

		
	}
}
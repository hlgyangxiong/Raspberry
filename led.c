#include <stdio.h>
#include <wiringPi.h> 

#define LEDG1	23
#define LEDY1	24
#define LEDR1	25	

#define LEDG2	27
#define LEDY2	28
#define LEDR2	29	

void init(void)
{
    wiringPiSetup() ; 
    pinMode(LEDG1,OUTPUT);
    pinMode(LEDY1,OUTPUT);
    pinMode(LEDR1,OUTPUT);
    pinMode(LEDG2,OUTPUT);
    pinMode(LEDY2,OUTPUT);
    pinMode(LEDR2,OUTPUT);
}

int main(void)
{
    init();
   for(;;)   
  {  
    digitalWrite(LEDG1, HIGH) ;
    digitalWrite(LEDY1, HIGH) ;
    digitalWrite(LEDR1, HIGH) ;
    digitalWrite(LEDG2, HIGH) ;
    digitalWrite(LEDY2, HIGH) ;
    digitalWrite(LEDR2, HIGH) ;
    delay (500) ;  
    digitalWrite(LEDG1,  LOW) ;
    digitalWrite(LEDY1,  LOW) ;
    digitalWrite(LEDR1,  LOW) ; 
    digitalWrite(LEDG2,  LOW) ;
    digitalWrite(LEDY2,  LOW) ;
    digitalWrite(LEDR2,  LOW) ;
    delay (500) ;  
  } 
}

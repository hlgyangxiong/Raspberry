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
    pinMode(LEDG1,OUTPT);
    pinMode(LEDY1,OUTPT);
    pinMode(LEDR1,OUTPT);
    pinMode(LEDG2,OUTPT);
    pinMode(LEDY2,OUTPT);
    pinMode(LEDR2,OUTPT);
}

int main(void)
{
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
    digitalWrite(LEDR2,  LOW) ;delay (500) ;  
  } 
}

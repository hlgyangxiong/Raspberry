#include <stdio.h>
#include <wiringPi.h> 

#define LEDG1	23
#define LEDY1	24
#define LEDR1	25	

#define LEDG2	27
#define LEDY2	28
#define LEDR2	29	

void LED(int number);
void Fan(int number);
void Bell();

void init(void)
{
    wiringPiSetup() ; 
    pinMode(0 ,OUTPUT);
    pinMode(22,OUTPUT);
    
    pinMode(LEDG1,OUTPUT);
    pinMode(LEDY1,OUTPUT);
    pinMode(LEDR1,OUTPUT);
    
    pinMode(LEDG2,OUTPUT);
    pinMode(LEDY2,OUTPUT);
    pinMode(LEDR2,OUTPUT);
    
    LED(1);
    LED(4);
    Fan(0);
    digitalWrite(0,  LOW);
}

int main(void)
{
    init(); 
    Fan(1);
    Bell();
}
void LED(int number)
{
    switch(number)
    {
        case 1: digitalWrite(LEDG1, HIGH);
                digitalWrite(LEDY1,  LOW);
                digitalWrite(LEDR1,  LOW);
                break;
        case 2: digitalWrite(LEDG1, LOW);
                digitalWrite(LEDY1, HIGH);
                digitalWrite(LEDR1, LOW);
                break;
        case 3: digitalWrite(LEDG1, LOW);
                digitalWrite(LEDY1, LOW);
                digitalWrite(LEDR1, HIGH);
                break;
                
        case 4: digitalWrite(LEDG2, HIGH);
                digitalWrite(LEDY2,  LOW);
                digitalWrite(LEDR2,  LOW);
                break;
        case 5: digitalWrite(LEDG2, LOW);
                digitalWrite(LEDY2, HIGH);
                digitalWrite(LEDR2, LOW);
                break;
        case 6: digitalWrite(LEDG2, LOW);
                digitalWrite(LEDY2, LOW);
                digitalWrite(LEDR2, HIGH);
                break;
        case 7: digitalWrite(LEDG2, LOW);
                digitalWrite(LEDY2, HIGH);
                digitalWrite(LEDR2, HIGH);
                break;
        default:break;
    }
}

void Fan(int number)
{
    switch(number)
    {
        case 0: digitalWrite(22,  LOW);
                break;
        case 1: digitalWrite(22, HIGH);
                break;
        default:break;
    }
}

void Bell()
{
    int i;
    for(i = 0; i < 6; i++)
    {
        printf ("the Buzzer will make sound\n");
        digitalWrite(0,  LOW);
        delay (500) ;
        digitalWrite(0, HIGH);
        delay (500) ;
        
    }
}

#include <stdio.h>
#include <wiringPi.h> 
#include <stdlib.h>  
#include <stdint.h>  

#define DHT11_MAX_TIME 40  
#define DHT11PIN 7 

#define LEDG1	23
#define LEDY1	24
#define LEDR1	25	

#define LEDG2	27
#define LEDY2	28
#define LEDR2	29	

int dht11_val[5]={0,0,0,0,0}; 

void init(void);
void LED(int number);
void Fan(int number);
void Bell();
int dht11_read_val();



int main(void)
{
    int i;
    int Humidity    = 0;
    int Temperature = 0;
    float farenheit = 0; 
    
    init(); 
    
    for(i = 0; i < 4; i++)
    {
        if(dht11_read_val(Humidity,Temperature) == 1)
        {
            farenheit=dht11_val[2]*9./5.+32; 
            printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit);
            break;
        }
    }
    

}

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
    for(i = 0; i < 5; i++)
    {
        printf ("the Buzzer will make sound\n");
        digitalWrite(0,  LOW);
        delay (500) ;
        digitalWrite(0, HIGH);
        delay (500) ;
        
    }
}

int dht11_read_val(int Humidity,int Temperature)  
{  
  int counter=0;  
  uint8_t i;  
  //float farenheit = 0;  
  for(i = 0; i < 5; i++)  
     dht11_val[i]=0;  

  pinMode(DHT11PIN,OUTPUT);  
  digitalWrite(DHT11PIN,LOW);  
  delay(18);  
  digitalWrite(DHT11PIN,HIGH);  
  delayMicroseconds(40);  
  pinMode(DHT11PIN,INPUT);  
  while(digitalRead(DHT11PIN)==LOW){ 
    continue; 
  }  
  while(digitalRead(DHT11PIN)==HIGH){ 
    continue; 
  }
             
  for(i=0;i<DHT11_MAX_TIME;i++)  
  {  
    counter=0;  
    while(digitalRead(DHT11PIN)==LOW){
      continue; 
      
    }
    while(digitalRead(DHT11PIN)==HIGH){  
      counter++; 
      delayMicroseconds(1);
      if(counter > 100){
        break;  
      }   
    }
    if(counter < 35){
      dht11_val[i/8] = dht11_val[i/8] + ( 0 << (7-i%8));  
    }
    else{
      dht11_val[i/8] = dht11_val[i/8] + ( 1 << (7-i%8));
    } 
  }
  
  // verify cheksum and print the verified data 
  
  if(dht11_val[4]==((dht11_val[0]+dht11_val[1]+dht11_val[2]+dht11_val[3])& 0xFF)) 
  {  
    farenheit=dht11_val[2]*9./5.+32;  
    //printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit); 
    Humidity    = dht11_val[0];
    Temperature = dht11_val[2];
    return 1;
  }  
  else  
  {
    //printf("Invalid Data!!\n"); 
    return 0;
  }
}

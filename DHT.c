#include <wiringPi.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <stdint.h>  
#define MAX_TIME 40  
#define DHT11PIN 7  
int dht11_val[5]={0,0,0,0,0}; 
int dht11[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  
  
void dht11_read_val()  
{  
  uint8_t counter=0;  
  uint8_t j=0,i;  
  float farenheit = 0;  
  for(i=0;i<5;i++)  
     dht11_val[i]=0;  
  printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit); 

  pinMode(DHT11PIN,OUTPUT);  
  digitalWrite(DHT11PIN,LOW);  
  delay(18);  
  digitalWrite(DHT11PIN,HIGH);  
  delayMicroseconds(40);  
  pinMode(DHT11PIN,INPUT);  
  for(i=0;i<MAX_TIME;i++)  
  {  
    counter=0;  
    while(digitalRead(DHT11PIN)==LOW){
      //printf("counter = %d",counter);        
      continue; 
      
    }
    while(digitalRead(DHT11PIN)==HIGH){  
      counter++; 
      //printf("HIHG");
      if(counter > 200){
        break;  
      }   
    }
     
    if(counter < 32){
      dht11[i] = 0;  
    }
    else{
      dht11[i] = 1;
    } 
  }
  for(i = 0; i<40; i++){
    printf("%d,",dht11[i]);  
  }
  farenheit=dht11_val[2]*9./5.+32;  
  printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit); 
  // verify cheksum and print the verified data 
  //dht11_val[0] = dht11[0]
  if(dht11_val[4]==((dht11_val[0]+dht11_val[1]+dht11_val[2]+dht11_val[3])& 0xFF))  
  {  
    farenheit=dht11_val[2]*9./5.+32;  
    printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit);  
  }  
  else  
    printf("Invalid Data!!\n");  
}  
  
int main(void)  
{  
  printf("Interfacing Temperature and Humidity Sensor (DHT11) With Raspberry Pi\n");  
  if(wiringPiSetup()==-1)  
    exit(1);  
  while(1)  
  {  
     dht11_read_val();  
     delay(3000);  
  }  
  return 0; 
}

#include <wiringPi.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <stdint.h>  
#define MAX_TIME 41  
#define DHT11PIN 7  
int dht11_val[5]={0,0,0,0,0}; 
int dht11[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  
  
void dht11_read_val()  
{  
  int counter=0;  
  uint8_t i;  
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
      delayMicroseconds(1);
      if(counter > 100){
        break;  
      }   
    }
    if(i>=1){ 
      if(counter < 30){
        dht11[i-1] = 0;  
      }
      else{
        dht11[i-1] = 1;
      } 
    }
  }
  
  for(i = 0; i<40; i++){
    printf("%d,",dht11[i]);  
  }
  farenheit=dht11_val[2]*9./5.+32;  
  printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit); 
  // verify cheksum and print the verified data 
  
  dht11_val[0] = dht11[0] + (dht11[1]<<1)+ (dht11[2]<<2)+ (dht11[3]<<3)+ (dht11[4]<<4)+ (dht11[5]<<5)+ (dht11[6]<<6)+ (dht11[7]<<7);
  dht11_val[1] = dht11[8] + (dht11[9]<<1)+ (dht11[10]<<2)+ (dht11[11]<<3)+ (dht11[12]<<4)+ (dht11[13]<<5)+ (dht11[14]<<6)+ (dht11[15]<<7);
  dht11_val[2] = dht11[16] + (dht11[17]<<1)+ (dht11[18]<<2)+ (dht11[19]<<3)+ (dht11[20]<<4)+ (dht11[21]<<5)+ (dht11[22]<<6)+ (dht11[23]<<7);
  dht11_val[3] = dht11[24] + (dht11[25]<<1)+ (dht11[26]<<2)+ (dht11[27]<<3)+ (dht11[28]<<4)+ (dht11[29]<<5)+ (dht11[30]<<6)+ (dht11[31]<<7);
  dht11_val[4] = dht11[32] + (dht11[33]<<1)+ (dht11[34]<<2)+ (dht11[35]<<3)+ (dht11[36]<<4)+ (dht11[37]<<5)+ (dht11[38]<<6)+ (dht11[39]<<7);
 
 //if(dht11_val[4]==((dht11_val[0]+dht11_val[1]+dht11_val[2]+dht11_val[3])& 0xFF)) 
   if(1)
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

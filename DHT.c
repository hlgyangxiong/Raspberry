#include <wiringPi.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <stdint.h>  
#define MAX_TIME 40  
#define DHT11PIN 7  
int dht11_val[5]={0,0,0,0,0}; 
int dht11[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  
  
int dht11_read_val()  
{  
  int counter=0;  
  uint8_t i;  
  float farenheit = 0;  
  for(i=0;i<5;i++)  
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
             
  for(i=0;i<MAX_TIME;i++)  
  {  
    counter=0;  
    while(digitalRead(DHT11PIN)==LOW){
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
    if(counter < 35){
      dht11_val[i/8] <<= 1; 
      //dht11[i] = 0;  
    }
    else{
      dht11_val[i/8] |= 1;
      //dht11[i] = 1;
    } 
  }
  
  for(i = 0; i<40; i++){
    printf("%d,",dht11[i]);  
  }
  // verify cheksum and print the verified data 
  
  //dht11_val[0] = (dht11[0] <<7) + (dht11[1] <<6)+ (dht11[2] <<5)+ (dht11[3] <<4)+ (dht11[4] <<3)+ (dht11[5] <<2)+ (dht11[6] <<1)+ dht11[7 ];
  //dht11_val[1] = (dht11[8] <<7) + (dht11[9] <<6)+ (dht11[10]<<5)+ (dht11[11]<<4)+ (dht11[12]<<3)+ (dht11[13]<<2)+ (dht11[14]<<1)+ dht11[15];
  //dht11_val[2] = (dht11[16]<<7) + (dht11[17]<<6)+ (dht11[18]<<5)+ (dht11[19]<<4)+ (dht11[20]<<3)+ (dht11[21]<<2)+ (dht11[22]<<1)+ dht11[23];
  //dht11_val[3] = (dht11[24]<<7) + (dht11[25]<<6)+ (dht11[26]<<5)+ (dht11[27]<<4)+ (dht11[28]<<3)+ (dht11[29]<<2)+ (dht11[30]<<1)+ dht11[31];
  //dht11_val[4] = (dht11[32]<<7) + (dht11[33]<<6)+ (dht11[34]<<5)+ (dht11[35]<<4)+ (dht11[36]<<3)+ (dht11[37]<<2)+ (dht11[38]<<1)+ dht11[39];
 
  if(dht11_val[4]==((dht11_val[0]+dht11_val[1]+dht11_val[2]+dht11_val[3])& 0xFF)) 
  {  
    farenheit=dht11_val[2]*9./5.+32;  
    printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit);  
    return 1;
  }  
  else  
  {
    //printf("Invalid Data!!\n"); 
    return 0;
  }
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

#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define LED1     0
#define LED2     23

int main (void)
{
  printf ("Raspberry Pi - Gertboard Blink\n") ;

  wiringPiSetup () ;

  pinMode (LED1, OUTPUT) ;
  pinMode (LED2, OUTPUT) ;

  for (;;)
  {
    digitalWrite (LED1, 1) ;     // On
    digitalWrite (LED2, 1) ;
    delay (500) ;               // mS
    digitalWrite (LED1, 0) ;     // Off
    digitalWrite (LED2, 0) ;
    delay (500) ;
  }
  return 0 ;
}

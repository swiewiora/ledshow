#include "../header.h"
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void none ()
{
  int repeat = 2;
  while (repeat) 
  {
  	int i;
  	
    // reset LATCH
    digitalWrite (LATCH, LOW);
    delay(1);

    // turn off all 48 leds (set everything to 0)
    for (i = 0; i < 6; i++) {
    	data[i] = 0x00;
    }

    wiringPiSPIDataRW (SPI_CHAN, data, 6);

    // set latch
    delay(1);
    digitalWrite (LATCH, HIGH);
    repeat --;
  }
}
#include "../header.h"
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void all ()
{
	int i;
	
  // reset LATCH
  digitalWrite (LATCH, LOW);
	delay(1);

  // light up all 48 leds (set everything to 1)
  for (i = 0; i < 6; i++) {
  	data[i] = ~0;
  }

  wiringPiSPIDataRW (SPI_CHAN, data, 6);

  // set latch
  delay(1);
  digitalWrite (LATCH, HIGH);
  delay(1);
}

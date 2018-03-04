
#include "config.h"
#include "../header.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <errno.h>

static int myFd;

int config ()
{
	int resultSetup, result, i;
	unsigned char *config_data;
  if ( (config_data = malloc (CONFIG_SIZE) ) == NULL ||
       (data = malloc (SIZE) ) == NULL || 
       (buffer = malloc (2)) == NULL )  
  {
    fprintf (stderr, "Unable to allocate buffer: %s\n", strerror (errno));
    exit (EXIT_FAILURE);
  }

  resultSetup = wiringPiSetup ();
  if (resultSetup < 0)
  {
  	printf("Failure. Result Setup: %d\n", resultSetup);
  	exit (EXIT_FAILURE);
  }
  
  // set non-SPI bits:
  pinMode (LATCH, OUTPUT); 
  pinMode (BLANK, OUTPUT); 	

  // speed 1 MHz, mode 3
  spiSetup (1e3, 3);

  // wake up
	digitalWrite (LATCH, LOW);
	delay(1);
	digitalWrite (BLANK, HIGH);
	delay(1);
	digitalWrite (BLANK, LOW);

  config_data[0] = 0x01;
  config_data[1] = 0x96;
  config_data[2] = 0x00;
  config_data[3] = 0x24;
  config_data[4] = 0xFF;
  config_data[5] = 0xFF;
  config_data[6] = 0xF8;

  wiringPiSPIDataRW(0, config_data, CONFIG_SIZE);

  digitalWrite (LATCH, LOW); //?
	delay(1); //?
  digitalWrite (LATCH, HIGH);
	delay(1);
  digitalWrite (LATCH, LOW);
	delay(1);

  return 0;
}	

void spiSetup (int speed, int mode)
{
  if ((myFd = wiringPiSPISetupMode (SPI_CHAN, speed, mode)) < 0)
  {
    fprintf (stderr, "Can't open the SPI bus: %s\n", strerror (errno));
    exit (EXIT_FAILURE);
  }
}

void quit ()
{
  int repeat = 2;
  while (repeat) 
  {
    int i;
    digitalWrite (LATCH, LOW);
    delay(1);

    for (i = 0; i < SIZE; i++) {
      data[0] = 0;
    }

    wiringPiSPIDataRW(0, data, 6);

    delay(1);
    digitalWrite (LATCH, HIGH);
    repeat --;
  }
}
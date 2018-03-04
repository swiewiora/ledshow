#include "../lib/itoa.h"
#include "../header.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <errno.h>
#include <string.h>

void choice ()
{
	int i;

	delay(1);
	digitalWrite (LATCH, LOW);

	for (i = 0; i < SIZE; i++) {
		data[i] = 0;
	}

	char * tmp_data;

	if ( (tmp_data = malloc (CONFIG_SIZE) ) == NULL )
  {
    fprintf (stderr, "Unable to allocate buffer: %s\n", strerror (errno));
    exit (EXIT_FAILURE);
  }

	// Set up bit sequence to light up desired led
	for (i = 0; i < SIZE; i++) {
		printf("Enter value for %d set: ", i + 1);
		scanf("%x", &tmp_data[i]);
		memcpy(data, tmp_data, SIZE * sizeof *data);

		wiringPiSPIDataRW(0, data, SIZE);

		delay(1);
		digitalWrite (LATCH, HIGH);
		delay(1);
		digitalWrite (LATCH, LOW);
	}
	
  for (i = SIZE-1; i >= 0; i--) {
  	itoa (tmp_data[i], buffer, 2);
  	printf ("%08s ", buffer);
  }
  printf("\n");
}	
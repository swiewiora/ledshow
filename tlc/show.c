#include "../header.h"
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void * show(void *arg_pointer)
{
	volatile uint64_t number = 0;
	uint8_t i = 0, state = 0, count = 0, repeat = 0, j;


	int * set = (int *) arg_pointer;

	// infinite loop
	while (1) {

		number = (1 << 0) + (1 << 12) + (1 << 24) + (1ULL << 36);
		i = 0;
		state = 0;
		
		//repeat = 0;
		while (* set == 1) {
			number = number << 1;
			if ((number & (1ULL << 48)) != 0)
				number = (number & 0xFFFFFFFFFFFF) + 1;

			delay(i);

			data[0] = (number >> 40) & 0xFF;
			data[1] = (number >> 32) & 0xFF;
			data[2] = (number >> 24) & 0xFF;
			data[3] = (number >> 16) & 0xFF;
			data[4] = (number >> 8) & 0xFF;
			data[5] = (number >> 0) & 0xFF;
			
			wiringPiSPIDataRW(0, data, 6);

			delay(1);
			digitalWrite (LATCH, HIGH);
			delay(1);
			digitalWrite (LATCH, LOW);
			
			if (count++ > 3) {
				count = 0;
				if (state == 0) {
					i++;
					if (i > 20)
						state = 1;
				} else {
					i--;
					if (i < 2)
						state = 0;
				}
			}
			//repeat++;
		}
		
		//delay(500);

	
		number = 0;
		state = 0;
		i = 0;
	
		//repeat = 0;
		while (*set == 2) {

			if (state == 0) {
				number |= (1ULL << (24 + i)) | (1ULL << (24 - 1 - i));
				delay(10);

				data[0] = (number >> 40) & 0xFF;
				data[1] = (number >> 32) & 0xFF;
				data[2] = (number >> 24) & 0xFF;
				data[3] = (number >> 16) & 0xFF;
				data[4] = (number >> 8) & 0xFF;
				data[5] = (number >> 0) & 0xFF;

				wiringPiSPIDataRW(0, data, 6);
				
				delay(1);
				digitalWrite (LATCH, HIGH);
				delay(1);
				digitalWrite (LATCH, LOW);

				if (i < 23)
					i++;
				else
					state = 1;
			} else {
				number &= ~((1ULL << (24 + i)) | (1ULL << (24 - i - 1)));
				delay(10);

				data[0] = (number >> 40) & 0xFF;
				data[1] = (number >> 32) & 0xFF;
				data[2] = (number >> 24) & 0xFF;
				data[3] = (number >> 16) & 0xFF;
				data[4] = (number >> 8) & 0xFF;
				data[5] = (number >> 0) & 0xFF;
				
				wiringPiSPIDataRW(0, data, 6);

				delay(1);
				digitalWrite (LATCH, HIGH);
				delay(1);
				digitalWrite (LATCH, LOW);

				if (i > 0)
					i--;
				else
					state = 0;
			}
			//repeat++;
		}

		//delay(500);

		number = 0;
		state = 0;
		i = 0;

		//repeat = 0;
		while (*set == 3) {

			if (state == 0) {
				number = (1ULL << (24 + i)) | (1ULL << (24 - 1 - i));
				delay(10);

				data[0] = (number >> 40) & 0xFF;
				data[1] = (number >> 32) & 0xFF;
				data[2] = (number >> 24) & 0xFF;
				data[3] = (number >> 16) & 0xFF;
				data[4] = (number >> 8) & 0xFF;
				data[5] = (number >> 0) & 0xFF;
				
				wiringPiSPIDataRW(0, data, 6);

				delay(1);
				digitalWrite (LATCH, HIGH);
				delay(1);
				digitalWrite (LATCH, LOW);

				if (i < 23)
					i++;
				else
					state = 1;
			} else {
				number = (1ULL << (24 + i)) | (1ULL << (24 - i - 1));
				delay(1);

				data[0] = (number >> 40) & 0xFF;
				data[1] = (number >> 32) & 0xFF;
				data[2] = (number >> 24) & 0xFF;
				data[3] = (number >> 16) & 0xFF;
				data[4] = (number >> 8) & 0xFF;
				data[5] = (number >> 0) & 0xFF;
				
				wiringPiSPIDataRW(0, data, 6);

				delay(1);
				digitalWrite (LATCH, HIGH);
				delay(1);
				digitalWrite (LATCH, LOW);

				if (i > 0)
					i--;
				else
					state = 0;
			}
			//repeat++;
		}

		//delay(500);

		number = 0;
		state = 0;
		i = 0;

		//repeat = 0;
		while (*set == 4) {

			if (state == 0) {
				number |= (1ULL << (12 + i)) | (1ULL << (12 - 1 - i))
						| (1ULL << (24 + i)) | (1ULL << (24 - 1 - i))
						| (1ULL << (36 + i)) | (1ULL << (36 - 1 - i))
						| (1ULL << (0 + i)) | (1ULL << (48 - 1 - i));
				delay(10);

				data[0] = (number >> 40) & 0xFF;
				data[1] = (number >> 32) & 0xFF;
				data[2] = (number >> 24) & 0xFF;
				data[3] = (number >> 16) & 0xFF;
				data[4] = (number >> 8) & 0xFF;
				data[5] = (number >> 0) & 0xFF;
				
				wiringPiSPIDataRW(0, data, 6);

				delay(1);
				digitalWrite (LATCH, HIGH);
				delay(1);
				digitalWrite (LATCH, LOW);

				if (i < 5)
					i++;
				else
					state = 1;

			} else {
				number &= ~((1ULL << (12 + i)) | (1ULL << (12 - 1 - i))
						| (1ULL << (24 + i)) | (1ULL << (24 - 1 - i))
						| (1ULL << (36 + i)) | (1ULL << (36 - 1 - i))
						| (1ULL << (0 + i)) | (1ULL << (48 - 1 - i)));
				delay(30);

				data[0] = (number >> 40) & 0xFF;
				data[1] = (number >> 32) & 0xFF;
				data[2] = (number >> 24) & 0xFF;
				data[3] = (number >> 16) & 0xFF;
				data[4] = (number >> 8) & 0xFF;
				data[5] = (number >> 0) & 0xFF;
				
				wiringPiSPIDataRW(0, data, 6);

				delay(1);
				digitalWrite (LATCH, HIGH);
				delay(1);
				digitalWrite (LATCH, LOW);

				if (i > 0)
					i--;
				else
					state = 0;
			}
			//repeat++;
		}

		//delay(500);
	}
}

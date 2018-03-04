#pragma once

#include <pthread.h>

#define	SPI_CHAN		0
#define CONFIG_SIZE	7 // 7 * 8 = 56 bits
#define SIZE        6 // 6 * 8 = 48 bits
#define LATCH				2 // GPIO5 - Data Latch
#define BLANK				3 // GPIO6 - BLANK Signal

#define clear() printf("\033[H\033[J")

unsigned char *data, *buffer;

void all ();
void none ();
void * show ();
void choice ();

void quit ();
void thread_controller (void *);

// Mutex
pthread_mutex_t	spi;
// Thread
pthread_t thread;

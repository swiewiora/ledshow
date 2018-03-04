#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int main (int argc, char *argv[]) {

	config();

	// Mutex stuff
	pthread_mutexattr_t mutexattr;
	pthread_mutexattr_init(&mutexattr);
	pthread_mutex_init(&spi, &mutexattr);

	// Pthread stuff
	pthread_attr_t attr;
	pthread_attr_init( &attr );

	menu();

	return EXIT_SUCCESS;
}

#include "header.h"
#include "config/config.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void thread_controller (void * function) {

	int set = 1;
	pthread_create (&thread, NULL, function, (void *) &set);

	int c = 0;
	clear ();
	do {

		printf ("  1 set\n");
		printf ("  2 set\n");
		printf ("  3 set\n");
		printf ("  4 set\n");
		printf ("  0 - cancel\n");
		printf ("  ==================\n");
		printf ("  choose an option: ");
		scanf ("%d", &c);
		printf ("\n");

		switch (c)
		{
			case 0:
				pthread_cancel(thread);
				quit();
			break;

			case 1:
				set = 1;
			break;
			
			case 2:
				set = 2;
			break;
			
			case 3:
				set = 3;
			break;

			case 4:
				set = 4;
			break;

			default: printf ("%d is not a correct choice.\n", c);

			printf ("\n");
		}
	} while (c != 0);
}
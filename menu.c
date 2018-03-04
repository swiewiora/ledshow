#include "header.h"
#include "config/config.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void menu ()
{
	int selection = -1;

	clear ();
	printf ("  ===========================================\n");
	printf ("  | Real Time Operating Systems - LED Show  |\n");
	printf ("  | Sebastian Wiewiora, VSB FEI 2016/2017   |\n");
	printf ("  ===========================================\n");
	
	do
	{
		clear ();
		printf ("  MAIN MENU\n");
		printf ("  ==================\n");
		printf ("  1 - all\n");
		printf ("  2 - none\n");
		printf ("  3 - led show\n");
		printf ("  4 - choice\n\n");
	
		printf ("  0 - end\n");
		printf ("  ==================\n");
		printf ("  choose an option: ");
		scanf ("%d", &selection);
		printf ("\n");
		
		switch (selection)
		{
			case 1:
				all();
			break;

			case 2:
				none();
			break;
			
			case 3:
				thread_controller (show);
			break;
			
			case 4:
				choice();
			break;

			case 0:
				quit ();
				printf ("bye ;)\n");
			break;

			default: printf ("%d is not a correct choice.\n", selection);

			printf ("\n");
		}

	} while ( selection != 0 );
}
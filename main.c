#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "data.h"




int main (int argc ,char **argv) {

	if (OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}


	init_display(argc , argv , NULL);
	MainLoop ();
	return EXIT_SUCCESS;
}
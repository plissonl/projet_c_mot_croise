#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"


int main (int argc ,char **argv) {
	

	if (OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}

	char mat_joueur[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			mat_joueur[i][j]='0';
		}

	}
	mat_joueur[0][0]=' ';



	init_display(argc , argv , mat_joueur);
	MainLoop ();
	return EXIT_SUCCESS;
}
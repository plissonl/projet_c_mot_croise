#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"


int main (int argc ,char **argv) {
	ValeurCourante *data;
	data=malloc(sizeof(ValeurCourante));


	if (OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}

	init_matrice_resultat(data);
	init_display(argc , argv , NULL);
	
	afficherGrille(NB_COLONNES,data->matrice_resultat);
	MainLoop ();
	free(data);
	return EXIT_SUCCESS;
}

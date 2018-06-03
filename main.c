#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"


int main (int argc ,char **argv) {
	char matrice_resultat[NB_LIGNES][NB_COLONNES];


	if (OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}

	init_matrice_resultat(NB_COLONNES, matrice_resultat);
	init_display(argc , argv , NULL);
	
	afficherGrille(NB_COLONNES,matrice_resultat);
	MainLoop ();

	return EXIT_SUCCESS;
}

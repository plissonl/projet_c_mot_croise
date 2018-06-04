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
	init_matrice_joueur(data);
	init_display(argc , argv , data);
	
	afficherGrille(NB_COLONNES,data->matrice_resultat);
	afficherGrille(NB_COLONNES,data->matrice_joueur);

	MainLoop ();
	afficherGrille(NB_COLONNES,data->matrice_joueur);
	free(data);

	return EXIT_SUCCESS;
}

#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"


int main (int argc ,char **argv) {
	FILE *fichier;
	ValeurCourante *data;
	data=malloc(sizeof(ValeurCourante));
	initListeChaine(data);
	


	if (OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}
	// On regarde si une sauvegarde existe, sinon, on initialise pour la grille 1
	if ((fichier=fopen("save.txt","r"))==NULL) {   //on teste l'existence ou la bonne ouverture de de save.txt
		init_fichier(data);
		init_matrice_resultat(data);
		init_matrice_joueur(data);
	}
	else {   // ie le fichier existe
		fclose(fichier);  // on le ferme
		charger_grille(data);
		init_matrice_resultat(data);	

	}
	
	init_display(argc , argv , data);
	
	MainLoop ();

	free(data);

	return EXIT_SUCCESS;
}

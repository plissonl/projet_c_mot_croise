#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"


int main (int argc ,char **argv) {
	FILE *fichier;
	ValeurCourante *data;
	data=malloc(sizeof(ValeurCourante));


	if (OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}
	// On regarde si une sauvegarde existe, sinon, on initialise pour la grille 1
	if ((fichier=fopen("save.txt","r"))==NULL) {   //on teste l'existence ou la bonne ouverture de de save.txt
		data->NomGrille="grille1.txt";
		data->NomDefinitions="definitions1.txt";
		init_matrice_resultat(data);
		init_matrice_joueur(data);
	}
	else {   // ie le fichier existe
		fclose(fichier);
		charger_grille(data);
		init_matrice_resultat(data);	

	}
	
	init_display(argc , argv , data);
	
	//afficherGrille(12,data->matrice_resultat);
	//afficherGrille(12,data->matrice_joueur);

	MainLoop ();
	//afficherGrille(12,data->matrice_joueur);
	free(data);

	return EXIT_SUCCESS;
}

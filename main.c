#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"
#include<io.h>


int main (int argc ,char **argv) {

	ValeurCourante *data;
	data=malloc(sizeof(ValeurCourante));


	if (OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}

	// On regarde si une sauvegarde existe, sinon, on initialise pour la grille 1
	if (access("save.txt",F_OK)) {  //fonction de la bibiothèque io.h permettant de tester l'existence d'un fichier (renvoi 0 si le fichier n'existe pas)
		charger_grille(data);
		init_matrice_resultat(data);		
	}
	else {
		data->NomGrille="grille1.txt";
		data->NomDefinitions="definitions1.txt";
		init_matrice_resultat(data);
		init_matrice_joueur(data);
	}
	
	init_display(argc , argv , data);
	
	afficherGrille(12,data->matrice_resultat);
	afficherGrille(12,data->matrice_joueur);
	printf("hello1\n");

	MainLoop ();
	printf("hello2\n");
	afficherGrille(12,data->matrice_joueur);
	free(data);

	return EXIT_SUCCESS;
}

#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"


int main (int argc ,char **argv) {

	ValeurCourante *data;
	data=malloc(sizeof(ValeurCourante));
	initListeChaine(data->l,data);
	//data->l=malloc(sizeof(LISTE));
	//data->l->tete=malloc(sizeof(struct noeud ));
	//data->l->tete=NULL;
	//data->l->longueur=0;


	if (OpenDisplay(argc , argv) == 0) {
		fprintf(stderr ,"Can’t open  display\n");
		return EXIT_FAILURE;
	}

	data->NomGrille="grille1.txt";
	data->NomDefinitions="definitions1.txt";
	init_matrice_resultat(data);
	init_matrice_joueur(data);
	
	init_display(argc , argv , data);
	
	afficherGrille(NB_COLONNES,data->matrice_resultat);
	afficherGrille(NB_COLONNES,data->matrice_joueur);
	printf("hello1\n");

	MainLoop ();
	printf("hello2\n");
	afficherGrille(NB_COLONNES,data->matrice_joueur);
	free(data);

	return EXIT_SUCCESS;
}

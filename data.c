#include "callbacks.h"
#include "data.h"
#include <time.h>


void init_fichier(ValeurCourante *d) {
	int numFichier;
	int num_min=1;
	int num_max=1;
	srand(time(NULL));
	numFichier=rand()%(num_max+1-num_min)+num_min ; // on génère un entier aléatoire compris entre num_min et num_max.
	switch(numFichier) {  // choix aléatoire de la grille de lecture
		case 1 : d->NomGrille="grille1.txt"; d->NomDefinitions="definitions1.txt"; break;
		case 2 : d->NomGrille="grille2.txt"; d->NomDefinitions="definitions2.txt"; break;
		case 3 : d->NomGrille="grille3.txt"; d->NomDefinitions="definitions3.txt"; break;
	}
}



/* Procédure initialisant la matrice appelée matrice_resultat */
void init_matrice_resultat(ValeurCourante *d) {
	FILE *fichier;
	int i=0 ,j=0;
	int c;
	init_fichier(d);
	if ((fichier=fopen(d->NomGrille,"r"))==NULL) {  //ouverture du fichier
		perror(d->NomGrille);
		exit(1);
	}
	while ((c=fgetc(fichier))!=EOF) { //lecture du caractère
		if (isalpha(c) || c==' ') {
			d->matrice_resultat[i][j]=c;
			j++;
		}
		else if (c=='\n') { // si fin de ligne
			j=0;
			i++;
		}
		else {
			printf ("erreur sur le fichier texte\n");
			exit(1);  //possibilité d'ajout d'autres erreurs par exemple sur la longueur
		}
	}


	fclose(fichier);
}

void afficherGrille(int taille,char mat[][taille]){ //affichage de test
    printf("\n");
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            printf(" |%c",mat[i][j]);

        }
        printf("\n");
    }
}



void init_display(int argc ,char **argv, ValeurCourante *d){
	Widget Zone_grille, boutonQuitter, ZoneDefinitions;
	Zone_grille=MakeDrawArea(LARGEUR+LARGEUR/NB_LIGNES,HAUTEUR+HAUTEUR/NB_COLONNES, redisplay,d); 
	boutonQuitter = MakeButton ("Quit", quit, NULL);
	ZoneDefinitions = MakeTextWidget(d->NomDefinitions, TRUE, FALSE, 900, 400);
	
	SetWidgetPos (boutonQuitter, PLACE_UNDER, Zone_grille, NO_CARE, NULL);
	SetWidgetPos (ZoneDefinitions, PLACE_RIGHT, Zone_grille, NO_CARE, NULL);
	SetButtonDownCB(Zone_grille,clique); 
	SetKeypressCB(Zone_grille,rentrer_caractere); 
	GetStandardColors();
	ShowDisplay();
	printf("hello\n");


}


void init_matrice_joueur(ValeurCourante *data){


	for(int i=0;i<NB_LIGNES;i++){
		for(int j=0;j<NB_COLONNES;j++){


			if(data->matrice_resultat[i][j]==' '){

				data->matrice_joueur[i][j]=' ';

			}
			else 
				data->matrice_joueur[i][j]='0';

		}
	}
}




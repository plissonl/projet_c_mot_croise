#include "callbacks.h"
#include "data.h"


/* Procédure initialisant la matrice appelée matrice_resultat */
void init_matrice_resultat(int taille,char mat[][taille]) {
	FILE *fichier;
	char * NomFichier;
	int numFichier =1;
	int i=0 ,j=0;
	int c;
	//faire aléatoire numFichier
	switch(numFichier) {  // choix aléatoire de la grille de lecture
		case 1 : NomFichier="grille1.txt"; break;
		case 2 : NomFichier="grille2.txt"; break;
		case 3 : NomFichier="grille3.txt"; break;
	}
	if ((fichier=fopen(NomFichier,"r"))==NULL) {  //ouverture du fichier
		perror(NomFichier);
		exit(1);
	}
	while ((c=fgetc(fichier))!=EOF) { //lecture du caractère
		if (isalpha(c) || c==' ') {
			mat[i][j]=c;
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


void init_display(int argc ,char **argv, void *d){
	Widget Zone_grille, boutonQuitter;
	Zone_grille=MakeDrawArea(LARGEUR,HAUTEUR, redisplay,NULL); 
	boutonQuitter = MakeButton ("Quit", quit, NULL);
	SetWidgetPos (boutonQuitter, PLACE_UNDER, Zone_grille, NO_CARE, NULL);

	SetButtonDownCB(Zone_grille,clique); 
	SetKeypressCB(Zone_grille,rentrer_caractere); 
	GetStandardColors();
	ShowDisplay();


}



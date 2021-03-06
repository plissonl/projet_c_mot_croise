#include "callbacks.h"
#include "data.h"
#include <time.h>
#define tailleZoneVerif 200
#define BN_MAX 20



/* Procédure initialisant la matrice appelée matrice_resultat */
void init_matrice_resultat(ValeurCourante *d) {
	FILE *fichier;
	int i=0 ,j=0;
	int c;
	if ((fichier=fopen(d->NomGrille,"r"))==NULL) {  //ouverture du fichier
		perror(d->NomGrille);
		exit(1);
	}
		
	// premiere lecture du fichier, pour trouver NB_LIGNES et NB_COLONNES
	while ((c=fgetc(fichier))!=EOF) { //lecture du caractère
		if (isalpha(c) || c==' ') {
			j++;
		}
		else if (c=='\n') { // si fin de ligne
			d->NB_COLONNES=j;  //nécessite qu'il n'y ai pas de lignes vide à la fin du fichier
			j=0;
			i++;
		}
		else {
			printf ("erreur sur le fichier texte\n");
			exit(1);  //possibilité d'ajout d'autres erreurs par exemple sur la longueur
		}
	}
	d->NB_LIGNES=i;
	printf("lignes=%d  colonnes=%d \n",d->NB_LIGNES,d->NB_COLONNES );
	// allocation dynamique de la matrice résultat
	d->matrice_resultat=malloc(sizeof(char*)*d->NB_LIGNES);
	for (int ligne=0; ligne<d->NB_LIGNES; ligne++) {
		d->matrice_resultat[ligne] = malloc(sizeof(char)*d->NB_COLONNES);
	}

	rewind(fichier);  //on se remet au début du fichier
	i=0;
	while ((c=fgetc(fichier))!=EOF) { //lecture du caractère
		if (isalpha(c) || c==' ') {
			d->matrice_resultat[i][j]=c;
			j++;
		}
		else if (c=='\n') { // si fin de ligne
			j=0;
			i++;
		}
	}


	fclose(fichier);
}


void afficherGrillej(ValeurCourante *d){ //affichage de test
    printf("\n");

    for(int i=0;i<d->NB_LIGNES;i++){
        for(int j=0;j<d->NB_COLONNES;j++){
            printf(" |%c",d->matrice_joueur[i][j]);

        }
        printf("\n");
    }
}

void afficherGriller(ValeurCourante *d){ //affichage de test
    printf("\n");

    for(int i=0;i<d->NB_LIGNES;i++){
        for(int j=0;j<d->NB_COLONNES;j++){
            printf(" |%c",d->matrice_resultat[i][j]);

        }
        printf("\n");
    }
}


void initListeChaine(ValeurCourante *d){
	d->l=malloc(sizeof(LISTE));
	d->l->tete=malloc(sizeof(struct noeud ));
	d->l->longueur=0;

}


void init_display(int argc ,char **argv, ValeurCourante *d){

	
	Widget Zone_grille, boutonQuitter, ZoneDefinitions, boutonVerifier, ChoixGrille, boutonSauvegarde;
	Zone_grille=MakeDrawArea(LARGEUR+LARGEUR/d->NB_COLONNES,HAUTEUR+HAUTEUR/d->NB_LIGNES, redisplay,d); 
	boutonQuitter = MakeButton ("Quitter", quit, NULL);
	ZoneDefinitions = MakeTextWidget(d->NomDefinitions, TRUE, FALSE, 900, 400);
	ChoixGrille=MakeMenu("Choix de la grille");
	boutonSauvegarde=MakeButton("Sauvegarder", sauvegarder, d);
	boutonVerifier= MakeButton("Verifier",Verifier,d);


	MakeMenuItem(ChoixGrille,"Grille 1",choix_grille1,d);
	MakeMenuItem(ChoixGrille,"Grille 2",choix_grille2,d);
	MakeMenuItem(ChoixGrille,"Grille 3",choix_grille3,d);
	SetButtonDownCB(Zone_grille,clique); 
	SetKeypressCB(Zone_grille,rentrer_caractere); 

	

	
	
	SetWidgetPos (ZoneDefinitions, PLACE_RIGHT, Zone_grille, NO_CARE, NULL);
	SetWidgetPos (ChoixGrille,PLACE_RIGHT,Zone_grille,PLACE_UNDER,ZoneDefinitions);
	SetWidgetPos (boutonVerifier,PLACE_RIGHT,Zone_grille,PLACE_UNDER,ChoixGrille);
	SetWidgetPos (boutonSauvegarde,PLACE_RIGHT,Zone_grille,PLACE_UNDER,boutonVerifier);
	SetWidgetPos (boutonQuitter, PLACE_RIGHT, Zone_grille, PLACE_UNDER, boutonSauvegarde);


	GetStandardColors();

	ShowDisplay();



}


void init_matrice_joueur(ValeurCourante *d){
	// allocation dynamique de la matrice joueur
	// allocation du nombre de lignes
	d->matrice_joueur=malloc(sizeof(char*)*d->NB_LIGNES);
		// allocation du nombre de colonnes
	for (int ligne=0; ligne<d->NB_LIGNES; ligne++) {
		d->matrice_joueur[ligne] = malloc(sizeof(char)*d->NB_COLONNES);
	}

	for(int i=0;i<d->NB_LIGNES;i++){
		for(int j=0;j<d->NB_COLONNES;j++){


			if(d->matrice_resultat[i][j]==' '){

				d->matrice_joueur[i][j]=' ';

			}
			else 
				d->matrice_joueur[i][j]='0';

		}
	}
	afficherGrillej(d);
}

void charger_grille(ValeurCourante *d) {
	FILE *fichier;
	int c;
	int i=0, j=0 ;
	if ((fichier=fopen("save.txt","r"))==NULL) {  //ouverture du fichier en mode lecture
		perror("save.txt");
		exit(1);
	}
	switch(c=fgetc(fichier)) {
		case '1' : d->NomGrille="grille1.txt"; d->NomDefinitions="definitions1.txt"; break;
		case '2' : d->NomGrille="grille2.txt"; d->NomDefinitions="definitions2.txt"; break;
		case '3' : d->NomGrille="grille3.txt"; d->NomDefinitions="definitions3.txt"; break;
	}
	c=fgetc(fichier);   // lecture du \t	
	d->NB_LIGNES=fgetc(fichier);
	c=fgetc(fichier);   // lecture du \t
	d->NB_COLONNES=fgetc(fichier);
	c=fgetc(fichier);	//lecture du \n 
	// allocation dynamique des tableaux de char à deux dimensions
	// allocation du nombre de lignes
	d->matrice_joueur=malloc(sizeof(char*)*d->NB_LIGNES);
	// allocation du nombre de colonnes
	for (int ligne=0; ligne<d->NB_LIGNES; ligne++) {
		d->matrice_joueur[ligne] = malloc(sizeof(char)*d->NB_COLONNES);
	}
	while ((c=fgetc(fichier))!=EOF) { //lecture du caractère
		if (isalpha(c) || c==' ' || c=='0') {
			d->matrice_joueur[i][j]=c;
			j++;
		}
		else if (c=='\n') { // si fin de ligne
			j=0;
			i++;
		}
		else {
			printf ("erreur sur le fichier texte save.txt\n");
			exit(1);  //possibilité d'ajout d'autres erreurs par exemple sur la longueur
		}
	}
	fclose(fichier);
}

void init_fichier(ValeurCourante *d) {
		d->NomGrille="grille1.txt";
		d->NomDefinitions="definitions1.txt";
}

#include "callbacks.h"
#include "data.h"

#include <ctype.h>

// Il faut ajouter +pas ligne et +pas colonne à chaque truc utilisant i ou j ou trouver un moyen de le faire automatiquement.

int abscisse,ordonnee; // on peut faire une structure coordonnées ,abscisse,ordonne= coordonnee matrice

//int pas_ligne=LARGEUR/d->NB_LIGNES;
//int pas_colonne=HAUTEUR/d->NB_COLONNES;



void  redisplay(Widget w, int width, int height, void *data){ // fcontion 
	ValeurCourante *d=data;
	int pas_ligne=LARGEUR/d->NB_LIGNES;
	int pas_colonne=HAUTEUR/d->NB_COLONNES;
	for(int i=0;i<d->NB_LIGNES;i++){
		for(int j=0;j<d->NB_COLONNES;j++){

			if(d->matrice_joueur[j][i]==' '){
				DrawFilledBox(i*pas_ligne+pas_ligne+2,j*pas_colonne+pas_colonne+2,pas_ligne-4,pas_colonne-4);
			}
			else if(d->matrice_joueur[j][i]=='0') {
				DrawText(" ",i*pas_ligne+pas_ligne/2,j*pas_colonne+pas_colonne/2);
			}
			else {
				DrawText(d->matrice_joueur[j][i],i*pas_ligne+pas_ligne/2,j*pas_colonne+pas_colonne/2);
			}
		}
	} 
	
	for(int i=0;i<d->NB_LIGNES+1;i++){
		DrawLine( i*pas_ligne+pas_ligne,pas_ligne,i*pas_ligne+pas_ligne,LARGEUR+pas_ligne);
	}
	
	for(int i=0;i<d->NB_COLONNES+1;i++){
		DrawLine(pas_colonne,i*pas_colonne+pas_colonne,HAUTEUR+pas_colonne,i*pas_colonne+pas_colonne);

	}
	for(int num_ligne=1; num_ligne<d->NB_LIGNES+1;num_ligne++) {
		char numl[3];
		sprintf(numl,"%d",num_ligne);
		DrawText(numl,(num_ligne+1)*pas_ligne-pas_ligne/2,pas_colonne/2);
	}
	for(int num_colonne=1; num_colonne<d->NB_COLONNES+1;num_colonne++) {
		char numc[3];
		sprintf(numc,"%d",num_colonne);
		DrawText(numc,pas_ligne/2,(num_colonne+1)*pas_colonne-pas_colonne/2);

	}
}



void selectionne(int j,int i,int couleur,void *data){    // i et j représente les coordonéees matricielles
	ValeurCourante *d=data;
	int pas_ligne=LARGEUR/d->NB_LIGNES;
	int pas_colonne=HAUTEUR/d->NB_COLONNES;
	SetColor(couleur);
	if(i>=1&& j>=1){	
	DrawBox(j*pas_ligne+1,i*pas_colonne+1,pas_ligne-2,pas_colonne-2);
	DrawBox(j*pas_ligne+2,i*pas_colonne+2,pas_ligne-4,pas_colonne-4);
	abscisse=j;
	ordonnee=i;
	printf("%d %d\n",i,j);
	}
	SetColor(BLACK);

}



void deSelectionner(int j,int i,void *data){
	ValeurCourante *d=data;
	int pas_ligne=LARGEUR/d->NB_LIGNES;
	int pas_colonne=HAUTEUR/d->NB_COLONNES;
	SetColor(WHITE);
	DrawBox(j*pas_ligne+1,i*pas_colonne+1,pas_ligne-2,pas_colonne-2);
	DrawBox(j*pas_ligne+2,i*pas_colonne+2,pas_ligne-4,pas_colonne-4);
	SetColor(BLACK);
}

void  clique(Widget w,int a,int x,int y,void *data){
	ValeurCourante *d=data;
	int pas_ligne=LARGEUR/d->NB_LIGNES;
	int pas_colonne=HAUTEUR/d->NB_COLONNES;
	deSelectionner(abscisse,ordonnee,d);
	abscisse=x/pas_ligne;
	ordonnee=y/pas_colonne;

	selectionne(abscisse,ordonnee,BLUE,d);

}




void rentrer_caractere(Widget w,char *input,int up_or_down, void *d){
	ValeurCourante *data=d;
	int pas_ligne=LARGEUR/data->NB_LIGNES;
	int pas_colonne=HAUTEUR/data->NB_COLONNES;
	int x_milieu,y_milieu;
	x_milieu=0.5*(abscisse+(abscisse+1))*pas_colonne;
	y_milieu=0.5*(ordonnee+(ordonnee+1))*pas_ligne;


	if(up_or_down==1)
	{
		if(*input>=97 && abscisse>=1 && ordonnee >=1 &&*input<=122 && !*(input+1) && data->matrice_joueur[ordonnee-1][abscisse-1]!=' ')  //lettre minuscule et le second element correpond au caractere de fin de chaine de caracter donc pas Up ou Down
				{
					*input=toupper(*input);
					DrawText(input,x_milieu,y_milieu);
					data->matrice_joueur[ordonnee-1][abscisse-1]=*input;   //Les -1 sont liés aux affichage des numéros de lignes et de colonnes décalants la grille
					afficherGrille(data->NB_COLONNES,data->matrice_joueur);


				}
		else if (*input>=65 && abscisse>=1 && ordonnee>=1 && *input<=90 && !*(input+1) && data->matrice_joueur[ordonnee-1][abscisse-1]!= ' ') // lettre majuscule
				{
					DrawText(input,x_milieu,y_milieu);
					data->matrice_joueur[abscisse-1][ordonnee-1]=*input;
		
				}
		else 
		{

			switch(*input)
			{
				case 'U':	// touche Up
					deSelectionner(abscisse,ordonnee,data);
					selectionne(abscisse,ordonnee-1,BLUE,data);
					break;
				case 'L': // touche Left
					deSelectionner(abscisse,ordonnee,data);
					selectionne(abscisse-1,ordonnee,BLUE,data);
					break;
				case 'R'://touche right
					deSelectionner(abscisse,ordonnee,data);
					selectionne(abscisse+1,ordonnee,BLUE,data);
					break;
				case 'D': //Down
					deSelectionner(abscisse,ordonnee,data);
					selectionne(abscisse,ordonnee+1,BLUE,data);
					break;
				case 8: // touche backspace

					*input=' ';
					DrawText(input,x_milieu,y_milieu);
					data->matrice_joueur[ordonnee-1][abscisse-1]='0';

					//deSelectionner(abscisse,ordonnee);
					//selectionne(abscisse,ordonnee+1);
					break;
				default:
					printf("erreur sur l'entree standard\n "); // changer le message d'erreur en un widget
					break;
			}

		}
	}
}

void Verifier(Widget w,void *data){
	ValeurCourante *d=data;
	deSelectionner(abscisse,ordonnee,data);
	for(int i=0;i<d->NB_LIGNES;i++){
		for(int j=0;j<d->NB_COLONNES;j++){
			if(d->matrice_joueur[i][j]!='0' && d->matrice_joueur[i][j]!=d->matrice_resultat[i][j]){
				selectionne(j+1,i+1,RED,data);


			}

		}
	}
}


void quit (Widget w, void *d) {
	if(GetYesNo("Etes vous sur de vouloir quitter ?"))
	exit(EXIT_SUCCESS);
}


void choix_grille1(Widget w, void *data) {
	ValeurCourante *d=data;
	if(GetYesNo("Etes vous sur de vouloir recommencer une partie ?")) {
		d->NomGrille="grille1.txt";
		d->NomDefinitions="definitions1.txt";
		init_matrice_resultat(d);
		init_matrice_joueur(d);
		init_display(0, NULL,d); // on ne se sère pas de argc et argv dans la fonction
	}
}

void choix_grille2(Widget w, void *data) {
	ValeurCourante *d=data;
	if(GetYesNo("Etes vous sur de vouloir recommencer une partie ?")) {
		d->NomGrille="grille2.txt";
		d->NomDefinitions="definitions2.txt";
		init_matrice_resultat(d);
		init_matrice_joueur(d);
		init_display(0, NULL,d);
	}
}
/*
void choix_grille3(Widget w, void *data) {
	ValeurCourante *d=data;
	d->NomGrille="grille3.txt";
	d->NomDefinitions="definitions3.txt";
	init_matrice_resultat(d);
	init_matrice_joueur(d);
}
*/


//ajouter un switch case pour le numéro de fichier ( case 'grille1.txt' ...)

void sauvegarder(Widget w, void *data) {
	FILE *fichier;
	ValeurCourante *d=data;
	if ((fichier=fopen("save.txt","w+"))==NULL) {  //ouverture du fichier en mode ecriture et lecture en effaçant le contenu au préalable
		perror("save.txt");
		exit(1);
	}
	if (d->NomGrille=="grille1.txt") fputc("1",fichier) ;
	else if (d->NomGrille=="grille2.txt") fputc("2",fichier) ;
	else if (d->NomGrille=="grille3.txt") fputc("3",fichier) ;

	fputc('\t',fichier);
	fputc(d->NB_LIGNES,fichier);
	fputc('\t',fichier);
	fputc(d->NB_COLONNES,fichier);
	fputc('\n',fichier);   // tout ce qu'il y a avant constitue la première ligne du fichier, contenant des informations
	for (int i=0; i<d->NB_COLONNES ; i++) {
		for (int j=0; j<d->NB_LIGNES ; j++) {
			fputc(d->matrice_joueur[i][j],fichier);
		}
		fputc('\n',fichier);
	}

	fclose(fichier);
}
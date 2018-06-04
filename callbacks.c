#include "callbacks.h"
#include "data.h"

#include <ctype.h>

// Il faut ajouter +pas ligne et +pas colonne à chaque truc utilisant i ou j ou trouver un moyen de le faire automatiquement.

int abscisse,ordonnee; // on peut faire une structure coordonnées

int pas_ligne=LARGEUR/NB_LIGNES;
int pas_colonne=HAUTEUR/NB_COLONNES;



void  redisplay(Widget w, int width, int height, void *d){ // fcontion 
	ValeurCourante *data=d;
	for(int i=0;i<NB_LIGNES;i++){
		for(int j=0;j<NB_COLONNES;j++){
			if(data->matrice_joueur[i][j]==' '){


				DrawFilledBox(i*pas_ligne,j*pas_colonne,pas_ligne,pas_colonne);
			} 
		}
	} 
	
	for(int i=0;i<NB_LIGNES+1;i++){
		DrawLine( i*pas_ligne+pas_ligne,pas_ligne,i*pas_ligne+pas_ligne,LARGEUR+pas_ligne);
	}
	
	for(int i=0;i<NB_COLONNES+1;i++){
		DrawLine(pas_colonne,i*pas_colonne+pas_colonne,HAUTEUR+pas_colonne,i*pas_colonne+pas_colonne);

	}
	for(int num_ligne=1; num_ligne<NB_LIGNES+1;num_ligne++) {
		char numl[3];
		sprintf(numl,"%d",num_ligne);
		DrawText(numl,(num_ligne+1)*pas_ligne-pas_ligne/2,pas_colonne/2);
	}
	for(int num_colonne=1; num_colonne<NB_COLONNES+1;num_colonne++) {
		char numc[3];
		sprintf(numc,"%d",num_colonne);
		DrawText(numc,pas_ligne/2,(num_colonne+1)*pas_colonne-pas_colonne/2);

	}
}



void selectionne(int x,int y){
	DrawBox(x*pas_ligne+1,y*pas_colonne+1,pas_ligne-2,pas_colonne-2);
	DrawBox(x*pas_ligne+2,y*pas_colonne+2,pas_ligne-4,pas_colonne-4);
}

void deSelectionner(int x,int y){
	SetColor(WHITE);
	DrawBox(x*pas_ligne+1,y*pas_colonne+1,pas_ligne-2,pas_colonne-2);
	DrawBox(x*pas_ligne+2,y*pas_colonne+2,pas_ligne-4,pas_colonne-4);
	SetColor(BLACK);
}


void  clique(Widget w,int a,int x,int y,void *data){
	abscisse=x/pas_ligne;
	ordonnee=y/pas_colonne;

	selectionne(abscisse,ordonnee);

}




void rentrer_caractere(Widget w,char *input,int up_or_down, void *d){
	int x_milieu,y_milieu;
	x_milieu=0.5*(abscisse+(abscisse+1))*pas_colonne;
	y_milieu=0.5*(ordonnee+(ordonnee+1))*pas_ligne;
	ValeurCourante *data=d;
	

	if(up_or_down==1 && isalpha(*input)){

		*input=toupper(*input);
		DrawText(input,x_milieu,y_milieu);
		data->matrice_joueur[abscisse][ordonnee]=*input;
	}
	if (up_or_down==1 && *(input)==8)// *(input)=='U' && *(input+1)=='p')
	{
		DrawText(NULL,abscisse*pas_ligne,ordonnee*pas_colonne);
	


	}

	if(up_or_down==1 &&*input=='U' &&*(input+1)=='p'){
		deSelectionner(abscisse,ordonnee);
		selectionne(abscisse,ordonnee-1);
	}

}
void quit (Widget w, void *d) {
	exit(EXIT_SUCCESS);
}


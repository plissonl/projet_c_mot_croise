#include "callbacks.h"
#include "data.h"

int abscisse,ordonnee;
int pas_ligne=LARGEUR/NB_LIGNES;
int pas_colonne=HAUTEUR/NB_COLONNE;


void  redisplay(Widget w, int width, int height, void *data){ // fcontion  

	for(int i=0;i<NB_LIGNES;i++){
		DrawLine( i*pas_ligne,0,i*pas_ligne,LARGEUR);
	}
	
	for(int i=0;i<NB_COLONNE;i++){
		DrawLine(0,i*pas_colonne,HAUTEUR,i*pas_colonne);

	}
}



void  clique(Widget w,int a,int x,int y,void *data){
	abscisse=x/pas_ligne;
	ordonnee=y/pas_colonne;
}

void rentrer_caractere(Widget w,char *input,int up_or_down, void *data){
	int x_milieu,y_milieu;
	x_milieu=0.5*(abscisse+(abscisse+1))*pas_colonne;
	y_milieu=0.5*(ordonnee+(ordonnee+1))*pas_ligne;

	if(up_or_down==1){

		DrawText(input,x_milieu,y_milieu); 
	}
}

void quit (Widget w, void *d) {
	exit(EXIT_SUCCESS);
}












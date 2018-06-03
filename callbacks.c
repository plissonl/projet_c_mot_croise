#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "data.h"



void  redisplay(Widget w, int width, int height, void *data){

	int pas_ligne=LARGEUR/NB_LIGNES;
	int pas_colonne=HAUTEUR/NB_COLONNE;
	for(int i=0;i<NB_LIGNES;i++){
		DrawLine( i*pas_ligne,0,i*pas_ligne,LARGEUR);
	}

	for(int i=0;i<NB_COLONNE;i++){
		DrawLine(0,i*pas_colonne,HAUTEUR,i*pas_colonne);

	}
}
		 


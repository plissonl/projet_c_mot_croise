#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "data.h"



void  redisplay(Widget w, int width, int height, void *data){

	int pas_ligne=LARGEUR/NB_LIGNES;
	for(int i=0;i<NB_LIGNES;i++){
		DrawLine( i*pas_ligne,0,i*pas_ligne,LARGEUR);
	}
}



#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
#include "data.h"



void init_display(int argc ,char **argv, void *d){
	Widget Zone_grille;
	Zone_grille=MakeDrawArea(LARGEUR,HAUTEUR, redisplay,NULL); 

	
	GetStandardColors();
	ShowDisplay();
	SetButtonDownCB(Zone_grille,clique); 
	SetKeypressCB(Zone_grille,rentrer_caractere); 



}



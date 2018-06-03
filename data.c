#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
# include"data.h"

#define LARGEUR 600
#define HAUTEUR 600



void init_display(int argc ,char **argv, void *d){
	Widget Zone_grille;

	Zone_grille=MakeDrawArea(LARGEUR,HAUTEUR, NULL,NULL); 
	


	GetStandardColors();
	ShowDisplay();

}



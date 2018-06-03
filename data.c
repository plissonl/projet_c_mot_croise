#include "callbacks.h"
#include "data.h"



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



#include "callbacks.h"
#include "data.h"




void init_display(int argc ,char **argv, char *d){
	Widget Zone_grille, boutonQuitter;
	Zone_grille=MakeDrawArea(LARGEUR,HAUTEUR, redisplay,d); 
	
	boutonQuitter = MakeButton ("Quit", quit, NULL);
	SetWidgetPos (boutonQuitter, PLACE_UNDER, Zone_grille, NO_CARE, NULL);

	SetButtonDownCB(Zone_grille,clique); 
	SetKeypressCB(Zone_grille,rentrer_caractere); 
	GetStandardColors();
	ShowDisplay();


}


void init_matrice_reponse(int n,int m,char mat_reponse[n][m],char mat_joueur[n][m]){

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat_reponse[i][j]==' '){
				mat_joueur[i][j]=' ';

			}
			else 
				mat_reponse[i][j]='0';

		}
	}
}




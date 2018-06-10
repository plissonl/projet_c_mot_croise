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
				DrawText(" ",i*pas_ligne+pas_ligne/2+pas_ligne,j*pas_colonne+pas_colonne/2+pas_colonne);
			}
			else if(isalpha(d->matrice_joueur[j][i])){
				char lettre[2];  
				sprintf(lettre,"%c",d->matrice_joueur[j][i]);  //conversion du char en chaine de caractères pour le DrawText
				DrawText(lettre,i*pas_ligne+pas_ligne/2+pas_ligne,j*pas_colonne+pas_colonne/2+pas_colonne);
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
	//printf("%d %d\n",i,j);
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
// cette fonction permet de selectionner une case avec la souris et de séselectionner les cases en rouge correspondant aux erreurs après une modification
void  clique(Widget w,int a,int x,int y,void *data){
	ValeurCourante *d=data;
	int pas_ligne=LARGEUR/d->NB_LIGNES;
	int pas_colonne=HAUTEUR/d->NB_COLONNES;

	if(d->l->longueur!=0){
		//afficherListe(d->l->tete);
		struct noeud *p;
		p=d->l->tete;
		for(int i=0;i<d->l->longueur;i++){
				deSelectionner(p->j_erreur+1,p->i_erreur+1,d);
				p=p->suivant;
				printf("la chaine n'est pas vide\n");


		}
	d->l->longueur=0;

	}
	deSelectionner(abscisse,ordonnee,d);
	abscisse=x/pas_ligne;
	ordonnee=y/pas_colonne;

	selectionne(abscisse,ordonnee,BLUE,d);

}

void afficherListe(struct noeud* liste)

{

    struct noeud *tmp = liste;

    /* Tant que l'on n'est pas au bout de la liste */

    while(tmp != NULL)

    {

        /* On affiche */

        //printf("l'erreur correspond a %d \n", tmp->i_erreur);

        /* On avance d'une case */

        tmp = tmp->suivant;

    }

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
		if(data->l->longueur!=0){
			afficherListe(data->l->tete);
			struct noeud *p;
			p=data->l->tete;
			for(int i=0;i<data->l->longueur;i++){
				deSelectionner(p->j_erreur+1,p->i_erreur+1,data);
				p=p->suivant;
				//printf("la chaine n'est pas vide\n");


			}
			data->l->longueur=0;

		}
		
		if(abscisse>=1 && ordonnee >=1 &&*input>=97 && *input<=122 && !*(input+1) && data->matrice_joueur[ordonnee-1][abscisse-1]!=' ')  //lettre minuscule et le second element correpond au caractere de fin de chaine de caracter donc pas Up ou Down
				{
					*input=toupper(*input);
					DrawText(input,x_milieu,y_milieu);
					data->matrice_joueur[ordonnee-1][abscisse-1]=*input;   //Les -1 sont liés aux affichage des numéros de lignes et de colonnes décalants la grille
					//afficherGrille(data->NB_COLONNES,data->matrice_joueur);


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
					if(data->matrice_joueur[ordonnee-1][abscisse-1]!=' '){

						*input=' ';
						DrawText(input,x_milieu,y_milieu);
						data->matrice_joueur[ordonnee-1][abscisse-1]='0';
					}


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

	d->l->longueur=0;
	
	struct noeud *p;
	p=d->l->tete;
	


	deSelectionner(abscisse,ordonnee,d);
	for(int i=0;i<d->NB_LIGNES;i++){
		for(int j=0;j<d->NB_COLONNES;j++){
			if(d->matrice_joueur[i][j]!='0' ){
				if( d->matrice_joueur[i][j]!=d->matrice_resultat[i][j]){
					d->l->longueur++;
					//printf("la :longueur de la liste chaine est %d\n",d->l->longueur);
					p->i_erreur=i;
					p->j_erreur=j;
					p->suivant=malloc(sizeof(struct noeud));
					p=p->suivant;
					selectionne(j+1,i+1,RED,d);




				}
				else if(d->matrice_joueur[i][j]!=' '){
					selectionne(j+1,i+1,GREEN,d);

				}
			}

		}
	
	}
//free(d->l);
p->suivant=NULL;
afficherListe(d->l->tete);

//free(d->l);

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
		ClearDrawArea();
		init_display(0, NULL,d); // on ne se sert pas de argc et argv dans la fonction
	}
}

void choix_grille2(Widget w, void *data) {
	ValeurCourante *d=data;
	if(GetYesNo("Etes vous sur de vouloir recommencer une partie ?")) {
		d->NomGrille="grille2.txt";
		d->NomDefinitions="definitions2.txt";
		init_matrice_resultat(d);
		init_matrice_joueur(d);
		ClearDrawArea();
		init_display(0, NULL,d);
	}
}

void choix_grille3(Widget w, void *data) {
	ValeurCourante *d=data;
	if(GetYesNo("Etes vous sur de vouloir recommencer une partie ?")) {
		d->NomGrille="grille3.txt";
		d->NomDefinitions="definitions3.txt";
		init_matrice_resultat(d);
		init_matrice_joueur(d);
		ClearDrawArea();
		init_display(0, NULL,d);
	}
}



//ajouter un switch case pour le numéro de fichier ( case 'grille1.txt' ...)

void sauvegarder(Widget w, void *data) {
	FILE *fichier;
	ValeurCourante *d=data;
	if ((fichier=fopen("save.txt","w+"))==NULL) {  //ouverture du fichier en mode ecriture et lecture en effaçant le contenu au préalable
		perror("save.txt");
		exit(1);
	}
	switch(*(d->NomGrille+6)) {   // 6ème caractère de la chaine de caractère grille1.txt ie le numéro // on aurait pu utiliser strcmp pour comparer les chaînes de caractères
		case '1' : fputc('1',fichier); break;
		case '2' : fputc('2',fichier); break;
		case '3' : fputc('3',fichier); break;
	}

	fputc('\t',fichier);
	//printf("%d lignes et %d colonnes\n",d->NB_LIGNES,d->NB_COLONNES);
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
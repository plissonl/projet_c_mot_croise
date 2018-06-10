#include "callbacks.h"
#include "data.h"

#include <ctype.h>

// Il faut ajouter +pas ligne et +pas colonne à chaque truc utilisant i ou j ou trouver un moyen de le faire automatiquement.

int abscisse,ordonnee; // on peut faire une structure coordonnées ,abscisse,ordonne= coordonnee matrice

//int pas_ligne=LARGEUR/d->NB_LIGNES;
//int pas_colonne=HAUTEUR/d->NB_COLONNES;



void  redisplay(Widget w, int width, int height, void *data){ // fcontion 
	int nuli,nulj;
	ValeurCourante *d=data;
	int pas_ligne=LARGEUR/d->NB_LIGNES; /* pas_ligne correspond à la distance en pixel entre deux lignes, donc corresponds à la hauteur en pixel dune case */
	int pas_colonne=HAUTEUR/d->NB_COLONNES; /* pas_colonne corrsponds à la largeur en pixel d'une case */ 
	for(int i=0;i<d->NB_LIGNES;i++){
		for(int j=0;j<d->NB_COLONNES;j++){

			if(d->matrice_joueur[i][j]==' '){
				DrawFilledBox(j*pas_colonne+pas_colonne+2,i*pas_ligne+pas_ligne+2,pas_colonne-4,pas_ligne-4);
				nuli=i;
				nulj=j;
				printf("la derniere erreur est %d %d \n",nuli,nulj);


			}
			
			else if(d->matrice_joueur[i][j]=='0') {
				DrawText(" ",j*pas_colonne+pas_colonne/2+pas_colonne,i*pas_ligne+pas_ligne/2+pas_ligne);
			}
			else if(isalpha(d->matrice_joueur[i][j])){
				char lettre[2];  
				sprintf(lettre,"%c",d->matrice_joueur[j][i]);  //conversion du char en chaine de caractères pour le DrawText
				DrawText(lettre,j*pas_colonne+pas_colonne/2+pas_colonne,i*pas_ligne+pas_ligne/2+pas_ligne+3); // correspond aux x_milieu et y_milieu definis plus bas 
			}
			
		}

	} 
	/* boucle de trace des colonnes*/
	for(int i=0;i<d->NB_COLONNES+1;i++){

		DrawLine( pas_colonne*(1+i),pas_ligne,i*pas_colonne+pas_colonne,HAUTEUR+pas_ligne);

	}
	
	
	
	/*boucle de trace des lignes */ 
	for(int i=0;i<d->NB_LIGNES+1;i++){
		DrawLine(pas_colonne,i*pas_ligne+pas_ligne,LARGEUR+pas_colonne,i*pas_ligne+pas_ligne);

	}
	for(int num_ligne=1; num_ligne<d->NB_LIGNES+1;num_ligne++) {
		char numl[3];
		sprintf(numl,"%d",num_ligne);
		DrawText(numl,pas_colonne/2,(num_ligne+1)*pas_ligne-pas_ligne/2);
	}
	for(int num_colonne=1; num_colonne<d->NB_COLONNES+1;num_colonne++) {
		char numc[3];
		sprintf(numc,"%d",num_colonne);
		DrawText(numc,(num_colonne+1)*pas_colonne-pas_colonne/2,pas_ligne/2);

	}
}



void selectionne(int j,int i,int couleur,void *data){    // i et j représente les coordonéees matricielles 
	ValeurCourante *d=data;
	int pas_ligne=HAUTEUR/d->NB_LIGNES;
	int pas_colonne=LARGEUR/d->NB_COLONNES;
	SetColor(couleur);

	if(i>=1&& j>=1 && i<=d->NB_LIGNES && j<=d->NB_COLONNES){
	/*ici les coordonnees sont donc valides*/	
		DrawBox(j*pas_colonne+1,i*pas_ligne+1,pas_colonne-2,pas_ligne-2);
		DrawBox(j*pas_colonne+2,i*pas_ligne+2,pas_colonne-4,pas_ligne-4);
		abscisse=j;
		ordonnee=i;
	}
	SetColor(BLACK);

}


// cette fonction permet de de-selectionner la case en coordonnee matrcieille i et j
void deSelectionner(int j,int i,void *data){ 
	ValeurCourante *d=data;
	int pas_ligne=HAUTEUR/d->NB_LIGNES;
	int pas_colonne=LARGEUR/d->NB_COLONNES;
	SetColor(WHITE);
	DrawBox(j*pas_colonne+1,i*pas_ligne+1,pas_colonne-2,pas_ligne-2);
	DrawBox(j*pas_colonne+2,i*pas_ligne+2,pas_colonne-4,pas_ligne-4);
	SetColor(BLACK);
}
/* cette fonction  permet de selectionner une case avec des coordonnees valides, donc dans la grille et en dehors des cases noircis à l'aide la souris,
 et de dé-selectionner les cases en rouge correspondant aux erreurs après une verification par l'utilisateur
 */
void  clique(Widget w,int a,int x,int y,void *data){
	ValeurCourante *d=data;
	int pas_ligne=LARGEUR/d->NB_LIGNES;
	int pas_colonne=HAUTEUR/d->NB_COLONNES;
// de-selection des cases 
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
	abscisse=x/pas_colonne;
	ordonnee=y/pas_ligne;

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


/*cette fonction gere la configuration et l'utilisation du clavier 

-pour des coordonnees valides, donc dans la grille l'utilisateur rentre des lettre
-avec les fleches du clavier l'utilisateur peu selectionner une case 
-l'utilisateur peu effacer une lettre à l'aide de la touche back-space du clavier 
-cette fonction permet aussi de de selectionner les cases en rouge correspondant aux erreurs après verification par l'utilisateur 
*/

void rentrer_caractere(Widget w,char *input,int up_or_down, void *d){
	ValeurCourante *data=d;
	int pas_ligne=LARGEUR/data->NB_LIGNES;
	int pas_colonne=HAUTEUR/data->NB_COLONNES;
	int x_milieu,y_milieu;
	x_milieu=0.5*(abscisse+(abscisse+1))*pas_colonne;
	y_milieu=0.5*(ordonnee+(ordonnee+1))*pas_ligne+3;



	if(up_or_down==1)

	{
		/*
		de -semection de toutes les cases contenant des erreurs, les coordonnees de ces erreurs sont contennue dans une liste chaine remplis lorsque l'utilisateur appuie sur le bouton verifier
		*/
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
		/*
		les coordonnees sont valides, la lettre est en miniscule sont code ascii est donc compris entre 97 et 122, la taille de la chaine de carractere input est égale a 1,
		contrairement aux entree Up, Down, Left,Right correspondant aux fleches qui sont affecté à la chaine input lors de l'utilisation des fleches par l'utilisateur.
		*/
		if(abscisse>=1 /*$&& abscisse<=data->NB_COLONNES */&&  ordonnee >=1 && /*ordonnee<=data->NB_LIGNES &&*/ data->matrice_joueur[ordonnee-1][abscisse-1]!=' ' &&*input>=97 && *input<=122 && !*(input+1))  
				{
					*input=toupper(*input);
					DrawText(input,x_milieu,y_milieu);
					data->matrice_joueur[ordonnee-1][abscisse-1]=*input;   //Les -1 sont liés aux affichage des numéros de lignes et de colonnes décalants la grille
					//afficherGrille(data->NB_COLONNES,data->matrice_joueur);


				}
		/*
		l'entree est uniquement une lettre majuscule avec des coordonnées valides
		*/
		else if (abscisse>=1 && ordonnee>=1 && data->matrice_joueur[ordonnee-1][abscisse-1]!= ' ' && *input>=65  && *input<=90 && !*(input+1) ) // lettre majuscule
				{
					DrawText(input,x_milieu,y_milieu);
					data->matrice_joueur[abscisse-1][ordonnee-1]=*input;
		
				}
		else 
		{
		/*
		l'entree correcponds à l'utilisation des fleches et de la touche Back space par l'utilisateur
		*/
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


					
					break;
				default:
					printf("erreur sur l'entree standard\n "); // changer le message d'erreur en un widget
					break;
			}

		}
	
	}
}

/* cette fonction correspond au callback du bouton Verfier, elle permet de verifier toutes les cases remplies par l'utilisateur,
de selectionner les cases contennant une erreur en rouge, et en vert pour les lettres valides.
les coordonnes de ces erreurs sont stocke dans une liste chaine afin de les deselectionner lorsque l'utilisateur selectionne une case après une verification.
*/

void Verifier(Widget w,void *data){

	ValeurCourante *d=data;
//on initialise la longueur de la liste chainé à chaque appel de la fonction
	d->l->longueur=0;
// p pointe sur le premier noeud de la liste chainé
	struct noeud *p;
	p=d->l->tete;
	


	deSelectionner(abscisse,ordonnee,d);
	for(int i=0;i<d->NB_LIGNES;i++){
		for(int j=0;j<d->NB_COLONNES;j++){
			if(d->matrice_joueur[i][j]!='0' ){
				if( d->matrice_joueur[i][j]!=d->matrice_resultat[i][j]){
					d->l->longueur++;
				/*le caractere de la matrice joueur à ete rentré par l'utilisateur et il est different de la grille de correction
				on rentre les coordonee des erreurs, et on passe au second noeud
				*/
					p->i_erreur=i;
					p->j_erreur=j;
					p->suivant=malloc(sizeof(struct noeud));
					p=p->suivant;
					selectionne(j+1,i+1,RED,d);




				}
				// l'utilisateur à rentre un caractere correcte la case est selectionner en vert
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
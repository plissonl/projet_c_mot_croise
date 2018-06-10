#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<libsx.h>
#include<ctype.h>

#include "callbacks.h"
struct noeud{
	int i_erreur; /*Coordoonnée matricielle correspondant a la ligne pour laquel il y a une erreur */ 
	int j_erreur; /* Coordonnee matricielle correspondant à la ligne */ 
	struct noeud *suivant;
};
typedef struct {
	int longueur;
	struct noeud *tete; /* tete pointe vers le 1er noeud de la liste */
}LISTE;



typedef struct {
	int NB_LIGNES ;
	int NB_COLONNES ;
	char **matrice_joueur;  
	char **matrice_resultat;  // un tableau à deux dimensions se comporte comme un pointeur sur pointeur 
	char* NomGrille;
	char* NomDefinitions;
	LISTE *l; // pointeur sur la liste chaine
} ValeurCourante;


//extern void setZoneVerification(Widget w, ValeurCourante *data);
//extern *char comparaisonResulat(ValeurCourante *data);

/*procédure initialisant l'affichage*/
extern void init_display(int argc ,char **argv, ValeurCourante *d);

/*Procédure initialisant la matrice joueur avec des zeros au niveau des lettres de la matrice resultat*/
extern void init_matrice_joueur(ValeurCourante *data);


extern void initListeChaine(LISTE *l,ValeurCourante *d);

/* Procédure initialisant la matrice appelée matrice_resultat et choisissant le fichier utilisé*/
extern void init_matrice_resultat(ValeurCourante *data);

//affichage de test de la matrice joueur
void afficherGrillej(ValeurCourante *d); 

//affichage de test de la matrice resultat
void afficherGriller(ValeurCourante *d); 

/* Procédure initialisant les noms des fichier à la Grille 1 */
void init_fichier(ValeurCourante *d);

/*Procédure initialisant les noms des fichiers à ceux de la grille en mémoire, 
	et initialisant la matrice joueur avec les valeurs stockées en mémoire dans save.txt */
void charger_grille(ValeurCourante *d);
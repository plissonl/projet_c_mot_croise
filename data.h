#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<libsx.h>
#include<ctype.h>

#include "callbacks.h"
struct noeud{
	int i_erreur;
	int j_erreur;
	struct noeud *suivant;
};
typedef struct {
	int longueur;
	struct noeud *tete;
}LISTE;



typedef struct {
	int NB_LIGNES ;
	int NB_COLONNES ;
	char **matrice_joueur;  // pbm comment creer bien ta matrice si t'as pas le nombre de ligne    =>  Reponse en utilisant un pointeur classique puis des malloc
	char **matrice_resultat;  // un tableau à deux dimensions est un pointeur sur pointeur 
	char* NomGrille;
	char* NomDefinitions;

	//char lettre_fausse;
	Widget ZoneDeVerification;
	LISTE *l;
} ValeurCourante;


//extern void setZoneVerification(Widget w, ValeurCourante *data);
//extern *char comparaisonResulat(ValeurCourante *data);


extern void init_display(int argc ,char **argv, ValeurCourante *d);

extern void init_matrice_joueur(ValeurCourante *data);

extern void initListeChaine(LISTE *l,ValeurCourante *d);


/* Procédure initialisant la matrice appelée matrice_resultat et choisissant le fichier utilisé*/
extern void init_matrice_resultat(ValeurCourante *data);

void afficherGrille(int taille,char mat[][taille]); //affichage de test

void init_fichier(ValeurCourante *d);

void charger_grille(ValeurCourante *d);

void init_fichier(ValeurCourante *d);
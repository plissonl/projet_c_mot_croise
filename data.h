#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<libsx.h>
#include<ctype.h>

#include "callbacks.h"


typedef struct{
	char matrice_joueur[NB_LIGNES][NB_COLONNES];
	char matrice_resultat[NB_LIGNES][NB_COLONNES];
	char* NomGrille;
	char* NomDefinitions;
	char lettre_fausse;
	Widget ZoneDeVerification;
} ValeurCourante;


//extern void setZoneVerification(Widget w, ValeurCourante *data);
//extern *char comparaisonResulat(ValeurCourante *data);




extern void init_display(int argc ,char **argv, ValeurCourante *d);

extern void init_matrice_joueur(ValeurCourante *data);




/* Procédure initialisant la matrice appelée matrice_resultat et choisissant le fichier utilisé*/
extern void init_matrice_resultat(ValeurCourante *data);

void afficherGrille(int taille,char mat[][taille]); //affichage de test

void init_fichier(ValeurCourante *d);

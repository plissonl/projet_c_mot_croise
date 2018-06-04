#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<libsx.h>
#include<ctype.h>



extern void init_display(int argc ,char **argv, char *d);
extern void init_matrice_reponse(int n,int m,char mat_reponse[n][m],char mat_joueur[n][m]);



/* Procédure initialisant la matrice appelée matrice_resultat */
extern void init_matrice_resultat(int taille, char mat[][taille]);

void afficherGrille(int taille,char mat[][taille]); //affichage de test

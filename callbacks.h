#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<libsx.h>
#include<string.h>

//# define NB_LIGNES 12
//#define NB_COLONNES 12
#define LARGEUR 600
#define HAUTEUR 600

/*callback du widget ZoneGrille dessinant la grille, les cases noires, les lettres déjà presentes dans la matrice joueur*/
void  redisplay(Widget w, int width, int height,void *d);


void  clique(Widget w,int a,int x,int y,void *data);
void rentrer_caractere(Widget w,char *input,int up_or_down, void *data);

/* Callback bouton quit dont le role est de terminer l'application */
extern void quit (Widget w, void *d);

extern void Verifier(Widget w,void *d);

/* Callbacks des widgets appelés dans le menu choix grille,
	permettant de réinitialiser une partie sur la grille choisie en rouvrant une fenêtre */
extern void choix_grille1(Widget w, void *d);
extern void choix_grille2(Widget w, void *d);
extern void choix_grille3(Widget w, void *d);

/* Callback du widget boutonSauvegarde permettant d'enregistrer
	le numéro du fichier courant, le nombre de lignes et de colonnes et 
	la matrice joueur dans un fichier de sauvegarde save.txt */
void sauvegarder(Widget w, void *data);
#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<libsx.h>


# define NB_LIGNES 12
#define NB_COLONNES 12
#define LARGEUR 600
#define HAUTEUR 600


void  redisplay(Widget w, int width, int height,void *d);

void  clique(Widget w,int a,int x,int y,void *data);
void rentrer_caractere(Widget w,char *input,int up_or_down, void *data);

/* Callback bouton quit
	Role : terminer l'application
*/
extern void quit (Widget w, void *d);
extern void Verifier(Widget w,void *d);
extern void choix_grille1(Widget w, void *d);
extern void choix_grille2(Widget w, void *d);
//extern void choix_grille3(Widget w, void *d);
void sauvegarder(Widget w, void *data);
#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<libsx.h>

# define NB_LIGNES 12
#define NB_COLONNES 12
#define LARGEUR 600
#define HAUTEUR 600

void  redisplay(Widget w, int width, int height, void *data);
void  clique(Widget w,int a,int x,int y,void *data);
void rentrer_caractere(Widget w,char *input,int up_or_down, void *data);

/* Callback bouton quit
	Role : terminer l'application
*/
extern void quit (Widget w, void *d);

#include<stdlib.h>
#include<stdio.h>
# define NB_LIGNES 10
#define NB_COLONNE 10
#define LARGEUR 300
#define HAUTEUR 300

void  redisplay(Widget w, int width, int height, void *data);
void  clique(Widget w,int a,int x,int y,void *data);
void rentrer_caractere(Widget w,char *input,int up_or_down, void *data);


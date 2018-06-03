#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<libsx.h>



typedef struct {
	char lettre_joueur;
	char lettre_resultat;
	int coord_x; //ou i
	int coord_y; //ou j
} 

extern void init_display(int argc ,char **argv, void *d);

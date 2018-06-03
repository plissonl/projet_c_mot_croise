#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "callbacks.h"
# include"data.h"




void  redisplay(Widget w, int width, int height, void *data){
	int nb_ligne=10.
	int pas=600/nb_ligne;
	for(int i=0;i<nb_ligne;i++){


		DrawLine( i*pas, int 0, int i*pas, int 600);
		}}
		 

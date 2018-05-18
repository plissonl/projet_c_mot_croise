#include <stdio.h>
#include <stdlib.h>


# include <ctype.h>
 typedef struct{
    char lettre;
    int x;
    int y;
} position;

void afficherMat(int taille,char mat[][taille]){
    printf("\n");
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            printf(" |%c",mat[i][j]);

        }
        printf("\n");
    }

}

void stocker_coordonnee(int taille,char mat[taille][taille],position *mat_struct[][taille]){
    printf("hello");
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            printf("hello");

            mat_struct[i][j]->lettre=mat[i][j];
            mat_struct[i][j]->x=i;
            mat_struct[i][j]->y=j;





        }
    }
}

int main(int argc, char *argv[])

{
    int longueur=6;
    char mat[longueur][longueur];
    int i=0;
    int j=0;
    position *mat_coordonnee[longueur][longueur];

    FILE* fichier = NULL;

    int c = 0;

 

    fichier = fopen("mon_fichier.txt", "r");

 

    if (fichier != NULL)

    {

        // Boucle de lecture des caractères un à un

        do

        {
            


            c = fgetc(fichier); // On lit le caractère
            if(c!='/'){
                mat[i][j]=c;
            }
            else if(j!=0){// c=/
                mat[i][j]='0';
            }

             if(j>=longueur){
                i++;
                j=0;
            }
            else{
                j++;
            }
            

            printf("%c", c); // On l'affiche

        } while (c!= EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

 

        fclose(fichier);

    }
    printf("hello");
    afficherMat(longueur,mat);
    printf("hello");
    stocker_coordonnee(longueur,mat,mat_coordonnee);

    return 0;

}
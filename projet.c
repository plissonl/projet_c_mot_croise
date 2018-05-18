#include <stdio.h>
#include <stdlib.h>


# include <ctype.h>
 typedef struct{
    char lettre;
    int x;
    int y;
} position;

void afficherGrille(int taille,char mat[][taille]){
    printf("\n");
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            printf(" |%c",mat[i][j]);

        }
        printf("\n");
    }

}
// remplie la grille une fois le fichier texte ouvert
void remplirGrille(int taille,char mat[][taille],FILE *fichier){
    printf("hello_fonction");
    int c= 0;
    int i=0;
    int j=0;

    if (fichier != NULL)
    {// Boucle de lecture des caractères un à un
      do
        {
        c = fgetc(fichier); // On lit le caractère
        if(c=='/'){ // fin d'un mot
        
            mat[i][j]='0';
            j++;
        }
        else if(isalpha(c)){ // le caractere est une lettre et ce n'est pas la fin d'un mot on place la lettre dans la grille
            mat[i][j]=c;
            j++;
            
           }
        else if(c=='\n'){  
            if(j<taille){
                printf("erreur de longueur pour la ligne %d",i); // le fichier text est mal remplie 
                exit(1); 
            i++;
            j=0;
            }
            else {
                printf("erreur sur le fichier text");
                exit(2);
            }
             printf("%c", c); // On l'affiche

        } while (c!= EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
    }
}



 




int main(int argc, char *argv[])

{

    int longueur=12;
    char mat[longueur][longueur];
    int i=0;
    int j=0;
    
    

    FILE* fichier = NULL;

    int c = 0;

 

    fichier = fopen("grille.txt", "r");

    if (fichier != NULL){ 
    remplirGrille(longueur,mat,fichier);
    fclose(fichier);
}

    
   
    afficherGrille(longueur,mat);
    

    return 0;

}
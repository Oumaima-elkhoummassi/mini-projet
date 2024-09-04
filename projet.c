#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//test 

void welcome() {
    printf("\tBonjour!\n");
    printf("");
    printf("\n0: exit\n1: ajouter un livre\n2: afficher les livres\n3:update livre \n4:delete livre \n5:afficher le nombre du livre et du stock\n");
}

void  ajouter(char titre[][100], char auteur[][100], float prix[], int quantite[], int count) 
{
    printf ("titre : ");
    scanf ("%s", titre[count]);
    printf ("auteur : ");
    scanf ("%s", &auteur[count]);
    printf ("prix : ");
    scanf ("%f", &prix[count]);
    printf ("quantite : ");
    scanf ("%d", &quantite[count]);
}

void afficher(char titre[][100], char auteur[][100], float prix[], int quantite[], int count)
{
    printf("\nListe des livres :\n");
    for (int i = 0; i < count; i++)
    {
        printf("\n| Titre : %s | Auteur : %s | Prix :  %f | Quantite : %d |", titre[i], auteur[i], prix[i], quantite[i]);
    }
    printf("\n");
}
void  update(char titre[][100],char add[],int quantite[] ,int count,int nv ){
    int i;
     for(i=0;i<count;i++){
        if(strcmp(titre[i],add)==0){
            quantite[i] = nv;
        }
        }

}

int deletey(char titre[][100], char auteur[][100], float prix[], int quantite[], int count, char *t) {
     int i,j;
     for(i=0;i<count-1;i++){
        if(strcmp(titre[i],t)==0){
          for(j=i+1;j<count;j++){
             strcpy(titre[i],titre[j]);
             strcpy(auteur[i],auteur[j]);
             prix[i]=prix[j];
             quantite[i]=quantite[j];
          }

          count--;
           i--;
        }

       
     } return count ;
     }
void stock(int quantite[],int count){
    int i,somme=0;
    for(i=0;i<count;i++){
        somme =somme+quantite[i];
    }
    printf("le nombre totale de livre est : %d\n",count);
    printf("la quantite totale de livre est : %d\n",somme);


}
int main() {
    int choix;
    int c = 0;

    char titre[10][100];
    char auteur[10][100];
    float prix[10];
    int quantite[10];
    welcome();
    while(1) {
        printf("Entee votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter(titre, auteur, prix, quantite, c);
                c++;
                break;
            case 2:
                printf("Count: %d\n", c);
                afficher(titre, auteur, prix, quantite, c);
                break;
            case 3:
                 char word[10];
                 int q;
                printf("enter le titre de livre :");
                scanf("%s",&word);
                printf("enter le quentite :");
                scanf("%d",&q);
                update(titre,word,quantite,c,q);
                break;
            case 4:
                 char t[10];
                printf("enter le titre de livre a supprime:");
                scanf("%s",&t);
                 c = deletey(titre, auteur, prix, quantite, c, t);


                break; 
            case 5:
                stock(quantite,c);
                break;
            case 0:
                printf("exit...");
                exit(0);
            default:
                printf("Default!");

    }
    }
    return (0);
}
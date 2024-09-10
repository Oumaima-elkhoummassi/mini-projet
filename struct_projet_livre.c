#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titre[20];
    char auteur[20];
    float prix;
    int quantite;
} livre;

void welcome()
{
    printf("\tBonjour!\n");
    printf("");
    printf("\n0: exit\n1: ajouter un livre\n2: afficher les livres\n3:update livre \n4:delete livre \n5:afficher le nombre du livre et du stock \n6:Recherche \n7:Tri les livre \n");
}
int ajouter(livre l[100], int count)
{
    printf("titre : ");
    scanf("%s", &l[count].titre);
    printf("auteur : ");
    scanf("%s", &l[count].auteur);
    printf("prix : ");
    scanf("%f", &l[count].prix);
    printf("quantite : ");
    scanf("%d", &l[count].quantite);
    count++;
    return count;
}

void afficher(livre l[100], int count)
{
    int i;
    printf("\nListe des livres :\n");
    for (i = 0; i < count; i++) {
        printf("\n| Titre : %s | Auteur : %s | Prix :  %.2f | Quantite : %d |", l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);
    }
    printf("\n");
}


void update(livre l[100],char add[],int count)
{
    int i;
    int r;
    printf("\n1:modifier le titre\n2:modifier le auteur\n3:modifier le quantite\n4:modifier le prix\n5:modifier toux\n6:return \nentre votre choix : ");
    scanf("%d",&r);
    switch (r) {
    case 1:
        char titre_modifier[20];
        printf("entre la nouveau titre:");
        scanf("%s",titre_modifier);
        for(i=0; i<count; i++) {
            if(strcmp(l[i].titre,add)==0) {
                strcpy(l[i].titre,titre_modifier);
            } 
        }
        break;
    case 2:
        char autre_modifier[20];
        printf("entre la nouveau auture:");
        scanf("%s",autre_modifier);
        for(i=0; i<count; i++) {
            if(strcmp(l[i].titre,add)==0) {
                strcpy(l[i].auteur,autre_modifier);
            }
        }
        break;
    case 3:
        int nv;
        printf("entre la nouveau quantite:");
        scanf("%d",&nv);
        for(i=0; i<count; i++) {
            if(strcmp(l[i].titre,add)==0) {
                l[i].quantite = nv;
            }
        }
        break;
    case 4:
        float prix_nv;
        printf("entre la nouveau prix:");
        scanf("%f",&prix_nv);
        for(i=0; i<count; i++) {
            if(strcmp(l[i].titre,add)==0) {
                l[i].prix = prix_nv;
            } 

        }
        break;
    case 5:
        char titre_modifier_tout[20];
        float prix_nv_tout;
        char autre_modifier_tout[20];
        int quantite_nv;
        printf("entre la nouveau titre:");
        scanf("%s",titre_modifier_tout);
        printf("entre la nouveau auture:");
        scanf("%s",autre_modifier_tout);
        printf("entre la nouveau prix:");
        scanf("%f",&prix_nv_tout);
        printf("entre la nouveau quantite :");
        scanf("%d",&quantite_nv);
        for(i=0; i<count; i++) {
            if(strcmp(l[i].titre,add)==0) {
                strcpy(l[i].titre,titre_modifier_tout);
                strcpy(l[i].auteur,autre_modifier_tout);
                l[i].prix = prix_nv_tout;
                l[i].quantite = quantite_nv;
            }
        }

        break;
    case 6:
        welcome();
        break;
    default:
        break;
    }

}
int suprime(livre l[100],char titreS[],int count)
{
    int i,j;
    for(i=0; i<count-1; i++) {
        if(strcmp(l[i].titre,titreS)==0) {
            for(j=i+1; j<count; j++) {
                l[i]=l[j];
                //      l[j - 1] = l[j];
            }

            count--;
            i--;
        }

    }
    return count;
}

void recherche(livre l[100],char nom_cherche[],int c)
{
    int i ;
    for(i=0; i<c; i++) {
        if(strcmp(l[i].titre,nom_cherche)==0) {
            printf("\n| Titre : %s | Auteur : %s | Prix :  %f | Quantite : %d |", l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);

        }
    }
}

void tribulle(livre l[100],int count)
{
    int i,j;
    livre tmp;
    for(i=0; i<count; i++) {
        for(j=0; j<count-i-1; j++) {
            if(strcmp(l[j].titre,l[j+1].titre)>0) {
                tmp = l[j];
                l[j]=l[j+1];
                l[j+1]=tmp;

            }
        }
    }

    printf("\nListe des livres :\n");
    for (int i = 0; i < count; i++) {
        printf("\n| Titre : %s | Auteur : %s | Prix :  %.2f | Quantite : %d |", l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);

    }
    printf("\n");


}



void tribullecontraire(livre l[100],int count)
{
    int i,j;
    livre tmp;
    for(i=0; i<count; i++) {
        for(j=0; j<count-i-1; j++) {
            if(strcmp(l[j].titre,l[j+1].titre)<0) {
                tmp = l[j];
                l[j]=l[j+1];
                l[j+1]=tmp;

            }
        }
    }

    printf("\nListe des livres :\n");
    for (int i = 0; i < count; i++) {
        printf("\n| Titre : %s | Auteur : %s | Prix :  %.2f | Quantite : %d |", l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);

    }
    printf("\n");


}

void stock(livre l[100],int count)
{
    int i,j;
    int r;
    printf("\n1:la somme de quantite \n2:le auteur qui ecrie beaucoup de livre \n3:le livre qui moin vandu \n4:le livre le plus cher\n5:return \nentre votre choix : ");
    scanf("%d",&r);
    switch (r) {
    case 1:
        int somme=0;
        for(i=0; i<count; i++) {
            somme =somme+l[i].quantite;
        }
        printf("le nombre totale de livre est : %d\n",count);
        printf("la quantite totale de livre est : %d\n",somme);
        break ;
    case 2:
        int max_a=0;
        int max_auteur=0;
        char auteurMax[20];
        for(i=0; i<count; i++) {
            for(j=0; i<count ; j++) {
                if(strcmp(l[i].auteur,l[j].auteur)==0) {
                max_a++;
            }
            if(max_a>max_auteur) {
                max_auteur=max_a;
                strcpy(auteurMax,l[i].auteur);
                    printf("L auteur qui a ecrit le plus de livres est : %s avec %d livres.\n", auteurMax, max_auteur);
                }
            }
        }
        break;

    case 3:
        int max=l[0].quantite;

        for(i=0; i<count; i++) {

            for(j=i+1; i<count ; j++) {
                if(l[j].quantite>max) {
                    max=l[j].quantite;
                }
            }
        }
        printf("le livre qui moin vendu : %d",max);
        break;
    case 4:

        float max_prix=l[0].prix;

        for(i=0; i<count; i++) {
            for(j=i+1; i<count ; j++) {
                if(l[j].prix>max_prix) {
                    max_prix=l[j].prix;
                }
            }
        }
        printf("le livre le plus cher : %d",max_prix);
        break;

    case 5:
        welcome();
        break;
    }





}

int main()
{
    int choix;
    int c = 0;
    int r;
    livre l[100];
    while (1) {
        welcome();
        printf("Entee votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
        case 1:
            int n = 0, i;
            do {
                printf("\n1: ajouter un livre\n2:ajoute plusieur livre\n3:return \nentre votre choix : ");
                scanf("%d", &r);
                if (r != 1 && r != 2 && r!=3) {
                    printf("erreur s'il vous plait entre just 1 or 2 or 3");
                }
            } while (r != 1 && r != 2 && r!=3 );

            if (r == 1) {
                c = ajouter(l, c);
            } else if (r == 2) {
                printf("entre le nombre de element a ajoute :");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    c = ajouter(l, c);
                }
            } else if (r==3) {
                welcome();
            }

            break;
        case 2:
            printf("count %d\n", c);

            afficher(l, c);

            break;
        case 3:
            char word[10];
            int q,j,f=0;
            printf("avant la modification :\n");
            afficher(l, c);
            printf("---------------------------\n");
            printf("enter le titre de livre :");
            scanf("%s",word);
            for(j=0; j<c; j++){
            if(strcmp(l[j].titre,word)==0){
             f=1;
             update(l,word,c); 
              printf("apres la modification :\n");
             afficher(l,c);
            }
            }

            if(f==0){
                printf("not found\n");
            }


            break;
        case 4:
       
            char t[10],rep[10];
            int s;
            printf("avant la suppression :\n");
            afficher(l, c);
            printf("enter le titre de livre a supprime:");
            scanf("%s",&t);

            for(j=0; j<c; j++){
            if(strcmp(l[j].titre,t)==0){
             s=1;
            }
            }
            if(s==1){
                 printf("vous voulais vraiment supprime 'y' or 'n' ");
            scanf("%s",rep);
            if(strcmp(rep,"y")==0) {
              c = suprime(l,t,c);
                printf("apres la suppression :\n");
                afficher(l, c);
            }
            }

           if(s==0){
            printf("not found");
           }
           



            break;
        case 5:
            stock(l,c);
            break;
        case 6:
            char nom_cherche[20];
            afficher(l,c);
            printf("entre votre nom a cherche :");
            scanf("%s",&nom_cherche);
            recherche(l,nom_cherche,c);
            break;

        case 7:
            int Reponce;
            printf("\n1: tri de 'a' vs 'z'\n2: tri de 'z' vs 'a'\n3: Return \n entre votre choix : ");
            scanf("%d", &Reponce);
            if(Reponce==1) {
                tribulle(l,c);
            } else if (Reponce==2) {
                tribullecontraire(l,c);
            } else if (Reponce==3) {
                welcome();
            }



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

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
/*void  update(livre l[100] ,char add[],int count,int nv){
    int i;
     for(i=0;i<count;i++){
        if(strcmp(l[i].titre,add)==0){
            l[i].quantite = nv;
        }else printf("not found!\n");

        }

}*/


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

void recherche(livre l[100],char nom_cherche[],int n)
{
    int i ;
    for(i=0; i<n-1; i++) {
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
/*
void recherche(livre l[100],char nom_cherche[],int count){
	int i ;
   int premier=0,dernier=count-1;
   tribulle(l,count);
	 while (dernier>=premier)
     {
        int m=(dernier+premier)/2;
        if(strcmp(l[m].titre,nom_cherche)==0){
            printf("\n| Titre : %s | Auteur : %s | Prix :  %f | Quantite : %d |", l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);
        }else if(strcmp(l[m].titre,nom_cherche)>0){
            premier=m+1;
        }else dernier=m-1;
     }


}

*/
void stock(livre l[100], int count) {
    int i, j;
    int r;

    printf("\n1: la somme des quantites \n2: l'auteur qui a ecrit beaucoup de livres \n3: le livre qui s'est le moins vendu \n4: le livre le plus cher\n5: retour \nEntrez votre choix : ");
    scanf("%d", &r);

    switch (r) {
        case 1: {
            int somme = 0;
            for (i = 0; i < count; i++) {
                somme += l[i].quantite;
            }
            printf("Le nombre total de livres est : %d\n", count);
            printf("La quantite totale de livres est : %d\n", somme);
            break;
        }

        case 2: {
            int max = 0;
            int max_auteur = 0;
            char auteurMax[20];
            for (i = 0; i < count; i++) {
                int count_auteur = 0;
                for (j = 0; j < count; j++) {
                    if (strcmp(l[i].auteur, l[j].auteur) == 0) {
                        count_auteur++;
                    }
                }
                if (count_auteur > max_auteur) {
                    max_auteur = count_auteur;
                    strcpy(auteurMax, l[i].auteur);
                }
            }
            printf("L'auteur qui a ecrit le plus de livres est : %s avec %d livres.\n", auteurMax, max_auteur);
            break;
        }

        case 3: {
            int min_quantite = l[0].quantite;
            char titremin[20];
            strcpy(titremin, l[0].titre);
            
            for (i = 1; i < count; i++) {
                if (l[i].quantite < min_quantite) {
                    min_quantite = l[i].quantite;
                    strcpy(titremin, l[i].titre);
                }
            }
            printf("Le livre qui s'est le moins vendu est : %s avec %d exemplaires.\n", titremin, min_quantite);
            break;
        }

        case 4: {
            float max_prix = l[0].prix;
            char titreCher[20];
            strcpy(titreCher, l[0].titre);

            for (i = 1; i < count; i++) {
                if (l[i].prix > max_prix) {
                    max_prix = l[i].prix;
                    strcpy(titreCher, l[i].titre);
                }
            }
            printf("Le livre le plus cher est : %s avec un prix de %.2f.\n", titreCher, max_prix);
            break;
        }

        case 5:
            printf("Retour au menu principal.\n");
            break;

        default:
            printf("Choix invalide.\n");
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
            int q;
            printf("avant la modification :\n");
            afficher(l, c);
            printf("---------------------------\n");
            printf("enter le titre de livre :");
            scanf("%s",&word);

            update(l,word,c);
            printf("apres la modification :\n");
            afficher(l,c);

            break;
        case 4:
            char t[10],rep[10];
            printf("avant la suppression :\n");
            afficher(l, c);
            printf("enter le titre de livre a supprime:");
            scanf("%s",&t);
            printf("vous voulais vraiment supprime 'y' or 'n' ");
            scanf("%s",rep);
            if(strcmp(rep,"y")==0) {
                c = suprime(l,t,c);
                printf("apres la suppression :\n");
                afficher(l, c);
            } else {
                welcome();
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

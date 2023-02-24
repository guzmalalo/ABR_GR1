
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition d'un noeud
typedef struct N
{
    // clé
    int n;

    // Information à stocker
    char nom[50];

    // Lien d'hierarchie
    struct N *sag; // Noued à gauche
    struct N *sad; // Noued à droite

} Node ;

void creerNoued(Node **arbre_n, int n, char *str)
{

    // Allocation de memoire (Creation du noued)
    // et recuperation de son adresse
    (*arbre_n) = (Node *)malloc(sizeof(Node));

    // Initialisation du noued
    (*arbre_n)->n = n;
    strcpy((*arbre_n)->nom, str);

    // Initialisation des noueds enfants
    (*arbre_n)->sad = NULL;
    (*arbre_n)->sag = NULL;

    return;
}

void ajouterNoued(Node **p_arbre, int n, char *str)
{
    // Creation d'un pointeur temporaire vers
    // le sous-arbre
    Node *arbre = *p_arbre;

    if (arbre == NULL)
    {
        creerNoued(p_arbre, n, str);
    }
    else if (n < arbre->n)
    {
        ajouterNoued(&(arbre->sag), n, str);
    }
    else if (n > arbre->n)
    {
        ajouterNoued(&(arbre->sad), n, str);
    }
    else
    {
        printf("Clé existante");
    }
}



void libereArbre(Node ** arbre){
    if(*arbre == NULL){
        return;
    }
    libereArbre(&(*arbre)->sag);
    libereArbre(&(*arbre)->sad);
    free(*arbre);
}


void afficheInfixe(Node * arbre){

    if (arbre == NULL)
        return;
    afficheInfixe(arbre->sag);
    printf("%d\t", arbre->n );
    afficheInfixe(arbre->sad);
}

void affichePrefixe(Node * arbre){

    if(arbre != NULL){
        printf("%d\t", arbre->n );
        affichePrefixe(arbre->sag);
        affichePrefixe(arbre->sad);
    }
}

void affichePostfixe(Node * arbre){

    if(arbre != NULL){
        affichePostfixe(arbre->sag);
        affichePostfixe(arbre->sad);
        printf("%d\t", arbre->n );
    }
}

Node * trouveNode(Node *arbre, int n){
    if (arbre == NULL)
    {
        printf("Valeur non trouvée \n");
        return NULL;
    }
    if (arbre->n == n)
    {
        printf("Valeur trouvé \n");
        return arbre;
    }else if (n < arbre->n)
    {
        // cherche a gauche
        return trouveNode(arbre->sag, n);
    }else if (n > arbre->n)
    {
        // cherche à droite
        return trouveNode(arbre->sad, n);
    }

}


int main()
{
    // Initialisation de l'arbre
    Node *arbre = NULL;

    // Creation du premier noued (racine)
    ajouterNoued(&arbre, 50, "A");

    // Ajout des noueds à trier
    ajouterNoued(&arbre, 42, "B");
    ajouterNoued(&arbre, 73, "C");
    ajouterNoued(&arbre, 11, "D");
    ajouterNoued(&arbre, 47, "E");
    ajouterNoued(&arbre, 66, "F");
    ajouterNoued(&arbre, 121, "G");

    // Affichage
    printf(" \n Pre-fixe\n");
    affichePrefixe(arbre);
    printf(" \n Infixe \n");
    afficheInfixe(arbre);
    printf(" \n Post-fixe\n");
    affichePostfixe(arbre);

    free(arbre);

    return 0;
}

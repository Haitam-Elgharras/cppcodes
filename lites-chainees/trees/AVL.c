#include <stdio.h>
#include <stdlib.h>

/*
Cette structure définit un nœud dans un arbre par une liste chaînée pour un arbre binaire à deux branches.
 Chaque nœud contient une valeur et deux pointeurs vers les nœuds fils gauche et droite.*/

typedef struct NoeudEntier
{
    int valeur;
    struct NoeudEntier *gauche;
    struct NoeudEntier *droite;
    int hauteur; // pour l'équilibrage
} NoeudEntier;

// arbre binaire de recherche
NoeudEntier *creerNoeud(int valeur)
{
    NoeudEntier *noeud = (NoeudEntier *)malloc(sizeof(NoeudEntier));
    noeud->valeur = valeur;
    noeud->gauche = NULL;
    noeud->droite = NULL;
    noeud->hauteur = 0; // initialisation de la hauteur à 0
    return noeud;
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int hauteur(NoeudEntier *noeud)
{
    if (noeud == NULL)
        return -1;
    else
        return noeud->hauteur;
}

int facteurEquilibre(NoeudEntier *noeud)
{
    return hauteur(noeud->gauche) - hauteur(noeud->droite);
}

void miseAJourHauteur(NoeudEntier *noeud)
{
    noeud->hauteur = 1 + max(hauteur(noeud->gauche), hauteur(noeud->droite));
}

NoeudEntier *rotationGauche(NoeudEntier *noeud)
{
    NoeudEntier *x = noeud->droite;
    NoeudEntier *y = x->gauche;
    x->gauche = noeud;
    noeud->droite = y;
    miseAJourHauteur(noeud);
    miseAJourHauteur(x);
    return x;
}

NoeudEntier *rotationDroite(NoeudEntier *noeud)
{
    NoeudEntier *x = noeud->gauche;
    NoeudEntier *y = x->droite;
    x->droite = noeud;
    noeud->gauche = y;
    miseAJourHauteur(noeud);
    miseAJourHauteur(x);
    return x;
}

void insererNoeud(NoeudEntier **racine, int valeur)
{
    if (*racine == NULL)
        *racine = creerNoeud(valeur);
    else
    {
        if (valeur > (*racine)->valeur)
        {
            insererNoeud(&(*racine)->droite, valeur);
        }
        else
        {
            // delete this if
            if (valeur < (*racine)->valeur)
            {
                insererNoeud(&(*racine)->gauche, valeur);
            }
        }
        miseAJourHauteur(*racine);                               // mise à jour de la hauteur du nœud courant
        int equilibre = facteurEquilibre(*racine);               // calcul du facteur d'équilibre
        if (equilibre > 1 && (*racine)->gauche->valeur > valeur) // rotation droite simple
        {
            *racine = rotationDroite(*racine);
        }
        else if (equilibre < -1 && (*racine)->droite->valeur < valeur) // rotation gauche simple
        {
            *racine = rotationGauche(*racine);
        }
        else if (equilibre > 1 && (*racine)->gauche->valeur < valeur) // rotation gauche-dro
        {
            (*racine)->gauche = rotationGauche((*racine)->gauche);
            *racine = rotationDroite(*racine);
        }
        else if (equilibre < -1 && (*racine)->droite->valeur > valeur) // rotation droite-gauche
        {
            (*racine)->droite = rotationDroite((*racine)->droite);
            *racine = rotationGauche(*racine);
        }
    }
}
/*l'affichage est préfixé l'affichage est effectué en parcours préfixé (ou pré-ordre),
 c'est-à-dire que l'on visite d'abord le nœud courant, puis son sous-arbre gauche, puis son sous-arbre droit*/
void afficherArbrePref(NoeudEntier *racine)
{
    if (racine == NULL)
    {
        return;
    }
    printf("%d ", racine->valeur);
    afficherArbrePref(racine->gauche);
    afficherArbrePref(racine->droite);
}
void afficherArbreInf(NoeudEntier *racine)
{
    if (!racine)
    {
        return;
    }
    afficherArbreInf(racine->gauche);
    printf("%d ", racine->valeur);
    afficherArbreInf(racine->droite);
}
void afficherArbrePostf(NoeudEntier *racine)
{
    if (!racine)
    {
        return;
    }
    afficherArbrePostf(racine->gauche);
    afficherArbrePostf(racine->droite);
    printf("%d ", racine->valeur);
}

void libererArbre(NoeudEntier *racine)
{
    if (racine == NULL)
    {
        return;
    }
    libererArbre(racine->gauche);
    libererArbre(racine->droite);
    free(racine);
}
// le predecesseur si la noeud le plus à droite dans son arbre gauche
NoeudEntier *predecesseur(NoeudEntier *racine)
{
    NoeudEntier *gauche = racine->gauche;
    while (gauche->droite != NULL)
        gauche = gauche->droite;
    printf("le predecesseur est : %d\n", gauche->valeur);
    return gauche;
}
NoeudEntier *seccesseur(NoeudEntier *racine)
{
    NoeudEntier *droite = racine->droite;
    while (droite->gauche != NULL)
        droite = droite->gauche;
    printf("le seccesseur est : %d\n", droite->valeur);
    return droite;
}
NoeudEntier **searchNoeud(NoeudEntier **racine, int value)
{
    if (*racine == NULL)
    {
        printf("la valeur nexiste pas\n");
        return NULL;
    }
    if ((*racine)->valeur == value)
    {
        printf("la valeur existe \n");
        return racine;
    }
    else
    {
        if ((*racine)->valeur < value)
            return searchNoeud(&(*racine)->droite, value);
        else
            return searchNoeud(&(*racine)->gauche, value);
    }
    return NULL;
}

void supprimerNoeud(NoeudEntier **racine, int value)
{
    if (*racine == NULL)
    {
        printf("l'arbre est vide\n");
        return;
    }

    NoeudEntier **supp = searchNoeud(racine, value);
    if (supp == NULL || *supp == NULL)
    {
        printf("Le noeud avec la valeur %d n'existe pas\n", value);
        return;
    }

    if ((*supp)->droite == NULL && (*supp)->gauche == NULL)
    {
        printf("Le noeud avec la valeur %d a ete supprime\n", (*supp)->valeur);
        free(*supp); // liberer le noeud
        *supp = NULL;
    }
    else if ((*supp)->droite == NULL)
    {
        printf("Le noeud avec la valeur %d a ete remplace par son enfant gauche\n", (*supp)->valeur);
        NoeudEntier *temp = *supp;
        *supp = (*supp)->gauche;
        free(temp);
    }
    else if ((*supp)->gauche == NULL)
    {
        printf("Le noeud avec la valeur %d a ete remplace par son enfant droit\n", (*supp)->valeur);
        NoeudEntier *temp = *supp;
        *supp = (*supp)->droite;
        free(temp);
    }
    else // quand noeud a deux enfants
    {
        // we don't need to free the node because we will replace it with its successor and it's obligatory that this successor has no left child
        NoeudEntier *succ = seccesseur(*supp);
        printf("Le noeud avec la valeur %d a ete remplace par son successeur (%d)\n", (*supp)->valeur, (succ)->valeur);
        (*supp)->valeur = (succ)->valeur;
        miseAJourHauteur(*racine);
        supprimerNoeud(&(*supp)->droite, (succ)->valeur);
    }

    if (*racine == NULL)
        return;

    miseAJourHauteur(*racine);                 // mise à jour de la hauteur du nœud courant
    int equilibre = facteurEquilibre(*racine); // calcul du facteur d'équilibre

    if (equilibre > 1 && facteurEquilibre((*racine)->gauche) >= 0) // rotation droite simple
    {
        *racine = rotationDroite(*racine);
    }
    else if (equilibre < -1 && facteurEquilibre((*racine)->droite) <= 0) // rotation gauche simple
    {
        *racine = rotationGauche(*racine);
    }
    else if (equilibre > 1 && facteurEquilibre((*racine)->gauche) < 0) // rotation gauche-droite
    {
        (*racine)->gauche = rotationGauche((*racine)->gauche);
        *racine = rotationDroite(*racine);
    }
    else if (equilibre < -1 && facteurEquilibre((*racine)->droite) > 0) // rotation droite-gauche
    {
        (*racine)->droite = rotationDroite((*racine)->droite);
        *racine = rotationGauche(*racine);
    }
}

int main()
{

    NoeudEntier *racine = NULL;

    insererNoeud(&racine, 10);
    insererNoeud(&racine, 5);
    insererNoeud(&racine, 15);
    insererNoeud(&racine, 2);
    insererNoeud(&racine, 7);
    insererNoeud(&racine, 12);
    insererNoeud(&racine, 17);
    insererNoeud(&racine, 8);

    printf("prefixe: ");
    afficherArbrePref(racine);
    printf("\n");
    printf("infixe: ");
    afficherArbreInf(racine);
    printf("\n");
    supprimerNoeud(&racine, 2);
    supprimerNoeud(&racine, 12);
    supprimerNoeud(&racine, 15);
    printf("prefixe: ");
    afficherArbrePref(racine);
    printf("\n");
    printf("infixe: ");
    afficherArbreInf(racine);
    printf("\n");
    libererArbre(racine);
    return 0;
}

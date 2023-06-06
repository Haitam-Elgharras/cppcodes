#include <stdio.h>
#include <stdlib.h>

/*
Cette structure définit un nœud dans un arbre par une liste chaînée pour un arbre binaire à trois branches.
 Chaque nœud contient une valeur et trois pointeurs vers les nœuds fils gauche, milieu et droite.*/

typedef struct Noeud
{
    int valeur;
    struct Noeud *gauche;
    struct Noeud *milieu;
    struct Noeud *droite;
} NoeudEntier;

// arbre binaire de recherche
NoeudEntier *creerNoeud(int valeur)
{
    NoeudEntier *noeud = (NoeudEntier *)malloc(sizeof(NoeudEntier));
    noeud->valeur = valeur;
    noeud->gauche = NULL;
    noeud->milieu = NULL;
    noeud->droite = NULL;
    return noeud;
}

/*
The precedence of the operators in the expression "&(*ptr)->left" is as follows:

The "->" operator has higher precedence than the "&" operator, so it is evaluated first.

The "*" operator has higher precedence than the "->" operator, so it is evaluated next.

Finally, the "&" operator is evaluated last.

So the expression is equivalent to "&((*ptr)->left)".
*/

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
            // the -> operator has higher precedence than the * operator
            if (valeur < (*racine)->valeur)
            {
                insererNoeud(&(*racine)->gauche, valeur);
            }
            else
                insererNoeud(&(*racine)->milieu, valeur);
        }
    }
}
void insererNoeudFalse(NoeudEntier *racine, int valeur)
{
    if (racine == NULL)
    {
        racine = creerNoeud(valeur); // will not work
    }
    else
    {
        if (valeur < racine->valeur)
        {
            /* this necessary with * , cause if we passed it and it's null we passed just the copy and the values will change just in the copy
             the copy will get creerNoeud in another memory and not inside the racine*/
            if (racine->gauche == NULL)
            {
                racine->gauche = creerNoeud(valeur);
            }
            else
            {
                insererNoeudFalse(racine->gauche, valeur);
            }
        }
        else if (valeur > racine->valeur)
        {
            if (racine->droite == NULL)
            {
                racine->droite = creerNoeud(valeur);
            }
            else
            {
                insererNoeudFalse(racine->droite, valeur);
            }
        }
        else
        {
            // le millieu va cotenir les valeur egale a la racine
            if (racine->milieu == NULL)
            {
                racine->milieu = creerNoeud(valeur);
            }
            else
            {
                insererNoeudFalse(racine->milieu, valeur);
            }
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
    afficherArbrePref(racine->milieu);
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
    afficherArbreInf(racine->milieu);
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
    afficherArbrePostf(racine->milieu);
}

void libererArbre(NoeudEntier *racine)
{
    if (racine == NULL)
    {
        return;
    }
    libererArbre(racine->gauche);
    libererArbre(racine->milieu);
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
// searchParent(NoeudEntier *racine, int value)
// {
// }
void supprimerNoeud(NoeudEntier **racine, int value)
{
    if (*racine == NULL)
    {
        printf("l'arbre est vide\n");
        return;
    }
    NoeudEntier **supp = searchNoeud(racine, value);
    if (supp == NULL)
    {
        printf("Le noeud avec la valeur %d n'existe pas\n", value);
        return;
    }

    if ((*supp)->droite == NULL && (*supp)->gauche == NULL)
    {
        printf("Le noeud avec la valeur %d a ete supprime\n", (*supp)->valeur);
        // we need to deallocate the memory
        free(*supp);
        *supp = NULL;
        return;
    }

    if ((*supp)->droite == NULL)
    {
        printf("Le noeud avec la valeur %d a ete remplace par son enfant gauche\n", (*supp)->valeur);
        NoeudEntier *temp = *supp;
        *supp = (*supp)->gauche;
        free(temp);
        return;
    }

    if ((*supp)->gauche == NULL)
    {
        printf("Le noeud avec la valeur %d a ete remplace par son enfant droit\n", (*supp)->valeur);
        NoeudEntier *temp = *supp;
        *supp = (*supp)->droite;
        free(temp);
        return;
    }
    // quand noeud a deux enfants
    NoeudEntier *succ = seccesseur(*supp);
    printf("Le noeud avec la valeur %d a ete remplace par son successeur (%d)\n", (*supp)->valeur, (succ)->valeur);
    (*supp)->valeur = (succ)->valeur;
    supprimerNoeud(&(*supp)->droite, (succ)->valeur);
}
// ############ file #################
typedef struct
{
    NoeudEntier **elements;
    int taille;
    int debut;
    int fin;
} File;

File *creer_file(int taille)
{
    File *file = malloc(sizeof(File));
    file->elements = (NoeudEntier **)malloc(taille * sizeof(NoeudEntier *));
    file->taille = taille;
    file->debut = 0;
    file->fin = -1;
    return file;
}

int file_est_vide(File *file)
{
    return file->fin < file->debut;
}

void enfiler(File *file, NoeudEntier *noeud)
{
    // Si la fin de la file atteint la fin du tableau, revenir au début
    if (file->fin == file->taille - 1)
    {
        file->fin = -1;
    }

    // Augmenter la taille de la file en utilisant realloc
    if (file->fin + 1 == file->debut)
    {
        // File pleine, doubler la taille du tableau
        printf("augmenter:\n");
        file->taille *= 2;
        NoeudEntier **new_elements = (NoeudEntier **)realloc(file->elements, file->taille * sizeof(NoeudEntier *));
        if (new_elements == NULL)
        {
            exit(EXIT_FAILURE);
        }
        file->elements = new_elements;
    }

    file->elements[++file->fin] = noeud;
}

NoeudEntier *defiler(File *file)
{
    if (file_est_vide(file))
    {
        exit(EXIT_FAILURE);
    }

    NoeudEntier *resultat = file->elements[file->debut++];

    // Si le début de la file atteint la fin du tableau, revenir au début
    if (file->debut == file->taille - 1)
    {
        file->debut = 0;
    }

    return resultat;
}

void parcours_largeur(NoeudEntier *racine)
{
    File *file = creer_file(5);
    enfiler(file, racine);
    while (!file_est_vide(file))
    {
        NoeudEntier *noeud = defiler(file);
        printf("%d ", noeud->valeur);
        if (noeud->gauche != NULL)
        {
            enfiler(file, noeud->gauche);
        }
        if (noeud->milieu != NULL)
        {
            enfiler(file, noeud->milieu);
        }
        if (noeud->droite != NULL)
        {
            enfiler(file, noeud->droite);
        }
    }
    printf("\n");
}

int main()
{
    /*
    we have a litle problem , the insererNoeudFalse take the racine as an argument so we can change only the values inside the racine
    if we passed the racine and it's NULL all the functions will not work , that's why we write NoeudEntier *racine = creerNoeud(10);
    before working with insererNoeud , to solve this prb we must pass a pointer to the racine so we can change it's value(we can allocate to it a memory)
    or we can use this trick*/
    // NoeudEntier *racine = creerNoeud(10);
    // insererNoeudFalse(racine, 5);
    // insererNoeudFalse(racine, 15);
    // insererNoeudFalse(racine, 12);
    // insererNoeudFalse(racine, 20);
    // insererNoeudFalse(racine, 7);
    NoeudEntier *racine = NULL;

    insererNoeud(&racine, 15);
    insererNoeud(&racine, 3);
    insererNoeud(&racine, 26);
    insererNoeud(&racine, 2);
    insererNoeud(&racine, 7);
    insererNoeud(&racine, 18);
    insererNoeud(&racine, 19);
    insererNoeud(&racine, 1);
    printf("prefixe: ");
    afficherArbrePref(racine);
    printf("\n");
    printf("infixe: ");
    afficherArbreInf(racine);
    printf("\n");
    printf("postfixe: ");
    afficherArbrePostf(racine);
    printf("\n");
    printf("en largeur d'abord: ");
    parcours_largeur(racine);
    printf("\n");
    NoeudEntier *resultPre = predecesseur(racine->droite);
    NoeudEntier *resultsecc = seccesseur(racine);
    NoeudEntier **el = searchNoeud(&racine, 12);
    printf("infixe: ");
    afficherArbreInf(racine);
    printf("\n");
    supprimerNoeud(&racine, 5);
    supprimerNoeud(&racine, 7);
    supprimerNoeud(&racine, 2);
    printf("infixe: ");
    afficherArbreInf(racine);
    printf("\n");
    libererArbre(racine);
    return 0;
}

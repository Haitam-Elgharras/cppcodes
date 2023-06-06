#include <iostream>
#include "Etudiants.h"

using namespace std;

class File
{
private:
    Etudiants *tab; // tableau d'étudiants
    int taille;     // taille de la file
    int tete;       // indice de la tête de la file
    int queue;      // indice de la queue de la file
public:
    // Constructeur
    File(int taille)
    {
        tab = new Etudiants[taille];
        this->taille = taille;
        tete = 0;
        queue = -1;
    }

    // Destructeur
    ~File()
    {
        delete[] tab;
    }

    // Vérifier si la file est vide
    bool estVide()
    {
        return (queue == -1);
    }

    // Vérifier si la file est pleine
    bool estPleine()
    {
        return (queue == taille - 1);
    }

    // Ajouter un étudiant à la fin de la file
    void enfiler(Etudiants e)
    {
        if (estPleine())
        {
            cout << "La file est pleine, impossible d'ajouter un etudiant." << endl;
            return;
        }
        queue++;
        tab[queue] = e;
    }

    // Retirer l'étudiant en tête de la file et le retourner
    Etudiants defiler()
    {
        if (estVide())
        {
            cout << "La file est vide, impossible de retirer un etudiant." << endl;
            return Etudiants("", 0);
        }
        Etudiants e = tab[tete];
        tete++;
        if (tete > queue)
        {
            tete = 0;
            queue = -1;
        }
        return e;
    }
};

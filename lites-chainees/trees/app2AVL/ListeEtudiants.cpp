#include <iostream>
#include <vector>
#include "Etudiants.h"

using namespace std;

class ListeEtudiants
{
private:
    vector<Etudiants> liste;
    int tailleMax;

public:
    ListeEtudiants(int tailleMax)
    {
        this->tailleMax = tailleMax;
    }

    int taille() const
    {
        return liste.size();
    }

    bool inserer(Etudiants e)
    {
        if (liste.size() >= tailleMax)
        {
            return false;
        }
        liste.push_back(e);
        return true;
    }

    bool supprimer(int matricule)
    {
        for (auto it = liste.begin(); it != liste.end(); it++)
        {
            if (it->getMatricule() == matricule)
            {
                liste.erase(it);
                return true;
            }
        }
        return false;
    }

    void afficher() const
    {
        for (auto e : liste)
        {
            cout << e << endl;
        }
    }
};

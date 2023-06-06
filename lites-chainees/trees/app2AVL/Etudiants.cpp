#include "Etudiants.h"

Etudiants::Etudiants(string nom)
{
    this->nom = nom;
    this->notes = vector<float>();
    this->moy = 0;
}

int Etudiants::getMatricule()
{
    return this->matricule;
}

string Etudiants::getNom()
{
    return this->nom;
}

vector<float> Etudiants::getNotes()
{
    return this->notes;
}

float Etudiants::getMoyenne()
{
    return this->moy;
}

void Etudiants::setMatricule(int matricule)
{
    this->matricule = matricule;
}

void Etudiants::ajouterNote(float note)
{
    this->notes.push_back(note);
    this->calculerMoyenne();
}

void Etudiants::calculerMoyenne()
{
    float somme = 0;
    for (float note : this->notes)
    {
        somme += note;
    }
    this->moy = somme / this->notes.size();
}

string Etudiants::toString()
{
    string result = "Matricule: " + to_string(this->matricule) + ", Nom: " + this->nom + ", Notes: [";
    for (int i = 0; i < this->notes.size(); i++)
    {
        result += to_string(this->notes[i]);
        if (i < this->notes.size() - 1)
        {
            result += ", ";
        }
    }
    result += "], Moyenne: " + to_string(this->moy);
    return result;
}

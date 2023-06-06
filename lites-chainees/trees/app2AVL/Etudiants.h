#include <string>
#include <vector>

class Etudiant
{
private:
    static int compteur_matricule;
    int matricule;
    std::string nom;
    std::vector<float> notes;
    float moyenne;

public:
    Etudiant(std::string nom, std::vector<float> notes);
    int getMatricule() const;
    std::string getNom() const;
    void setNom(std::string nom);
    std::vector<float> getNotes() const;
    void setNotes(std::vector<float> notes);
    float getMoyenne() const;
    void calculerMoyenne();
};

int Etudiant::compteur_matricule = 0;

Etudiant::Etudiant(std::string nom, std::vector<float> notes)
    : matricule(++compteur_matricule), nom(nom), notes(notes), moyenne(0) {}

int Etudiant::getMatricule() const
{
    return matricule;
}

std::string Etudiant::getNom() const
{
    return nom;
}

void Etudiant::setNom(std::string nom)
{
    this->nom = nom;
}

std::vector<float> Etudiant::getNotes() const
{
    return notes;
}

void Etudiant::setNotes(std::vector<float> notes)
{
    this->notes = notes;
}

float Etudiant::getMoyenne() const
{
    return moyenne;
}

void Etudiant::calculerMoyenne()
{
    float somme = 0;
    for (float note : notes)
    {
        somme += note;
    }
    moyenne = somme / notes.size();
}

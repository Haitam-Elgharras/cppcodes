#include <iostream>
using namespace std;
class Personne
{
protected:
    string nom, prenom;
    string date;

public:
    virtual void afficher();
    // void saisie(string Nom, string Prenom, string Date)
    // {
    //     nom = Nom;
    //     prenom = Prenom;
    //     date = Date;
    // }
};
void Personne::afficher()
{
    cout << "from an obj of Personne class" << endl;
}
class Etudiant : public Personne
{
    int niveau;
    string specialite;
    float *notes;

public:
    void saisie(string nom, string prenom, string date, int niveau, string specialite, float notes[]);
    void afficher() override
    {
        cout << "nom :" << nom << " specialite :" << specialite << moyenne() << endl;
        cout << "from etudiant" << endl;
    }
    float moyenne();
};
void Etudiant::saisie(string Nom, string Prenom, string Date, int Niveau, string Specialite, float *notes_)
{

    niveau = Niveau;
    specialite = Specialite;
    // Personne::saisie(nom, prenom, date);
    nom = Nom;
    prenom = Prenom;
    date = Date;
    notes = new float(sizeof(notes_) / sizeof(notes_[0]));
    for (int i = 0; i < sizeof(notes_) / sizeof(notes_[0]); i++)
    {
        notes[i] = notes_[i];
    }
    cout << "true";
    return;
}

float Etudiant::moyenne()
{
    float m = 0;
    for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++)
    {
        m += notes[i];
    }
    return m / (sizeof(notes) / sizeof(notes[0]));
}
class Enseignant : public Personne
{
    string diplome;
    string specialite;
    float nombre_heures;
    int taux;

public:
    void saisie(string nom, string prenom, string date, string diplome, string specialite, float nombre_heures, int taux);
    void afficher() override
    {
        // cout << "nom :" << nom << " diplome :" << diplome << endl;
        cout << "from enseignant" << endl;
    }
    float salaire();
};
void Enseignant::saisie(string Nom, string Prenom, string Date, string Diplome, string Specialite, float Nombre_heures, int Taux)
{
    diplome = Diplome;
    specialite = Specialite;
    nombre_heures = Nombre_heures;
    taux = Taux;
    // Personne::saisie(Nom, Prenom, Date);
    nom = Nom;
    prenom = Prenom;
    date = Date;
};

float Enseignant::salaire()
{
    cout << "le salaire est : " << nombre_heures * taux * 0.83;
    return nombre_heures * taux * 0.83;
}
void presenter(Personne &obj1, Personne &obj2, Personne &obj3)
{
    obj1.afficher();
    obj2.afficher();
    obj3.afficher();
}

int main()
{
    Etudiant et;
    Personne p;
    Enseignant en;
    // presenter(p, et, en);
    float notes[] = {10, 15.5, 16, 19};
    cout << "true";
    et.saisie("elgharras", "haitam", "2002-10-3", 16, "GLSID", notes);

    et.afficher();
    return 0;
}
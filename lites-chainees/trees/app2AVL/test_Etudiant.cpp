#include <iostream>
#include <vector>
#include "Etudiants.h"

using namespace std;

int main()
{
    // Création d'un étudiant
    vector<float> notes1 = {10.0, 12.5, 14.0};
    Etudiant etudiant1("john", notes1);

    // Accès aux attributs de l'étudiant
    cout << "Matricule: " << etudiant1.getMatricule() << endl;
    cout << "Nom: " << etudiant1.getNom() << endl;
    cout << "Notes: ";
    for (float note : etudiant1.getNotes())
    {
        cout << note << " ";
    }
    cout << endl;
    cout << "Moyenne: " << etudiant1.getMoyenne() << endl;

    // Modification de l'attribut nom
    etudiant1.setNom("john-jack");
    cout << "Nouveau nom: " << etudiant1.getNom() << endl;

    // Modification de l'attribut notes
    vector<float> notes2 = {8.0, 10.5, 9.0};
    etudiant1.setNotes(notes2);
    cout << "Nouvelles notes: ";
    for (float note : etudiant1.getNotes())
    {
        cout << note << " ";
    }
    cout << endl;

    // Recalcul de la moyenne
    etudiant1.calculerMoyenne();
    cout << "Nouvelle moyenne: " << etudiant1.getMoyenne() << endl;

    return 0;
}

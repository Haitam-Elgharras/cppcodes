#include <iostream>
#include <string>

using namespace std;

class Produit
{
private:
    int reference;
    string designation;
    float prix_unitaire;

public:
    Produit(int ref, string desig, float prix) : reference(ref), designation(desig), prix_unitaire(prix) {}

    string ToString() const
    {
        cout << "reference : " << reference << endl;
        cout << "Designation : " << designation << endl;
        cout << "Prix unitaire : " << prix_unitaire << " DH" << endl;
        return "Référence : " + to_string(reference) + ", Désignation : " + designation + ", Prix unitaire : " + to_string(prix_unitaire);
    }

    float GetPrix()
    {
        return prix_unitaire;
    }

    void SetPrix(float nouveau_prix)
    {
        prix_unitaire = nouveau_prix;
    }

    void AfficherP()
    {
        cout << "Le prix du produit est : " << prix_unitaire << " euros" << endl;
    }
};

class ProduitEnSolde : public Produit
{
    int TauxRemise;

public:
    ProduitEnSolde(float x, string y, float z, int t) : Produit(x, y, z), TauxRemise(t) {}
    int GetRemise()
    {
        return TauxRemise;
    }
    void SetRemise(int NvTauxRemise)
    {
        TauxRemise = NvTauxRemise;
    }
    float GetPrix()
    {
        return Produit::GetPrix() * (1 - TauxRemise * 0.01);
    }
    void AfficherP()
    {
        cout << "Le prix du produit est : " << GetPrix() << " euros" << endl;
        cout << "le pourcentage de remise est de :" << TauxRemise << "%" << endl;
    }

    // void ToString() const
    // {
    //     Produit::ToString();
    //     cout << "Taux de remise : " << TauxRemise << "%" << endl;
    // }
};

int main()
{
    string st = "bobi";
    Produit newProduit(11755, st, 155.6);
    ProduitEnSolde newProduitSolde(22556, st, 200, 10);
    newProduit.AfficherP();
    newProduitSolde.AfficherP();
    return 0;
}

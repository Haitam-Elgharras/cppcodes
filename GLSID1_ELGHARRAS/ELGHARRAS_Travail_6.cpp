#include <iostream>
using namespace std;
class Elgharras_Cercle
{
    float x, y;
    float R;

public:
    // travail_5
    void Elgharras_Affiche(char *nom)
    {
        cout << "le cercle " << *nom << " est defini par :" << endl;
        Elgharras_Affiche();
    }
    void Elgharras_Affiche()
    {
        cout << "le cercle est defini par :" << endl;
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
        cout << "R=" << R << endl;
    }

    // travail_4
    static int nombre_Objet_Cercle;
    void affiche_Nombre_Objet_Cercle()
    {
        cout << "le nombre d'objet cercle est :" << nombre_Objet_Cercle << endl;
    }

    // travail_3
    Elgharras_Cercle()
    {
        cout << "le constructeur par defaut" << endl;
        x = y = 0;
        R = 0;
        nombre_Objet_Cercle++;
    }
    Elgharras_Cercle(float a)
    {
        cout << "le constructeur avec un parametre" << endl;
        x = y = a;
        R = a;
        nombre_Objet_Cercle++;
    }
    Elgharras_Cercle(float a, float b, float c)
    {
        cout << "le constructeur avec trois parametres" << endl;
        x = a;
        y = b;
        R = c;
        nombre_Objet_Cercle++;
    }
    ~Elgharras_Cercle()
    {
        cout << "le destructeur appeler sur le cercle defini par " << endl;
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
        cout << "R=" << R << endl;
        nombre_Objet_Cercle--;
    }

    // travail_2
    void Elgharras_Definir()
    {
        cout << "donner les coordonnees du centre du cercle" << endl;
        cin >> x >> y;
        cout << "donner le rayon du cercle" << endl;
        cin >> R;
    }
    float Elgharras_perimetre()
    {
        return 2 * 3.14 * R;
    }
    float Elgharras_Surface()
    {
        return 3.14 * R * R;
    }
};
// travail_4
int Elgharras_Cercle::nombre_Objet_Cercle = 0;

int main()
{
    // teste travail_6
    Elgharras_Cercle C1(2.22, 5.55, 12);
    Elgharras_Cercle C2(3.2, 0, 2);
    Elgharras_Cercle C4(3.2, 0, 2);
    Elgharras_Cercle C5(3.2, 0, 2);
    Elgharras_Cercle C6(3.2, 0, 2);
    C1.Elgharras_Affiche();
    C2.Elgharras_Affiche();
    C1.Elgharras_perimetre();
    C2.Elgharras_perimetre();
    C1.affiche_Nombre_Objet_Cercle();
    C1.Elgharras_Surface();
    C2.Elgharras_Surface();
    C1.Elgharras_Affiche();
    C2.Elgharras_Affiche();
    C1.Elgharras_perimetre();
    C2.Elgharras_perimetre();
    C1.affiche_Nombre_Objet_Cercle();
    C1.Elgharras_Surface();
    C2.Elgharras_Surface();
    C1.Elgharras_Affiche();

    return 0;
}
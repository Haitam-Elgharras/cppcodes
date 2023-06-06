#include <iostream>
using namespace std;
class Elgharras_Cercle
{
    float x, y;
    float R;

public:
    // travail_3
    Elgharras_Cercle();
    Elgharras_Cercle(float);
    Elgharras_Cercle(float, float, float);
    ~Elgharras_Cercle();

    // travail_2
    void Elgharras_Definir();
    float Elgharras_perimetre();
    float Elgharras_Surface();
    void Elgharras_Affiche();
};

// travail_3
Elgharras_Cercle::Elgharras_Cercle()
{
    cout << "le constructeur par defaut" << endl;
    x = y = 0;
    R = 0;
}
Elgharras_Cercle::Elgharras_Cercle(float a)
{
    cout << "le constructeur avec un parametre" << endl;
    x = y = a;
    R = a;
}
Elgharras_Cercle::Elgharras_Cercle(float a, float b, float c)
{
    cout << "le constructeur avec trois parametres" << endl;
    x = a;
    y = b;
    R = c;
}
Elgharras_Cercle::~Elgharras_Cercle()
{
    cout << "le destructeur appeler sur le cercle defini par " << endl;
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "R=" << R << endl;
}

// travail_2
void Elgharras_Cercle::Elgharras_Definir()
{
    cout << "donner les coordonnees du centre du cercle" << endl;
    cin >> x >> y;
    cout << "donner le rayon du cercle" << endl;
    cin >> R;
}
float Elgharras_Cercle::Elgharras_perimetre()
{
    return 2 * 3.14 * R;
}
float Elgharras_Cercle::Elgharras_Surface()
{
    return 3.14 * R * R;
}
void Elgharras_Cercle::Elgharras_Affiche()
{
    cout << "le cercle est defini par :" << endl;
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "R=" << R << endl;
}
int main()
{
    // travail_3
    Elgharras_Cercle C_Sans_Parametre; // tester le constructeur par defaut
    C_Sans_Parametre.Elgharras_Affiche();

    Elgharras_Cercle C_Un_Parametre(5.66); // tester le constructeur avec un parametre
    C_Un_Parametre.Elgharras_Affiche();

    Elgharras_Cercle C_Trois_Parametres(2.564, 3.33, 10); // tester le constructeur avec trois parametres
    C_Trois_Parametres.Elgharras_Affiche();

    return 0;
}
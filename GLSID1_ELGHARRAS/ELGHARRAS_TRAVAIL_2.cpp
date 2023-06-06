#include <iostream>
using namespace std;
class Elgharras_Cercle
{
    float x, y;
    float R;

public:
    void Elgharras_Definir();
    float Elgharras_perimetre();
    float Elgharras_Surface();
    void Elgharras_Affiche();
};
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
    Elgharras_Cercle C;
    C.Elgharras_Definir();
    cout << "le perimetre du cercle est :" << C.Elgharras_perimetre() << endl;
    cout << "la surface du cercle est :" << C.Elgharras_Surface() << endl;
    C.Elgharras_Affiche();
    return 0;
}
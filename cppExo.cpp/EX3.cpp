

#include <iostream>
using namespace std;

class vecteur
{
    float x, y;

public:
    vecteur(float abs, float ord);
    vecteur &homothetie(float val);
    void affiche();
    float det(vecteur &);
};
// si on ne mis pas abs=0 ord=0 et on declare un vecteur sans parametre => erreur : no default constructor
vecteur::vecteur(float abs = 0, float ord = 0)
{
    x = abs;
    y = ord;
}
vecteur &vecteur::homothetie(float val)
{
    // obligatoirement static pour etre indépendent du scoop et des objects
    static vecteur myNewVar;
    myNewVar.x = x * val;
    myNewVar.y = y * val;
    return myNewVar;
}
void vecteur::affiche()
{
    cout << "Les coordonnees du vecteur sont : " << x << " et " << y << endl;
}
float vecteur::det(vecteur &v)
{
    return v.y * x - v.x * y;
}

int main()
{
    vecteur myV1(1, 2), myV2(1, 1);
    // passage par reference
    cout << "le nouveau vecteur est ";
    // ici ona le variable static
    myV1.homothetie(2).affiche(); // 2 et 4

    return 0;
}
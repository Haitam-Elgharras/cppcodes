#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Elgharras_Cercle
{
    float x, y;
    float R;

public:
    // travail_7
    void meme(Elgharras_Cercle &);

    // travail_5
    // on reprend la fonction affiche qui est defini dans le travail_2
    virtual void Elgharras_Affiche();
    void Elgharras_Affiche(char *);

    // travail_4
    static int nombre_Objet_Cercle;
    void affiche_Nombre_Objet_Cercle();

    // travail_3
    Elgharras_Cercle();
    Elgharras_Cercle(float);
    Elgharras_Cercle(float, float, float);
    ~Elgharras_Cercle();

    // travail_2
    void Elgharras_Definir();
    float Elgharras_perimetre();
    float Elgharras_Surface();
};
// travail_8
class Elgharras_Cerclecol : public Elgharras_Cercle
{
    char *couleur;

public:
    Elgharras_Cerclecol() : Elgharras_Cercle()
    {
        couleur = nullptr;
    }

    Elgharras_Cerclecol(float a, char *col) : Elgharras_Cercle(a)
    {
        couleur = new char[strlen(col) + 1];
        strcpy(couleur, col);
    }

    Elgharras_Cerclecol(float a, float b, float c, const char *col) : Elgharras_Cercle(a, b, c)
    {
        couleur = new char[strlen(col) + 1];
        strcpy(couleur, col);
    }
    ~Elgharras_Cerclecol()
    {
        delete[] couleur;
    }

    void Elgharras_Affiche()
    {
        Elgharras_Cercle::Elgharras_Affiche();
        if (couleur != nullptr)
            cout << "Couleur : " << couleur << endl;
    }

    void Elgharras_Definir()
    {
        Elgharras_Cercle::Elgharras_Definir();
        cout << "Donner la couleur du cercle : ";
        cin >> couleur;
    }
};

// trvaail_7
void Elgharras_Cercle::meme(Elgharras_Cercle &C)
{
    if (&C == this)
    {
        cout << "les deux cercles sont les memes" << endl;
        return;
    }

    if (this->x == C.x && this->y == C.y && this->R == C.R)
    {
        cout << "les deux cercles ont les meme cordonnees et le meme rayone" << endl;
    }
    else
    {
        cout << "les deux cercles ne sont pas les memes" << endl;
    }
}
// travail_5
void Elgharras_Cercle::Elgharras_Affiche(char *nom)
{
    cout << "le cercle " << *nom << " est defini par :" << endl;
    Elgharras_Affiche();
}
void Elgharras_Cercle::Elgharras_Affiche()
{
    cout << "le cercle est defini par :" << endl;
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "R=" << R << endl;
}

// travail_4
int Elgharras_Cercle::nombre_Objet_Cercle = 0;
void Elgharras_Cercle::affiche_Nombre_Objet_Cercle()
{
    cout << "le nombre d'objet cercle est :" << nombre_Objet_Cercle << endl;
}
void Test()
{
    Elgharras_Cercle C1(2.22, 5.55, 12);
    Elgharras_Cercle C2(3.2, 0, 2);
}
// travail_3
Elgharras_Cercle::Elgharras_Cercle()
{
    cout << "le constructeur par defaut" << endl;
    x = y = 0;
    R = 0;
    nombre_Objet_Cercle++;
}
Elgharras_Cercle::Elgharras_Cercle(float a)
{
    cout << "le constructeur avec un parametre" << endl;
    x = y = a;
    R = a;
    nombre_Objet_Cercle++;
}
Elgharras_Cercle::Elgharras_Cercle(float a, float b, float c)
{
    cout << "le constructeur avec trois parametres" << endl;
    x = a;
    y = b;
    R = c;
    nombre_Objet_Cercle++;
}
Elgharras_Cercle::~Elgharras_Cercle()
{
    cout << "le destructeur appeler sur le cercle defini par " << endl;
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "R=" << R << endl;
    nombre_Objet_Cercle--;
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

int main()
{
    // tester travail_8
    Elgharras_Cerclecol C1(2.22, 5.55, 12, "rouge");
    Elgharras_Cerclecol C2(3.2, 0, 2, "bleu");
    C1.Elgharras_Affiche();

    return 0;
}
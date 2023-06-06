#include <iostream>
#include <string>
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
    void Elgharras_Affiche();
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
    // tester travail_7
    // tester la fonction meme
    Elgharras_Cercle C1(2.22, 5.55, 12);
    Elgharras_Cercle C2(2.22, 5.55, 12);
    C1.meme(C2); // les deux cercles ont les meme cordonnees et le meme rayone
    C1.meme(C1);
    Elgharras_Cercle C3(3);
    Elgharras_Cercle C4(4);
    C3.meme(C4); // les deux cercles ne sont pas les memes

    return 0;
}
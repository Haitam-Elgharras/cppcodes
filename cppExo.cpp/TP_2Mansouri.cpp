#include <iostream>
#include <stdlib.h>
class point
{
private:
    int x, y, couleur;

public:
    void initialiser(int, int, int);
    void deplacer(int, int);
    void afficher();
    void effacer();
};

void point::initialiser(int x, int y, int couleur)
{
    this->x = x;
    this->y = y;
    this->couleur = couleur;
}
void point::deplacer(int dx, int dy)
{
    x = x + dx;
    y = y + dy;
}
void afficher()
{
}
void effacer();
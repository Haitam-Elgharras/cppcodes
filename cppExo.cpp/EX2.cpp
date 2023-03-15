

#include <iostream>
using namespace std;

class point
{
    int x, y;

public:
    point();
    point(int);
    point(int, int);
    void affiche();
    void affiche(char *);
};

point::point()
{
    x = y = 0;
}
point::point(int val)
{
    x = y = val;
}
point::point(int val1, int val2)
{
    x = val1;
    y = val2;
}
void point::affiche()
{
    cout << " :x= " << x << " et y= " << y << endl;
}
void point::affiche(char *name)
{
    cout << *name;
    affiche();
}

int main()
{
    char newName;
    cin >> newName;
    point p1(1, 3);
    p1.affiche(&newName);
    point p2(5);
    cin >> newName;
    p2.affiche(&newName);

    point p3;
    cin >> newName;
    p3.affiche(&newName);
}

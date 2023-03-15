
#include <iostream>
#include <stdlib.h>
using namespace std;

// class hasard
// {
//     int *val;
//     int nbVal;
//     int max;
//     hasard(int, int);
//     ~hasard();
// };

// hasard::hasard(int max, int nbVal = 10)
// {
//     this->nbVal = nbVal;
//     this->max = max;
//     val = new int[nbVal];
//     for (int i = 0; i < nbVal; i++)
//     {
//         val[i] = rand() % (max + 1);
//         cout << rand() % (max + 1) << endl;
//     }
// }
// hasard ::~hasard()
// {
//     cout << "we will deallocate now" << endl;
//     delete[] val;
// }

/*


#include <iostream>
using namespace std;

class compteur
{
    // static int classMembres = 0; we can't initialize a static memeber inside the class

    static int classMembres;

public:
    compteur()
    {
        classMembres++;
    }
    ~compteur()
    {
        cout << classMembres << endl;
        classMembres--;
        cout << "an object was destroyed "
             << "the number of objects now is :" << classMembres << endl;
    }
};
int compteur::classMembres = 0;
void essai()
{
    compteur u, v;
}

int main()
{
    compteur a;
    essai();
    compteur a;

    return 0;
}*/

/*


#include <iostream>
using namespace std;

class point
{
    int x, y;

public:
    point()
    {
        x = y = 0;
    }
    point(int val)
    {
        x = y = val;
    }
    point(int val1, int val2)
    {
        x = val1;
        y = val2;
    }
    void affiche()
    {
        cout << " :x= " << x << " et y= " << y << endl;
    }
    void affiche(char *name)
    {
        cout << *name;
        affiche();
    }
};

int main()
{
    char newName;
    cin >> newName;
    point p1(1, 3);
    p1.affiche(&newName);
    point p2(5);
    cin >> newName;
    for (int i = 0; i < 90; i++)
    {
        p2.affiche(&newName);
    }
    point p3;
    cin >> newName;
    p3.affiche(&newName);
}
*/
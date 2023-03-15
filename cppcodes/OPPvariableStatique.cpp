#include <iostream>

using namespace std;

// Dans cet exemple, nous avons défini la classe MaClasse qui contient une variable de classe statique
// a et une variable d'instance b.

/*
 Lorsque nous créons deux objets obj1 et obj2 de la classe MaClasse, chaque objet aura sa propre copie
  de la variable d'instance b. Cela signifie que lorsque nous modifions la variable b de l'objet obj1,
   cela n'affecte pas la variable b de l'objet obj2.
 */

/*
 En revanche, la variable de classe statique a est partagée entre toutes les instances de la classe MaClasse.
  Cela signifie que lorsqu'on modifie la variable a d'un objet obj1, cela affecte la variable a
   de tous les autres objets MaClasse, y compris l'objet obj2.
*/
/*
 Dans l'exemple ci-dessus, nous avons modifié la variable a de l'objet obj1 pour la définir à 1,
  puis modifié la variable a de l'objet obj2 pour la définir à 3. En conséquence, lorsque nous affichons
   les valeurs de obj1.a et obj2.a, nous voyons que les deux objets ont la même valeur pour a,
    qui est la dernière valeur affectée (c'est-à-dire 3). D'un autre côté, nous voyons que obj1.
    b a la valeur 2 et obj2.b a la valeur 4, car chaque objet a sa propre copie de la variable b.

*/
/*
En résumé, la variable de classe statique a est partagée entre toutes les instances de la classe MaClasse,
 tandis que la variable d'instance b est unique à chaque instance de la classe MaClasse.
*/
class MaClasse
{
public:
    // variable de classe statique : ce variable est partagé par toutes les obj (drived base ....)
    static int a;
    // variable d'instance:chaqu'un a sa propre copie
    int b;
};

// If you try to compile and run this code without defining the static variable a outside the class,
// you will get a linker error
int MaClasse::a; // initialisation de la variable de classe statique

// note :Les membres de données statiques ne contribuent pas à la taille d’un objet.
int main()
{
    MaClasse obj1;
    MaClasse obj2;

    obj1.a = 1;
    obj1.b = 2;

    obj2.a = 3;
    obj2.b = 4;

    cout << "obj1.a = " << obj1.a << ", obj2.a = " << obj2.a << endl; // 3 3
    cout << "obj1.b = " << obj1.b << ", obj2.b = " << obj2.b << endl; // 2 4

    return 0;
}

// #######################################################################################
// const method

class MaClasse
{
    int var;

public:
    /*
    Comme write() est une fonction constante, donc il ne peut pas changer l’état d’un objet.
     Dans la fonction « write » nous essayons de modifier le membre « var » de l’objet,
     donc le programme affiche une erreur.*/
    int write(int i) const
    {
        var = i;
    }
    int read() const
    {
        return var;
    }
};
int main(int argc, char const *argv[])
{
    MaClasse obj;
    obj.write(2);
    cout << obj.read();
}

// correct form
class MaClasse
{

public:
    int var;
    // the const function musn't change the obj
    void write() const
    {
        cout << "here";
    }
    // the const function musn't change the obj

    int read() const
    {
        return var;
    }
};
int main(int argc, char const *argv[])
{
    MaClasse obj;
    obj.var = 10;
    obj.write();
    cout << obj.read();
}

// ####################################################################################"
// defaut de l'heritage multiple
#include <iostream>

using namespace std;

class A
{
public:
    int tab[10];
};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};

int main(void)
{
    /*Puisque B et C héritent de la classe mère A, deux copies de la classe mère
    sont présentes dans la classe D, donc 2*(4*10)=80 octets */
    cout << sizeof(D);
    D x;
    x.B::tab[0] = 10;
    x.C::tab[0] = 20;
    return 0;
}
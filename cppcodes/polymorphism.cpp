/*Polymorphism is a key concept in object-oriented programming, and it refers to the ability of objects
of different classes to be treated as objects of a common class. In C++, polymorphism is achieved
through virtual functions and function overriding.

A virtual function is a member function in a base class that can be overridden in derived classes.
When a virtual function is called through a pointer or reference to an object of a derived class,
  the function implementation of the derived class is executed, rather than the one in the base class.
  This is known as dynamic dispatch, and it allows objects of different classes to be treated polymorphically.

Here's an example to illustrate the use of polymorphism in C++:*/

#include <iostream>

class Shape
{
public:
  virtual void draw() { std::cout << "Drawing a shape." << std::endl; }
};

class Circle : public Shape
{
public:
  void draw() override { std::cout << "Drawing a circle." << std::endl; }
};

class Square : public Shape
{
public:
  void draw() override { std::cout << "Drawing a square." << std::endl; }
};
class Animal
{
public:
  virtual void makeSound() { std::cout << "Animal sound." << std::endl; }
};

class Dog : public Animal
{
public:
  void makeSound() override { std::cout << "Woof woof." << std::endl; }
};

class Cat : public Animal
{
public:
  void makeSound() override { std::cout << "Meow meow." << std::endl; }
};
/*les condition pour cree des fonction dans les classes dérivées (polymorphisme)

Il existe plusieurs conditions pour définir des méthodes dans une classe dérivée
qui implémentent le polymorphisme:

La classe de base doit définir une méthode virtuelle pure (virtual void foo() = 0).

La classe dérivée doit définir une implémentation pour cette méthode virtuelle.

La méthode définie dans la classe dérivée doit avoir le même nom et
la même signature que la méthode virtuelle pure définie dans la classe de base.

La méthode définie dans la classe dérivée doit être déclarée avec le mot-clé override
pour indiquer que c'est une surcharge de la méthode définie dans la classe de base.

Les objets de la classe dérivée peuvent être stockés dans un tableau
ou un pointeur vers la classe de base.
*/
int main()
{
  // new returns a pointer that's why we declare shape *shapes[]
  // what the shapes will take as methods ? circle or shape ?
  Shape *shapes[3];
  shapes[0] = new Shape;
  shapes[1] = new Circle;
  shapes[2] = new Square;
  /*result : Drawing a shape.
Drawing a circle.
Drawing a square.*/
  for (int i = 0; i < 3; i++)
  {
    shapes[i]->draw();
  }
  /*same as
    Shape s;
  Circle c;
  Square sq;

  s.draw();
  c.draw();
  sq.draw();*/

  /**
   *
   * it is possible to use the example of polymorphism without pointers.
    You can use object references instead of pointers, like this:

  */
  Animal animals[2];
  /*
    In the example, Dog() is a default constructor for the Dog class. A default constructor
    is a constructor that takes no arguments and creates an object using default values for
    its member variables. In this case,the Dog() constructor creates a Dog object and
    initializes it with default values.*/
  animals[0] = Dog();
  animals[1] = Cat();

  for (int i = 0; i < 2; i++)
  {
    animals[i].makeSound();
  }
  /*The difference between Dog() and new Dog is in the way they create and manage objects in memory.
Dog() creates a temporary Dog object on the stack. This means that the object is automatically destroyed
and its memory is freed when it goes out of scope (i.e. when the function that created it returns).

new Dog creates a Dog object on the heap. This means that the object will persist
in memory until it is explicitly destroyed using the delete operator. The memory for the object
is dynamically allocated using the new operator and must be explicitly freed using delete when
it is no longer needed, or it will result in a memory leak.*/

  return 0;
}

// ################################## la résolution dynamique des liens#######################

class Personne
{
public:
  virtual void afficher();
};

void Personne::afficher()
{
  cout << "from an obj of Personne class" << endl;
}

class Etudiant : public Personne
{
public:
  void afficher() override
  {
    // cout << "nom :" << nom << " specialite :" << specialite << endl;
    cout << "from etudiant" << endl;
  }
};

class Enseignant : public Personne
{
public:
  void afficher() override
  {
    // cout << "nom :" << nom << " diplome :" << diplome << endl;
    cout << "from enseignant" << endl;
  }
  float salaire();
};

void presenter(Personne &obj1, Personne &obj2, Personne &obj3)
{
  obj1.afficher();
  obj2.afficher();
  obj3.afficher();
}

int main()
{
  /*
    la résolution dynamique des liens nécéssite deux choses indisponsable :
      -utilisation du virtual methodes
      -utilisation du passage par référence ou adresse

    Si on n'utilise pas les deux la methode persenter va afficher pour n'import quel obj "from an obj of Personne class"
    car il connue que les obj passé sont de type Personne et la seul solution c'est la RDL
    */
  Etudiant et;
  Personne p;
  Enseignant en;
  presenter(p, et, en);
  return 0;
}

/*
*Here's an example to demonstrate the difference:
#include <iostream>

class Dog {
public:
  Dog() { std::cout << "Dog created." << std::endl; }
  ~Dog() { std::cout << "Dog destroyed." << std::endl; }
};

void func1() {
  Dog dog1;  // created on the stack
}  // destroyed automatically when the function returns

void func2() {
  Dog* dog2 = new Dog;  // created on the heap
  delete dog2;  // must be explicitly destroyed
}

int main() {
  func1();
  func2();
  return 0;
}
*/

// **************************************************************// *******************************
/*c'est quoi la difference entre class abstrait et concret avec des exemples

En programmation orientée objet, une classe abstraite est une classe qui ne peut pas être utilisée
pour créer des objets. Elle sert de base pour les classes dérivées qui peuvent être créées
sous forme d'objets. Une classe abstraite peut définir des méthodes virtuelles pures,
qui sont des méthodes sans corps qui #doivent être surchargées dans les classes dérivées.

Au contraire, une classe concrète est une classe qui peut être utilisée pour créer des objets.
Elle peut définir des méthodes concrètes qui ont des corps, et des méthodes virtuelles
  qui peuvent être surchargées dans les classes dérivées.*/
/*
#include <iostream>

class Shape {
public:
virtual void draw() = 0;  // méthode virtuelle pure
};

class Circle : public Shape {
public:
void draw() override { std::cout << "Drawing a circle." << std::endl; }
};

class Square : public Shape {
public:
void draw() override { std::cout << "Drawing a square." << std::endl; }
};
*/

// **************************************************************// *******************************

/*la spécification et la generalisation

En programmation orientée objet, la spécialisation et la généralisation sont des concepts importants
qui décrivent la relation entre les classes.

La spécialisation: est le processus de création d'une classe dérivée à partir d'une classe de base existante.
La classe dérivée hérite des propriétés et des comportements de la classe de base, mais peut également ajouter
  ou surcharger des méthodes pour fournir une implémentation plus spécifique. La classe dérivée est considérée
  comme une spécialisation de la classe de base.

La généralisation: est le processus inverse de la spécialisation. Elle consiste à définir une classe de base à partir
de plusieurs classes dérivées. La classe de base encapsule les propriétés et les comportements communs aux classes dérivées,
  et peut être utilisée pour représenter un ensemble plus large d'objets. la classe de base est considérées comme
  généralistaion  des classes dérivées

Voici un exemple en C++ pour montrer la spécialisation et la généralisation:

//example

class Animal {
public:
  virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
  void makeSound() override { std::cout << "Woof!" << std::endl; }
};

class Cat : public Animal {
public:
  void makeSound() override { std::cout << "Meow!" << std::endl; }
};

Dans cet exemple, la classe Animal est une classe de base qui définit une méthode virtuelle pure makeSound().
Les classes Dog et Cat sont des classes dérivées qui spécialisent la classe de base Animal en surchargeant
la méthode makeSound() pour fournir leur propre implémentation. La généralisation est représentée par
la définition de la classe de base Animal, qui encapsule le comportement commun à tous les animaux.

*/

/***********************************************************************************************/

/*
La différence entre une méthode virtuelle et une méthode virtuelle pure est la suivante :

1/Une méthode virtuelle #peut avoir un corps de méthode dans la classe de base,
tandis qu'une méthode virtuelle pure n'a pas de corps de méthode dans la classe de base.

2/Une méthode virtuelle peut être surchargée dans une classe dérivée (sinon on affiche la virtual de base),
tandis qu'une méthode virtuelle pure #doit être surchargée dans une classe dérivée (sinn error).

3/Une méthode virtuelle peut être appelée sur un objet de la classe de base,
tandis qu'une méthode virtuelle pure ne peut pas être appelée sur un objet de la classe de base.

Une classe qui définit une méthode virtuelle pure ne peut pas être
instanciée(cree un objet apartir de cette class),car elle est considérée comme une classe abstraite.
*/
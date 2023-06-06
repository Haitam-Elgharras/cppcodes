// CH5 SURDEFINITION DES OPERATEURS
#include <iostream>
using namespace std;
/*
Operator functions are special member functions of a class that define the behavior of an operator
 when applied to objects of that class.
 =>Limites :
 -Cannot overload operators for primitive types: Operators can only be overloaded for user-defined types,
  not for built-in types such as int or float.

-we can only overload the operators that are already defined in the language.

-you cannot overload operators such as the ternary conditional operator (? :), scope resolution operator (::),
 or the member selection operator (.)*/

/*
 NOTE :
 * 2-operator overloading can be done in two ways:

    1-Defining the operator as a member function: In this case, the operator function is a member function of the class
    and takes one or more arguments, including the object that called the function.

    2-Defining the operator as a non-member function: In this case, the operator function is defined outside the class,
    but has access to the private and protected members of the class by being declared as a friend of the class.
    The operator function takes one or more arguments, including at least one object of the class type.

  They have the following syntax:*/

return -type operator symbol(parameters)
{
    // Operator definition
}
//  example
class Point
{
public:
    // Constructor
    Point(int x, int y) : x_(x), y_(y) {}

    // Copy constructor
    Point(Point &other)
    {
        this->x_ = other.x_;
        this->y_ = other.y_;
    };
    // Define the = operator for the Point class
    // if we need This for cascaded assignments, such as t1 = t2 = t3; we add the return type
    void Point::operator=(const Point &other)
    {
        // Check for self-assignment
        if (this != &other)
        {
            // Copy the values of the other Point object
            x_ = other.x_;
            y_ = other.y_;
        }
    }
    // NOTE 1
    /*When an operator is overloaded for a class, it takes precedence over the default implementation of that operator.
     This means that when an object of that class is used with the overloaded operator, the implementation
     of the overloaded operator will be executed instead of the default implementation.
     in this case the = operator instead of the copy constructor which is called by default when we write a=b ;
     */
    // NOTE 2
    // if we assigne at the time of the creation of the object =>will call the copy contructor
    list myList2 = myList;

    cout << "Testing the = operator:\n";
    list myList3(0); // create an empty list to assign to
    // if the object is already exist and we assigne to it =>will call the '=' operator
    myList3 = myList;

    // Overloaded "+" operator for adding two Point objects
    // The function returns a new Point object
    // The function is marked as "const" to ensure that it does not modify the objects it operates on
    Point operator+(const Point &other) const
    {
        return Point(x_ + other.x_, y_ + other.y_);
    }

    // Overloaded "*" operator for scalar multiplication
    // The function returns a new Point object
    Point operator*(int h)
    {
        return Point(x_ * h, y_ * h);
    }

    // Overloaded "*" operator for dot product
    // The function returns an integer
    int operator*(const Point &other) const
    {
        return x_ * other.x_ + y_ * other.y_;
    }

    // Function to display the coordinates of the Point object
    // The function is marked as "const" to ensure that it does not modify the objects it operates on
    void display() const
    {
        std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
    }

private:
    int x_;
    int y_;
};

int main()
{
    Point a(1, 2);
    Point b(1, 2);

    // it's the same as c=a.operator+(b) but we must use the c=a+b cause if we use the 1st one
    // it's like a function and not a surdefinition
    Point c = a + b;
    c.display();

    int produitScalair = a * b;
    cout << produitScalair << endl;
    // a*5 will immediatly passed 5 to the operator*(int)
    a = a * 5;
    /*  5*a
     when we write a = 5 * a, the operator* function is called with 5 as the left operand and a as the right operand.
     This doesn't work because the operator* function is not defined to handle this case , it only knows how to multiply
     a Point object by an integer, not an integer by a Point object.*/
    a.display();
    return 0;
}

// ##############################################################################################################

/* friend functions :A friend function in C++ is a function that is not a member of a class
but has access to the private and protected members of the class. we can say that the benefit of those functions
when we need to do a summation we need two operand the friend function is more clear*/

class B
{
private:
    int b_private_member;

public:
    // Part of public interface
    friend int A::de_A(char, B); // Declare the friend function de_A from class A
};

class A
{
    int a_private_member;

public:
    int de_A(char c, B &b)
    {
        return b.b_private_member + c; // can Access the private member of class B
    }

    /* This declaration makes class C a friend of class A. This means that all the member functions of class C
    can access the private members of class A, even though they are not part of class A.*/
    friend class C;
};

class C
{

public:
    A all(A &a, A &b)
    {
        return a.a_private_member + b.a_private_member;
    }
}

// #######################################################################################################

// CH7 : la technique d'heritage

/*when a member variable or member function is declared as private in a class,it can only be accessed
 by other members of the same class.This means that even derived classes
 cannot directly access private elements of their parent classes.
 */

/*
-protected member in the base class :
A protected member in a base class is accessible from the derived class, but it is treated
as if it were declared private within the derived class. This means that you cannot access the protected member
 from outside the derived class, but you can access it from within the derived class's member functions*/

// public inhertitence
// Classe de base
class Base
{
private:
    int base_private_var;

protected:
    int base_protected_var;

public:
    int base_public_var;

    Base() : base_private_var(0), base_protected_var(0), base_public_var(0) {}

    void base_public_func() {}
};

// Classe dérivée héritant de Base

// public=public , private=private(inside the base and also the derived), protected=private ,
//  public directly , private protected indirectly from public functions (private 2 pb fct(set))(protected 1pc fct)
class Derived : public Base
{
private:
    int derived_private_var;

public:
    int derived_public_var;

    Derived() : derived_private_var(0), derived_public_var(0) {}

    void derived_public_func() {}
};

int main()
{
    // Création d'une instance de Base
    Base b;

    // Accès aux membres publics de Base
    b.base_public_var = 42;
    b.base_public_func();

    // Création d'une instance de Derived
    Derived d;

    // Accès aux membres publics de Derived
    d.derived_public_var = 23;
    d.derived_public_func();

    // Accès aux membres publics de Base via une instance de Derived
    d.base_public_var = 13;
    d.base_public_func();

    // Impossible d'accéder aux membres privés de Base et de Derived depuis l'extérieur
    // d.base_private_var = 10; // Erreur de compilation : 'int Base::base_private_var' is private within this context
    // d.derived_private_var = 20; // Erreur de compilation : 'int Derived::derived_private_var' is private within this context
    // d.base_protected_var=30; //Erreur de compilation :'int base::base_protected_var' is protected within this context(acessible inside the class)

    return 0;
}

// inhertite private :

class Base
{
private:
    int base_private_var;

protected:
    int base_protected_var = 33;

public:
    int sendPrivateToDrived()
    {
        return base_private_var;
    }
    int base_public_var;

    Base() : base_private_var(0), base_protected_var(0), base_public_var(0) {}

    void base_public_func() {}
};

// Derived class with private inheritance from Base
// public=private , private=private, protected=private , public indirectly , private protected indirectly
class Derived : private Base
{
private:
    int derived_private_var;

public:
    int derived_public_var;

    Derived() : derived_private_var(0), derived_public_var(0) {}

    void derived_public_func() {}

    int accessBaseMembers()
    {
        // Accessing public members of Base
        base_public_var = 13;
        base_public_func();
        base_protected_var = 33;
        return base_protected_var;
        // Cannot access private and protected members of Base from outside the Derived class
        // base_private_var = 10; // Compilation error: 'int Base::base_private_var' is private within this context
        // base_protected_var = 30; // Compilation error: 'int Base::base_protected_var' is protected within this context
    }
};

int main()
{
    // Creating instances of Base and Derived
    Base b;
    Derived d;

    // Accessing public members of Base
    b.base_public_var = 42;
    b.base_public_func();

    // Cannot access members of Base from outside the Derived class
    // d.base_public_var = 13; // Compilation error: 'Base' is a private base of 'Derived'
    // d.base_public_func(); // Compilation error: 'Base' is a private base of 'Derived'

    // Accessing members of Derived
    d.derived_public_var = 23;
    d.derived_public_func();

    // Accessing public members of Base via an instance of Derived
    cout << d.accessBaseMembers();

    return 0;
}

/*  NOTE1 : in this case if we want the private inside the base we must have a method inside the base that return
 this value then this method will be private inside the drived ,then we make a public method in drived to send the value
 returned from this method

    NOTE2: for the public and protected we need just to define a public method inside the drived and return the values directly

    NOTE3: the private in the base always needs 2 functions

    NOTE4 :  we can use protected members in the base class as private. The same rules of using apply to
     both private and protected members in the base class.
    */

// example of this notes
// Classe de base
#include <iostream>
#include <string>
using namespace std;

class Base
{
private:
    int base_private_var;

protected:
    int base_protected_var;

public:
    int base_public_var;

    Base() : base_private_var(0), base_protected_var(0), base_public_var(0) {}

    // Method to get private member
    int get_base_private_var() const
    {
        return base_private_var;
    }
    void set_base_private_var_base(int value)
    {
        base_private_var = value;
    }
    void set_base_protected_var_base(int value)
    {
        base_protected_var = value;
    }
    int get_base_protected_var() const
    {
        return base_protected_var;
    }
};

// Classe dérivée héritant de Base
class Derived : private Base
{
private:
    int derived_private_var;

public:
    int derived_public_var;

    Derived() : derived_private_var(0), derived_public_var(0) {}

    // Method to set base private member
    void set_base_private_var_derived(int value)
    {
        set_base_private_var_base(value); // private inside the derived
    }

    // Method to get base protected member cause it considered private here
    int get_base_protected_var() const
    {
        return base_protected_var;
    }

    // Method to get base public member
    int get_base_public_var() const
    {
        return base_public_var;
    }

    int get_base_private_var_derived() const
    {
        return get_base_private_var();
    }
};
int main()
{
    // Création d'une instance de Base
    Base b;

    // Accès aux membres publics de Base
    b.base_public_var = 42;
    b.set_base_protected_var_base(99);
    cout << b.get_base_protected_var() << endl;

    // Création d'une instance de Derived
    Derived d;

    // Accès aux membres publics de Derived
    d.derived_public_var = 23;

    // Accès aux membres publics de Base via une instance de Derived
    d.base_public_var = 13;

    // Accès aux membres privés de Base et de Derived via une méthode publique de Derived
    d.set_base_private_var_derived(10);
    cout << d.get_base_private_var_derived();
    // Accès aux membres protégés et publics de Base via des méthodes publiques de Derived
    int base_protected_var = d.get_base_protected_var();
    int base_public_var = d.get_base_public_var();

    return 0;
}

// protected
//  Classe de base
class Base
{
private:
    int base_private_var;

protected:
    int base_protected_var;

public:
    int base_public_var;

    Base() : base_private_var(0), base_protected_var(0), base_public_var(0) {}

    void base_public_func() {}
};

// Classe dérivée héritant de Base
// protected =private=public=private;
/*
When a base class is inherited as protected, all of its members, including public and protected members,
 are treated as if they were private members of the derived class. This means that the derived class
 cannot access those members directly from outside the class, but it can access them through public
 or protected member functions of the derived class.*/
class Derived : protected Base
{
private:
    int derived_private_var;

public:
    int derived_public_var;

    Derived() : derived_private_var(0), derived_public_var(0) {}

    void derived_public_func() {}

    // Accessing the protected members of the base class using public member functions of the derived class
    void set_base_protected_var(int value)
    {
        base_protected_var = value;
    }

    int get_base_protected_var() const
    {
        return base_protected_var;
    }
};

int main()
{
    // Création d'une instance de Base
    Base b;

    // Accès aux membres publics de Base
    b.base_public_var = 42;
    b.base_public_func();

    // Création d'une instance de Derived
    Derived d;

    // Impossible d'accéder aux membres publics de Derived depuis l'extérieur
    // d.derived_public_var = 23; // Erreur de compilation : 'int Derived::derived_public_var' is inaccessible

    // Impossible d'accéder aux membres  de Base dans Derived depuis l'extérieur
    // d.derived_private_var = 20; // Erreur de compilation : 'int Derived::derived_private_var' is inaccessible
    // d.base_protected_var=30; && d.base_public_var; //Erreur de compilation :'int base::base_protected_var' is inaccessible

    // Accès aux membres publics de Base via une instance de Derived
    d.set_base_protected_var(30);
    // the same for public
    cout << d.get_base_protected_var() << endl;
    // d.base_public_var = 13;
    // d.base_public_func();

    return 0;
}

// ################################

// redefinition des fonctions memebres

/* In C++, it is possible to have multiple member functions with the same name, but we need to take a small precaution
  to avoid calling a function recursively.

    To avoid the recursive call of the affiche function, we use the scope resolution operator ::
   to call the affiche function of the point class from within the affiche function of the pointcol class.
   cause when an object of type pointcol call affiche we call directly the affiche in the pointcol implimentation

   If affiche() were to be called from within pointcol, the :: operator is used to specify that we want to call
    the implementation of affiche() that is defined in the point class. drivedObj.Base::functionOfBase();
    */
#include <iostream>
#include <cstdlib> // nécessaire pour la fonction exit()

class point
{
    int x, y;

public:
    void initialise(int abs, int ord)
    {
        x = abs;
        y = ord;
    }
    void deplace(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
    void affiche()
    {
        std::cout << "Le point est en (" << x << ", " << y << ")" << std::endl;
    }
};

class pointcol : public point
{
    short couleur;

public:
    void colore(short cl)
    {
        couleur = cl;
    }
    void affiche()
    {
        // Utilisation de l'opérateur de portée pour appeler la fonction affiche() de la classe point
        point::affiche();
        std::cout << "Couleur : " << couleur << std::endl;
    }
};

int main()
{
    pointcol p;
    p.initialise(10, 20);
    p.affiche();
    p.point::affiche(); // call the affiche of the base class
    p.deplace(2, 4);
    p.affiche();
    p.colore(2);
    p.affiche();
    exit(EXIT_SUCCESS); // nécessaire pour éviter que la console ne se ferme immédiatement
}

// ##############################################################################################

// constructor and destructor calls
/*
the constructors are called in the order of the inheritance hierarchy, from base to derived, while the destructors
 are called in the reverse order, from derived to base. This is because the base class must be fully constructed
 before the derived class can be constructed, and the opposite is true for destruction.

 NOTE : When an object of type Derived is created, its constructor is called first, which then calls the constructor
 of its base class Base. After the constructor of Base completes, the constructor of Derived continues and completes.
*/
class Base
{
public:
    Base(int x)
    {
        std::cout << "Base constructor called with x = " << x << std::endl;
    }
    ~Base()
    {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base
{
public:
    // if the base constructor needs arguments for attrs cames from base we passed them like this
    Derived(int x, int y) : Base(x)
    {
        std::cout << "Derived constructor called with y = " << y << std::endl;
    }
    ~Derived()
    {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main()
{
    Derived d;
    return 0;
}

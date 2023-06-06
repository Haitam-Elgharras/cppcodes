#include <iostream>
#include <typeinfo>

using namespace std;

// passage par reference
void passByAddress(int *ptr)
{
    *ptr = 42;
}

void passByReference(int &ref)
{
    ref = 42;
}

int main()
{
    int x = 0;

    passByAddress(&x);  // x vaut maintenant 42
    passByReference(x); // x vaut toujours 42

    return 0;
}

// ##################################################################################################

// type conversion in C++

/*En C++, il est possible de faire des conversions automatiques implicites
 entre les différents types de données, en utilisant les règles de promotion,
  de conversion et de classe de conversion.*/

int funcitionC()
{
    int j = 65;
    char c = j; // conversion de int à char
    double x = 3.141594545;
    float f = x;          // conversion de double à float
    int i = f;            // conversion de float à int
    unsigned int ui = -1; // conversion de -1 à unsigned int(from end)
    long l = ui;          // conversion de unsigned int à long
    bool b = l;           // conversion de long à bool

    cout << "c = " << c; // c = A, type = c
    cout << "f = " << f; // f = 3.14159,
    // i = 3
    cout << "i = " << i;
    // ui = 4294967295,
    cout << "ui = " << ui;
    // l = 4294967295,
    cout << "l = " << l;
    // b = 1,
    cout << "b = " << b;
    return 0;
}

// ##################################################################################################

// Function overloading,

// also known as method overloading, is a feature of object - oriented programming that allows multiple
//  functions to have the same name but different parameters.This means that you can define two or more
//  functions with the same name in the same scope, as long as they have different parameter lists.

int fucntionO()
{

    int sum(int a, int b)
    {
        return a + b;
    }

    double sum(double a, double b)
    {
        return a + b;
    }

    int main()
    {
        int x = 5, y = 7;
        double z = 3.14, w = 2.72;
        cout << sum(x, y) << endl; // should output 12
        cout << sum(z, w) << endl; // should output 5.86
        return 0;
    }
    return 12;
}
// code will result in a compilation error because the compiler is not sure whether to call
// the function with an int parameter or a float parameter:
void foo(int x) {}
void foo(float x) {}
int main()
{
    foo(5);
    return 0;
}
//*******************************

void essai(float x, char c, int n = 0)
{
    cout << "Fonction N°1: x = " << x << " c = " << c
         << " n = " << n << "\n";
}
void essai(float x, int n)
{
    cout << "Fonction N°2 : x = " << x << " n = " << n << "\n";
}
int main()
{
    char l = 'z';
    int u = 4;
    float y = 2.0;
    essai(y, l, u); // fonction N°1
    essai(y, l);    // fonction N°1
    essai(y, u);    // fonction N°2
    // fonction N°2 : car pour le première parametre les deux besion une conversion , main a la deuxième
    // parametre la fct 2 ne besion pas une convesion donc on choisi fct2
    essai(u, u);
    essai(u, l); // fonction N°1
    // rejet car les deux function besion le meme nombre de conversion (2 conversion) donc le compliteur
    // n'arrive pas a choisir la fonction convenable
    essai(y, y);    // rejet par le compilateur, mais pour quoi  ?
    essai(y, y, u); // fonction N°1
    return 0;
}

// default parameters
// Function overloading can also be used to define default arguments. Here's an example:
// the deafult variables should always be at the end
int sum(int a, int b, int c = 0)
{
    return a + b + c;
}
int sum(int a, int b);

int main()
{
    int x = 5, y = 7, z = 3;
    // which sum should be called ? it's a probelem without solution in c++
    cout << sum(x, y) << endl;
    cout << sum(x, y, z) << endl; // should output 15
    return 0;
}

/***********************************************************************************************************/

/*A destructor in C++ is a special member function that is called automatically
 when an object is destroyed or goes out of scope. Its primary purpose is to release
 any resources that were allocated during the lifetime of the object.
- the element is destroyed with a lifo type (but just when going out of it scope)
-the global objects are the last always

In C++, a destructor has the same name as that of the class, preceded by a tilde (~),
 and it does not have any parameters or return type. For example,*/

class Wall
{
public:
    // create a destructor
    ~Wall()
    {
        // code
    }
};

/*******************/

class Wall
{
private:
    double *ptr;

public:
    // constructor to allocate memory
    Wall()
    {
        ptr = new double[10];
        cout << "Memory allocated" << endl;
    }

    // destructor to release memory
    ~Wall()
    {
        delete[] ptr;
        cout << "Memory deallocated" << endl;
    }
};
/*Here, we have a class Wall with a constructor that allocates memory for a double array of size 10
 using the new operator. We also have a destructor that releases this memory using the delete[] operator.

When we create an object of the Wall class, the constructor is called and memory is allocated.
 When the object goes out of scope, the destructor is called and memory is released.
  This can be seen in the output of the program:*/

int main()
{
    Wall wall1;
    return 0;
}

/***************************/

class Wall
{
private:
    int *height;

public:
    Wall(int h)
    {
        height = new int;
        *height = h;
    }
    ~Wall()
    {
        delete height;
    }
};

int main()
{
    Wall *wall = new Wall(10);
    delete wall;
    return 0;
}

/*the problem of P1 and *P1 */

// tell me exactly what happend from the beginin to the end if this code point *P1 ; P1=new point(0,0); delete P1 ;
// the memory commes with new point(0,0) was deallocated but what about the memory comes with point *P1 ?

/*
point *P1;
P1 = new point(0, 0);
delete P1;
*/

/*
In the code point *P1 ; P1=new point(0,0); delete P1 ;, the following sequence of events occur:

point *P1 ; - a pointer to a point object is declared but not initialized.

P1=new point(0,0); - dynamic memory is allocated for a new point object and a pointer P1 is assigned
 the address of this newly allocated memory. The point object is initialized with x=0 and y=0.

delete P1 ; - The memory allocated to the point object is freed,
 but the pointer variable P1 still holds the address of the deallocated memory.

After step 3, the memory pointed to by P1 has been deallocated, and any attempt to dereference P1
would result in undefined behavior. However, the pointer variable P1 itself is still in scope
 and has not been explicitly destroyed. The memory used by the pointer variable P1 is automatically released when the scope
  in which P1 was declared is exited, or when the program terminates.*/

/* stack and heap */

// point *P1 in stack or heap ?
/*The pointer variable P1 itself is allocated on the stack, but the memory it points to
 (i.e., the point object created with new point(0,0)) is allocated on the heap.*/

// In C++, stack and heap are two different memory regions where objects can be allocated.
/*
Stack memory is used for local variables and function parameters. The stack is automatically managed by the system
 and is used for relatively small amounts of data. The lifetime of stack memory is limited to the scope of the function
  in which it is defined. When a function returns, the memory used by its stack is automatically freed.

Heap memory is used for dynamic memory allocation, where the size and lifetime of an object are not known at compile time.
 Memory is allocated on the heap using the new operator and is released using the delete operator.
  Heap memory has a potentially unlimited lifetime, and its allocation and deallocation must be managed manually by the programmer.

In the case of point *P1, P1 is a pointer to a point object, and it is initialized on the stack.
 When new point(0, 0) is called, memory is dynamically allocated on the heap to create a new point object.
  The address of the allocated memory is returned, and P1 is set to point to this memory location.

When delete P1 is called, the memory allocated by new is released, and the object is destroyed.
 However, the memory used by the pointer P1 itself is not released, as it was allocated on the stack
 and will be automatically released when the function returns.*/

/*



#######################################################################################################################*/

/*fonctions memebres */
/*
what is the diffrence between declaring a function inside the class and declare it outside the class

1/if we declare it inside the claas : (fast)

when a function is defined inline inside a class, the function's code is directly inserted
 into the code where it is called. This means that the function code is duplicated
 at each place where it is called, instead of being compiled once and linked like a normal function.
*

2/if we declare it outSide the class :(the time will be more )

When a function is defined outside of a class and called multiple times in a program,
 the function's code is compiled only once and then linked to the program at the linking phase.

 When a function is compiled one time and then executed multiple times,
 the function's code is stored in the program's executable file and is ready to be executed
 whenever the function is called. When the function is called, the program jumps to the address
 where the function's code is stored and begins executing the code. Once the function has completed its execution,
  it returns a result (if any) to the calling code.
*/

class MyClass
{
public:
    void foo()
    {
        // Some code here
    }
};

/*In this example, the foo() function is defined inline inside the MyClass class and is called twice in the main()
 function. When the program is compiled, the code for the foo() function is duplicated twice,
 once for each call to the function.*/
int main()
{
    MyClass obj;
    obj.foo();
    obj.foo();
    return 0;
}

// ###################################################################################################################

// CH5

// ###########################################################################################################

// constructor (destructor) called at main objects ? : yes

/*#include <iostream>

class Point
{
public:
    // Constructor
    Point(int x, int y) : x_(x), y_(y)
    {
        std::cout << "Constructor called for Point (" << x_ << ", " << y_ << ")" << std::endl;
    }

    // Destructor
    ~Point()
    {
        std::cout << "Destructor called for Point (" << x_ << ", " << y_ << ")" << std::endl;
    }

private:
    int x_;
    int y_;
};

// Function with static variable of Point class
void test()
{
    static Point staticPoint(1, 2);
    std::cout << "Inside test function" << std::endl;
}

int main()
{
    // Create object of Point class in main
    test();

    Point point(3, 4);
    std::cout << "Inside main function" << std::endl;

    // Call test function

    std::cout << "Exiting main function" << std::endl;
    return 0;
}*/

// ##############################################################################################

// pointer point to a deallocated memory? :we can't acess to this adress from any pointer point to this adress

/*#include <iostream>

class Point
{
public:
    Point(int x, int y) : x_(x), y_(y)
    {
        std::cout << "Constructor called for Point (" << x_ << ", " << y_ << ")" << std::endl;
    }

    ~Point()
    {
        std::cout << "Destructor called for Point (" << x_ << ", " << y_ << ")" << std::endl;
    }

    void affiche()
    {
        std::cout << "Accessing deleted memory: (" << this->x_ << ", " << this->y_ << ")" << std::endl;
    }

private:
    int x_;
    int y_;
};

void test(Point *ptr)
{
    std::cout << "Deleting Point from test function" << std::endl;
    delete ptr;
}

int main()
{
    Point *ptr1 = new Point(1, 2);
    Point *ptr2 = ptr1;
    std::cout << "Point created" << std::endl;

    // show before delete
    ptr1->affiche();

    // will delete the adress pointed by ptr1 so there so we can't acess to this adress from any pointer point to this adress
    test(ptr1);

    // Accessing the deleted memory through ptr2 & ptr1 can lead to undefined behavior
    ptr1->affiche(); // Accessing deleted memory: (807344064, 488)
    ptr2->affiche(); // Accessing deleted memory: (807344064, 488)

    return 0;
}*/

// #############################################################################################

// the copy constructor

/*
In C++, when you copy an object, a copy constructor is called to create a new object with the same values
 as the original object. If you don't define a copy constructor explicitly, the compiler will generate a default copy constructor
  that performs a shallow copy of the object's members.
*/

#include <iostream>
using namespace std;
class Point
{
public:
    Point(int x, int y) : x_(x), y_(y)
    {
        std::cout << "Constructor called for Point (" << x_ << ", " << y_ << ")" << std::endl;
    }

    Point(const Point &other) : x_(other.x_), y_(other.y_)
    {
        std::cout << "Copy constructor called for Point (" << x_ << ", " << y_ << ")" << std::endl;
    }
    void affiche()
    {
        cout << this->x_;
        cout << this->y_;
    }

private:
    int x_;
    int y_;
};

int main()
{
    Point a(1, 2);

    Point b = a;
    // or Point b(a);
    std::cout << "Copying Point" << std::endl;
    b.affiche();

    return 0;
}

// #######################################################################################################

// if the object has dynamic elements(or pointers) we have only way to solve this problem
/*
types of problems we have
 *problem of encapsulation : if the 1st element has a private attributes
 *problem of commun memory : the two ptrs will have the same memory
 *commun changes : if we modify at the 1st ptr the 2nd will change
 */

/* If the Point class has pointers as members, then the default copy constructor generated by the compiler
 will perform a shallow copy of those pointers.This means that the copied object will have pointers that point to
  the same memory locations as the original object, which can lead to problems if one object modifies the memory through the pointer.*/

//                                                                                                                                                                                                                                                                            To avoid these problems,
//     you need to define a copy constructor that performs a deep copy of the pointers.Here's an example of how to do this:

#include <iostream>

class Point
{
public:
    int *x_;
    int *y_;
    Point(int x, int y) : x_(new int(x)), y_(new int(y))
    {
        std::cout << "Constructor called for Point (" << *x_ << ", " << *y_ << ")" << std::endl;
    }

    // before declaring the copy constructor the *b.x=10 ; will change *b.x and and also *a.x
    Point(const Point &other) : x_(new int(*other.x_)), y_(new int(*other.y_))
    {
        std::cout << "Copy constructor called for Point (" << *x_ << ", " << *y_ << ")" << std::endl;
    }

    ~Point()
    {
        std::cout << "Destructor called for Point (" << *x_ << ", " << *y_ << ")" << std::endl;
        delete x_;
        delete y_;
    }
};

int main()
{
    Point a(1, 2);
    Point b = a;
    *b.x_ = 10;
    std::cout << "Copying Point" << std::endl;

    return 0;
}

// in this case the two objects has two different adresses but the adr's adresses  are the same
#include <iostream>
#include <conio.h>

class liste
{

public:
    int taille;
    float *adr;
    liste(int t);
    ~liste();
};

liste::liste(int t)
{
    taille = t;
    adr = new float[taille];
    std::cout << "Adresse de l'objet : " << this << std::endl;
    std::cout << "Adresse de tableau : " << adr << std::endl;
}

liste::~liste()
{

    std::cout << "Liberation de la place" << std::endl;
    std::cout << "Adresse de tableau : " << adr << std::endl;
    delete[] adr;
}

int main()
{
    std::cout << "Debut de main()" << std::endl;

    liste a(3);
    liste b = a;
    b.adr[0] = 10;
    std::cout << b.adr[0] << std::endl;
    std::cout << a.adr[0];
    std::cout
        << "Fin de main()" << std::endl;
    return 0;
}

/* in this (when having a dynamic attributes) case obligatory to work with copy constructor where we should use the reference passing obligatory
and when meet the table do a loop in each element and copy the value not the adresses : here is the copy constructor*/
liste::liste(const liste &other)
{
    // point b=a ; other is a it's the original object
    taille = other.taille;
    adr = new float[taille];
    for (int i = 0; i < taille; i++)
    {
        adr[i] = other.adr[i];
    }
    std::cout << "Copy constructor called for List with size " << taille << std::endl;
}

//***************************************************

// constructring and destructring of temporary objects

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        cout << "Constructing Point object at address: " << this << endl;
    }

    ~Point()
    {
        cout << "Destructing Point object at address: " << this << endl;
    }
};

int main()
{
    Point a(0, 0);
    a = Point(3, 4);
    a = Point(5, 6);

    /*
    Constructing Point object at address: exd404dffc18 create the variable a
    Constructing Point object at address: axd404dffc20 tmp (0,0) (and affecte it to a)
    Destructing Point object at address: axd404dffc20 destroyed tmp
    Constructing Point object at address: axd404dffc28 create tmp(3,4)...
    Destructing Point object at address: axd404dffc28
    Destructing Point object at address: axd4Ndffc18
*/
    return 0;
}

// #########################################################################################################################

// when a function return an object what happens ?
/*
where is stocked the return object ? as we know the p will destroyed after foo finished !!
In this example, the foo function returns a point object. When the foo function is called, a new point object p
 is created and initialized with coordinates (3, 4). Then, p is returned by value to the caller,
  which in this case is the main function.

  when p is returned from foo(), a new copy of the point object is created using the copy constructor.
  This copy is then returned to the caller. The copy is typically stored in a temporary location in memory,
   often referred to as the return value register.

   *NOTE if the returned object of the function has dynamic attr => copy constructor obligatory
*/
point foo()
{
    point p(3, 4);
    return p;
}

int main()
{
    point p1 = foo();
    p1.show();
    return 0;
}

//*****************************************************
// OBJECT OF OBJECT
#include <iostream>
#include <conio.h>
using namespace std;
class Point
{
    int x, y;

public:
    Point(int abs = 0, int ord = 0) : x(abs), y(ord)
    {
        cout << "point const ";
    }
};

class PointColore
{
    Point p;
    int couleur;

public:
    // the point constructor will be calling first casue we start with the first line
    // before entring on the paint color constructor
    PointColore(int abs = 0, int ord = 0, int coul = 0) : p(abs, ord)
    {
        cout << "color constr";
        couleur = coul;
    }
};

int main()
{
    PointColore pc(3, 9, 5);

    return 0;
}

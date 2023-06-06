
// l'heritage multiple
/*
multiple inheritance is a feature that allows a class to inherit from multiple base classes.
*/
class DerivedClass : access_specifier BaseClass1, access_specifier BaseClass2, ...
{
    // class definition
};

/*
In the diamond problem, the inheritance hierarchy forms a diamond shape, where a derived class inherits from two or more classes
 that inherit from a common base class. In your example, the diamond-shaped inheritance hierarchy would look like this:

    A
   / \
  B   C
   \ /
    D
In this case, if B and C override the same method of A, and D calls that method inherited from both B and C,
 it is unclear which version of the method to use. This ambiguity leads to a compilation error.

To resolve the diamond problem, C++ uses a technique called virtual inheritance. Virtual inheritance ensures
that there is only one copy of the common base class in the inheritance hierarchy. This way, the derived class
 can access the members of the common base class without any ambiguity. To use virtual inheritance,
 you need to declare the inheritance relationship with the virtual keyword, like this:

class A { ... };
class B : virtual public A { ... };
class C : virtual public A { ... };
class D : public B, public C { ... };
In this example, both B and C inherit virtually from A, and D inherits from both B and C. This ensures
 that there is only one copy of class A in the inheritance hierarchy, and the diamond problem is resolved.*/

//  example of diamond problem
#include <iostream>
using namespace std;
class A
{
public:
    void foo() { cout << "A::foo()" << endl; }
};

class B : public A
{
public:
    void foo() { cout << "B::foo()" << endl; }
};

class C : public A
{
public:
    void foo() { cout << "C::foo()" << endl; }
};

class D : public B, public C
{
public:
    void foo() { cout << "D::foo()" << endl; }
};

int main()
{
    D d;
    /* d.A::foo(); is an ambiguous base of 'D'*/
    d.A::foo();
    return 0;
}

// ################################################################################################

// ############### polymorphisme #####################

/*use pure virtual function , and also passed the arguments (inherited objects) by refrence or by adresse*/
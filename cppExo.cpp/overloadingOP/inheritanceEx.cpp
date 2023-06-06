// Base class
#include <iostream>
using namespace std;
class Base
{
private:
    int base_private_var;

protected:
    int base_protected_var = 33;

public:
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

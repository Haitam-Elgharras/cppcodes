#include <iostream>
using namespace std;
class instrument
{
public:
    // polymorphisme
    //  this make the implimentaion of makesound obligatory to all derived classes
    virtual void makesound() = 0; // it's a pure virtual fonction
    // every abstarct must have at least one pure v fonction
};
class accordion : public instrument
{
public:
    void makesound() override
    {
        cout << "this is obligatory sir ";
    }
};
class error : public instrument
{
public:
    void makesound() override
    {
        cout << "delete this to see the diffrence ";
    }
};
int main()
{
    accordion t;
    error p;
    p.makesound();
    t.makesound();
}
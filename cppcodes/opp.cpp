#include <iostream>
using namespace std;
// we say that empolyee is a class
class employee
{
private:
    // we have three types public private , protected
    // but with pri  anything inside the object you can't acess to it, if you are outside the class
    string Name;
    string Company;
    int Age;

public:
    // we can also make a fonction inside the class that describe the behaviour of the object after ...
    void introduce()
    {
        cout << "name\t" << Name << "\n";
        cout << "company\t" << Company << "\n";
        cout << "age\t" << Age << "\n";
    }
    // we can creat a constracter that make fill of the object easyer
    // we have three conditions to make a constructor

    // 1- no type
    // 2- the same name of the class
    // 3-must be public(for this level)
    // 4-create an object of employee will call directly the constructor
    employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
        // cout << "hello";
    }
};

int main()
{
    employee employee1 = employee("haitam", "meta", 25);
    employee1.introduce();
    // error cause the Age is private , if we want it we must passed with a function inside the class
    cout << employee1.Age;
    /*if the propreties are pblic
    employee1.name="ahmed";
    employee1.company ="facebook";
    employee1.age=25;
    employee1.introduce() ;*/
}
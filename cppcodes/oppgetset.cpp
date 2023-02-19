#include <iostream>
using namespace std;
// we say that empolyee is a class
class employee
{
private:
    string Name;
    string Company;
    int Age;

public:
    // setter
    void setname(string name) // if you want to entre  the name
    {
        Name = name;
    }
    // getter
    // if you want to get the acess to the name althought it's private
    string getname()
    {
        return Name;
    }
    // to set the age and it's private
    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }

    void introduce()
    {
        cout << "name\t" << Name << "\n";
        cout << "company\t" << Company << "\n";
        cout << "age\t" << Age << "\n";
    }

    employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    employee employee1 = employee("mohamed", "meta", 25);
    employee1.setname("Haitam");
    cout << employee1.getname() << endl;
    employee1.setAge(19);
    cout << employee1.getAge() << endl;
}
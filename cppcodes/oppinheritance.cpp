#include <iostream>
using namespace std;
class employee
{
protected: // all the derives classes of employee will get the acess to name company age .
           // that's mean that those variables are already defined in all drived classes
           // we will use set inside the derived class to assign the value to those attr and then you can get it
    string Name;
    string Company;
    int Age;

public:
    void setname(string name)
    {
        Name = name;
    }
    string getname()
    {
        return Name;
    }
    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }
    /*example
       #include <iostream>
using namespace std;

// Base class
class Employee  {
  protected:  // Protected access specifier
    int salary;
    public:
      int getSalary() {
      return salary;
    }
};

// Derived class
class Programmer: public Employee {
  public:
    int bonus;
    void setSalary(int s) {
      salary = s;
    }

};

int main() {
  Programmer myObj;
  myObj.setSalary(50000);
  myObj.bonus = 15000;
  cout << "Salary: " << myObj.getSalary() << "\n";
  cout << "Bonus: " << myObj.bonus << "\n";
  return 0;
}
    */
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
    // one using of polymorphism
    virtual void work()
    { /*virtual means thats if any implimentations of this fonction in derived class excute theme else excute
     this fonction here */
        cout << Name << "  is teaching in emp school the " << endl;
    }
};
// we can make dev inherits from other classes (class dev : public c1 , public c2)
//  public to get access to name .... in main fonction
class developer : public employee
{ // developer is a derive class of employee it means that developer can use
  // the elements of employe and we make this cause developer has the same objects with employee +his own objects
public:
    string FavoriteL;
    // we must creat the constracter of developer
    developer(string name, string company, int age, string favoritel) : employee(name, company, age)
    // when we write a value in string name it go directly to name in employee cause this class has
    // the propreties name company ...
    {
        FavoriteL = favoritel;
    }
    /*Dans ce cas, le constructeur de la classe developer prend en argument name, company, age et favoritel.
     Les trois premiers arguments sont passés à la classe de base employee pour initialiser ses membres name,
      company et age à l'aide de l'initialisation de constructeur de la classe de base : employee(name, company, age).
       Ensuite, le membre FavoriteL est initialisé avec la valeur de l'argument favoritel.*/
    void solveprob()
    {
        cout << Name << "  has solve the prob using  " << FavoriteL << endl;
    }
    void work()
    {
        cout << Name << "  is coding in  " << FavoriteL << endl;
    }
};
class teacher : public employee
{
public:
    string subject;
    teacher(string name, string company, int age, string sub) : employee(name, company, age)
    // to transfert name co ag to employee directly
    {
        subject = sub;
    }
    void lesson()
    {
        cout << Name << "  is preparing the lesson of " << subject << endl;
    }
    // poly
    void work() // override
    {
        cout << Name << "  is teaching in emp school the " << subject << endl;
    }
};
int main()
{
    developer d = developer("haitam", "google", 19, "C");
    d.solveprob();
    teacher t = teacher("snee", "school", 35, "english");
    t.lesson();
    t.introduce();
    employee *p1;
    p1 = new developer("haitam", "google", 19, "C");
    p1 = &d;
    employee *p2 = &t;
    p1->work();
    p2->work();
    // if you don't write p1=null the d will delete
    p1 = NULL;
    delete p1;
    d.solveprob();
}
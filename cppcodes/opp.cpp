#include <iostream>
using namespace std ;
//we say that empolyee is a class 
class employee {
public: // we have three types public private , protected 
// but with pri  anything inside the object you can't acess to it 
string Name ;
string Company ;
int Age ;
//we can also make a fonction inside the class that describe the behaviour of the object after ...
void introduce()
{ cout<<"name\t"<<Name<<"\n" ;
cout<<"company\t"<<Company<<"\n" ;
cout <<"age\t"<<Age<<"\n" ;
}
// we can creat a constracter that make fill of the object easyer
// we have three conditions to make a constracter 
//1- no type 2- the same name of the class 3-must be public(for this level)
employee (string name , string company , int age )
{
Name = name ;
Company = company ;
Age = age ;
}
};

int main ()
{
employee employee1=employee("haitam","meta",25);
employee1.introduce() ;
/*employee1.name="ahmed";
employee1.company ="facebook";
employee1.age=25;
employee1.introduce() ;*/

}
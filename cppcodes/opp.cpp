#include <iostream>
using namespace std ; 
//we say that empolyee is a class 
class employee {
public: // we have three types public private , protected 
// but with pri et pro anything inside the object you can't acess to it 
string name ;
string company ;
int age ;
//we can also make a fonction inside the class that describe the behaviour of the object after ...
void introduce()
{ cout<<"name\t"<<name<<"\n" ;
cout<<"company\t"<<company<<"\n" ;
cout <<"age\t"<<age<<"\n" ;
}
};

int main ()
{
employee employee1 ;
employee1.name="ahmed";
employee1.company ="facebook";
employee1.age=25;
employee1.introduce() ;

}
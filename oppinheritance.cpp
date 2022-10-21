#include <iostream>
using namespace std ; 
class employee {
    protected : // all the derives of employee will get the acess to name company age .
string Name ;
string Company ;
int Age ;
public: 
void setname(string name )
{
Name = name ; 
}
string getname(){
    return Name ;
}
void setAge(int age )
{
Age = age ; 
}
int  getAge(){
    return Age ;
}
void introduce()
{ cout<<"name\t"<<Name<<"\n" ;
cout<<"company\t"<<Company<<"\n" ;
cout <<"age\t"<<Age<<"\n" ;
}
employee (string name , string company , int age )
{
Name = name ;
Company = company ;
Age = age ;
}
//one using of polymorphism
 virtual void work()
{/*virtual means thats if any implimentations of this fonction in derived class excute theme else excute
this fonction here */
    cout <<Name<<"  is teaching in emp school the "<<endl  ;
}
};
//public to get acess to name .... in main fonction 
class developer : public  employee {//developer is a derive class of employee it means that developer can use 
//the elements of employe and we make this cause developer has the same objects with employee +his own objects
public  : 
string FavoriteL ;
// we must creat the constracter of developer 
developer(string name , string company , int age,string favoritel):employee(name ,company,age) {
FavoriteL=favoritel ;
}
void solveprob(){
    cout<<Name<<"  has solve the prob using  "<<FavoriteL<<endl;
}
void work()
{
    cout <<Name<<"  is coding in  "<<FavoriteL<< endl  ;
}

};
class teacher : public employee {
    public :
    string subject ;
teacher(string name , string company , int age ,string sub) : employee(name,company,age)//to transfert name c a to employee directly 
{
subject = sub ; 
}
void lesson(){
    cout<< Name <<"  is preparing the lesson of "<< subject << endl ;
}
//poly
void work()
{
    cout <<Name<<"  is teaching in emp school the "<<subject << endl  ;
}
};
int main ()
{
developer d= developer("haitam","google",19,"C") ; 
d.solveprob();
teacher t=teacher("snee","school",35,"english");
t.lesson();
t.introduce();
employee *p1=&d ;
employee *p2=&t ;
p1->work();
p2->work();
}
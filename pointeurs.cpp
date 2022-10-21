#include <iostream>
#include<vector>

int main ()
{
int *p , a=10 ; 
p=new int  ; //résérver une espace pour le pointeur
p=&a ;
std::cout<<*p ;
p=NULL ;
delete p ; // pour liberer l'espace de p 
std::vector<int> T={1,2} ;
std::cout<<T[0];
}
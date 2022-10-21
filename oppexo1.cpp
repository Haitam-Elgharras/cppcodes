#include <iostream>
#include <cmath>
using namespace std ;
class point {
int x ;
int y ; 
public :
point(){
x=0 ;
y=0 ;
}
point(int x1 , int y1)
{
x=x1 ;
y=y1 ;
}
void  dis (point p1 ,point p2 ){
cout<<"la distance entre  les deux point "<<sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2))<<endl ;
}
void  milieu (point p1 ,point p2 ){
cout<<"la milieu entre  les deux point "<<"("<<(float)(p1.x+p2.x)/2<<","<<(float)(p1.x+p2.y)/2<<")"<<endl ;
}
void setx(int a ){
x=a ;
}
int getx(){
    return x ;
}
void sety(int b ){
y=b ;
}
int gety(){
    return y ;
}
};
int main(){
point p11=point() ;
point p22=point() ;
cout<<p11.getx()<<endl ;
//cout<<"donner les coordonnes de la premier point est la deuxieme "<<endl ; 
/*cin>>p11.x ;
cin>>p11.y ;
cin>>p22.x ;
cin>>p22.y ;*/
p11.setx(2);
p22.setx(1);
p11.sety(2);
p22.sety(1);
p11.dis(p11,p22);
p22.milieu(p11,p22);
}
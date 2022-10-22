#include<iostream>
#include<vector>
using namespace std ;
int main ()
{int i ;
vector<int> even(5);
for( i =0 ;i<even.size();i++)
{
  even.push_back(i);
}
even.push_back(6);
even.pop_back();
for( i =0 ;i<even.size();i++)
{
  cout<<even[i];
}
}
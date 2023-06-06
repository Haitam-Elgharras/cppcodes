#pragma once
#include <iostream>
using namespace std;
class Student
{
private:
  int mtr;
  string firstname;
  string lastname;
  string email;

public:
  Student() {}
  Student(int mtr, string fn, string ln, string email)
  {
    this->mtr = mtr;
    firstname = fn;
    lastname = ln;
    this->email = email;
  }
  friend ostream &operator<<(ostream &, const Student &);
};
ostream &operator<<(ostream &os, const Student &st)
{
  os << "{ mtr: " << st.mtr << ", Firstname: " << st.firstname << ", Lastname: " << st.lastname << ", email: " << st.email << "}";
  return os;
}
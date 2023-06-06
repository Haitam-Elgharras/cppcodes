#include <iostream>
#include "String.h"

using namespace std;

void String::display()
{
    cout << "I'm in the display function\n";
    cout << this->adr;
    cout << "\n";
}
std::ostream &operator<<(std::ostream &os, String &str)
{
    return os << str.adr; // like replacing cout<<str with cout<<str.adr;
}

String::String()
{
    cout << "I'm in the default constructor\n";
    adr = new char[1];
    *adr = '\0';
}

String::String(const char *myChar)
{
    cout << "I'm in the constructor with a char array argument\n";
    if (adr != nullptr)
    {
        delete[] adr;  // release memory block pointed by adr
        adr = nullptr; // set to nullptr to indicate that it's not pointing to any memory
    }

    int size = 0;
    while (*(myChar + size) != '\0')
    {
        size++;
    }
    adr = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        adr[i] = myChar[i];
    }
    adr[size] = '\0';
    this->size();
}
String::String(char *myChar)
{
    cout << "I'm in the constructor with a char array argument\n";
    if (adr != nullptr)
    {
        delete[] adr;  // release memory block pointed by adr
        adr = nullptr; // set to nullptr to indicate that it's not pointing to any memory
    }

    int size = 0;
    while (*(myChar + size) != '\0')
    {
        size++;
    }
    adr = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        adr[i] = myChar[i];
    }
    adr[size] = '\0';
    this->size();
}

String::String(char c)
{
    cout << "I'm in the constructor with a single char argument\n";
    delete[] adr;
    adr = new char[2];
    adr[0] = c;
    adr[1] = '\0';
    this->size();
}

String::String(String &myStringObject)
{
    cout << "I'm in the copy constructor\n";

    if (adr != nullptr)
    {
        delete[] adr;  // release memory block pointed by adr
        adr = nullptr; // set to nullptr to indicate that it's not pointing to any memory
    }
    myStringObject.size();
    adr = new char[myStringObject.len + 1];
    for (int i = 0; i < myStringObject.len; i++)
    {
        adr[i] = myStringObject.adr[i];
    }
    adr[myStringObject.len] = '\0';
}

void String::operator=(String &myString)
{
    cout << "I'm in the assignment operator\n";
    if (adr != nullptr)
    {
        delete[] adr;
        adr = nullptr;
    }
    len = myString.size();
    adr = new char[len + 1];
    for (int i = 0; i < len + 1; i++)
    {
        adr[i] = myString.adr[i];
    }
}

bool String::operator==(String &myString)
{
    cout << "I'm in the equality operator\n";
    if (size() != myString.size())
        return 0;
    for (int i = 0; i < len; i++)
    {
        if (myString.adr[i] != adr[i])
            return 0;
    }
    return 1;
}

/*
    We must use a pointer here to pass the value by address. If we pass it by value in the a=b+c statement,
    the = operator needs the left operand as a reference. But if the concat is a local variable, we pass just the value, which means the object doesn't exist.
    When we pass it by address, the object exists, and there is a reference to it even after the function is finished.
*/
String &String::operator+(String &myStringOne)
{
    cout << "I'm in the addition operator\n";
    String *concat = new String;
    delete[] concat->adr;
    this->size();
    concat->adr = new char[myStringOne.len + len + 1];

    for (int i = 0; i < len; i++)
    {
        concat->adr[i] = adr[i];
    }

    for (int i = len; i < myStringOne.len + len; i++)
    {
        concat->adr[i] = myStringOne.adr[i - len];
    }

    concat->adr[myStringOne.len + len] = '\0';
    concat->size();
    return *concat;
}
String &String::append(String &myStringOne)
{
    cout << "I'm in the append function\n";

    *this = (*this + myStringOne);
    return *this;
}
String &String::append(const char *myString)
{
    String st(myString);
    *this = (*this + st);
    return *this;
}

// a reference to the value
char &String::operator[](int i) const
{
    cout << "I'm in the [] operator\n";
    return adr[i];
}

int String::size()
{
    cout << "size function \n";
    int i = 0;
    while (*(adr + i) != '\0')
    {
        i++;
    }
    len = i;
    return len;
}

String &String::assign(const char *myString)
{
    cout << "I'm in the assign function\n";
    if (adr != nullptr)
    {
        delete[] adr;
    }
    int size = 0;
    while (myString[size] != '\0')
    {
        size++;
    }
    adr = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        adr[i] = myString[i];
    }
    adr[size] = '\0';
    return *this;
}
String &String::assign(String &myString)
{
    cout << "I'm in the assign function\n";

    *this = myString;
    return *this;
}

char &String::at(int i)
{
    cout << "I'm in the at() function\n";
    return adr[i];
}

char &String::back()
{
    cout << "I'm in the back() function\n";
    return adr[this->size() - 1];
}

char &String::begin()
{
    cout << "I'm in the BEGIN() function\n";
    return adr[0];
}

int String::copy(char *buffer, int n)
{
    cout << "I'm in the copy() function\n";

    int i = 0;
    if (sizeof(buffer) / sizeof(char) < n)
        return 0;
    while (i < n)
    {
        buffer[i] = adr[i];
        i++;
    }
    return n;
}

bool String::empty()
{
    cout << "I'm in the empty() function\n";
    return size() == 0;
}

String &String::substr(size_t position = 0, size_t length = 0)
{
    cout << "I'm in the substr() function\n";
    String *myString = new String;
    myString->adr = new char[length + 1];
    for (size_t i = position; i < position + length; i++)
    {
        myString->adr[i - position] = adr[i];
    }
    myString->adr[length] = '\0';

    return *myString;
}

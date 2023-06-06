#include <iostream>
#include <string>
using namespace std;
class chaine
{
    char *adr = nullptr;
    int len = 0;

public:
    chaine();
    chaine(chaine &);
    chaine(char *);
    chaine(char c);
    int longeur();
    void display();
    void operator=(chaine &);
    bool operator==(chaine &);
    chaine &operator+(chaine &) const;
    char &operator[](int i) const; // a reference to the value
    friend int myfriend();
};

chaine::chaine()
{
    cout << "the constructor\n";
    adr = new char[1];
    *adr = '\0';
}
chaine::chaine(char *myChar)
{
    cout << "initilize\n";
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
    longeur();
}
chaine::chaine(char c)
{
    delete[] adr;
    adr = new char[2];
    adr[0] = c;
    adr[1] = '\0';
    longeur();
}
chaine::chaine(chaine &myCharObject)
{
    cout << "initilize by copy constructor\n";
    delete[] adr;
    adr = nullptr;
    adr = new char[myCharObject.len + 1];
    for (int i = 0; i < myCharObject.len; i++)
    {
        adr[i] = myCharObject.adr[i];
    }
    adr[myCharObject.len] = '\0';
    len = myCharObject.len;
}
void chaine::operator=(chaine &myChaine)
{
    cout << "the = operator\n";
    if (adr != nullptr)
    {
        delete[] adr;
        adr = nullptr;
    }
    len = myChaine.len;
    adr = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        adr[i] = myChaine.adr[i];
    }
    adr[len] = '\0';
}
bool chaine::operator==(chaine &myChaine)
{
    if (len != myChaine.len)
        return 0;
    for (int i = 0; i < len; i++)
    {
        if (myChaine.adr[i] != adr[i])
            return 0;
    }
    return 1;
}
/*
     -we must use here a pointer to pass the value by adress , if we pass it by value in the a=b+c the =operator need
    the left operand as a reference but if the concat is a local variable we pass just the value that's mean tha object doesn't exist
    -when we passed it by adress the obj exist and there is a reference to it event the function is finished

    -UPDATE :
    use the ptr and pass the value by reference the best way
    */
chaine &chaine::operator+(chaine &myChaineOne) const
{
    chaine *concat = new chaine;
    concat->adr = nullptr;
    concat->adr = new char(myChaineOne.len + len + 1);

    for (int i = 0; i < len; i++)
    {
        concat->adr[i] = adr[i];
        cout << adr[i] << " ";
    }
    for (int i = len; i < myChaineOne.len + len; i++)
    {
        concat->adr[i] = myChaineOne.adr[i - len];
        cout << i;
    }

    concat->adr[myChaineOne.len + len] = '\0';
    concat->longeur();
    return *concat;
}
// a reference to the value
char &chaine::operator[](int i) const
{
    return adr[i];
}

int chaine::longeur()
{
    int i = 0;
    while (*(adr + i) != '\0')
    {
        i++;
    }
    cout << "longeur " << i << endl;
    len = i;
    return len;
}

void chaine::display()
{
    cout << "display\n";
    for (int i = 0; i < len; i++)
    {
        cout << adr[i];
    }
    cout << endl;
}

int main()
{

    char a[10] = "haitam";
    char b[12] = " elgharras";
    chaine myC(a);
    chaine myNC(myC);
    myNC.display();

    // myC.display();
    // myC.longeur();
    // chaine myC1(b);
    // myC1.display();
    // myC1.longeur();
    // chaine myC2;
    // myC2 = myC1;
    // myC2.display();
    // myC2.longeur();
    // bool test = myC2 == myC1;
    // cout << test << endl;

    // chaine res;
    // res = myC + myC1;
    // res.display();
    // res.longeur();
    // cout << res[3];

    return 0;
}
#include <iostream>
using namespace std;
class list
{

    int taille;
    float *adr;

public:
    list(int);
    list(list &);
    void saisie();
    void affiche();
    void operator=(list &);
    float &operator[](int);
    ~list();
};
list::~list()
{
    delete[] adr;
}
list::list(int t)
{
    cout << "the constructor  \n";
    taille = t;
    adr = new float[taille];
}

list::list(list &other)
{
    cout << "the copy constructor \n";
    taille = other.taille;
    adr = new float[taille];
    for (int i = 0; i < taille; i++)
    {
        adr[i] = other.adr[i];
    }
};

void list::saisie()
{
    for (int i = 0; i < taille; i++)
    {
        cout << "write a number ";
        // cin >> adr[i];
        cin >> (*this)[i];
        // if we don't return a & from the[] it doesn't work cause we return a value instead of a reference to the value

        /*In the case of cin >> adr[i], the >> operator expects a reference to a variable, not a copy,
         so it cannot be used with a parameter passed by value. That's why we need to pass the argument
         by reference using the & symbol in the function parameter.
         */
    }
}
void list::affiche()
{
    cout << "the data of the list is : \n";
    for (int i = 0; i < taille; i++)
    {
        // cout << adr[i] << endl;
        cout << (*this)[i];
    }
}

void list::operator=(list &other)
{
    cout << "the '=' operator ";
    taille = other.taille;

    /* Before assigning the new memory block, we need to make sure that the old memory block pointed to by adr is released
     to avoid memory leaks. cause the element to assigne to is already exist and point to a memory so we have to
     released to the system */

    delete[] adr;
    adr = new float[taille];
    for (int i = 0; i < taille; i++)
    {
        adr[i] = other.adr[i];
        // cout << (*this)[i] << endl;
    }
}

float &list::operator[](int i)
{
    return adr[i];
}

#include <iostream>
using namespace std;

// #include "list.h" //  the list class is defined in a separate header file

int main()
{
    int size;
    cout << "Enter the size of the list: ";
    cin >> size;
    cout << "1=>\n";
    list myList(size);

    // cout << "Enter " << size << " numbers for the list:\n";
    myList.saisie();

    cout << "The contents of the list are:\n";
    myList.affiche();

    cout << "2=>\n";
    cout << "Testing the copy constructor:\n";
    // if we assigne at the time of the creation of the object => copy contructor
    list myList2 = myList;
    cout << "The contents of the copied list are:\n";
    myList2.affiche();

    cout << "Testing the = operator:\n";
    list myList3(0); // create an empty list to assign to
    // if the object is already exist and we assigne to it =>the '=' operator
    myList3 = myList;
    cout << "The contents of the assigned list are:\n";
    myList3.affiche();

    cout << "Testing the [] operator:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "myList[" << i << "] = " << myList[i] << endl;
    }

    return 0;
}

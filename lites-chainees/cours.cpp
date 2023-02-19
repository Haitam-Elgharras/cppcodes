#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int var;
    var = 10;
    int *tmp = new int(0);
    tmp = &var;
    int *t = new int(0);
    t = tmp;
    // important
    tmp = NULL;
    delete tmp;
    cout << *t;
}
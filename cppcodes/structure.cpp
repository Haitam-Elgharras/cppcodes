#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// converts the attributes in a comma separated string, using stringstream//
/*string to_string()
{
    stringstream ss;
    string s;
    ss << _age <<  "," << _first_name << "," << _last_name << "," << _standard <<            endl;
    return ss.str();
}*/

/*
    add code for struct here.
*/
struct Student
{
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main()
{
    Student st;
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    return 0;
}
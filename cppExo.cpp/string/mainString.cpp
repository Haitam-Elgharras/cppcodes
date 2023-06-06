#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    // Test default constructor
    String s1;
    cout << s1 << endl; // ""

    // Test copy constructor
    String s2("Hello World!");
    String s3(s2);
    cout << s3 << endl; // "Hello World!"

    // Test constructor with char array argument
    char c_arr[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    String s4(c_arr);
    cout << s4 << endl; // "Hello"

    // Test constructor with char pointer argument
    char *c_ptr = new char[6];
    c_ptr[0] = 'W';
    c_ptr[1] = 'o';
    c_ptr[2] = 'r';
    c_ptr[3] = 'l';
    c_ptr[4] = 'd';
    c_ptr[5] = '\0';
    String s5(c_ptr);
    delete[] c_ptr;
    cout << s5 << endl; // "World"

    // Test constructor with char argument
    String s6('!');
    cout << s6 << endl; // "!"

    // Test size function
    cout << s2.size() << endl; // 12

    // Test assignment operator
    String s7;
    s7 = s2;
    cout << s7 << endl; // "Hello World!"

    // Test equality operator
    cout << (s2 == s3) << endl; // 1 (true)

    // Test concatenation operator
    String s8 = s4 + s5;
    cout << s8 << endl; // "HelloWorld"

    // Test indexing operator
    cout << s8[5] << endl; // 'W'

    // Test append function
    String s9("Hello");
    s9.append(s6);
    cout << s9 << endl; // "Hello!"

    // Test assign function with char array argument
    String s10;
    s10.assign("World");
    cout << s10 << endl; // "World"

    // Test assign function with String argument
    s10.assign(s9);
    cout << s10 << endl; // "Hello!"

    // Test at function
    cout << s8.at(2) << endl; // 'd'

    // Test back function
    cout << s6.back() << endl; // '!'

    // Test begin function
    cout << s2.begin() << endl; // 'H'

    // Test copy function
    char copy_arr[6];
    s4.copy(copy_arr, 5);
    copy_arr[5] = '\0';
    cout << copy_arr << endl; // "Hello"

    // Test empty function
    cout << s1.empty() << endl; // 1 (true)

    // Test substr function
    String s11("Hello World!");
    String s12 = s11.substr(6, 5);
    cout << s12 << endl; // "World"

    return 0;
}

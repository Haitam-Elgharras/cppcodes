#include <iostream>

class String
{
    char *adr = nullptr;
    int len = 0;

public:
    String();
    String(String &);
    String(const char *);
    String(char *);
    String(char c);
    int size();
    void display();
    friend std::ostream &operator<<(std::ostream &os, String &str);
    void operator=(String &);
    bool operator==(String &);
    String &operator+(String &);
    char &operator[](int i) const; // a reference to the value

    // Appends a string to the end of the 'a'
    String &append(String &myStringOne);
    String &append(const char *);

    // // Assigns a new value to the string object 'a'
    String &assign(const char *);
    String &assign(String &);

    // // Returns a reference to the character at a specified position in the string
    char &at(int);

    // // Returns a reference to the last character in the string
    char &back();

    // // Returns an iterator pointing to the first character of the string
    char &begin();

    // // Copies a sequence of characters from a string to a character array
    int copy(char *, int);

    // // Returns true if the string is empty, false otherwise
    bool empty();

    // // Returns a new string that is a substring of the current string object
    String &substr(size_t, size_t);
};

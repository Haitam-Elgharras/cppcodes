/*C++ Files
The fstream library allows us to work with files.

To use the fstream library, include both the standard <iostream> AND the <fstream> header file:
#include <iostream>
#include <fstream>
There are three classes included in the fstream library, which are used to create, write or read files:

Class	Description
ofstream	Creates and writes to files
ifstream	Reads from files
fstream	A combination of ofstream and ifstream: creates, reads, and writes to files
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

int main()
{
    string myText;
    // Create and open a text file
    ofstream MyFile("filename.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";
    // Close the file
    MyFile.close();
    // Reopen the file in read mode
    ifstream MyFile("filename.txt");
    if (MyFile.is_open())
    {
        getline(MyFile, myText);
        cout << myText;
    }
    else
    {
        cout << "Error opening file";
    }
}

#include "stack.h"
#include "expression.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
// superficielle
// si ona an object qui point sur des variables , si on fait obj pNew=pOld , les deux point sur le meme element pointeé
// c'est quoi la diff avec obj Newp ; Newp=pOld;
// si l'object ne containe pas un variable pointeur on aura pas de probleme

// IMPORTANT NOTES
/*
It's important to separate the function definitions from the function declarations, which is what the header file
(stack.h and expression.h) does. The header file contains the declarations of the functions and classes,
which are necessary for other files (like main.cpp, expression.cpp, and stack.cpp) to use them.

When you define the functions in the header file instead of a separate source file (like stack.cpp or expression.cpp),
it can lead to multiple definitions of the same function, which can cause linker errors like the ones you experienced earlier.

It's also important to have a main.cpp file because that's where the program starts executing. The other files
 (like stack.cpp and expression.cpp) contain the functions and classes that are used by main.cpp, but they don't define the program's entry point.

In summary, header files are used for declarations and separate source files are used for definitions. And main.cpp is necessary as the program's entry point.*/
int main()
{
    datatype exp;
    try
    {
        cout << "write the expression" << endl;
        getline(cin, exp);
        expression ex(exp);
        cout << ex.exp << endl;
        float result = ex.eval();
        cout << result;
        cout << "hello world ";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    /*
    // int i = 0;
    // int counter = exp.length() - 1;
    // for (int i = 0; i < exp.length(); i++)
    // {
    //     cout << "here";
    // }
    we cant write string c = exp[i];
   an error message indicates that you are trying to assign a char value to a string object,
    which is not possible because string objects are created using a constructor
    that takes a const char* as an argument

    // for (i = 0; i < exp.length(); i++)
    // {
    //     // to extract a string from the exp
    //     string c = exp.substr(i, 1);
    //     mainStack.push(c);
    //     i++;
    // }
    // mainStack.printStack();
    // cout << stoi("45");

    /* while (exp.length() > i)
     {
         if (isdigit(exp[i]))
         {
             string degits = "";
             int k = i;
             while (isdigit(exp[k]) || exp[k] == '.')
             {
                 degits = degits + exp[k];
                 cout << degits << endl;
                 k++;
                 // mainStack.pop();
             }
             i = k;
             operandStack.push(degits);
             // cout << operandStack.peek();
             // cout << degits;
         }
         else
         {
             if (exp[i] == '+' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' || exp[i] == '%' || exp[i] == '-')
             {
                 opratorStack.push(exp.substr(i, 1));
                 i++;
             }
             else
             {
                 if (exp[i] == ')')
                 {
                     float n;

                     string a = operandStack.pop();
                     string op = opratorStack.pop();
                     string b = operandStack.pop();
                     cout << "operation =>" << b << " " << op << " " << a << endl;
                     // int n = stoi(a) op stoi(b);
                     op[0] == '+' ? n = stof(a) + stof(b) : op[0] == '*' ? n = stof(a) * stof(b)
                                                        : op[0] == '/'   ? n = (stof(b) / stof(a))
                                                        : op[0] == '^'   ? n = pow(stof(b), stof(a))
                                                        : op[0] == '-'   ? n = (stof(b) - stof(a))
                                                                         : n = stoi(b) % stoi(a);
                     operandStack.push(to_string(n));
                     // if (i == 8)
                     // {
                     //     cout << endl;
                     //     cout << "here its" << n << endl;
                     // }
                 }
                 // cout << i;
                 i++;
             }
         }
     }
    // cout << operandStack.peek();
    // float result = stof(operandStack.pop());
    // cout << "the result is " << result << endl;
    // cout << operandStack.isEmpty() << endl;
    // cout << opratorStack.isEmpty() << endl;

    // cout << "test" << stof("3.4");
    // operandStack.printStack();
    // opratorStack.printStack();
    */

    return 0;
}
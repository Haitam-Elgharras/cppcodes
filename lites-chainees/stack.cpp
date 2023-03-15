#include "stack.h"
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
// superficielle
// si ona an object qui point sur des variables , si on fait obj pNew=pOld , les deux point sur le meme element pointeé
// c'est quoi la diff avec obj Newp ; Newp=pOld;
// si l'object ne containe pas un variable pointeur on aura pas de probleme

int main()
{
    datatype exp;
    stack mainStack(100), operandStack(50), opratorStack(50);

    cin >> exp;
    int i = 0;
    int counter = exp.length() - 1;
    // for (int i = 0; i < exp.length(); i++)
    // {
    //     cout << "here";
    // }
    /*we cant write string c = exp[i];
   an error message indicates that you are trying to assign a char value to a string object,
    which is not possible because string objects are created using a constructor
    that takes a const char* as an argument
    */
    // for (i = 0; i < exp.length(); i++)
    // {
    //     // to extract a string from the exp
    //     string c = exp.substr(i, 1);
    //     mainStack.push(c);
    //     i++;
    // }
    // mainStack.printStack();
    // cout << stoi("45");
    while (exp.length() > i)
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
                    op[0] == '+' ? n = stoi(a) + stoi(b) : op[0] == '*' ? n = stoi(a) * stoi(b)
                                                       : op[0] == '/'   ? n = (stoi(b) / stoi(a))
                                                       : op[0] == '^'   ? n = pow(stoi(b), stoi(a))
                                                       : op[0] == '-'   ? n = (stoi(b) - stoi(a))
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

    int result = stoi(operandStack.pop());
    cout << "the result is " << result << endl;
    cout << operandStack.isEmpty() << endl;
    cout << opratorStack.isEmpty() << endl;

    // operandStack.printStack();
    // opratorStack.printStack();

    return 0;
}
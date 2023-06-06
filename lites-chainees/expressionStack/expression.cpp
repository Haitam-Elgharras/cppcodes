#include <string>
#include "stack.h"
#include "expression.h"
#include <math.h>
using namespace std;
int pos = 0;
datatype expression::getTokenType(datatype token) const
{
    if (token == "(")
        return "LPAR";
    if (token == ")")
    {
        cout << "hello from RPAR" << endl;
        return "RPAR";
    }
    if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "^")
        return "OP";
    return "VAL";
}
datatype expression::nextToken() const
{
    if (exp.length() > pos)
    {
        if (getTokenType(exp.substr(pos, 1)) == "VAL")
        {
            cout << "hello from VAL nextToken " << pos;
            string degits = "";
            int k = pos;
            while (getTokenType(exp.substr(k, 1)) == "VAL")
            {
                degits = degits + exp[k];
                cout << degits << endl;
                k++;
            }
            pos = k;
            cout << "hello from VAL" << degits << endl;
            return degits;
        }
        else
        {
            cout << "hello from nextToken Other than VAL " << pos << endl;
            cout << exp.substr(pos, 1) << endl;
            return exp.substr(pos++, 1);
        }
    }
    return "";
}
float expression::evalOp(float val1, float val2, datatype op) const
{
    if (op == "+")
        return val1 + val2;
    if (op == "-")
        return val1 - val2;
    if (op == "*")
        return val1 * val2;
    if (op == "%")
        return int(val1) % int(val2);
    if (op == "^")
        return pow(val1, val2);
    else
        return val1 / val2;
}
float expression::eval() const
{

    stackArray mainStack(5), operandStack(1), opratorStack(5);
    datatype token;
    string vide = "";
    while ((token = nextToken()) != vide)
    {

        string tokenType = getTokenType(token);
        cout << "hello token type =>" << tokenType << endl;
        if (tokenType == "VAL")
        {
            cout << "hello from eval =>" << token << endl;
            operandStack.push(token);
            continue;
        }
        if (tokenType == "OP")
        {
            cout << "hello" << endl;

            opratorStack.push(token);
            continue;
        }
        cout << "result";
        if (tokenType == "RPAR")
        {
            cout << "result";
            float a = stof(operandStack.pop());
            string op = opratorStack.pop();
            float b = stof(operandStack.pop());
            float result = evalOp(b, a, op);
            cout << "hello from result =>" << to_string(result) << endl;
            operandStack.push(to_string(result));
            continue;
        }
    }
    if (!operandStack.isEmpty())
        throw "Expression Error";
    float result = stof(operandStack.pop());
    if (!operandStack.isEmpty())
        throw "Expression Error";
    operandStack.printstackArray();
    operandStack.printstackArray();
    return result;
}
expression::expression(datatype ex)
{
    exp = ex;
}
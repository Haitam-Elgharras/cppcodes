#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

typedef string datatype;
class stackArray
{
private:
    const int capacity;
    int top;
    datatype *values;

public:
    stackArray(uint32_t _capacity = 100);
    stackArray(const stackArray &);
    ~stackArray();
    void push(datatype val);
    datatype pop();
    datatype peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void printstackArray();
    uint32_t getCapacity() const
    {
        return capacity;
    };
    uint32_t getSize()
    {
        return top + 1;
    }
};

stackArray::stackArray(uint32_t _capacity) : capacity(_capacity)
{
    top = -1;
    values = new datatype[capacity];
}
// our stackArray has a dynamic attribute so it's obligatory to use the copy constructor
stackArray::stackArray(const stackArray &otherstackArray) : capacity(otherstackArray.capacity), top(otherstackArray.top)
{
    values = new datatype[capacity];
    for (int i = 0; i < capacity; i++)
    {
        values[i] = otherstackArray.values[i];
    }
};
stackArray::~stackArray()
{
    delete[] values;
}
void stackArray::push(datatype val)
{
    if (isFull())
        throw string("push error : stackArray is full ");

    values[++top] = val;
}
datatype stackArray::pop()
{
    if (isEmpty())
        throw string("pop error : the stackArray is empty "); // essayer de faire sinn throw

    datatype val = values[top--];
    return val;
}
datatype stackArray::peek() const
{
    if (isEmpty())
        throw "peek error : the stackArray is empty "; // essayer de faire sinn throw
    return values[top];
}
bool stackArray::isEmpty() const
{
    return top < 0;
}
bool stackArray::isFull() const
{
    return top == capacity - 1;
}

void stackArray::printstackArray()
{
    if (isEmpty())
    {
        cout << "stackArray is empty." << endl;
        return;
    }
    cout << "stackArray: ";
    for (int i = top; i >= 0; i--)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}
class expression
{
private:
    datatype nextToken() const;
    datatype getTokenType(datatype) const;
    float evalOp(float, float, datatype) const;

public:
    float eval() const;
    expression(datatype);
    datatype exp;
};

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
            cout << "hello from VAL nextToken " << pos << endl;
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
        return val2 - val1;
    if (op == "*")
        return val1 * val2;
    if (op == "%")
        return int(val2) % int(val1);
    if (op == "^")
        return pow(val2, val1);
    else
        return val2 / val1;
}
float expression::eval() const
{

    stackArray mainStack(100), operandStack(50), opratorStack(50);
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

        if (tokenType == "RPAR")
        {
            cout << "top result" << endl;
            float a = stof(operandStack.pop());
            cout << "top result" << a << endl;
            string op = opratorStack.pop();
            cout << "top result" << op << endl;

            float b = stof(operandStack.pop());
            cout << "top result" << b << endl;
            float result = evalOp(a, b, op);
            cout << "hello from result =>" << result << endl;
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
int main()
{
    datatype exp;
    // stack mainStack(100), operandStack(50), opratorStack(50);
    cout << "write the expression" << endl;
    getline(cin, exp);
    expression ex(exp);
    cout << ex.exp << endl;
    float result = ex.eval();
    cout << result;
    cout << "hello world ";
    // int i = 0;
    // int counter = exp.length() - 1;
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
     }*/
    // cout << operandStack.peek();
    // float result = stof(operandStack.pop());
    // cout << "the result is " << result << endl;
    // cout << operandStack.isEmpty() << endl;
    // cout << opratorStack.isEmpty() << endl;

    // cout << "test" << stof("3.4");
    // operandStack.printStack();
    // opratorStack.printStack();

    return 0;
}
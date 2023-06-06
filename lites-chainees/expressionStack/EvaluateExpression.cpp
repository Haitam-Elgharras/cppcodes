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
    delete[] values; // delete the array
}
void stackArray::push(datatype val)
{
    if (!isFull())
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
    datatype exp; // we can make it private and use a getter

public:
    float eval() const;
    expression(datatype); // this is the constructor
};
int pos = 0; // to keep track of the position of the next token

expression::expression(datatype ex)
{
    exp = ex;
}
datatype expression::getTokenType(datatype token) const
{
    if (token == "(")
        return "LPAR";
    if (token == ")")
    {
        // cout << "hello from RPAR" << endl;
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
        // we can't use exp[pos] because it's returns a char and we need a string
        if (getTokenType(exp.substr(pos, 1)) == "VAL")
        {
            string degits = "";
            int k = pos;
            while ((getTokenType(exp.substr(k, 1)) == "VAL") && exp.length() > k)
            {
                degits = degits + exp[k];
                k++;
            }
            pos = k;
            return degits;
        }
        else
            return exp.substr(pos++, 1);
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
        if (tokenType == "VAL")
        {
            operandStack.push(token);
            continue;
        }

        if (tokenType == "OP" && (token == "+" || token == "-"))
        {
            opratorStack.push(token);
        }
        else
        {
            opratorStack.push(token);
            token = nextToken();
            if (token != vide)
            {
                operandStack.push(token);
                if (operandStack.getSize() != 0)
                {
                    float a = stof(operandStack.pop()); // stof convert string to float
                    string op = opratorStack.pop();
                    float b = stof(operandStack.pop());

                    float result = evalOp(a, b, op);
                    operandStack.push(to_string(result));
                }
                continue;
            }
        }
    }
    while (operandStack.getSize() != 1)
    {
        float a = stof(operandStack.pop());
        string op = opratorStack.pop();
        float b = stof(operandStack.pop());
        float result = evalOp(a, b, op);
        operandStack.push(to_string(result));
    }

    if (operandStack.isEmpty())
        throw "Expression Error";
    float result = stof(operandStack.pop());
    if (!operandStack.isEmpty())
        throw "Expression Error";
    operandStack.printstackArray();
    operandStack.printstackArray();
    return result;
}

int main()
{
    datatype exp;
    cout << "write the expression" << endl;
    getline(cin, exp);
    expression ex(exp);
    // cout << ex.exp << endl;
    float result = ex.eval();
    cout << "the result is " << result;

    // float i = 0;
    // float counter = exp.length() - 1;
    // for (float i = 0; i < exp.length(); i++)
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
    // mainStack.prfloatStack();
    // cout << stoi("45");

    /* while (exp.length() > i)
     {
         if (isdigit(exp[i]))
         {
             string degits = "";
             float k = i;
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
                     // float n = stoi(a) op stoi(b);
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
    // operandStack.prfloatStack();
    // opratorStack.prfloatStack();

    return 0;
}

/*

typedef string datatype;
class stackArray
{
private:
    const float capacity;
    float top;
    datatype *values;

public:
    stackArray(ufloat32_t _capacity = 100);
    stackArray(const stackArray &);
    ~stackArray();
    void push(datatype val);
    datatype pop();
    datatype peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void prfloatstackArray();
    ufloat32_t getCapacity() const
    {
        return capacity;
    };
    ufloat32_t getSize()
    {
        return top + 1;
    }
};

stackArray::stackArray(ufloat32_t _capacity) : capacity(_capacity)
{
    top = -1;
    values = new datatype[capacity];
}
// our stackArray has a dynamic attribute so it's obligatory to use the copy constructor
stackArray::stackArray(const stackArray &otherstackArray) : capacity(otherstackArray.capacity), top(otherstackArray.top)
{
    values = new datatype[capacity];
    for (float i = 0; i < capacity; i++)
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

void stackArray::prfloatstackArray()
{
    if (isEmpty())
    {
        cout << "stackArray is empty." << endl;
        return;
    }
    cout << "stackArray: ";
    for (float i = top; i >= 0; i--)
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

float pos = 0;
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
{ cout<<"the problem is here " << endl;
    if (exp.length() > pos)
    {
        if (getTokenType(exp.substr(pos, 1)) == "VAL")
        {
            cout << "hello from VAL nextToken " << pos << endl;
            string degits = "";
            float k = pos;
            while (getTokenType(exp.substr(k, 1)) == "VAL" && exp.length() > k)
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
float newcounter=0;
float expression::evalOp(float val1, float val2, datatype op) const
{
    if (op == "+")
        return val1 + val2;
    if (op == "-")
        return val2 - val1;
    if (op == "*")
        return val1 * val2;
    if (op == "%")
        return float(val2) % float(val1);
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
    while ((token = nextToken()) != vide  )
    {
// newcounter++;&& newcounter<this->exp.length()
        string tokenType = getTokenType(token);
        cout << "hello token type =>" << tokenType << endl;
        if (tokenType == "VAL")
        {
            cout << "hello from eval =>" << token << endl;
            operandStack.push(token);
            continue;
        }
        if (tokenType == "OP" && token != "*" && token != "/" && token != "%")
        {
            cout << "hello add OP" << endl;

            opratorStack.push(token);
            // continue;
        }

        if (tokenType == "OP" && token == "*" || token == "/" || token == "%")
        {
            opratorStack.push(token);
            cout << "this is the token " << token << endl;
            token = nextToken();
            operandStack.push(token);
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
    while (operandStack.getSize() > 1)
    {
        cout << "from second ? " << endl;
        cout << "top result" << endl;
        cout<<"its here" << endl;
        float a = stof(operandStack.pop());
        cout << "top result" << a << endl;
        string op = opratorStack.pop();
        cout << "top result" << op << endl;

        float b = stof(operandStack.pop());
        cout << "top result" << b << endl;
        float result = evalOp(a, b, op);
        cout << "hello from result 2 =>" << result << endl;
        operandStack.push(to_string(result));
    }

    if (operandStack.isEmpty())
        throw "Expression Error";
    float result = stof(operandStack.pop());
    if (!operandStack.isEmpty())
        throw "Expression Error";
    operandStack.prfloatstackArray();
    operandStack.prfloatstackArray();
    return result;
}
expression::expression(datatype ex)
{
    exp = ex;
}

class Solution {
public:
    float calculate(string s) {

    // stack mainStack(100), operandStack(50), opratorStack(50);

    expression ex(s);

    float result = ex.eval();
    cout << "the result is " << result;
    return result ;
    }
};
*/
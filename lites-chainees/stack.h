#include <iostream>
#include <string.h>
using namespace std;

typedef string datatype;
class stack
{
private:
    const int capacity;
    int top = -1;
    datatype *values;

public:
    stack(uint32_t _capacity = 100);
    // stack(const stack &)
    // {
    //     }
    void push(datatype val);
    datatype pop();
    datatype peek() const;
    bool isEmpty() const;
    bool isFull() const;
    ~stack();
    void printStack();
};

stack::stack(uint32_t _capacity) : capacity(_capacity)
{
    top = -1;
    values = new datatype[capacity];
}
void stack::push(datatype val)
{
    if (isFull())
    {
        throw "push error : stack is full ";
        return;
    }
    else
        values[++top] = val;
}
datatype stack::pop()
{
    if (isEmpty())
        throw "pop error : the stack is empty "; // essayer de faire sinn throw

    datatype val = values[top--];
    return val;
}
datatype stack::peek() const
{
    if (isEmpty())
        throw "peek error : the stack is empty "; // essayer de faire sinn throw
    return values[top];
}
bool stack::isEmpty() const
{
    return top < 0;
}
bool stack::isFull() const
{
    return top == capacity - 1;
}
stack::~stack()
{
    delete[] values;
}
void stack::printStack()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; i--)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}
// void stack::push(datatype val)
// {
//     top++;
//     values[top] = val;
// }

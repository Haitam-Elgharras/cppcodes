#include <iostream>
#include "stack.h"
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
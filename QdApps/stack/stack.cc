#include "stack.h"
#include <iostream>
#include <iomanip>
ArrayStack::ArrayStack(uint32_t _capacity) : capacity(_capacity)
{
  top = -1;
  values = new datatype[capacity];
}

ArrayStack::ArrayStack(const ArrayStack &stack) : capacity(stack.capacity), top(stack.top)
{
  values = new datatype[capacity];
  for (int i = 0; i <= stack.top; i++)
    values[i] = stack.values[i];
}

ArrayStack::~ArrayStack()
{
  delete[] values;
}
void ArrayStack::push(datatype val)
{
  if (isFull())
    throw std::string("push error: stack is full");
  values[++top] = val;
}
datatype ArrayStack::pop()
{
  if (isEmpty())
    throw std::string("pop erro: the stack is empty");
  datatype val = values[top--];
  return val;
}
datatype ArrayStack::peek() const
{
  if (isEmpty())
    throw std::string("peek erro: the stack is empty");
  return values[top];
}
bool ArrayStack::isEmpty() const
{
  return top < 0;
}
bool ArrayStack::isFull() const
{
  return size() == capacity;
}

uint32_t ArrayStack::size() const
{
  return top + 1;
}

void ArrayStack::print() const
{
  std::cout << "\n |" << std::string(10, ' ') << "|\n";
  std::cout << " |" << std::string(10, '_') << "|\n";
  for (int i = top; i >= 0; i--)
  {
    printf(" |%10s|\n", values[i].c_str());
    std::cout << " |" << std::string(10, '_') << "|\n";
  }
}
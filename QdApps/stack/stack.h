#pragma once
#include<string>

typedef std::string datatype;
class ArrayStack{
  public:
    ArrayStack(uint32_t _capacity=100);
    ArrayStack(const ArrayStack& );
    ~ArrayStack();
    void push(datatype);
    datatype pop();
    datatype peek()const;
    bool isEmpty()const;
    bool isFull()const;
    uint32_t getCapacity()const{
      return capacity;
    }
    void print()const;
    uint32_t size()const;
  private:
    const uint32_t capacity;
    int top;
    datatype *values;
};
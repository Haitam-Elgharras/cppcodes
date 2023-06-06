#include <iostream>
#include <string.h>
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

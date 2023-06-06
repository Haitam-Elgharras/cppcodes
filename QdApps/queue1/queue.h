#include <iostream>
using namespace std;

typedef char datatype;

class Queue
{
private:
    datatype *arr;
    uint16_t front, rear, size;
    const uint16_t capacity;

public:
    Queue(uint16_t _capacity);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(datatype value); // add the value at the rear of the queue
    datatype dequeue();           // remove and return the front item of the queue
    datatype peek();              // return the front item of the queue
    uint16_t getSize();
};

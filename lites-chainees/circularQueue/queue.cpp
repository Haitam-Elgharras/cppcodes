#include "queue.h"
#include <exception>
Queue::Queue(uint16_t _capacity) : capacity(_capacity)
{
    arr = new datatype[capacity];
    front = rear = 0;
    size = 0;
}
Queue::~Queue()
{
    delete[] arr;
}
void Queue::enqueue(datatype element)
{
    if (isFull())
    {
        // when we use throw we must use try catch
        try // try to catch the exception
        {
            throw string("Error Enqueue: Queue is full. Cannot enqueue element.");
        }
        catch (string &e) // catch the exception
        {
            cout << e << endl;
        }
        // throw string("Error Enqueue: Queue is full. Cannot enqueue element.");
    }
    // rear always at a empty box , we fill it then we go the the next box (from 0 to 99)
    arr[rear] = element;
    rear = (rear + 1) % capacity;
    size = (capacity + rear - front) % capacity;
}
datatype Queue::peek()
{
    if (isEmpty())
    {
        throw string("Error dequeue: Queue is empty. Cannot dequeue element.");
    }
    return arr[front];
}

datatype Queue::dequeue()
{
    if (isEmpty())
    {

        throw string("Error dequeue: Queue is empty. Cannot dequeue element.");
    }
    datatype element = arr[front];
    front = (front + 1) % capacity;
    size = (capacity - front + rear) % capacity;
    return element;
}
bool Queue::isEmpty()
{
    return front == rear;
}
bool Queue::isFull()
{
    // we use %capacicty for the case if rear at capacity-1 so if we add 1 we goes out of the array
    return front == (rear + 1) % capacity;
}
// or
//  bool Queue::isFull()
//  {
//      return size == capacity - 1;
//  }
uint16_t Queue::getSize()
{
    return size;
}

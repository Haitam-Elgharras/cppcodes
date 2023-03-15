#include <iostream>
using namespace std;

typedef int datatype; // replace int with the desired type

class Queue
{
private:
    int front;
    int rear;
    uint16_t capacity;
    uint16_t size;
    datatype *arr;

public:
    Queue(uint16_t _capacity) : front(-1), rear(-1), size(0), capacity(_capacity)
    {
        arr = new datatype[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isFull();
    bool isEmpty();
    void enqueue(datatype value);
    datatype dequeue();
    datatype peek();
    uint16_t getSize();
};

bool Queue::isFull()
{

    // calculer size avec la method dans le cours
    return size == capacity - 1; // un case pour laisser vide
}

bool Queue::isEmpty()
{
    return size == 0;
}

void Queue::enqueue(datatype value)
{
    if (isFull())
    {
        throw "Queue is full";
    }
    if (rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == capacity - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = value;
    size++;
}

datatype Queue::dequeue()
{
    if (isEmpty())
    {
        throw "Queue is empty";
    }
    datatype value = arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == capacity - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    size--;
    return value;
}

datatype Queue::peek()
{
    if (isEmpty())
    {
        throw "Queue is empty";
    }
    return arr[front];
}

uint16_t Queue::getSize()
{
    return size;
}

int main()
{
    uint16_t capacity = 6;
    Queue q(capacity);
    try
    {
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        // cout << "Queue size: " << q.getSize() << endl;
        // cout << "Queue front: " << q.peek() << endl;
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        // cout << "Queue size after dequeuing three elements: " << q.getSize() << endl;
        // cout << "Queue front after dequeuing three elements: " << q.peek() << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        q.enqueue(5);

        cout << "Queue size after enqueueing six elements: " << q.getSize() << endl;
        cout << "peek: " << q.peek() << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    return 0;
}

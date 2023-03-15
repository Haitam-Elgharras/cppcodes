#include <iostream>
using namespace std;

typedef int datatype; // replace int with the desired type

class Queue
{
private:
    int front;
    int rear;
    datatype arr[MAX_SIZE];

public:
    Queue() : front(-1), rear(-1) {}
    ~Queue() {}
    bool isFull();
    bool isEmpty();
    void enqueue(datatype value);
    datatype dequeue();
    datatype peek();
    uint16_t size();
};

bool Queue::isFull()
{
    return (front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1);
}

bool Queue::isEmpty()
{
    return front == -1;
}

void Queue::enqueue(datatype value)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = value;
}

datatype Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return datatype();
    }
    datatype value = arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return value;
}

datatype Queue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return datatype();
    }
    return arr[front];
}

uint16_t Queue::size()
{
    if (isEmpty())
    {
        return 0;
    }
    if (rear >= front)
    {
        return rear - front + 1;
    }
    else
    {
        return MAX_SIZE - front + rear + 1;
    }
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue front: " << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "Queue size after dequeuing three elements: " << q.size() << endl;
    cout << "Queue front after dequeuing three elements: " << q.peek() << endl;
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    cout << "Queue size after enqueueing six elements: " << q.size() << endl;
    cout << "Queue front after enqueueing six elements: " << q.peek() << endl;
    return 0;
}

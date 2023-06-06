#pragma once
#include <iostream>
#include "queue.h"
using namespace std;

template <class T>
CircularQueue<T>::CircularQueue(uint16_t capacity)
{
  arr = new T[capacity];
  front = rear = 0;
  size = 0;
  this->capacity = capacity;
}

template <class T>
CircularQueue<T>::~CircularQueue()
{
  delete[] arr;
}

template <class T>
bool CircularQueue<T>::isEmpty() const
{
  return (front == rear);
}

template <class T>
bool CircularQueue<T>::isFull() const
{
  return ((rear + 1) % capacity == front);
}

template <class T>
void CircularQueue<T>::enqueue(T element)
{
  if (isFull())
  {
    throw "Enqueue error: Queue is full!!!";
  }
  //  cout<<rear<<"  <-- "<<element<<endl;
  arr[rear] = element;
  rear = (rear + 1) % capacity;
  size = (capacity - front + rear) % capacity;
}

template <class T>
T CircularQueue<T>::dequeue()
{
  if (isEmpty())
  {
    cout << "before throw\n";
    throw string("Dequue Error:  Queue is empty!!!");
  }
  T temp = arr[front];
  front = (front + 1) % capacity;
  size = (capacity - front + rear) % capacity;
  return temp;
}

template <class T>
T CircularQueue<T>::peek() const
{
  if (isEmpty())
  {
    throw "Peek Error:  Queue is empty!!!";
  }
  return arr[front];
}

template <class T>
void CircularQueue<T>::display() const
{
  if (isEmpty())
  {
    cout << "Empty Queue" << endl;
  }
  uint16_t i = front;
  cout << "front<--";
  while (i != rear)
  {
    cout << arr[i] << "<--";
    i = (i + 1) % capacity;
  }
  cout << "<--rear\n";
}

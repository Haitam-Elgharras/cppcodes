#ifndef _QUEUE
#define _QUEUE
#include <iostream>
#include <string>
using namespace std;
template <class T>
class CircularQueue
{
private:
  T *arr;
  uint16_t front, rear, size;
  uint16_t capacity;

public:
  CircularQueue(uint16_t capacity = 20);
  ~CircularQueue();
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(T element);
  T dequeue();
  T peek() const;
  // void display() ;
  uint16_t getSize() const;
  void display() const;
};
#include "queue.cc"
#endif
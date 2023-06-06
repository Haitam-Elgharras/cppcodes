#include "queue.h"
#include <iostream>
#include <string>
int main()
{
    try
    {
        Queue q(10);
        q.enqueue('A');
        q.enqueue('B');
        q.enqueue('C');
        q.enqueue('D');
        q.enqueue('E');
        q.enqueue('F');
        q.enqueue('G');
        q.enqueue('H');
        q.enqueue('I');
        q.enqueue('J');
        while (!q.isEmpty())
        {
            char x = q.dequeue();
            std::cout << x << std::endl;
        }
    }
    catch (std::string ex)
    {
        std::cout << ex << std::endl;
    }
}
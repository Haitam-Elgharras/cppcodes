#include <stdio.h>
#include <stdlib.h>

// heap and priority queue course
/*
A heap is a tree-based data structure in which all the nodes of the tree are in a specific order.
For example, in a max heap, the parent node is always greater than or equal to the value of the child node.
we can draw it like this
                100
            /         \
        19              36
    /       \         /    \
    17      18      25      35
    /   \   /  \    /  \    /  \
    2   7   4  5   12  9   13  11

The same is true for a min heap, where the parent node is always less than or equal to the child node.
we can draw it like this

                2
            /         \
        3              15
    /       \         /    \
    5       4         45      35
    /   \   /  \    /  \    /  \
   9   7   8  6   120  100  130  110

   -we can do this implimentation by using an array and each node has two childrens
    and the index of the left child is (2*i+1) and the index of the right child is (2*i+2)

The heap is one maximally efficient implementation of an abstract data type called a priority queue,
and in fact, priority queues are often referred to as "heaps", regardless of how they may be implemented.
*/

/*
a priority queue is a data structure that stores elements in a queue-like format in which each element has a priority associated with it.
In a priority queue, an element with high priority is served before an element with low priority.
If two elements have the same priority, they are served according to their order in the queue.

-the priority key it's an object associated with the element and it's used to compare the elements
 *the key can be a number or a string or a date or a time or a combination of these things
 * not necessary unique
 * mybe is a complex object that cant be compared directly

 so in this case wa need  to define an order relation between the keys
    * the order relation is a function that takes two keys and return 1 if the first key is greater than the second key
    * and return 0 if the first key is less than the second key
    * and return -1 if the two keys are equal


 -we have many types of implimentations of priority queue
    * array non sorted (do this one)
    * array sorted
    * linked list non sorted
    * linked list sorted
    * binary tree (do this one)
    * avl tree
    * heap (do this one)

*/
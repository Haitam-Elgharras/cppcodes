#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

// an implimentation to organize events in a priority queue
// with a non sorted array

// the maximum size of the array
#define max 100

// the event structure
struct event
{
    int id;
    string typeevent;
    string title, description;
    int priority;

    void scan() // read the data of an event
    {
        // we need to use cin.ignore() to ignore the \n character in the buffer
        // we need to read the spaces also so we use cin.getline() instead of cin
        // for getline we need to include <string.h> and
        cout << "id: ";
        cin >> id;
        cin.ignore(); // very important to ignore the \n character in the buffer
        cout << "type: ";
        getline(cin, typeevent);
        cout << "title: ";
        getline(cin, title);
        cout << "description: ";
        getline(cin, description);
        cout << "priority: ";
        cin >> priority;
    }

    void print()
    {

        cout << "id: " << id << endl;
        cout << "type: " << typeevent << endl;
        cout << "title: " << title << endl;
        cout << "description: " << description << endl;
        cout << "priority: " << priority << endl;
    }
};

// the data of the priority queue
struct eventList
{
    event list[max];
    int size = 0;
};

// primitive functions

void insert(eventList &pq, event e) // insert an event in the priority queue
{
    // what is assert() ? : assert is a macro that expands to an if statement; and if the condition is false, it writes a diagnostic message to standard error and terminates the program.
    // exemple assert(pq.size < max) ; pq.list[pq.size] = e ; pq.size++ ;
    if (pq.size < max)
        pq.list[pq.size++] = e;
    else
        cout << "the list is full" << endl;
}
static int getPosMinPriority(const eventList &pq) // get the position of the event with the minimum priority
{
    if (pq.size == 0)
        return -1;

    int posMin = 0;
    for (int i = 1; i < pq.size; i++)
    { // if the priority of the event at position i is less than the priority of the event at position posMin
        if (pq.list[i].priority < pq.list[posMin].priority)
            posMin = i;
    }
    return posMin;
}

event remove(eventList &pq) // remove the event with the minimum priority
{
    int posMin = getPosMinPriority(pq);
    assert(posMin != -1); // assert that the position is valid (not -1) else the program will stop
    event e = pq.list[posMin];
    for (int i = posMin; i < pq.size - 1; i++)
        pq.list[i] = pq.list[i + 1];
    pq.size--;
    return e;
}
event searchKieme(const eventList &pq, int k = 1) // search the kth minimum priority event the same as getPosMinPriority but with a k parameter
{
    assert(k <= pq.size);
    // we will copy the pq to a temporary pq and remove the k-1 first events with a loop using the remove function
    // we can't use the remove function directly on pq because it's not a const function so we need to make a deep copy of pq like this
    eventList temp;
    for (int i = 0; i < pq.size; i++)
        temp.list[i] = pq.list[i];
    temp.size = pq.size;

    for (int i = 0; i < k - 1; i++)
        remove(temp);
    return remove(temp);
}
// print list
void printList(eventList &pq)
{
    cout << "the list of events is :" << endl;
    for (int i = 0; i < pq.size; i++)
    {
        pq.list[i].print();
        cout << endl;
    }
}

void update(eventList pq, int idEvent, int newPriority) // update the priority of an event
{
    int i = 0;
    while (i < pq.size && pq.list[i].id != idEvent)
        i++;

    if (i < pq.size)
    {
        pq.list[i].priority = newPriority;
    }
    else
    {
        cout << "the event is not found" << endl;
    }
}
eventList merge(const eventList &pq1, const eventList &pq2) // merge two event lists
{
    eventList pq;
    pq.size = 0;
    assert(pq1.size + pq2.size <= max); // if the condition is false, the program will stop
    for (int i = 0; i < pq1.size; i++)
    {
        insert(pq, pq1.list[i]);
    }
    for (int i = 0; i < pq2.size; i++)
    {
        insert(pq, pq2.list[i]);
    }
    return pq;
}
int getSize(const eventList &pq)
{
    return pq.size;
}

// test functions
int main()
{
    eventList pq;
    event e;
    char c;
    do
    {
        e.scan();
        insert(pq, e);
        cout << "do you want to continue ? (y/n)" << endl;
        cin >> c;
    } while (c == 'y' || c == 'Y');
    event e1 = searchKieme(pq, 3);
    cout << "the minimum priority is : ";
    e1.print();

    return 0;
}
// we have many types of implimentations of priority queue(// an implimentation to organize events in a priority queue with a tree)
// now we will do it with a tree

#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

// the event structure
struct event
{
    int id;
    string typeevent;
    string title, description;
    int priority;

    void scan() // read the data of an event
    {
        // cout << "id: ";
        // cin >> id;
        // cin.ignore(); // very important to ignore the \n character in the buffer
        // cout << "type: ";
        // getline(cin, typeevent);
        // cout << "title: ";
        // getline(cin, title);
        // cout << "description: ";
        // getline(cin, description);
        cout << "priority: ";
        cin >> priority;
    }
    void print()
    {
        // cout << "id: " << id << endl;
        // cout << "type: " << typeevent << endl;
        // cout << "title: " << title << endl;
        // cout << "description: " << description << endl;
        cout << "priority: " << priority << endl;
    }
};
// the pq structure
struct pqTree
{
    event e;
    pqTree *left, *right;
    int size = 0;
};

// primitive functions
pqTree *creeNoeud(event e)
{
    pqTree *p = new pqTree;
    p->e = e;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(pqTree **pq, event e) // insert an event in the priority queue
{
    if (*pq == NULL)
        *pq = creeNoeud(e);
    else
    {
        if (e.priority < (*pq)->e.priority)
        {
            insert(&(*pq)->left, e);
        }
        else
        {
            insert(&(*pq)->right, e);
        }
    }
    (*pq)->size++;
}

event getMinPriority(pqTree *pq) // get the event with the minimum priority
{
    assert(pq != NULL);
    if (pq->left == NULL) // if the left child is null then the current node is the minimum
        return pq->e;
    else
        return getMinPriority(pq->left);
}

event remove(pqTree **pq) // remove the event with the minimum priority
{
    assert(*pq != NULL);
    if ((*pq)->left == NULL) // if the left child is null then the current node is the minimum
    {
        event e = (*pq)->e;
        pqTree *tmp = *pq;
        (*pq)->size--;
        *pq = (*pq)->right;
        delete tmp;
        return e;
    }
    else
        return remove(&(*pq)->left);
}

void printInfixe(pqTree *pq) // print the priority queue
{
    // this is an example of infix traversal it print the tree in the order left root right
    if (pq != NULL)
    {
        printInfixe(pq->left);
        pq->e.print();
        printInfixe(pq->right);
    }
}
void printPrefixe(pqTree *pq) // print the priority queue
{
    // this is an example of prefix traversal it print the tree in the order root left right
    if (pq != NULL)
    {
        pq->e.print();
        printPrefixe(pq->left);
        printPrefixe(pq->right);
    }
}
void printPostfixe(pqTree *pq) // print the priority queue
{
    // this is an example of postfix traversal it print the tree in the order left right root
    if (pq != NULL)
    {
        printPostfixe(pq->left);
        printPostfixe(pq->right);
        pq->e.print();
    }
}
void copyTree(pqTree *pq, pqTree **tmp)
{
    if (pq != NULL)
    {
        cout << "from copy tree" << endl;
        *tmp = creeNoeud(pq->e);
        // cout << (*tmp)->e.priority;
        copyTree(pq->left, &(*tmp)->left);
        copyTree(pq->right, &(*tmp)->right);
    }
}

event searchKieme(pqTree *pq, int k) // we search for the k-th min priority
{
    pqTree *tmp = new pqTree;
    tmp->left = NULL;
    tmp->right = NULL;
    // we need to make a deep copy of pq
    copyTree(pq, &tmp);
    // cout << "here";

    event e;
    for (int i = 0; i < k - 1; i++)
    {
        if (tmp != NULL)
        {
            // cout << "i need it here";
            e = remove(&tmp); // the problem appears here with the first iteration the program stops
            // cout << e.priority << endl;
            // cout << "i need it here";
        }
    }
    e = remove(&tmp);
    return e;
}

void update(pqTree *pq, int id, int priority)
{
    assert(pq != NULL);
    if (pq->e.id == id)
    {
        pq->e.priority = priority;
    }
    else
    {
        update(pq->left, id, priority);
        update(pq->right, id, priority);
    }
}

pqTree *merge(pqTree *pq1, pqTree *pq2)
{
    if (pq1 == NULL)
        return pq2;
    if (pq2 == NULL)
        return pq1;
    if (pq1->e.priority < pq2->e.priority)
    {
        pq1->right = merge(pq1->right, pq2);
        return pq1;
    }
    else
    {
        pq2->right = merge(pq2->right, pq1);
        return pq2;
    }
}

int main()
{
    pqTree *pq = NULL;
    event e1, e2, e3, e4, e5, e6, e7;
    e1.priority = 7;
    e2.priority = 4;
    e3.priority = 10;
    e4.priority = 3;
    e5.priority = 5;
    e6.priority = 9;
    e7.priority = 15;
    insert(&pq, e1);
    insert(&pq, e2);
    insert(&pq, e3);
    insert(&pq, e4);
    insert(&pq, e5);
    insert(&pq, e6);
    insert(&pq, e7);
    // cout << pq->size;

    // pqTree *tmp;
    // copyTree(pq, &tmp);
    // printInfixe(tmp);
    // test kth
    event e = searchKieme(pq, 7);
    e.print();
    printInfixe(pq);

    return 0;
}

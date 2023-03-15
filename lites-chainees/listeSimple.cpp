#include <iostream>
#include <vector>
using namespace std;
// Lorsque « struct»est utilisé à la place du mot-clé «class »est ce que quelque chose va changer dans le programme?
// A L’accès est public par défaut
// Pour les structures, par défaut, tous les membres(données et fonctions) sont publics.
struct noeud_t
{
    // we can work with a generic type(if we change the int to any type of data)
    // typedef int value;

    int data;
    noeud_t *next = NULL;

    // noued_t(int data)
    // {
    //     // the variable declare with noued type
    //     this->data = data;
    // }
};
/*we can define functions inside the structure and we can work with this function
at the element of type liste , it's like a class and his methods */
struct liste
{
    noeud_t *tete, *queue;
    int lg;
    // it's a constructor
    liste();
    void addAuDebut(int val);
    void addEnd(int val);
    void addAfter(int valInserer, int valChercher);
    void addBefore(int valInserer, int valChercher);
    void show();
    void supprimerTete();
    int findIndex(int val);
    // noeud_t rechercheVal(int pos);

    // const it doesn't change anything in the liste
    bool isEmpty() const; // getter
    int peekFirst() const;
    int peekLast() const;
    int peek() const;
};

/*when we create the function it know all the attr of the variable that has the type liste*/

// structure's name:: means that this function is inside the structure(function of struct)

liste::liste() // initialisation
{
    // we can refere to the Var with this-> or we can just change the attrs
    // it's apply automaticly to the var attrs
    // tete->next = NULL
    this->tete = this->queue = NULL;
    this->lg = 0;
}
void liste::supprimerTete()
{
    // tmp and tete are pointers they save the &of each noued
    noeud_t *tmp;
    if (this->tete == NULL)
        return;
    tmp = this->tete;

    if (this->tete == this->queue)
    {
        this->tete = this->queue = NULL;
    }
    else
    {

        this->tete = this->tete->next;
    }

    /*After updating the pointers, the tmp pointer still holds the address of the previous tete node.
     The delete operator is then used to free the memory pointed to by tmp. */
    delete tmp;
    this->lg--;
}
void liste::addAuDebut(int val)
{ // we never delete the allocation of the new noued
    noeud_t *newNoued = new noeud_t;
    newNoued->data = val;
    if (this->tete == NULL)
    {
        // new also is a pointer is point to the element that has the data=val and next=null
        tete = queue = newNoued;
    }
    else
    {
        newNoued->next = this->tete;
        tete = newNoued;
    }

    this->lg++;
}
void liste::addEnd(int val)
{
    noeud_t *newNoued = new noeud_t;
    newNoued->data = val;
    if (isEmpty())
    {
        tete = queue = newNoued;
    }
    else
    {
        queue->next = newNoued;
        queue = newNoued;
    }

    this->lg++;
}
void liste::addAfter(int valInserer, int valChercher)
{
    // tmp static variable :destroyed with the end of the function
    noeud_t *tmp = tete;
    noeud_t *newEl = new noeud_t;
    newEl->data = valInserer;
    if (tete == NULL)
    {
        addAuDebut(valInserer);
    }
    else
    {
        if (queue->data == valChercher)
        {
            addEnd(valInserer);
        }

        else
        {

            while (tmp != NULL && tmp->data != valChercher)
            {
                tmp = tmp->next;
            }
            if (tmp != NULL)
            {
                noeud_t *newEl = new noeud_t;
                newEl->data = valInserer;
                newEl->next = tmp->next;
                tmp->next = newEl;
            }
            else
            {
                cout << "the valChercher = " << valChercher << " doesnt existe" << endl;
                return;
            }
        }

        lg++;
    }
}
void liste::addBefore(int valInserer, int valChercher)
{
    // tmp static variable :destroyed with the end of the function
    noeud_t *tmp = tete;
    if (tete == NULL || tete->data == valChercher)
    {
        addAuDebut(valInserer);
    }
    else
    {

        while (tmp->next != NULL && tmp->next->data != valChercher)
        {
            tmp = tmp->next;
        }
        if (tmp->next != NULL)
        {
            noeud_t *newEl = new noeud_t;
            newEl->data = valInserer;
            newEl->next = tmp->next;
            tmp->next = newEl;
        }
        else
        {
            cout << "the valChercher = " << valChercher << " doesnt existe" << endl;
            return;
        }
    }
    lg++;
}

void liste::show()
{
    noeud_t *tmp = new noeud_t;
    tmp = tete;
    int counter = lg;

    while (counter != 0)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
        counter--;
    }
    delete tmp;
}
int liste::findIndex(int val)
{
    noeud_t *tmp = new noeud_t;
    tmp = tete;
    int index = 0;
    while (tmp != NULL)
    {
        if (tmp->data == val)
        {
            break;
        }
        index++;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        cout << "the element doesnt exist" << endl;
        return -1;
    }
    cout << "the index is " << index << endl;
    return index;
}
bool liste::isEmpty() const
{
    return tete == nullptr;
}

int main()
{
    // random state
    liste ls;
    // initial state
    // ls. addAuDebut(10);
    // ls. addAuDebut(11);
    // ls. addAuDebut(12);
    // ls. addAuDebut(13);
    // ls.supprimerTete();
    // ls.show();
    // ls. addEnd(9);
    // ls. addEnd(8);
    ls.addEnd(0);
    ls.addEnd(2);
    ls.addEnd(4);
    ls.addBefore(3, 4);
    ls.addEnd(6);
    ls.addAfter(7, 6);
    ls.addEnd(8);
    ls.addEnd(9);
    ls.addEnd(10);
    // ls.show();
    ls.addAfter(1, 0);
    ls.addAfter(1, 11);
    ls.addAfter(11, 10);
    ls.addAfter(5, 4);
    ls.addEnd(13);
    ls.addBefore(12, 13);
    ls.addEnd(14);
    ls.show();

    int index = ls.findIndex(8);
}
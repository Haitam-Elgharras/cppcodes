#include <iostream>
#include <vector>
using namespace std;
struct noeud_t
{
    int data;
    noeud_t *next = NULL;
};
/*we can define functions inside the structure and we can work with this function
at the element of type liste , it's like a class and his methods */
struct liste
{
    noeud_t *tete, *queue;
    int lg;
    void creatListe();
    void ajouterAuDebut(int val);
    void ajouterALaFin(int val);
    void afficherListe();
    void supprimerTete();
    // noeud_t recherchePos(int val);
    // int rechercheVal(int pos);
};
/*when we create the function it know all the attr of the variable that has the type liste*/

void liste::creatListe() // initialisation
{
    // we can refere to the Var with this-> or we can just change the attrs
    // it's apply automaticly to the var attrs
    // tete->next = NULL
    this->tete = this->queue = NULL;
    this->lg = 0;
}
// structure's name:: means that this function is inside the structure
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
void liste::ajouterAuDebut(int val)
{ // we never delete the allocation of the new noued
    noeud_t *newNoued = new noeud_t;
    newNoued->data = val;
    newNoued->next = NULL;
    if (this->tete == NULL)
    {
        tete = queue = newNoued;
    }
    else
    {
        newNoued->next = this->tete;
        this->tete = newNoued;
    }

    this->lg++;
}
void liste::ajouterALaFin(int val)
{
    noeud_t *newNoued = new noeud_t;
    newNoued->data = val;
    newNoued->next = NULL;
    if (this->tete == NULL)
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

void liste::afficherListe()
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

int main()
{

    liste ls;
    ls.creatListe();
    ls.ajouterAuDebut(10);
    ls.ajouterAuDebut(11);
    ls.ajouterAuDebut(12);
    ls.ajouterAuDebut(13);
    // ls.supprimerTete();
    // ls.afficherListe();
    ls.ajouterALaFin(9);
    ls.ajouterALaFin(8);
    ls.ajouterALaFin(7);
    ls.afficherListe();
}
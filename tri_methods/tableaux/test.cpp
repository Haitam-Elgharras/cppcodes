#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int fofo(Node *T)
{
    if (T == nullptr)
        return 0;
    else
    {
        int a = fofo(T->left);
        int b = fofo(T->right);
        if (a > b)
            return (a + 1);
        else
            return (b + 1);
    }
}
void h(int *a, Node *T)
{
    if (T == NULL)
        return;
    if ((T->left == NULL) && (T->right == NULL))
        *a = *a + 1;
    h(a, T->left);
    h(a, T->right);
}
void show(Node *L)
{
    if (L != NULL)
    {
        printf("%d ", L->data);
        show(L->next);
        show(L->next);
        printf("%d ", L->data);
    }
}

int main()
{
    // Création de l'arbre
    Node *element = new Node{7, nullptr, nullptr};
    element->left = new Node{9, nullptr, nullptr};
    element->right = new Node{5, nullptr, nullptr};
    element->left->left = new Node{1, nullptr, nullptr};
    element->left->left->right = new Node{2, nullptr, nullptr};
    element->right->right = new Node{6, nullptr, nullptr};
    element->right->right->left = new Node{3, nullptr, nullptr};

    // Appel de la fonction fofo
    int a = fofo(element);
    // std::cout << "Result: " << a << std::endl;
    int b = 0;
    h(&b, element);
    std::cout << "Result: " << b << std::endl;

    return 0;
}

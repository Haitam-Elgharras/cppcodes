#include <iostream>
#include "Etudiants.h"

class ABREtudiants
{
private:
    struct Node
    {
        Etudiant data;
        Node *left;
        Node *right;
        int height;
    };
    Node *root;

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return node->height;
        }
    }

    int balanceFactor(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return height(node->left) - height(node->right);
        }
    }

    void updateHeight(Node *node)
    {
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    Node *rotateRight(Node *node)
    {
        Node *newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }

    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }

    Node *balance(Node *node)
    {
        updateHeight(node);
        int bf = balanceFactor(node);
        if (bf == 2)
        {
            if (balanceFactor(node->left) < 0)
            {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        else if (bf == -2)
        {
            if (balanceFactor(node->right) > 0)
            {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        return node;
    }

    Node *insert(Node *node, Etudiant data)
    {
        if (node == nullptr)
        {
            node = new Node;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
            node->height = 1;
        }
        else if (data.getMatricule() < node->data.getMatricule())
        {
            node->left = insert(node->left, data);
        }
        else if (data.getMatricule() > node->data.getMatricule())
        {
            node->right = insert(node->right, data);
        }
        return balance(node);
    }

    Node *findMin(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        else if (node->left == nullptr)
        {
            return node;
        }
        else
        {
            return findMin(node->left);
        }
    }

    Node *removeMin(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        else if (node->left == nullptr)
        {
            return node->right;
        }
        else
        {
            node->left = removeMin(node->left);
            return balance(node);
        }
    }

    Node *remove(Node *node, int matricule)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        else if (matricule < node->data.getMatricule())
        {
            node->left = remove(node->left, matricule);
        }
        else if (matricule > node->data.getMatricule())
        {
            node->right = remove(node->right, matricule);
        }
        else
        {
            Node *left = node->left;
            Node *right = node->right;
            if (right == nullptr)
            {
                delete node;
                return left;
            }
            Node *min = findMin(right);
            min->right = removeMin(right);
            min->left = left;
            delete node;
            return balance(min);
        }
        return balance(node);
    }

#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include "Voos.hpp"

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k);
};

class Avl {
public:
    Avl();
    ~Avl();

    void insert(int key);
    void remove(int key);
    bool search(int key);
    void inorder();
    
private:
    Node* root;

    Node* insert(Node* node, int key);
    Node* remove(Node* node, int key);
    Node* search(Node* node, int key);
    void inorder(Node* node);
    Node* findMin(Node* node);
    Node* balance(Node* node);
    Node* rotateLeft(Node* x);
    Node* rotateRight(Node* y);
    int getHeight(Node* node);
    int getBalance(Node* node);
    void updateHeight(Node* node);
    void destroyTree(Node* node);
};

#endif

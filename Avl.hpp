#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <string>
#include <ctime>
#include "Voo.hpp"

class Voo;

// Definição de um template para suportar múltiplos tipos de chave
template <typename T>
struct Node {
    T key;
    int height;
    Node* left;
    Node* right;
    Voo** voo;

    Node(T k, Voo* v = nullptr) : key(k), height(1), left(nullptr), right(nullptr), voo(v) {}
};

template <typename T>
class Avl {
public:
    Avl() : root(nullptr) {}
    ~Avl() { destroyTree(root); }

    void insert(T key, Voo* voo = nullptr) { root = insert(root, key, voo); }
    void remove(T key) { root = remove(root, key); }
    bool search(T key) { return search(root, key) != nullptr; }
    void inorder() { inorder(root); std::cout << std::endl; }
    
private:
    Node<T>* root;

    Node<T>* insert(Node<T>* node, T key, Voo* voo);
    Node<T>* remove(Node<T>* node, T key);
    Node<T>* search(Node<T>* node, T key);
    void inorder(Node<T>* node);
    Node<T>* findMin(Node<T>* node);
    Node<T>* balance(Node<T>* node);
    Node<T>* rotateLeft(Node<T>* x);
    Node<T>* rotateRight(Node<T>* y);
    int getHeight(Node<T>* node) { return node ? node->height : 0; }
    int getBalance(Node<T>* node) { return node ? getHeight(node->left) - getHeight(node->right) : 0; }
    void updateHeight(Node<T>* node) { node->height = 1 + std::max(getHeight(node->left), getHeight(node->right)); }
    void destroyTree(Node<T>* node);
};

// Implementação das funções

template <typename T>
Node<T>* Avl<T>::insert(Node<T>* node, T key, Voo* voo) {
    if (!node) return new Node<T>(key, voo);
    if (key < node->key) node->left = insert(node->left, key, voo);
    else if (key > node->key) node->right = insert(node->right, key, voo);
    else return node;
    updateHeight(node);
    return balance(node);
}

template <typename T>
Node<T>* Avl<T>::remove(Node<T>* node, T key) {
    if (!node) return node;
    if (key < node->key) node->left = remove(node->left, key);
    else if (key > node->key) node->right = remove(node->right, key);
    else {
        if (!node->left || !node->right) {
            Node<T>* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }
        Node<T>* temp = findMin(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }
    updateHeight(node);
    return balance(node);
}

template <typename T>
Node<T>* Avl<T>::search(Node<T>* node, T key) {
    if (!node || node->key == key) return node;
    return key < node->key ? search(node->left, key) : search(node->right, key);
}

template <typename T>
void Avl<T>::inorder(Node<T>* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->key << " ";
    inorder(node->right);
}

template <typename T>
Node<T>* Avl<T>::findMin(Node<T>* node) {
    while (node->left) node = node->left;
    return node;
}

template <typename T>
Node<T>* Avl<T>::balance(Node<T>* node) {
    int balanceFactor = getBalance(node);
    if (balanceFactor > 1) {
        if (getBalance(node->left) < 0) node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1) {
        if (getBalance(node->right) > 0) node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

template <typename T>
Node<T>* Avl<T>::rotateLeft(Node<T>* x) {
    Node<T>* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

template <typename T>
Node<T>* Avl<T>::rotateRight(Node<T>* y) {
    Node<T>* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

template <typename T>
void Avl<T>::destroyTree(Node<T>* node) {
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

#endif

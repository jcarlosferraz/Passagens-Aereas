#include "Avl.hpp"

// Construtor do nó
Node::Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}

// Construtor da Árvore AVL
Avl::Avl() : root(nullptr) {}

// Destrutor da Árvore AVL
Avl::~Avl() {
    destroyTree(root);
}

// Função auxiliar para destruir a árvore
void Avl::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Retorna a altura do nó
int Avl::getHeight(Node* node) {
    return node ? node->height : 0;
}

// Calcula o fator de balanceamento do nó
int Avl::getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Atualiza a altura do nó
void Avl::updateHeight(Node* node) {
    if (node) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
}

// Rotação simples à direita
Node* Avl::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Rotação simples à esquerda
Node* Avl::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Balanceia um nó após inserção ou remoção
Node* Avl::balance(Node* node) {
    updateHeight(node);
    int balanceFactor = getBalance(node);

    if (balanceFactor > 1) {
        if (getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    if (balanceFactor < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}

// Insere um valor na árvore AVL
Node* Avl::insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    return balance(node);
}

// Insere um valor na árvore AVL (interface pública)
void Avl::insert(int key) {
    root = insert(root, key);
}

// Encontra o nó com o menor valor
Node* Avl::findMin(Node* node) {
    return node->left ? findMin(node->left) : node;
}

// Remove um valor da árvore AVL
Node* Avl::remove(Node* node, int key) {
    if (!node) return nullptr;

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        } else {
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }

    return balance(node);
}

// Remove um valor da árvore AVL (interface pública)
void Avl::remove(int key) {
    root = remove(root, key);
}

// Busca um valor na árvore AVL
Node* Avl::search(Node* node, int key) {
    if (!node || node->key == key) return node;
    return key < node->key ? search(node->left, key) : search(node->right, key);
}

// Busca um valor na árvore AVL (interface pública)
bool Avl::search(int key) {
    return search(root, key) != nullptr;
}

// Percorre a árvore em ordem crescente
void Avl::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }
}

// Interface pública para percorrer a árvore
void Avl::inorder() {
    inorder(root);
    std::cout << std::endl;
}

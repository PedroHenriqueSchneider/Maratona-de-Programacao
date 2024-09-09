#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Estrutura de um nó da árvore
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Classe para a Árvore Binária de Pesquisa
class BST {
private:
    Node* root;

    // Função de inserção
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Função para procurar um valor
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (value == node->value) {
            return true;
        }
        return value < node->value ? search(node->left, value) : search(node->right, value);
    }

    // Função para imprimir em ordem infixa
    void infix(Node* node) {
        if (node) {
            infix(node->left);
            cout << node->value << endl;
            infix(node->right);
        }
    }

    // Função para imprimir em ordem prefixa
    void prefix(Node* node) {
        if (node) {
            cout << node->value << endl;
            prefix(node->left);
            prefix(node->right);
        }
    }

    // Função para imprimir em ordem posfixa
    void postfix(Node* node) {
        if (node) {
            postfix(node->left);
            postfix(node->right);
            cout << node->value << endl;
        }
    }

    // Função para encontrar o menor valor (antecessor)
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Função para remover um valor
    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            // Encontrado o nó a ser removido
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Nó com dois filhos: pega o menor na subárvore da direita
            Node* temp = findMin(node->right);
            node->value = temp->value; // Substitui o valor
            node->right = remove(node->right, temp->value); // Remove o antecess​⬤

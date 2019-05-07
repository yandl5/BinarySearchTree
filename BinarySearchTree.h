#ifndef BINARYTREE
#define BINARYTREE
#include "node.h"
class BinarySearchTree
{
private:
    Node* root;
    int quantidadeElementos;

public:
    BinarySearchTree();
    //métodos gets e sets
    void setRoot(Node* node);
    void setQuantidadeElementos(int quantidade);
    Node* getRoot();
    int getQuantidadeElementos();
    //inserção e remoção
    void insertTree(int valor);
    void removeTree(int valor);
    string toString();
    int mediana();
    bool ehCheia();
    bool ehCompleta();
    //int posicao(int x);
    int enesimoElemento(int n);
    //Função auxiliares
    int heightTree(Node* r);
    void printTree(Node* r);
    int auxEnesimoElemento(int n,Node* aux,int percorridos);
};

#endif // BINARYTREE

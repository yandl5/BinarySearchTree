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
    void setRoot(Node* node);
    void setQuantidadeElementos(int quantidade);
    Node* getRoot();
    int getQuantidadeElementos();

};

#endif // BINARYTREE

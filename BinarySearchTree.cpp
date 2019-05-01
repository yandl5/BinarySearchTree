#include "BinarySearchTree.h"
BinarySearchTree::BinarySearchTree()
{
    this->setRoot(NULL);
    this->setQuantidadeElementos(0);
}
void BinarySearchTree::setQuantidadeElementos(int quantidade)
{
    this->quantidadeElementos = quantidade;
}
void BinarySearchTree::setRoot(Node* node)
{
    this->root = node;
}
Node* BinarySearchTree::getRoot()
{
    return this->root;
}
int BinarySearchTree::getQuantidadeElementos()
{
    return this->quantidadeElementos;
}

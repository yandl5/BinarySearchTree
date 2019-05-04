#include "node.h"
Node::Node()
{
    this->setRight(NULL);
    this->setLeft(NULL);
}
Node::Node(int valor)
{
    this->valor = valor;
    this->setRight(NULL);
    this->setLeft(NULL);
}
Node* Node::getRight()
{
    return this->right;
}
Node* Node::getLeft()
{
    return this->left;
}
int Node::getValor()
{
    return this->valor;
}
void Node::setLeft(Node* node)
{
    this->left = node;
}
void Node::setRight(Node* node)
{
    this->right = node;
}
void Node::setValor(int valor)
{
    this->valor = valor;
}



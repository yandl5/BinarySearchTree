#include "node.h"
Node::Node()
{
    this->setFather(NULL);
    this->setRight(NULL);
    this->setLeft(NULL);
}
Node::Node(int valor)
{
    this->valor = valor;
    this->setFather(NULL);
    this->setRight(NULL);
    this->setLeft(NULL);
}
Node* Node::getFather()
{
    return this->father;
}
Node* Node::getRight()
{
    return this->right;
}
Node* Node::getLeft()
{
    return this->left;
}
int Node::getAltura()
{
    return this->altura;
}
int Node::getValor()
{
    return this->valor;
}
void Node::setFather(Node* node)
{
    this->father = node;
}
void Node::setLeft(Node* node)
{
    this->left = node;
}
void Node::setRight(Node* node)
{
    this->right = node;
}
void Node::setAltura(int altura)
{
    this->altura = altura;
}
void Node::setValor(int valor)
{
    this->valor = valor;
}



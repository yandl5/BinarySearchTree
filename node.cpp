#include "node.h"
Node::Node()
{
    this->setRight(NULL);
    this->setLeft(NULL);
    this->nodesLeft = 0;
    this->nodesRight = 0;
}
Node::Node(int valor)
{
    this->valor = valor;
    this->setRight(NULL);
    this->setLeft(NULL);
    this->nodesLeft = 0;
    this->nodesRight = 0;
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
int Node::getNodesRight()
{
    return this->nodesRight;
}
int Node::getNodesLeft()
{
    return this->nodesLeft;
}
void Node::setNodesRight(int n)
{
    this->nodesRight = n;
    if(nodesRight<0)
    {
        this->nodesRight = 0;
    }
}
void Node::setNodesLeft(int n)
{
    this->nodesLeft = n;
    if(this->nodesLeft<0)
    {
        this->nodesLeft = 0;
    }
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



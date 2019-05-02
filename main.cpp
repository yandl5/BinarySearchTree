#include <iostream>
#include "node.h"
#include "BinarySearchTree.h"
int main()
{
    BinarySearchTree *a = new BinarySearchTree();
    a->insertTree(50);
    a->insertTree(59);
    a->insertTree(56);
    a->insertTree(67);
    a->insertTree(66);
    a->insertTree(75);
    a->removeTree(67);
    Node* aux = new Node();
    aux = a->getRoot();
    cout<<a->getRoot()->getValor()<<endl<<a->getRoot()->getRight()->getValor()<<endl<<a->getRoot()->getRight()->getRight()->getValor()<<endl;
    cout<<a->getQuantidadeElementos()<<endl;
    return 0;
}

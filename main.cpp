#include <iostream>
#include "node.h"
#include "BinarySearchTree.h"
int main()
{
    BinarySearchTree *a = new BinarySearchTree();
    a->insertTree(15);
    a->insertTree(28);
    a->insertTree(7);
    a->insertTree(45);
    a->insertTree(45);
    cout<<a->getRoot()->getValor()<<endl;
    cout<<a->getRoot()->getRight()->getValor()<<endl;
    cout<<a->getRoot()->getLeft()->getValor()<<endl;
    cout<<a->getRoot()->getRight()->getRight()->getValor()<<endl;
    return 0;
}

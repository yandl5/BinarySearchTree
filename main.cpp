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
    a->insertTree(55);
    a->insertTree(57);
    a->insertTree(66);
    a->insertTree(75);
    a->insertTree(54);
    a->insertTree(65);
    a->insertTree(72);
    a->insertTree(78);
    a->insertTree(80);
    a->insertTree(70);
    a->insertTree(71);
    a->insertTree(45);
    a->insertTree(42);
    a->insertTree(41);
    a->insertTree(43);
    a->insertTree(46);
    a->insertTree(48);
    a->insertTree(69);
    a->insertTree(49);
    cout<<endl;

    BinarySearchTree *b = new BinarySearchTree();
    b->insertTree(50);
    b->insertTree(45);
    b->insertTree(59);
    b->insertTree(47);
    b->insertTree(56);
    b->insertTree(67);
    b->insertTree(44);
    Node* aux = new Node();
    aux=a->getRoot();
    while(aux!=NULL)
    {
        cout<<aux->getNodesLeft()<<" ";
        aux = aux->getLeft();
    }
    cout<<endl;
    a->removeTree(45);
    a->removeTree(50);
    aux=a->getRoot();
    while(aux!=NULL)
    {
        cout<<aux->getNodesLeft()<<" ";
        aux = aux->getLeft();
    }
    cout<<endl;
    aux=a->getRoot();
    cout<<aux->getLeft()->getRight()->getValor()<<" "<<aux->getLeft()->getRight()->getNodesRight()<<endl;
    return 0;
}

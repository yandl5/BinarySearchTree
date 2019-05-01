#include <iostream>
#include "node.h"
#include "BinarySearchTree.h"
int main()
{
    BinarySearchTree *a = new BinarySearchTree();
    Node *b = new Node(15);
    a->setRoot(b);
    cout<<a->getRoot()->getValor()<<endl;
    return 0;
}

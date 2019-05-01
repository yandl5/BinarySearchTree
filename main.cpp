#include <iostream>
#include "node.h"

int main()
{
    Node *a = new Node(12);
    cout<<a->getFather()->getValor()<<endl;
    return 0;
}

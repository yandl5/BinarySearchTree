#ifndef NODE
#define NODE
#include <iostream>
using namespace std;
class Node
{
private:
    int valor;
    Node* right;
    Node* left;
public:
    Node();
    Node(int valor);
    int getValor();
    Node* getRight();
    Node* getLeft();
    void setValor(int valor);
    void setRight(Node* node);
    void setLeft(Node* node);
};

#endif // NODE

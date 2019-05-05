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
    int nodesLeft;
    int nodesRight;
public:
    Node();
    Node(int valor);
    int getValor();
    Node* getRight();
    Node* getLeft();
    int getNodesRight();
    int getNodesLeft();
    void setNodesRight(int n);
    void setNodesLeft(int n);
    void setValor(int valor);
    void setRight(Node* node);
    void setLeft(Node* node);
};

#endif // NODE

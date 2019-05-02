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
    int altura;
public:
    Node();
    Node(int valor);
    int getValor();
    int getAltura();
    Node* getRight();
    Node* getLeft();
    void setValor(int valor);
    void setRight(Node* node);
    void setLeft(Node* node);
    void setAltura(int altura);
};

#endif // NODE

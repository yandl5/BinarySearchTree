#ifndef NODE
#define NODE
#include <iostream>
using namespace std;
class Node
{
private:
    int valor;
    Node* father;
    Node* right;
    Node* left;
    int altura;
public:
    Node();
    Node(int valor);
    int getValor();
    int getAltura();
    Node* getFather();
    Node* getRight();
    Node* getLeft();
    void setValor(int valor);
    void setFather(Node* node);
    void setRight(Node* node);
    void setLeft(Node* node);
    void setAltura(int altura);
};

#endif // NODE

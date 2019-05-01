#ifndef BINARYTREE
#define BINARYTREE
class BinarySearchTree
{
private:
    Node* root;
    int quantidadeElementos;

public:
    BinarySearchTree();
    void setRoot(Node* node);
    void setQuantidadeElementos(int quantidade);
    Node* getRoot();
    int getQuantidadeElementos();

};

#endif // BINARYTREE

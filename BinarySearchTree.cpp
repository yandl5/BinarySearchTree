#include "BinarySearchTree.h"
//construtor
BinarySearchTree::BinarySearchTree()
{
    this->setRoot(NULL);
    this->setQuantidadeElementos(0);
}
//métodos sets
void BinarySearchTree::setQuantidadeElementos(int quantidade)
{
    this->quantidadeElementos = quantidade;
}
void BinarySearchTree::setRoot(Node* node)
{
    this->root = node;
}
//métodos gets
Node* BinarySearchTree::getRoot()
{
    return this->root;
}
int BinarySearchTree::getQuantidadeElementos()
{
    return this->quantidadeElementos;
}
//inserção
void BinarySearchTree::insertTree(int valor)
{
    Node* inserir = new Node(valor);
    if(this->root==NULL)
    {
        this->root = inserir;
        this->quantidadeElementos++;
        return;
    }
    Node* auxiliar = new Node();
    auxiliar = this->root;
    while(auxiliar!=NULL)
    {
        if(valor == auxiliar->getValor())
        {
            cout<<"Valor que vc deseja inserir, ja existe na arvore"<<endl;
            return;
        }
        else if(valor <= auxiliar->getValor() && auxiliar->getLeft() != NULL)
        {
            auxiliar = auxiliar->getLeft();
        }
        else if(valor >= auxiliar->getValor() && auxiliar->getRight() != NULL)
        {
            auxiliar = auxiliar->getRight();
        }
        else if(valor < auxiliar->getValor() && auxiliar->getLeft() == NULL)
        {
            auxiliar->setLeft(inserir);
            auxiliar->getLeft()->setFather(auxiliar);
            this->quantidadeElementos++;
            return;
        }
        else if(valor > auxiliar->getValor() && auxiliar->getRight() == NULL)
        {
            auxiliar->setRight(inserir);
            auxiliar->getRight()->setFather(auxiliar);
            this->quantidadeElementos++;
            return;
        }
    }
    //remoção
    void BinarySearchTree::removeTree(int valor)
    {
        if(this->quantidadeElementos==0)
        {
            cout<<"Nao ha elementos para remorcao"<<endl;
            return;
        }
        if(this->quantidadeElementos==1 && root->getValor()==valor)
        {
            this->root = NULL;
            this->quantidadeElementos--;
            return;
        }
        Node* auxiliar = new Node();
        auxiliar = this->root;
        Node* auxiliarFather = new Node();
        while(auxiliar!= NULL)
        {
            //caso nao haja filhos a esquerda e direita
            if(auxiliar->getValor()==valor && auxiliar->getLeft()==NULL && auxiliar->getRight()==NULL)
            {
                auxiliarFather = auxiliar->getFather();
                if(auxiliarFather->getRight()==auxiliar)
                {
                    auxiliarFather->setRight(NULL);
                    this->quantidadeElementos--;
                    return;
                }
                else
                {
                    auxiliarFather->setLeft(NULL);
                    this->quantidadeElementos--;
                    return;
                }
            }
            //Tem filhos a esquerda somente
            else if(auxiliar->getValor()==valor && auxiliar->getLeft()!=NULL && auxiliar->getRight()==NULL)
            {
                auxiliarFather = auxiliar->getFather();
                auxiliarFather->set
            }
        }
    }

}

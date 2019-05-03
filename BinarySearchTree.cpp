#include "BinarySearchTree.h"
#include <vector>
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
            this->quantidadeElementos++;
            return;
        }
        else if(valor > auxiliar->getValor() && auxiliar->getRight() == NULL)
        {
            auxiliar->setRight(inserir);
            this->quantidadeElementos++;
            return;
        }
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
    Node* auxiliarB = new Node();
    auxiliar = this->root;
    int i=0;
    int j=0;
    vector<Node*> aux;
    vector<Node*> auxB;
    while(auxiliar!= NULL)
    {
        aux.push_back(auxiliar);
        //caso não haja filhos
        if((auxiliar->getValor()==valor) && (auxiliar->getRight()==NULL) && (auxiliar->getLeft()==NULL))
        {
            if(aux[i-1]->getRight()==auxiliar)
            {
                aux[i-1]->setRight(NULL);
                this->quantidadeElementos--;
                return;
            }
            else
            {
                aux[i-1]->setLeft(NULL);
                this->quantidadeElementos--;
                return;
            }
        }
        //caso haja filhos apenas um filho
        if((auxiliar->getValor()==valor) && (auxiliar->getLeft()==NULL) || (auxiliar->getRight()==NULL))
        {
            if(auxiliar->getLeft()==NULL)
            {
                aux[i-1]->setRight(auxiliar->getRight());
                this->quantidadeElementos--;
                return;
            }
            else if(auxiliar->getRight()==NULL)
            {
                aux[i-1]->setLeft(auxiliar->getLeft());
                this->quantidadeElementos--;
                return;
            }
        }
        //caso haja filhos pela direita e esquerda
        if((auxiliar->getValor()==valor) && (auxiliar->getLeft()!=NULL) && (auxiliar->getRight()!=NULL))
        {
            //vamos pegar o nó minimo da cadeia
            auxiliarB = auxiliar->getRight();
            auxB.push_back(auxiliarB);
            while(auxiliarB!=NULL)
            {
                auxiliarB = auxiliarB->getLeft();
                auxB.push_back(auxiliarB);
                j++;
            }
            auxiliarB = auxB[j-1];
            //Mantem a sequencia da árvore.
            if(auxB[j-1]->getRight()==NULL)
            {
                auxB[j-1]->setLeft(NULL);
            }
            else if(auxB[j-1]->getRight()!=NULL && auxB.size()>2)
            {
                auxB[j-2]->setLeft(auxB[j-1]->getRight());
            }
            //Atualiza o minimo achado
            auxB[j-1]->setRight(auxiliar->getRight());
            auxB[j-1]->setLeft(auxiliar->getLeft());
            //Atualiza nó pai ao nó que vai ser removido
            if(aux[i-1]->getRight()==auxiliar)
            {
                aux[i-1]->setRight(auxB[j-1]);
            }
            else
            {
                aux[i-1]->setLeft(auxB[j-1]);
            }
            this->quantidadeElementos--;
            return;
        }
        //Atualizadores
        if(auxiliar->getValor()>valor)
        {
            auxiliar = auxiliar->getLeft();
        }
        else if(auxiliar->getValor()<valor)
        {
            auxiliar = auxiliar->getRight();
        }
        //iteradores
        i++;
    }
}



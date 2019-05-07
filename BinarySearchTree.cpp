#include "BinarySearchTree.h"
#include <vector>
#include <math.h>
#include <queue>
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
    vector<char> mapaCaminho;
    vector<Node*> caminho;
    int i=0;
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
            while(i>0)
            {
                if(mapaCaminho[i-1]='r')
                {
                    caminho[i-1]->setNodesRight(caminho[i-1]->getNodesRight()-1);
                }
                else if(mapaCaminho[i-1]=='l')
                {
                    caminho[i-1]->setNodesLeft(caminho[i-1]->getNodesLeft()-1);
                }
                i--;
            }
            cout<<"Valor que vc deseja inserir, ja existe na arvore"<<endl;
            return;
        }
        else if(valor <= auxiliar->getValor() && auxiliar->getLeft() != NULL)
        {
            mapaCaminho.push_back('l');
            caminho.push_back(auxiliar);
            auxiliar->setNodesLeft(auxiliar->getNodesLeft()+1);
            auxiliar = auxiliar->getLeft();
        }
        else if(valor >= auxiliar->getValor() && auxiliar->getRight() != NULL)
        {
            mapaCaminho.push_back('r');
            caminho.push_back(auxiliar);
            auxiliar->setNodesRight(auxiliar->getNodesRight()+1);
            auxiliar = auxiliar->getRight();
        }
        else if(valor < auxiliar->getValor() && auxiliar->getLeft() == NULL)
        {
            auxiliar->setLeft(inserir);
            auxiliar->setNodesLeft(auxiliar->getNodesLeft()+1);
            this->quantidadeElementos++;
            return;
        }
        else if(valor > auxiliar->getValor() && auxiliar->getRight() == NULL)
        {
            auxiliar->setRight(inserir);
            auxiliar->setNodesRight(auxiliar->getNodesRight()+1);
            this->quantidadeElementos++;
            return;
        }
        i++;
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
    vector<char> mapaPercurso;
    while(auxiliar!= NULL)
    {
        aux.push_back(auxiliar);
        //caso não haja filhos
        if(auxiliar->getValor()==valor && auxiliar->getRight()==NULL && auxiliar->getLeft()==NULL)
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
        if((auxiliar->getValor()==valor) && (auxiliar->getLeft()==NULL || auxiliar->getRight()==NULL))
        {
            if(auxiliar->getLeft()==NULL)
            {
                if(auxiliar==root)
                {
                    this->root=auxiliar->getRight();
                    this->quantidadeElementos--;
                    return;
                }
                aux[i-1]->setRight(auxiliar->getRight());
                this->quantidadeElementos--;
                return;
            }
            else if(auxiliar->getRight()==NULL)
            {
                if(auxiliar==root)
                {
                    this->root=auxiliar->getLeft();
                    this->quantidadeElementos--;
                    return;
                }
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
            if(auxiliarB->getNodesRight()>0)
            {
                auxiliarB->setNodesRight(auxiliarB->getNodesRight());
            }
            auxB.push_back(auxiliarB);
            while(auxiliarB!=NULL)
            {
                auxiliarB = auxiliarB->getLeft();
                if(auxiliarB!=NULL)
                {
                    auxiliarB->setNodesLeft(auxiliar->getNodesLeft()-1);
                }
                auxB.push_back(auxiliarB);
                j++;
            }
            //Mantem a sequencia da árvore.
            if(auxB[j-1]->getRight()==NULL && auxB.size()>2)
            {
                auxB[j-2]->setNodesLeft(0);
                auxB[j-2]->setLeft(NULL);
            }
            else if(auxB[j-1]->getRight()!=NULL && auxB.size()>2)
            {
                auxB[j-2]->setNodesLeft(auxB[j-2]->getNodesRight());
                auxB[j-2]->setLeft(auxB[j-1]->getRight());
            }
            //caso que o nó é terminal
            if(auxB.size()<=2 && auxB[0]->getLeft()!=NULL)
            {
                auxiliar->setRight(NULL);
            }
            else if(auxB.size()<=2 && auxB[0]->getRight()!=NULL)
            {
                auxiliar->setRight(auxB[0]->getRight());
            }
            else if(auxB.size()<=2 && auxB[0]->getRight()==NULL)
            {
                auxiliar->setRight(auxB[0]->getRight());
            }
            //Atualiza o minimo achado
            auxB[j-1]->setRight(auxiliar->getRight());
            auxB[j-1]->setNodesRight(auxiliar->getNodesRight()-1);
            auxB[j-1]->setLeft(auxiliar->getLeft());
            auxB[j-1]->setNodesLeft(auxiliar->getNodesLeft());
            //Atualiza nó pai ao nó que vai ser removido
            if(i==0)
            {
                auxB[j-1]->setNodesRight(this->root->getNodesRight()-1);
                auxB[j-1]->setNodesLeft(this->root->getNodesLeft());
                this->setRoot(auxB[j-1]);
            }
            else
            {
                if(aux[i-1]->getRight()==auxiliar)
                {
                    aux[i-1]->setRight(auxB[j-1]);
                }
                else if(aux[i-1]->getLeft()==auxiliar)
                {
                    aux[i-1]->setLeft(auxB[j-1]);
                }
            }
            this->quantidadeElementos--;
            return;
        }
        //Atualizadores
        if(auxiliar->getValor()>valor)
        {
            auxiliar->setNodesLeft(auxiliar->getNodesLeft()-1);
            mapaPercurso.push_back('l');
            auxiliar = auxiliar->getLeft();
        }
        else if(auxiliar->getValor()<valor)
        {
            auxiliar->setNodesRight(auxiliar->getNodesRight()-1);
            mapaPercurso.push_back('r');
            auxiliar = auxiliar->getRight();
        }
        //caso não encontre o node para remorção
        if(auxiliar==NULL)
        {
            while(i>0)
                {
                    if(mapaPercurso[i-1]='r')
                    {
                        aux[i-1]->setNodesRight(aux[i-1]->getNodesRight()+1);
                    }
                    else if(mapaPercurso[i-1]=='l')
                    {
                        aux[i-1]->setNodesLeft(aux[i-1]->getNodesLeft()+1);
                    }
                    i--;
                }
        }
        //iteradores
        i++;
    }
}
string BinarySearchTree::toString()
{
    string porNivel;
    queue<Node*> Queue;
    Node* aux = new Node();
    Queue.push(this->root);
    while( !Queue.empty() )
    {
        aux = Queue.front();
        Queue.pop();
        porNivel = porNivel + to_string(aux->getValor());
        if(aux->getLeft() != NULL)
        {
            Queue.push(aux->getLeft());
        }
        if(aux->getRight() != NULL)
        {
            Queue.push(aux->getRight());
        }
        porNivel = porNivel + "  ";
    }
    return porNivel;
}
int BinarySearchTree::mediana()
{
    int mediana;
    if(quantidadeElementos==0)
    {
        cout<<"Não há mediana, pois não existe elementos válidos da árvore"<<endl;
        return 0;
    }

}
bool BinarySearchTree::ehCompleta()
{
    if(this->quantidadeElementos==0)
    {
        return false;
    }
    else
    {
        int altura = this->heightTree(this->root);
        int quantidadeMinima = pow(2,altura-1);
        int quantidadeMaxima = pow(2,altura) -1;
        if(this->quantidadeElementos>=quantidadeMinima&&this->quantidadeElementos<=quantidadeMaxima)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool BinarySearchTree::ehCheia()
{
    int altura = this->heightTree(this->root);
    int quantidadeMaxima = pow(2,altura) -1;
    if( this-> quantidadeElementos == 0)
    {
        return false;
    }
    else
    {
        if(this->quantidadeElementos==quantidadeMaxima)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void BinarySearchTree::printTree(Node* r)
{
    if(r!=NULL)
    {
        this->printTree(r->getLeft());
        cout<<r->getValor()<<" ";
        this->printTree(r->getRight());
    }
    else
    {
        cout<<endl;
        return;
    }
}
int BinarySearchTree::heightTree(Node* r)
{
    if(r != NULL)
    {
        int heightLeft = heightTree(r->getLeft());
        int heightRight = heightTree(r->getRight());
        if (heightLeft < heightRight)
        {
            return heightRight + 1;
        }
        else
        {
            return heightLeft + 1;
        }
    }
    else
    {
       return 0;
    }
}
int BinarySearchTree::enesimoElemento(int n)
{
    if(this->quantidadeElementos<0 && n<1)
    {
       return -1;
    }
    else
    {
        return auxEnesimoElemento(n,this->root,this->root->getNodesLeft()+1);
    }
}
int BinarySearchTree::auxEnesimoElemento(int n,Node* aux,int percorridos)
{
    cout<<aux->getValor()<<endl;
    cout<<aux->getNodesLeft()<<" "<<aux->getNodesRight()<<" "<<percorridos<<endl;
    if(aux==NULL)
    {
        return -1;
    }
    else if(percorridos==n)
    {
        return aux->getValor();
    }
    else if(percorridos>=n)
    {
        if(aux->getLeft()!=NULL && aux!= this->root)
        {
            return auxEnesimoElemento(n,aux->getLeft(),percorridos-aux->getLeft()->getNodesRight()-1);
        }
        else if(aux->getLeft()!=NULL && aux== this->root)
        {
            return auxEnesimoElemento(n,aux->getLeft(),percorridos-aux->getLeft()->getNodesRight()-1);
        }
        else
            return -1;
    }
    else if(percorridos<=n)
    {
        if(aux->getRight()!=NULL && aux!= this->root)
        {
            return auxEnesimoElemento(n,aux->getRight(),percorridos+aux->getRight()->getNodesLeft()+1);
        }
        else if(aux->getRight()!=NULL && aux== this->root)
        {
            return auxEnesimoElemento(n,aux->getRight(),percorridos+aux->getRight()->getNodesLeft()+1);
        }
        else return -1;
    }
    else
    {
        cout<<"sei lá"<<endl;
        return -1;
    }
}


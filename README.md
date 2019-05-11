# Árvore Binária de Busca Estendida

Neste repositório encontra-se uma implementação em C++ da estrutura de dados **Árvore Binária de Busca** (ABB) com algumas modificações que reduzir a complexidade de algumas operações que podem ser realizadas pela estrutura. 

## Árvore Binária de Busca

Em Ciência da Computação, uma **Árvore Binária de Busca** é uma estrutura de dados derivada de uma [Árvore Binária] (Estrutura Hierárquica baseada em Nós, que guardam uma determinada informação e são distinguidos por uma **_chave_**, geralmente um valor número) onde a estrutura da árvore segue a regra de que, dado um nó **_R_**, todos os nós da sub-árvore à esquerda de **_R_** tem o valor da **_chave_** menor que a **_chave_** de **_R_**. Analogamente, todos os nós que formam a sub-árvore à direita de **_R_** tem **_chave_** maior que **_R_**.

<p align="center">
<img src="http://www.desafiosdeti.com.br/wp-content/uploads/2017/02/arv1.png" width="30%"  />
</p>

O objetivo deste tipo de árvore é estruturar os dados de forma a permitir busca binária e realizar as operações com complexidade de ordem **logaritmíca**.     

**FUNCIONALIDADES IMPLEMENTADAS**  

- [X]  busca - Melhor caso: ***O(log n)*** | Pior caso: ***O(n)*** 
- [X]  inserção - Melhor caso: ***O(log n)*** | Pior caso: ***O(n)*** 
- [X]  remoção - Melhor caso: ***O(log n)*** | Pior caso: ***O(n)*** 
- [X]  nÉsimoTermo - Melhor caso: ***O(log n)*** | Pior caso: ***O(n)*** 
- [X]  posição - Melhor caso: ***O(log n)*** | Pior caso: ***O(n)*** 
- [X]  mediana - Melhor caso: ***O(log n)*** | Pior caso: ***O(n)*** 
- [X]  ehCheia - ***O(h)***
- [X]  ehCompleta - ***O(h)***
- [X]  toString - ***O(n)***

[Árvore Binária]: https://pt.wikipedia.org/wiki/%C3%81rvore_bin%C3%A1ria_de_busca

## Compilando e Executando em terminal Ubuntu

### Compilando

Em um terminal do Linux, entrar na pasta do projeto e compilar os arquivos .cpp, executando os seguintes comandos

```
g++ -Wall -std=c++11 BinarySearchTree.cpp node.cpp driveBST.cpp -o abb
```

### Executando
Para realizar a execução do programa é necessária a existência de 2 arquivos: um arquivo que contenha os valores a serem inseridos para criar a árvore e um arquivo que contenha os comandos que serão realizados.É **EXTREMAMENTE** importante que os arquivos tenham os nomes **EntradaDaABB** e **Comandos**, respectivamente. No diretório raiz do projeto já se encontram os dois arquivos, seguindo o padrão de nome descrito acima. 

Para excutar:
```
./abb Comandos < EntradadaABB 
```

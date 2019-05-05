/**

**/


#include "BinarySearchTree.h"
#include <string>
#include <fstream>
#include <stdio>
/**
 * @brief Função principal do projeto
 * @param argc Quantidade de argumentos passados via linha de comando
 * @param argv Vetor que guardará os argumentos passados
 */
int main(int argc, char *argv[])
{

    int valor;
    int indiceN;
    int inicio;
    BinarySearchTree arvore;

    string nomeArquivoEntrada = argv[1];
    string nomeArquivoComandos = argv[2];

    ifstream arquivoEntrada;
    ifstream arquivoComandos;

    string comando;

    string comandoPrincipal;

    if (nomeArquivoEntrada != "Entrada" || nomeArquivoComandos != "Comandos") {
        cout << "Erro ao ler os arquivos de entrada. Algum dos dois não foi encontrado. Os mesmos precisam ter como nome 'Entrada'e 'Comandos'!" << endl;
    } else {
        arquivoEntrada.open (nomeArquivoEntrada, fstream::in);

        if (!( arquivoEntrada.is_open() ) {
            cerr << "Falha ao abrir o arquivo de entrada!" << endl;
            return -1;
        }

        //Ler os valores para inserir na árvore
        while (! cin.eof() ) {
            cin >> valor;
            arvore.insertTree(valor);
        }

        arquivoEntrada.close();

        arquivoComandos.open(nomeArquivoComandos, fstream::in);

        if (! ( arquivoComandos.is_open() ) ) {
        	cerr << "Falha ao abrir o arquivo de Comandos!" << endl;
            return -1;
        }

        while (!arquivoComandos.eof() ) {
            getline (arquivoComandos, comando);

            if (comando.size() < 5) {
                cout << "Comando não reconhecido!" << endl;
            } else if (comando == "MEDIANA") {
                cout << "Comando MEDIANA reconhecido!"  << endl;
                cout << "A mediana da árvore é: " << arvore.mediana() << endl;
            } else if (comando == "CHEIA") {
                cout << "Comando CHEIA reconhecido" << endl;

                if (arvore.ehCheia() ) {
                    cout << "A árvore é cheia!" << endl;
                } else {
                    cout << "A árvore não é cheia!" << endl;
                }
            } else if (comando == "COMPLETA") {
                cout << "Comando COMPLETA reconhecido" << endl;

                if (arvore.ehCompleta() ) {
                    cout << "A árvore é completa!" << endl;
                } else {
                    cout << "A árvore não é completa!" << endl;
                }
            } else if (comando == "IMPRIMA") {
                cout << "Comando IMPRIMA reconhecido!" << endl;
                cout << "Imprimindo a árvore: " << arvore.toString() << endl;
            } else {
                /* Os comandos anteriores não utilizam algum índice
                * Já os seguintes (Enesimo, Posicao, Remova) utilizam algum
                * indice.
                */
                inicio = comando.find(" ") + 1; //Posição de inicio do N na linha no arquivo
                indiceN = stoi (comando.substr (inicio, comando.size() - inicio) ); //Converte o valor de N para um inteiro
                comandoPrincipal = comando.substr(0, inicio - 1); //Pegando o comando em si (Enesimo, etc)

                if (comandoPrincipal == "ENESIMO") {
                    cout << "Comando ENESIMO reconhecido!" << endl;
                    //cout << "O " << indiceN << " elemento é: " << arvore.enesimoElemento(indiceN);
                } else if (comandoPrincipal == "POSICAO") {
                    cout << "Comando POSICAO reconhecido!" << endl;
                    //cout << "O elemento " << indiceN << " está na posição: " << arvore.posicao(indiceN);
                } else if (comandoPrincipal == "REMOVA" ) {
                    cout << "Comando REMOVA reconhecido!" << endl;
                    arvore.removeTree(indiceN);
                }
            }
        }
        cout << endl;
        arquivoComandos.close();
    }

    return 0;
}

#include <iostream>

using namespace std;

// Estrutura de cada nó da árvore
struct No {
    int valor;
    No* esquerda;
    No* direita;
};


// Função para criar um novo nó
No* criarNo(int valor) {

    No* novo = new No;

    novo->valor = valor;
    novo->esquerda = nullptr;
    novo->direita = nullptr;

    return novo;
}


// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {

    // Se encontrou uma posição vazia,
    // cria o novo nó
    if (raiz == nullptr) {
        return criarNo(valor);
    }

    // Valores menores ficam à esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }

    // Valores maiores ficam à direita
    else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    // Valores iguais não são inseridos novamente
    else {
        cout << "Valor ja existe na arvore." << endl;
    }

    return raiz;
}


// Percurso em pré-ordem
// Raiz -> Esquerda -> Direita
void preOrdem(No* raiz) {

    if (raiz != nullptr) {

        cout << raiz->valor << " ";

        preOrdem(raiz->esquerda);

        preOrdem(raiz->direita);
    }
}


// Percurso em ordem
// Esquerda -> Raiz -> Direita
void emOrdem(No* raiz) {

    if (raiz != nullptr) {

        emOrdem(raiz->esquerda);

        cout << raiz->valor << " ";

        emOrdem(raiz->direita);
    }
}


// Percurso em pós-ordem
// Esquerda -> Direita -> Raiz
void posOrdem(No* raiz) {

    if (raiz != nullptr) {

        posOrdem(raiz->esquerda);

        posOrdem(raiz->direita);

        cout << raiz->valor << " ";
    }
}


// Função para buscar um número na árvore
No* buscar(No* raiz, int valor) {

    // Se chegou em uma posição vazia,
    // o valor não existe
    if (raiz == nullptr) {
        return nullptr;
    }

    // Encontrou o valor
    if (valor == raiz->valor) {
        return raiz;
    }

    // Se o valor é menor,
    // procura na esquerda
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }

    // Caso contrário, procura na direita
    return buscar(raiz->direita, valor);
}


// Libera a memória utilizada pela árvore
void liberarArvore(No* raiz) {

    if (raiz != nullptr) {

        liberarArvore(raiz->esquerda);

        liberarArvore(raiz->direita);

        delete raiz;
    }
}


// Função principal
int main() {

    No* raiz = nullptr;

    int opcao;
    int valor;

    do {

        cout << "\n===== ARVORE BINARIA DE BUSCA =====" << endl;
        cout << "1 - Inserir numero" << endl;
        cout << "2 - Percurso pre-ordem" << endl;
        cout << "3 - Percurso em ordem" << endl;
        cout << "4 - Percurso pos-ordem" << endl;
        cout << "5 - Buscar numero" << endl;
        cout << "0 - Sair" << endl;

        cout << "\nEscolha uma opcao: ";
        cin >> opcao;


        switch (opcao) {

            case 1:

                cout << "Digite o numero que deseja inserir: ";
                cin >> valor;

                raiz = inserir(raiz, valor);

                break;


            case 2:

                cout << "Pre-ordem: ";

                preOrdem(raiz);

                cout << endl;

                break;


            case 3:

                cout << "Em ordem: ";

                emOrdem(raiz);

                cout << endl;

                break;


            case 4:

                cout << "Pos-ordem: ";

                posOrdem(raiz);

                cout << endl;

                break;


            case 5:

                cout << "Digite o numero que deseja buscar: ";
                cin >> valor;

                if (buscar(raiz, valor) != nullptr) {
                    cout << "O valor " << valor
                         << " existe na arvore." << endl;
                }
                else {
                    cout << "O valor " << valor
                         << " nao existe na arvore." << endl;
                }

                break;


            case 0:

                cout << "Encerrando o programa..." << endl;

                break;


            default:

                cout << "Opcao invalida." << endl;
        }

    } while (opcao != 0);


    liberarArvore(raiz);

    return 0;
}
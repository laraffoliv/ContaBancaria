#include <iostream>
#include "Banco.hpp"

using namespace std;

int main() {
    Banco banco;

    char comando;
    int id, dest;
    string nome;
    float valor;

    while (true) {
        cin >> comando;

        if (comando == 'C') {
            cin >> id >> nome;
            ContaBancaria* novaConta = banco.criaConta(id, nome);
            if (novaConta != nullptr) {
                cout << "conta criada" << endl;
            } else {
                cout << "ERRO: conta repetida" << endl;
            }
        } else if (comando == 'D') {
            cin >> id >> valor;
            ContaBancaria* conta = banco.pesquisa(id);
            if (conta != nullptr) {
                conta->deposito(valor);
                cout << "deposito efetuado" << endl;
            } else {
                cout << "ERRO: conta inexistente" << endl;
            }
        } else if (comando == 'S') {
            cin >> id >> valor;
            ContaBancaria* conta = banco.pesquisa(id);
            if (conta != nullptr) {
                conta->saque(valor);
                cout << "saque efetuado" << endl;
            } else {
                cout << "ERRO: conta inexistente" << endl;
            }
        } else if (comando == 'P') {
            cin >> id >> dest >> valor;
            ContaBancaria* contaOrigem = banco.pesquisa(id);
            ContaBancaria* contaDestino = banco.pesquisa(dest);
            if (contaOrigem != nullptr && contaDestino != nullptr) {
                contaOrigem->pix(contaDestino, valor);
                cout << "pix efetuado" << endl;
            } else {
                cout << "ERRO: conta inexistente" << endl;
            }
        } else if (comando == 'I') {
            banco.listaContas();
        } else if (comando == 'T') {
            break;
        }
    }

    return 0;
}

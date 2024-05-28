#include "Banco.hpp"
#include <iostream>

Banco::Banco() : numContas(0) {
    for (int i = 0; i < MAX_CONTAS; ++i) {
        contas[i] = nullptr;
    }
}

ContaBancaria* Banco::criaConta(int id, std::string cliente) {
    if (numContas >= MAX_CONTAS) {
        return nullptr;
    }

    for (int i = 0; i < numContas; ++i) {
        if (contas[i]->getId() == id) {
            return nullptr;
        }
    }

    contas[numContas] = new ContaBancaria(id, cliente);
    numContas++;
    return contas[numContas - 1];
}

ContaBancaria* Banco::pesquisa(int id) {
    for (int i = 0; i < numContas; ++i) {
        if (contas[i]->getId() == id) {
            return contas[i];
        }
    }
    return nullptr;
}

void Banco::listaContas() {
    for (int i = 0; i < numContas; ++i) {
        contas[i]->imprime();
    }
}

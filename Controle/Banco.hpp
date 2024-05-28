#ifndef BANCO_HPP
#define BANCO_HPP

#include "ContaBancaria.hpp"

class Banco {
private:
    static const int MAX_CONTAS = 20;
    int numContas;
    ContaBancaria* contas[MAX_CONTAS];

public:
    Banco();
    ContaBancaria* criaConta(int id, std::string cliente);
    ContaBancaria* pesquisa(int id);
    void listaContas();
};

#endif /* BANCO_HPP */

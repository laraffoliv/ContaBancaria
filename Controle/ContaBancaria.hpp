#ifndef CONTABANCARIA_HPP
#define CONTABANCARIA_HPP

#include <string>

class ContaBancaria {
private:
    int id;
    std::string cliente;
    float saldo;

public:
    ContaBancaria(int _id, std::string _cliente);
    void deposito(float valor);
    void saque(float valor);
    void pix(ContaBancaria* outraConta, float valor);
    void imprime();
    int getId();
};

#endif /* CONTABANCARIA_HPP */

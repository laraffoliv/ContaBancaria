#include "ContaBancaria.hpp"
#include <iostream>
#include <iomanip>

ContaBancaria::ContaBancaria(int _id, std::string _cliente) : id(_id), cliente(_cliente), saldo(0) {}

void ContaBancaria::deposito(float valor) {
    saldo += valor;
}

void ContaBancaria::saque(float valor) {
    if (valor <= saldo) {
        saldo -= valor;
    }
}

void ContaBancaria::pix(ContaBancaria* outraConta, float valor) {
    if (valor <= saldo) {
        saldo -= valor;
        outraConta->deposito(valor);
    }
}

void ContaBancaria::imprime() {
    std::cout << id << " " << cliente << " " << std::fixed << std::setprecision(2) << saldo << std::endl;
}

int ContaBancaria::getId() {
    return id;
}

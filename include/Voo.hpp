#ifndef VOO_HPP
#define VOO_HPP

#include <iostream>
#include <string>


class Voo {
private:
public:

    std::string origem;
    std::string destino;
    float preco;
    int assentos;
    std::string dataPartida;
    std::string dataChegada;
    int numParadas;
    time_t duracaoTotal;

    Voo();
    ~Voo();
    void ImprimirVoo();
    void DefinirTempoVoo();

};

#endif

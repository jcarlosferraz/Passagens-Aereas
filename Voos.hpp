#ifndef VOOS_HPP
#define VOOS_HPP

#include <iostream>
#include <string>
#include "Avl.hpp"

struct Voo{
    std::string origem;
    std::string destino;
    float preco;
    int assentos;
    time_t dataPartida;
    time_t dataChegada;
    int numParadas;
    time_t duracaoTotal;

    Voo();
};

class Voos {
private:

    int tamanho; //Numero de voos da lista
    Voo* lista; //vetor de voos

public:

    Voos();
    ~Voos();

};

#endif

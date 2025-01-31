#ifndef CONSULTAS_HPP
#define CONSULTAS_HPP

#include <iostream>
#include <string>
#include "Avl.hpp"
#include "Voo.hpp"
#include "fstream"
#include "sstream"


class Consultas {
private:
    Voo* voos; // Vetor de voos
    int numVoos;
    int numConsultas;

public:

    Consultas();
    ~Consultas();

    int LerArquivo(std::string arquivo);
    void ImprimirLista();

};

#endif

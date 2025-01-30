#ifndef CONSULTAS_HPP
#define CONSULTAS_HPP

#include <iostream>
#include <string>
#include "Avl.hpp"
#include "Voos.hpp"
#include "fstream"
#include "sstream"


class Consultas {
private:
    Voos* voos; // Ponteiro para a lista de voos

public:
    int LerArquivo(std::string arquivo);

};

#endif

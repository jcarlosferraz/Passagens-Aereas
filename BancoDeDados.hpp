#ifndef BANCODEDADOS_HPP
#define BANCODEDADOS_HPP

#include <iostream>
#include <string>
#include "Avl.hpp"
#include "Voo.hpp"
#include "Consulta.hpp"
#include "fstream"
#include "sstream"


class BancoDeDados {
private:    
    Voo* voos; // Vetor de voos
    int numVoos;
    int numConsultas;
    Consulta* consultas; //vetor de consultas

public:

    BancoDeDados();
    ~BancoDeDados();

    int LerArquivo(std::string arquivo);
    void ImprimirLista();
    void ImprimirConsultas();

};

#endif

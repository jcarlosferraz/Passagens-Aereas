#ifndef BANCODEDADOS_HPP
#define BANCODEDADOS_HPP

#include <iostream>
#include <string>
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
    void ImprimirConsultas(int i);
    void ExecutarConsultas();
    int* Pesquisa(std::string sigla, std::string sinal, std::string referencia);
    int* Juncao(int* resultadoConsulta, int* resultadoFiltro);
    void OrdenarResultado(int* resultadoConsulta, std::string criterio);
    
};

#endif

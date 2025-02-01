#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include <iostream>
#include <string>
#include <algorithm>


class Consulta {
private:
public:
    int numRetornos;
    std::string criterioOrdenacao;
    std::string expressaoLogica;

    Consulta();
    void ImprimirConsulta();
    int NumFiltros();
};

#endif

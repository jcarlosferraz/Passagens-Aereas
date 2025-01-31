#include "Consulta.hpp"

Consulta::Consulta(){
    numRetornos = 0;
    criterioOrdenacao = "";
    expressaoLogica = "";
}

void Consulta::ImprimirConsulta(){
    std::cout << numRetornos << " " << criterioOrdenacao << " " << expressaoLogica << std::endl;
}
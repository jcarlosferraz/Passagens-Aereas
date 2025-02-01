#include "Consulta.hpp"

Consulta::Consulta(){
    numRetornos = 0;
    criterioOrdenacao = "";
    expressaoLogica = "";
}

void Consulta::ImprimirConsulta(){
    std::cout << numRetornos << " " << criterioOrdenacao << " " << expressaoLogica << std::endl;
}

int Consulta::NumFiltros(){  //analisar expressao logica para retornar numero de filtros da consulta
    int posicao = 0;
    int numFiltros = 0;
    std::string str = expressaoLogica;

    while(1){
        auto it = std::find(str.begin(), str.end(), '&');

        if (it == str.end()) {
           break;
        } else {
            posicao = (it - str.begin());
            numFiltros++;
            str = str.substr(posicao + 2);
        }
    }
    return numFiltros + 1;
}
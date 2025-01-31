#include <iostream>
#include "Consultas.hpp"

int main(){

    Consultas* consultas = new Consultas;

    consultas->LerArquivo("input1.txt");
    consultas->ImprimirLista();

    delete(consultas);

    //std::cout << "Hello World" << std::endl;
}


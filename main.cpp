#include <iostream>
#include "BancoDeDados.hpp"

int main(int argc, char* argv[]){

    std::string arquivo = argv[1];

    BancoDeDados* banco = new BancoDeDados;

    banco->LerArquivo(arquivo);
    banco->ImprimirLista();
    banco->ImprimirConsultas();

    delete(banco);

    //std::cout << "Hello World" << std::endl;
}


#include "Consultas.hpp"

int Consultas::LerArquivo(std::string arquivo){
    std::ifstream file(arquivo);
    if(!file.is_open()){
        return -1;
    }
    std::string linha;

    int contador = 0;   //registrar em que iteração do looping nós estamos
    while(std::getline(file, linha)){
        
    }

    return 1;
}
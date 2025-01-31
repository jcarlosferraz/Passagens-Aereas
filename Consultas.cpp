#include "Consultas.hpp"


Consultas::Consultas(){
    numVoos = 0;
    voos = nullptr;
}
Consultas::~Consultas(){
    delete[] voos;
}


int Consultas::LerArquivo(std::string arquivo){
    std::ifstream file(arquivo);
    std::string linha;

    int contador = 0;   //registrar em que iteração do looping nós estamos
    while(std::getline(file, linha)){
        contador ++;

        if(contador == 1){  //estou na linha 1
            numVoos = std::stoi(linha);
            voos = new Voo[numVoos];  //criando vetor de voos
        }
        else if(contador <= (numVoos + 1)){ //lendo os voos em si
            std::istringstream stream(linha);  //cria uma stream a partir da linha lida

            stream >> voos[contador - 2].origem >> voos[contador - 2].destino >> voos[contador - 2].preco >>
            voos[contador - 2].assentos >> voos[contador - 2].dataPartida >> voos[contador - 2].dataChegada >>
            voos[contador - 2].numParadas;

            voos[contador - 2].DefinirTempoVoo(); //atualizar variavel duracaoTotal
        }
        else if(contador == numVoos + 2){  //leu numero de consultas
            numConsultas = std::stoi(linha);
        }
        else break;
    }

    return 1;
}

void Consultas::ImprimirLista(){
    for(int i = 0; i < numVoos; i++){
        voos[i].ImprimirVoo();
    }
    std::cout << numConsultas << std::endl;
}
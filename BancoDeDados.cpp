#include "BancoDeDados.hpp"


BancoDeDados::BancoDeDados(){
    numVoos = 0;
    voos = nullptr;
    consultas = nullptr;
}
BancoDeDados::~BancoDeDados(){
    delete[] voos;
    delete[] consultas;
}


int BancoDeDados::LerArquivo(std::string arquivo){
    std::ifstream file(arquivo);
    if(!file.is_open()){       //verificar se arquivo abriu
        std::cout << "Erro ao abrir o arquivo " << arquivo << std::endl;
        return -1;
    }

    
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
            consultas = new Consulta[numConsultas]; //criando vetor de consultas
        }
        else{
            std::istringstream stream(linha);  //Ler as consultas

            stream >> consultas[contador - numVoos - 3].numRetornos >>
            consultas[contador - numVoos - 3].criterioOrdenacao >> 
            consultas[contador - numVoos - 3].expressaoLogica;
        }
    }

    return 1;
}

void BancoDeDados::ImprimirLista(){
    for(int i = 0; i < numVoos; i++){
        voos[i].ImprimirVoo();
    }
    std::cout << numConsultas << std::endl;
}

void BancoDeDados::ImprimirConsultas(){
    for(int i = 0; i < numConsultas; i++){
        consultas[i].ImprimirConsulta();
    }
}
#include "Voo.hpp"

time_t ConverterData(const std::string& dataStr){ //função para converter uma data para o formato time_t
    struct tm data = {0};

    // Extrai os valores da string
    sscanf(dataStr.c_str(), "%d-%d-%dT%d:%d:%d",
           &data.tm_year, &data.tm_mon, &data.tm_mday,
           &data.tm_hour, &data.tm_min, &data.tm_sec);

    // Ajusta os valores para o formato esperado pela struct tm
    data.tm_year -= 1900; // tm_year conta a partir de 1900
    data.tm_mon -= 1;     // tm_mon varia de 0 a 11

    return mktime(&data); // Converte para time_t
}

Voo::Voo(){
    origem = "";
    destino = "";
    preco = 0.0;
    assentos = 0;
    dataPartida = "";
    dataChegada = "";
    numParadas = 0;
    duracaoTotal= 0;    
}

Voo::~Voo(){
}

void Voo::ImprimirVoo(){
    std::cout << origem << " " << destino << " " << preco << " " << assentos <<
     " " << dataPartida << " " << dataChegada << " " << numParadas << std::endl;
}

void Voo::DefinirTempoVoo(){
    duracaoTotal = ConverterData(dataChegada) - ConverterData(dataPartida);
}
#include "Voos.hpp"

Voo::Voo(){
    origem = "";
    destino = "";
    preco = 0.0;
    assentos = 0;
    dataPartida = 0;
    dataChegada = 0;
    numParadas = 0;
    duracaoTotal= 0;
}

Voos::Voos(){
    tamanho = 0;
    lista = nullptr;
}

Voos::~Voos(){
    delete[] lista;
}
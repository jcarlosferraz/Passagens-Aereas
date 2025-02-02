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

bool Numerico(const std::string& str) {
    if (str.empty()) return false;

    bool ponto = false;
    bool sinal = false;

    for (size_t i = 0; i < str.size(); ++i) {
        if (i == 0 && (str[i] == '-' || str[i] == '+')) {  
            sinal = true; // Permite um único sinal no início
        } else if (str[i] == '.') {
            if (ponto) return false; // Se já havia um ponto antes, é inválido
            ponto = true;
        } else if (!isdigit(str[i])) {
            return false; // Qualquer caractere não numérico e não permitido falha
        }
    }

    return str.size() > (sinal ? 1 : 0); // Evita que apenas "-" ou "." sejam válidos
}

void BancoDeDados::OrdenarResultado(int* resultadoConsulta, std::string criterio){
    int i, j, min_idx, temp;


    if(criterio == "pds"){

        for (i = 0; resultadoConsulta[i] != -1; i++) {
            min_idx = i;
            for (j = i + 1; resultadoConsulta[j] != -1; j++) {

                if (voos[resultadoConsulta[j]].preco == voos[resultadoConsulta[min_idx]].preco) {

                    if (voos[resultadoConsulta[j]].duracaoTotal == voos[resultadoConsulta[min_idx]].duracaoTotal) {
                        if (voos[resultadoConsulta[j]].numParadas < voos[resultadoConsulta[min_idx]].numParadas) {
                            min_idx = j;
                        }
                    }

                    else if (voos[resultadoConsulta[j]].duracaoTotal < voos[resultadoConsulta[min_idx]].duracaoTotal) {
                        min_idx = j;
                    }
                }

                if (voos[resultadoConsulta[j]].preco < voos[resultadoConsulta[min_idx]].preco) {
                    min_idx = j;
                }
            }
            // Troca os índices no vetor A
            temp = resultadoConsulta[i];
            resultadoConsulta[i] = resultadoConsulta[min_idx];
            resultadoConsulta[min_idx] = temp;
        }
    }

    else if(criterio == "psd"){                                     //Selection Sort para ordenar

        for (i = 0; resultadoConsulta[i] != -1; i++) {
            min_idx = i;
            for (j = i + 1; resultadoConsulta[j] != -1; j++) {

                if (voos[resultadoConsulta[j]].preco == voos[resultadoConsulta[min_idx]].preco) {

                    if (voos[resultadoConsulta[j]].numParadas == voos[resultadoConsulta[min_idx]].numParadas) {
                        if (voos[resultadoConsulta[j]].duracaoTotal < voos[resultadoConsulta[min_idx]].duracaoTotal) {
                            min_idx = j;
                        }
                    }

                    else if (voos[resultadoConsulta[j]].numParadas < voos[resultadoConsulta[min_idx]].numParadas) {
                        min_idx = j;
                    }
                }

                if (voos[resultadoConsulta[j]].preco < voos[resultadoConsulta[min_idx]].preco) {
                    min_idx = j;
                }
            }
            // Troca os índices no vetor A
            temp = resultadoConsulta[i];
            resultadoConsulta[i] = resultadoConsulta[min_idx];
            resultadoConsulta[min_idx] = temp;
        }
    }

    else if(criterio == "dps"){

        for (i = 0; resultadoConsulta[i] != -1; i++) {
            min_idx = i;
            for (j = i + 1; resultadoConsulta[j] != -1; j++) {

                if (voos[resultadoConsulta[j]].duracaoTotal == voos[resultadoConsulta[min_idx]].duracaoTotal) {

                    if (voos[resultadoConsulta[j]].preco == voos[resultadoConsulta[min_idx]].preco) {
                        if (voos[resultadoConsulta[j]].numParadas < voos[resultadoConsulta[min_idx]].numParadas) {
                            min_idx = j;
                        }
                    }

                    else if (voos[resultadoConsulta[j]].preco < voos[resultadoConsulta[min_idx]].preco) {
                        min_idx = j;
                    }
                }

                if (voos[resultadoConsulta[j]].duracaoTotal < voos[resultadoConsulta[min_idx]].duracaoTotal) {
                    min_idx = j;
                }
            }
            // Troca os índices no vetor A
            temp = resultadoConsulta[i];
            resultadoConsulta[i] = resultadoConsulta[min_idx];
            resultadoConsulta[min_idx] = temp;
        }
    }

    else if(criterio == "dsp"){

        for (i = 0; resultadoConsulta[i] != -1; i++) {
            min_idx = i;
            for (j = i + 1; resultadoConsulta[j] != -1; j++) {

                if (voos[resultadoConsulta[j]].duracaoTotal == voos[resultadoConsulta[min_idx]].duracaoTotal) {

                    if (voos[resultadoConsulta[j]].numParadas == voos[resultadoConsulta[min_idx]].numParadas) {
                        if (voos[resultadoConsulta[j]].preco < voos[resultadoConsulta[min_idx]].preco) {
                            min_idx = j;
                        }
                    }

                    else if (voos[resultadoConsulta[j]].numParadas < voos[resultadoConsulta[min_idx]].numParadas) {
                        min_idx = j;
                    }
                }

                if (voos[resultadoConsulta[j]].duracaoTotal < voos[resultadoConsulta[min_idx]].duracaoTotal) {
                    min_idx = j;
                }
            }
            // Troca os índices no vetor A
            temp = resultadoConsulta[i];
            resultadoConsulta[i] = resultadoConsulta[min_idx];
            resultadoConsulta[min_idx] = temp;
        }

    }

    else if(criterio == "spd"){

        for (i = 0; resultadoConsulta[i] != -1; i++) {
            min_idx = i;
            for (j = i + 1; resultadoConsulta[j] != -1; j++) {

                if (voos[resultadoConsulta[j]].numParadas == voos[resultadoConsulta[min_idx]].numParadas) {

                    if (voos[resultadoConsulta[j]].preco == voos[resultadoConsulta[min_idx]].preco) {
                        if (voos[resultadoConsulta[j]].duracaoTotal < voos[resultadoConsulta[min_idx]].duracaoTotal) {
                            min_idx = j;
                        }
                    }

                    else if (voos[resultadoConsulta[j]].preco < voos[resultadoConsulta[min_idx]].preco) {
                        min_idx = j;
                    }
                }

                if (voos[resultadoConsulta[j]].numParadas < voos[resultadoConsulta[min_idx]].numParadas) {
                    min_idx = j;
                }
            }
            // Troca os índices no vetor A
            temp = resultadoConsulta[i];
            resultadoConsulta[i] = resultadoConsulta[min_idx];
            resultadoConsulta[min_idx] = temp;
        }

    }

    else{    //criterio == sdp

        for (i = 0; resultadoConsulta[i] != -1; i++) {
            min_idx = i;
            for (j = i + 1; resultadoConsulta[j] != -1; j++) {

                if (voos[resultadoConsulta[j]].numParadas == voos[resultadoConsulta[min_idx]].numParadas) {

                    if (voos[resultadoConsulta[j]].duracaoTotal == voos[resultadoConsulta[min_idx]].duracaoTotal) {
                        if (voos[resultadoConsulta[j]].preco < voos[resultadoConsulta[min_idx]].preco) {
                            min_idx = j;
                        }
                    }

                    else if (voos[resultadoConsulta[j]].duracaoTotal < voos[resultadoConsulta[min_idx]].duracaoTotal) {
                        min_idx = j;
                    }
                }

                if (voos[resultadoConsulta[j]].numParadas < voos[resultadoConsulta[min_idx]].numParadas) {
                    min_idx = j;
                }
            }
            // Troca os índices no vetor A
            temp = resultadoConsulta[i];
            resultadoConsulta[i] = resultadoConsulta[min_idx];
            resultadoConsulta[min_idx] = temp;
        }

    }
}

int BancoDeDados::LerArquivo(std::string arquivo){
    std::ifstream file(arquivo);
    if(!file.is_open()){                                            //verificar se arquivo abriu
        std::cout << "Erro ao abrir o arquivo " << arquivo << std::endl;
        return -1;
    }

    
    std::string linha;

    int contador = 0;                                               //registrar em que iteração do looping nós estamos
    while(std::getline(file, linha)){
        contador ++;

        if(contador == 1){                                          //estou na linha 1
            numVoos = std::stoi(linha);
            voos = new Voo[numVoos];                                //criando vetor de voos
        }
        else if(contador <= (numVoos + 1)){                         //lendo os voos em si
            std::istringstream stream(linha);                       //cria uma stream a partir da linha lida

            stream >> voos[contador - 2].origem >> voos[contador - 2].destino >> voos[contador - 2].preco >>
            voos[contador - 2].assentos >> voos[contador - 2].dataPartida >> voos[contador - 2].dataChegada >>
            voos[contador - 2].numParadas;

            voos[contador - 2].DefinirTempoVoo();                   //atualizar variavel duracaoTotal
        }
        else if(contador == numVoos + 2){                           //leu numero de consultas
            numConsultas = std::stoi(linha);
            consultas = new Consulta[numConsultas];                 //criando vetor de consultas
        }
        else{
            std::istringstream stream(linha);                       //Ler as consultas

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

void BancoDeDados::ImprimirConsultas(int i){

    consultas[i].ImprimirConsulta();
    
}

int* BancoDeDados::Pesquisa(std::string sigla, std::string sinal, std::string referencia){
    int* vetor = nullptr;
    int* temp = nullptr;
    int referenciaNumero = 0;
    if(Numerico(referencia)) {                                      //verifica se referencia é numero;
        referenciaNumero = std::stoi(referencia);    
    }
    int contador = 0;                                               //atualizando numero de elementos do vetor


    if(sigla == "org"){
        for(int i = 0; i < numVoos; i++){
            if(voos[i].origem == referencia){
                contador ++;
                temp = (int*)realloc(vetor, contador * sizeof(int));
                temp[contador - 1] = i;
                vetor = temp;
            }
        }
    }

    else if(sigla == "dst"){
        for(int i = 0; i < numVoos; i++){
            if(voos[i].destino == referencia){
                contador ++;
                temp = (int*)realloc(vetor, contador * sizeof(int));
                temp[contador - 1] = i;
                vetor = temp;
            }
        }
    }

    else if(sigla == "prc"){

        if(sinal == "<="){

            for(int i = 0; i < numVoos; i++){
                if(voos[i].preco <= referenciaNumero){
            
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
        else if(sinal == ">="){

            for(int i = 0; i < numVoos; i++){
                if(voos[i].preco >= referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
        else{

            for(int i = 0; i < numVoos; i++){
                if(voos[i].preco == referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
    }

    else if(sigla == "sea"){
        if(sinal == "<="){

            for(int i = 0; i < numVoos; i++){
                if(voos[i].assentos <= referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
        else if(sinal == ">="){

            for(int i = 0; i < numVoos; i++){
                if(voos[i].assentos >= referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
        else{

            for(int i = 0; i < numVoos; i++){
                if(voos[i].assentos == referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
    }

    else if(sigla == "sto"){
        if(sinal == "<="){

            for(int i = 0; i < numVoos; i++){
                if(voos[i].numParadas <= referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
        else if(sinal == ">="){

            for(int i = 0; i < numVoos; i++){
                if(voos[i].numParadas >= referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
        else{

            for(int i = 0; i < numVoos; i++){
                if(voos[i].numParadas == referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
    }

    else{                                                           //sigla == dur
        if(sinal == "<="){

            for(int i = 0; i < numVoos; i++){
                if(voos[i].duracaoTotal <= referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
        else if(sinal == ">="){

            for(int i = 0; i < numVoos; i++){
                if(voos[i].duracaoTotal >= referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
        else{

            for(int i = 0; i < numVoos; i++){
                if(voos[i].duracaoTotal == referenciaNumero){
                    contador ++;
                    temp = (int*)realloc(vetor, contador * sizeof(int));
                    temp[contador - 1] = i;
                    vetor = temp;
                }
            }

        }
    }


    contador ++;
    temp = (int*)realloc(vetor, contador * sizeof(int));
    temp[contador - 1] = -1;
    vetor = temp;

    return vetor;
}

int* BancoDeDados::Juncao(int* resultadoConsulta, int* resultadoFiltro){

    int* vetor = nullptr;
    int* temp = nullptr;
    int contador = 0;

    for(int i = 0; resultadoConsulta[i] != -1; i++){
        bool estaNosDois = false;                                   //adiciona do novo vetor apenas elementos que estejam nos 2 vetores 

        for(int j = 0; resultadoFiltro[j] != -1; j++){
            if(resultadoFiltro[j] == resultadoConsulta[i]){
                estaNosDois = true;
                break;
            }
        }

        if(estaNosDois == true){
            contador ++;
            temp = (int*)realloc(vetor, contador * sizeof(int));
            temp[contador - 1] = resultadoConsulta[i];
            vetor = temp;
        }

    }

    contador ++;
    temp = (int*)realloc(vetor, contador * sizeof(int));
    temp[contador - 1] = -1;
    vetor = temp;

    return vetor;
}

void BancoDeDados::ExecutarConsultas(){
    for(int i = 0; i < numConsultas; i++){                          //vamos iterar sobre cada uma das consultas

        ImprimirConsultas(i);

        int carac = 0;                                              // Guarda a posição do caractere que estamos analisando
        
        int numFiltros = consultas[i].NumFiltros();                 //numero de filtros
        int numFiltrosAnalisados = 0;

        int* resultadoConsulta = nullptr;                           //vetor de indices dos voos que serão retornados na consulta 

        while(1){                                                   //analisar cada filtro
            std::string referencia = "";
            std::string sinal = "";
            std::string sigla = "";
            int* resultadoFiltro = nullptr;

            if(consultas[i].expressaoLogica[carac] == '('){         //percorrer a string até sair dos parenteses
                carac ++; 
                continue;
            }

            else if(consultas[i].expressaoLogica[carac] == 'd'){    //verificacções para saber qual sigla estamos analisando
                if(consultas[i].expressaoLogica[carac + 1] == 's'){
                    sigla = "dst";
                }
                else if(consultas[i].expressaoLogica[carac + 1] == 'e'){
                    sigla = "dep";
                }
                else {
                    sigla = "dur";
                }
            }

            else if(consultas[i].expressaoLogica[carac] == 's'){
                if(consultas[i].expressaoLogica[carac + 1] == 'e'){
                    sigla = "sea";
                }
                else {
                    sigla = "sto";
                }
            }

            else if(consultas[i].expressaoLogica[carac] == 'o'){
                sigla = "org";
            }

            else if(consultas[i].expressaoLogica[carac] == 'p'){
                sigla = "prc";
            }

            else sigla = "arr";


            if(consultas[i].expressaoLogica[carac + 3] == '<') sinal = "<=";
            else if(consultas[i].expressaoLogica[carac + 3] == '>') sinal = ">=";
            else sinal = "==";                                      //identificamos a sigla e o sinal que esta sendo analisado

            
            carac = carac + 5;                                      //avanca para o caractere onde esta o comeco da referencia
            referencia = consultas[i].expressaoLogica.substr(carac);
            auto it = std::find(referencia.begin(), referencia.end(), ')');
            referencia = consultas[i].expressaoLogica.substr(carac, (it - referencia.begin()));
                                                                    //identificamos a referencia para pesquisa
            carac = carac + (it - referencia.begin()) + 4;          //avanca caractere analisado para o proximo filtro

            resultadoFiltro = Pesquisa(sigla, sinal, referencia);
            if(numFiltrosAnalisados == 0) resultadoConsulta = resultadoFiltro;

            resultadoConsulta = Juncao(resultadoConsulta, resultadoFiltro);
            numFiltrosAnalisados++;
            free(resultadoFiltro);
            if(numFiltrosAnalisados == numFiltros) break;
        }
    
        OrdenarResultado(resultadoConsulta, consultas[i].criterioOrdenacao);

        for(int k = 0; resultadoConsulta[k] != -1; k++){
            voos[resultadoConsulta[k]].ImprimirVoo();
            if((k + 1) == consultas[i].numRetornos) break;
        }

        //delete[] resultadoConsulta;
    }
}


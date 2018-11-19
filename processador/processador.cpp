#include "processador.hpp"
Processador::Processador(int id){
    this->id = id;
}

void Processador::setMensagensEnviadas(int mensagensEnviadas){
    this->mensagensEnviadas = mensagensEnviadas;
}

void Processador::setMensagensRecebidas(int mensagensRecebidas){
    this->mensagensRecebidas = mensagensRecebidas;
}

/*void Processador::setVetorProcessadores(vector<Processador> vetorDeProcessadores){
    this->vetorDeProcessadores = vetorDeProcessadores;
}*/

void Processador::addMensagensEnviadas(){
    this->mensagensEnviadas++;
}

void Processador::addMensagensRecebidas(){
    this->mensagensRecebidas++;
}

int Processador::getMensagensEnviadas(){
    return this->mensagensEnviadas;
}

int Processador::getMensagensRecebidas(){
    return this->mensagensRecebidas;
}

/*vector<Processador> Processador::getVetorProcessadores(){
    return this->vetorDeProcessadores;
}*/
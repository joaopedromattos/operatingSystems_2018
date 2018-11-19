#include "processo.hpp"
// Construtor da classe Processo
Processo::Processo(int tempoTotal, int CPUEncarregado){

    this->tempoTotal = tempoTotal;
    this->CPUEncarregado = CPUEncarregado;
    this->tempo_restante = 0;
    this->startTime = 0;

}

// Metodos setters e getters:
// Setters
void Processo::setCPUEncarregado(int cpuId){

    this->CPUEncarregado=cpuId;

}

void Processo::setStartTime(int startTime){

    this->startTime=startTime;

}

void Processo::setTempoTotal(int tempoTotal){

    this->tempoTotal=tempoTotal;
    this->tempo_restante=tempoTotal;

}

// Getters
int Processo::getCPUEncarregado(){
    return this->CPUEncarregado;
}

int Processo::getStartTime(){
    return this->startTime;
}

int Processo::getTempoTotal(){
    return this->tempoTotal;
}

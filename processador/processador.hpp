// TRABALHO PARA A DISCIPLINA DE SISTEMAS OPERACIONAIS - SSC-0140 - ICMC - USP 
// NOME DO PROJETO: SIMULADOR DE ALGORITMO EMISSOR DESCRITO NO LIVRO MODERN OPERATING SYSTEMS TANENBAUM 
// FEITO POR:
// JOAO PEDRO RODRIGUES MATTOS - 10295732
// GIOVANNI PAOLO MELONI - 10295603
// GUSTAVO SASAKI RONCAGLIA - 10295652

#ifndef _PROCESSADOR_HPP_
#define _PROCESSADOR_HPP_

#include <vector>
#include <queue>
#include <deque>
#include "../processo/processo.hpp"

using namespace std;

class Processador{
    private:
    int id;
    int mensagensEnviadas;
    int mensagensRecebidas;

    //static vector<Processador> vetorDeProcessadores;

    public:
   
    deque<Processo> filaDeProcessos;
    
    Processador(int id);

    void setMensagensEnviadas(int mensagensEnviadas);
    void setMensagensRecebidas(int mensagensRecebidas);
    //void setVetorProcessadores(vector<Processador> vetorDeProcessadores);

    void addMensagensEnviadas();
    void addMensagensRecebidas();

    int getMensagensEnviadas();
    int getMensagensRecebidas();
    //vector<Processador> getVetorProcessadores();

    bool TacaParaOutro(int NUMEROPROCESSADORES);
};

#endif
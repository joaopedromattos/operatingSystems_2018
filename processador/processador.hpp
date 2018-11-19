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
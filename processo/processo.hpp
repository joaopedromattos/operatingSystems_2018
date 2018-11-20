// TRABALHO PARA A DISCIPLINA DE SISTEMAS OPERACIONAIS - SSC-0140 - ICMC - USP 
// NOME DO PROJETO: SIMULADOR DE ALGORITMO EMISSOR DESCRITO NO LIVRO MODERN OPERATING SYSTEMS TANENBAUM 
// FEITO POR:
// JOAO PEDRO RODRIGUES MATTOS - 10295732
// GIOVANNI PAOLO MELONI - 10295603
// GUSTAVO SASAKI RONCAGLIA - 10295652
#ifndef _PROCESSO_HPP_
#define _PROCESSO_HPP_

class Processo{
    private:
    int CPUEncarregado;
    int startTime;
    int tempoTotal;
    public:
    int tempo_restante;

    Processo(int tempoTotal, int CPUEncarregado);

    int getCPUEncarregado();
    int getStartTime();
    int getTempoTotal();

    void setCPUEncarregado(int cpuId);
    void setStartTime(int startTime);
    void setTempoTotal(int tempoTotal);

};

#endif
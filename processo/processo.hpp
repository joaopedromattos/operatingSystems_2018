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
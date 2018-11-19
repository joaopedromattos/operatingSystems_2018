#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "./processo/processo.hpp"
#include "./processador/processador.hpp"
#include <random>
#include <string>
#include <fstream>
int AJL = 5;
double VARIANCIA = 2;
int NUMEROPROCESSADORES = 8;
int NUMERODEITERACOES = 2000000;
char TIPODECARGA = 1; // 1 => carga leve, 2=> carga pesada

using namespace std;

int TacaParaOutro(int id, int NUMEROPROCESSADORES, vector<Processador> &vetorDeProcessadores);
void iniciarProcesso(int NUMEROPROCESSADORES, vector<Processador> &vetorDeProcessadores, int tempoTotal);

int tempoDeExecucao = 0;


int main(int argc, char *argv[]){
    char answer;
    // Interface de comandos pela execucao
    cout << "Deseja mudar os parametros? (int AJL = 5, VARIANCIA = 2, NUMEROPROCESSADORES = 8, NUMERODEITERACOES = 20000000, TIPODECARGA = 1; // 1 => carga leve, 2=> carga pesada" << endl;
    cout << "Y/N" << endl;
    cin >> answer;

    if (answer == 'Y' or answer == 'y'){
        cout << "Por favor, insira os parametros na ordem estipulada: AJL, VARIANCIA, NUMEROPROCESSADORES, NUMERODEITERACOES E TIPODECARGA" << endl;
        cin >> AJL >> VARIANCIA >> NUMEROPROCESSADORES >> NUMERODEITERACOES >> TIPODECARGA;
    }



    // Gerador de dados para geracao pseudo-aleatoria de numeros
    random_device rd{}; 
    // Algoritmo de geracao de numeros aleatorios alimentadao pelo hardware do computador
    mt19937 gen{rd()}; 
    // Funcao gaussiana alimentada pelo algoritmo de geracao pseudo-aleatorio para gerar os quantums dos processos.
    normal_distribution<> normalGeneratorAjl{double(AJL),VARIANCIA}; 



    
    vector<Processador> vetorDeProcessadores;
    for(int i=0;i<NUMEROPROCESSADORES;i++){
        vetorDeProcessadores.push_back( Processador(i) );        
    }

    // Arquivos que registram o time lapse de mensagens enviadas e de mensagens recebidas...
    ofstream arquivoEnviadas;
    ofstream arquivoRecebidas;
    
    arquivoEnviadas.open("sentAccordingToTime.csv");
    arquivoRecebidas.open("receivedAccordingToTime.csv");
    
    // Registramos cada processador em uma coluna do arquivo
    arquivoEnviadas << 1 << "," << 2 << "," << 3 << "," << 4 << "," << 5 << "," << 6 << "," << 7 << "," << 8 << endl;
    arquivoRecebidas << 1 << "," << 2 << "," << 3 << "," << 4 << "," << 5 << "," << 6 << "," << 7 << "," << 8 << endl;


    for (int tempoDeExecucao=0; tempoDeExecucao<=NUMERODEITERACOES; tempoDeExecucao++){
        //A cada AJL segundos, X processos (depende da carga leve ou pesada) são criados
        //e distribuidos para os N processadores de forma aleatoria
        if (tempoDeExecucao % AJL == 0){
            int chamadasFunc = NUMEROPROCESSADORES;
            if(TIPODECARGA ==1)chamadasFunc/3;//carga leve
            
            //Distribuindo os X processos
            for(int k=0;k<chamadasFunc;k++){ 
                iniciarProcesso(NUMEROPROCESSADORES,vetorDeProcessadores,(int)normalGeneratorAjl(gen));
            }
        }

        for (int CPU=0; CPU<NUMEROPROCESSADORES; CPU++){
            if (vetorDeProcessadores[CPU].filaDeProcessos.size() != 0){ //Verifica se existe um processo nesse processador
                vetorDeProcessadores[CPU].filaDeProcessos[0].tempo_restante--; //
                if (vetorDeProcessadores[CPU].filaDeProcessos[0].tempo_restante == 0){
                    vetorDeProcessadores[CPU].filaDeProcessos.pop_front();
                }
            }

            if (tempoDeExecucao % 2000 == 0){
                cout << "Mensagens Enviadas: " << vetorDeProcessadores[CPU].getMensagensEnviadas() << " Mensagens recebidas: " << vetorDeProcessadores[CPU].getMensagensEnviadas() << endl;

                // Escrevemos no arquivo os dados do timelapse.
                arquivoEnviadas << vetorDeProcessadores[0].getMensagensEnviadas() << "," <<  vetorDeProcessadores[1].getMensagensEnviadas() << "," <<  vetorDeProcessadores[2].getMensagensEnviadas() << "," <<  vetorDeProcessadores[3].getMensagensEnviadas() << "," <<  vetorDeProcessadores[4].getMensagensEnviadas() << "," <<  vetorDeProcessadores[5].getMensagensEnviadas() << "," <<  vetorDeProcessadores[6].getMensagensEnviadas() << "," <<  vetorDeProcessadores[7].getMensagensEnviadas() << endl;
                arquivoRecebidas << vetorDeProcessadores[0].getMensagensRecebidas() << "," <<  vetorDeProcessadores[1].getMensagensRecebidas() << "," <<  vetorDeProcessadores[2].getMensagensRecebidas() << "," <<  vetorDeProcessadores[3].getMensagensRecebidas() << "," <<  vetorDeProcessadores[4].getMensagensRecebidas() << "," <<  vetorDeProcessadores[5].getMensagensRecebidas() << "," <<  vetorDeProcessadores[6].getMensagensRecebidas() << "," <<  vetorDeProcessadores[7].getMensagensRecebidas() << endl;
            }
        }        
    }

    // Fechamento dos arquivos que registram o time lapse de mensagens enviadas e recebidas
    arquivoEnviadas.close();
    arquivoRecebidas.close();


    // Criacao de um arquivo especifico para os dados finais do programa
    ofstream arquivoCSV;
    arquivoCSV.open ("finalMessages.csv");


    //Sequencialmente passa por cada um dos processadores
    // Todas as mensagens
    cout << "Numero final de mensagens por processador:" << endl;
    for (int CPU=0; CPU<NUMEROPROCESSADORES; CPU++){

        cout << "CPU NUM: " << CPU + 1 <<" Mensagens Enviadas: " << vetorDeProcessadores[CPU].getMensagensEnviadas() << " Mensagens recebidas: " << vetorDeProcessadores[CPU].getMensagensRecebidas() << endl;

        // Escrita dos dados num arquivo csv.
        arquivoCSV << CPU+1 << ","<< vetorDeProcessadores[CPU].getMensagensEnviadas() << "," << vetorDeProcessadores[CPU].getMensagensRecebidas() << endl;

    }

    // Fechamento do arquivo final de dados.
    arquivoCSV.close();


    return 0;
}


//procura processador nao sobrecarregado
int TacaParaOutro(int id, int NUMEROPROCESSADORES, vector<Processador> &vetorDeProcessadores){

    for(int i=0;i<floor(vetorDeProcessadores.size()/5);i++){
        
        vetorDeProcessadores[id].addMensagensEnviadas();
        //gerando numero aleatorio diferente do atual
        int randomNumber = rand()%NUMEROPROCESSADORES;
        while(randomNumber == id){
            randomNumber = rand()%NUMEROPROCESSADORES;
        }

        vetorDeProcessadores[randomNumber].addMensagensRecebidas();

        //verificando se o processador escolhido é válido
        if(vetorDeProcessadores[randomNumber].filaDeProcessos.size() == 0){
            return randomNumber;
        }
    }

    return id;//não achou válido
}

//colocando processo em um processador
void iniciarProcesso(int NUMEROPROCESSADORES, vector<Processador> &vetorDeProcessadores, int tempoTotal){
    int numProcessador = rand()%NUMEROPROCESSADORES;

    //caso processador esteja sobrecarregado, procure colocar processo em outro
    // cout << "TACA A MAE PRA VER SE KICKA : "<< vetorDeProcessadores[numProcessador].filaDeProcessos.size() << endl;
    if(vetorDeProcessadores[numProcessador].filaDeProcessos.size() >= 1){
        numProcessador = TacaParaOutro(numProcessador,NUMEROPROCESSADORES, vetorDeProcessadores);
    }

    //colocando processo no processador certo
    vetorDeProcessadores[numProcessador].filaDeProcessos.push_back( Processo(tempoTotal, numProcessador));

}
# TRABALHO PARA A DISCIPLINA DE SISTEMAS OPERACIONAIS - SSC-0140 - ICMC - USP 
# NOME DO PROJETO: SIMULADOR DE ALGORITMO EMISSOR DESCRITO NO LIVRO MODERN OPERATING SYSTEMS TANENBAUM 
# FEITO POR:
# JOAO PEDRO RODRIGUES MATTOS - 10295732
# GIOVANNI PAOLO MELONI - 10295603
# GUSTAVO SASAKI RONCAGLIA - 10295652
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Abro todos os arquivos de estatisticas e puxo eles para a RAM...
arquivoEnviadas = open("receivedAccordingToTime.csv", "r+").readlines()
arquivoRecebidas = open("sentAccordingToTime.csv", "r+").readlines()
arquivoFinal = open("finalMessages.csv", "r+").readlines()

# A ideia de puxa-los para a RAM e a de que demoraria muito fazer as seguites operacoes em disco...

# Os tres loops abaixo realizam o parsing dos dados gravados nos arquivos
for i in range(len(arquivoEnviadas)): # For que grava numa matriz as mensagens enviadas com o tempo
    arquivoEnviadas[i] = list(map(int, arquivoEnviadas[i].split(',')))

for i in range(len(arquivoRecebidas)): # For que grava numa matriz as mensagens recebidas com o tempo
    arquivoRecebidas[i] = list(map(int, arquivoRecebidas[i].split(',')))

for i in range(len(arquivoFinal)): # For que grava numa numa matriz os dados do fim da execucao do programa
    arquivoFinal[i] = list(map(int, arquivoFinal[i].split(',')))


# Transformamos em um outro tipo de matriz
arquivoEnviadas = np.array(arquivoEnviadas)
arquivoFinal = np.array(arquivoFinal)
arquivoRecebidas = np.array(arquivoRecebidas)

# Jogamos para o buffer da biblioteca que realiza os plots...
plt.plot(arquivoEnviadas[:,0])
plt.plot(arquivoEnviadas[:,1])
plt.plot(arquivoEnviadas[:,2])
plt.plot(arquivoEnviadas[:,3])
plt.plot(arquivoEnviadas[:,4])
plt.plot(arquivoEnviadas[:,5])
plt.plot(arquivoEnviadas[:,6])
plt.plot(arquivoEnviadas[:,7])

# Modificamos os labels dos eixos
plt.xlabel("Tempo - Em unidades fictícias")
plt.ylabel("Número de mensagens enviadas")

# Plotamos o grafico 
plt.show()

# O mesmo processo e aplicado a esta parte do codigo
plt.plot(arquivoRecebidas[:,0])
plt.plot(arquivoRecebidas[:,1])
plt.plot(arquivoRecebidas[:,2])
plt.plot(arquivoRecebidas[:,3])
plt.plot(arquivoRecebidas[:,4])
plt.plot(arquivoRecebidas[:,5])
plt.plot(arquivoRecebidas[:,6])
plt.plot(arquivoRecebidas[:,7])

plt.xlabel("Tempo - Em unidades fictícias")
plt.ylabel("Número de mensagens recebidas")


plt.show()

# Para o grafico em barras, separamos a matriz de dados finais dos seus dados propriamente ditos
aux = np.matrix(arquivoFinal[:, 1:])

# Transformamos a matriz separada em uma matriz dimensoes (1, numProcessadores * 2)...
aux = aux.flatten()
# ... e a convertemos em array novamente.
aux = np.array(aux)

# Definimos os nomes das barras.
names = ("Enviadas", "Recebidas")
names = names*arquivoFinal.shape[0]
listaNomesBarras = []

# Declaramos variaveis auxiliares
a=0
b=0

# Realizamos a modificacao dos nomes das barras de acordo com o numero de processadores
for i in range(0,arquivoFinal.shape[0]*2, 2):
    a = a + ((1+i)%2)
    listaNomesBarras.append(names[i] + ' ' + str(a))
    listaNomesBarras.append(names[i + 1] + ' ' + str(a))

# Declaramos uma nova lista baseada no array recem convertido para evitar conflitos de dados
newList = aux[0]

# Criamos uma sequencia de numeros para servir de referecia as funcoes de posicionamento de barras da biblioteca matplotlib
size = np.arange(arquivoFinal.shape[0]*2)

# Definimos as barras no buffer da biblioteca e usamos 'current' para instanciar um objeto de referencia a elas na RAM.
current = plt.bar(size,  newList)

# Com 'current' conseguimos modificar as cores das barras...
for i in current:
    # Montamos um esquema de alternancia de cores para as barras.
    if (b%2 == 0):
        i.set_facecolor('r')
    else:
        i.set_facecolor('b')
    b = b + 1
    
# Colocamos os nomes das barras no buffer da library...
plt.xticks(size, tuple(listaNomesBarras))

# ... junto dos labels dos eixos.
plt.xlabel("Processadores")
plt.ylabel("Numero de mensagens no fim da execução")

# Realizamos o ultimo plot
plt.show()



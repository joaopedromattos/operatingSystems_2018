# TRABALHO PARA A DISCIPLINA DE SISTEMAS OPERACIONAIS - SSC-0140 - ICMC - USP 
# NOME DO PROJETO: SIMULADOR DE ALGORITMO EMISSOR DESCRITO NO LIVRO MODERN OPERATING SYSTEMS TANENBAUM 
# FEITO POR:
# JOAO PEDRO RODRIGUES MATTOS - 10295732
# GIOVANNI PAOLO MELONI - 10295603
# GUSTAVO SASAKI RONCAGLIA - 10295652

all:
	g++ $(wildcard ./processador/*.cpp ./processador/*.hpp ./processo/*.cpp ./processo/*.hpp ./*.cpp ./*.hpp) -o main
run:
	g++ $(wildcard ./processador/*.cpp ./processador/*.hpp ./processo/*.cpp ./processo/*.hpp ./*.cpp ./*.hpp) -o main && ./main && python3 statModule.py
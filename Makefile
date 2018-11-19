# Quero um feedback sobre esse makefile aqui --- Nunca na vida vai funcionar... 
all:
	g++ $(wildcard ./processador/*.cpp ./processador/*.hpp ./processo/*.cpp ./processo/*.hpp ./*.cpp ./*.hpp) -o main
run:
	g++ $(wildcard ./processador/*.cpp ./processador/*.hpp ./processo/*.cpp ./processo/*.hpp ./*.cpp ./*.hpp) -o main && ./main
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import csv 

matrixValues = np.zeros((8010, 8))
with open('receivedAccordingToTime.csv') as csvfile:
    x = [i for i in range(1, 8011)]
    plt.style.context('Solarize_Light2')
    
    reader = csv.reader(csvfile)
    for row in reader:
        for i in range(len(row)):
            matrixValues[i] = row;

    plt.plot(x,matrixValues[:,0])
    plt.plot(x,matrixValues[:,1])
    plt.plot(x,matrixValues[:,2])
    plt.plot(x,matrixValues[:,3])
    plt.plot(x,matrixValues[:,4])
    plt.plot(x,matrixValues[:,5])
    plt.plot(x,matrixValues[:,6])
    plt.plot(x,matrixValues[:,7])

    plt.title('Tempo X Mensagens Recebidas - Por processador')

    plt.xlabel('Tempo')
    plt.ylabel('Mensagens Recebidas')


    plt.show()



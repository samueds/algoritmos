import math
import random
import sys




class Ponto:
    
    cords = []
    
    def __init__(self, cords, cluster = None):
        self.cords = [x for x in cords]
        self.grupo = cluster


class Grupo:


    def __init__(self, centroide, grupo, aux):
        self.centroide = centroide
        self.grupo = grupo
        self.pontos = [aux]

def exp(x):
    return x*x

def dist(a, b):

    dist = 0

    for i in range(len(a.cords)):

        dist += exp(a.cords[i] - b.cords[i])

    return math.sqrt(dist)



#lista de pontos do modelo, K do KMeans
def Kmeans(pontos, k, iterMax):
    
    grupos = []
    infinito = sys.maxsize
    n = len(pontos)

    aux = [i for i in range(n)]
    random.shuffle(aux)

    aux = aux[:k]

    #definindo K centroides aleatorios
    
    grupos = [Grupo(pontos[aux[i]], i, aux[i]) for i in range(k)]
    

    while iterMax:
        
        for i in range(n):

            menorValor = infinito
            centroideMaisProximo = 0

            for j in range(k):

                distancia = dist(pontos[i], grupos[j].centroide)
                if(menorValor > distancia):
                    menorValor = distancia
                    centroideMaisProximo = j

            if (i  not in grupos[centroideMaisProximo].pontos):

                grupos[centroideMaisProximo].pontos.append(i)
                pontos[i].grupo = centroideMaisProximo
                if(pontos[i].grupo != centroideMaisProximo):
                    grupos[centroideMaisProximo].pontos.remove(i)

        #calcular novos centroides
        
                
        iterMax -= 1

    print("Grupos e seus pontos:")
    

    for i in range (k):
        print('Cluster %d' %(i + 1))
        for j in grupos[i].pontos:
            print ("Ponto %d: " %j)
            for l in range(len(pontos[0].cords)):
                print(str(pontos[j].cords[l]) + " ", end = '')
            print("")

    

#main

arq = open('iris.txt', 'r')

disney = arq.readlines()

pontos = []



for linha in disney:
    x =linha.split(",")
  
    if(len(x) != 5): break
    cords = [float(x[0]) , float(x[1]), float(x[2]), float(x[3])]
    ponto = Ponto(cords)
    pontos.append(ponto)
    

print("Digite o K para o algoritmo de KNN:")

k = int(input())

print("Digite o numero maximo de iteracoes")

iterMax = int(input())    
    
Kmeans(pontos, k, iterMax)

import math
import random

class Point:
    
    x = None
    y = None
    z = None
    v = None
    
    def __init__(self, x, y, z, v):
        self.x = x
        self.y = y
        self.z = z
        self.v = v

#lista de pontos do modelo, K do KMeans
def Kmeans(pontos, k, iterMax):
    
    centroides = []
    
    #definindo K centroides aleatorios
    
    aux = [i for i in range(k)]
    print aux
    print random.shuffle(aux)
    print aux
    

#main

arq = open('iris.txt', 'r')

disney = arq.readlines()

pontos = []

for linha in disney:
    x =linha.split(",")
  
    if(len(x) != 5): break
    ponto = Point(float(x[0]) , float(x[1]), float(x[2]), float(x[3]))
    pontos.append(ponto)

print("Digite o K para o algoritmo de KNN:")

k = int(input())

print("Digite o numero maximo de iteracoes")

iterMax = int(input())    
    
Kmeans(pontos, k, iterMax)



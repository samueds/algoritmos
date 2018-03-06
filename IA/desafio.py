import math
import random
import sys
import knn
class Ponto:   
    cords = []
    def __init__(self, cords):
        self.cords = [x for x in cords]
        self.grupo = None
        
class Grupo:
    def __init__(self, centroide, grupo):
        self.centroide = centroide
        self.grupo = grupo
        self.pontos = []

def mean(numbers):
    return float(sum(numbers)) / max(len(numbers), 1)

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
  
    grupos = [Grupo(pontos[aux[i]], i) for i in range(k)]
   
    while iterMax:
        
        for i in range(n):

            menorValor = infinito
            centroideMaisProximo = 0

            for j in range(k):

                distancia = dist(pontos[i], grupos[j].centroide)
                if(menorValor > distancia):
                    menorValor = distancia
                    centroideMaisProximo = j

            if (i not in grupos[centroideMaisProximo].pontos):

                grupos[centroideMaisProximo].pontos.append(i)
                
                if(pontos[i].grupo != centroideMaisProximo and pontos[i].grupo != None):
                    grupos[pontos[i].grupo].pontos.remove(i)
                pontos[i].grupo = centroideMaisProximo

        #calcular novos centroides
        
        for i in range(k):
           
            cordenadas = [0 for v in range(len(pontos[0].cords))]
            
            for j in grupos[i].pontos:

                cordenadas = [x + y for x, y in zip(cordenadas, pontos[j].cords)]

            cordenadas = [x/len(grupos[i].pontos) for x in cordenadas]

            grupos[i].centroide = Ponto(cordenadas)
                    
        iterMax -= 1
    
    '''
    print("Grupos e seus pontos:")

    for i in range (k):
        print('Cluster %d' %(i + 1))
        for j in grupos[i].pontos:
            print ("Ponto %d: " %j)
            for l in range(len(pontos[0].cords)):
                print(str(pontos[j].cords[l]) + " ", end = '')
            print("")
    '''
    
    return pontos

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

random.shuffle(pontos)

treino = pontos[:100]
teste = pontos[100:]

print("Digite o K para o K-means:")

k = int(input())

print("Digite o numero maximo de iteracoes")

iterMax = int(input())  
    
modelo = Kmeans(treino, k, iterMax)

print("Digite o K para o Knn:")
k = int(input())

print("Classificao para os testes:")
for i in teste:
    print("Sua planta tem a seguinte classificacao: " + str(knn.Knn(modelo, k , i)))




'''
print("Digite as propriedades da planta a ser verificada:")
a = float(input())
b = float(input())
c = float(input())
d = float(input())

cords = [a,b,c,d]

novo = knn.Point(cords)

print("Sua planta tem a seguinte classificacao: " + str(knn.Knn(modelo, k , novo)))

'''
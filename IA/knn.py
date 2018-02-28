import math

class Point:
    
    x = None
    y = None
    z = None
    v = None
    cl = None
    def __init__(self, x, y, z, v ,cl):
        self.x = x
        self.y = y
        self.z = z
        self.v = v
        self.cl = cl
    
def exp(n):
    return n*n
    
def dist(a, b):
    return math.sqrt(exp(a.x - b.x) + exp(a.y - b.y) + exp(a.z - b.z) + exp(a.v - b.v))


#lista de pontos do modelo, K do Knn, e qual o ponto a ser classificado
def Knn(pontos, k, dado):
    

    if(k > len(pontos)):
        print("K maior que valor total de pontos! Impossivel de executar o método")
        

    dists = []
    
    for ponto in pontos:
        x = dist(ponto, dado)
        dists.append((x, ponto))
    
    dists.sort(key = lambda x : x[0])

    

    resp = {'Iris-setosa':0, 'Iris-versicolor':0, 'Iris-virginica':0}
    
    for i in range(k):
        x = dists[i][1].cl.replace(dists[i][1].cl[len(dists[i][1].cl) - 1], "")
        resp[x] += 1
    

    maior = 0
    ans = ""
    
    for x in resp:
        if(resp[x] > maior):
            maior = resp[x]
            ans = x
    
    return ans


#main

arq = open('iris.txt', 'r')

disney = arq.readlines()

pontos = []

for linha in disney:
    x =linha.split(",")
   
    if(len(x) != 5): break
    ponto = Point(float(x[0]) , float(x[1]), float(x[2]), float(x[3]),  x[4])
    pontos.append(ponto)

print("Digite as propriedades da planta a ser verificada:")

a = float(input())
b = float(input())
c = float(input())
d = float(input())

novo = Point(a,b,c, d, "")

print("Digite o K para o algoritmo de KNN:")

k = int(input())

print("Sua planta tem a seguinte classificação: " + Knn(pontos, k, novo))

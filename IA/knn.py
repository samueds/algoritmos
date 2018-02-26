class Point:
    
    x = None
    y = None
    z = None 
    cl = None
    def __init__(self, x, y, z, cl):
        self.x = x
        self.y = y
        self.z = z
        self.cl = cl
    
def exp(n):
    return n*n
    
def dist(a, b):
    return math.sqrt(exp(a.x - b.x) + exp(a.y - b.y) + exp(a.z - b.z))


#lista de pontos do modelo, K do Knn, e qual o ponto a ser classificado
def Knn(pontos, k, dado):
    
    dists = []
    
    for ponto in pontos:
        x = dist(ponto, dado)
        dists.append((x, ponto))
    
    dists.sort()
    
    resp = {}
    
    for i in range(k):
        resp[dists[i][1].cl] += 1
    
    maior = 0
    ans = ""
    
    for x in resp:
        if(resp[x] > maior):
            maior = resp[x]
            ans = x
    
    return x


    
    
    
    



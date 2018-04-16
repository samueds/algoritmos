import numpy as np

class Ponto:

	cords = []

	def __init__(self, cords):
		self.cords = cords
def g(n):
	if(n > 0):
		return 1
	else:
		return -1
class Perceptron:

	x = []
	w = []
	def __init__(self, x):
		self.x = x
		self.w = np.random.rand(len(x[0].cords))
	
	
	def treina(self,):
		epocas = 0
		taxaAprendizagem = 0.01
		limiar = -1
		erro = True
		while(erro and epocas < 10000):
			erro = False
			epocas += 1
			ultimo = len(self.x[0].cords)

			for i in range(len(self.x)):
				somatorio = limiar * self.w[0]
				for j in range(ultimo-1):
					#print(self.x[i].cords[j])
					#print(self.w[j+1])
					somatorio += (self.x[i].cords[j]*self.w[j+1])
				#print(somatorio)
				
				n = g(somatorio)
				if(n != self.x[i].cords[ultimo-1]):
					self.w[0] = self.w[0] + taxaAprendizagem*(self.x[i].cords[ultimo-1] - n)*-1
					for k in range(ultimo-1):
						self.w[k+1] = self.w[k+1] + taxaAprendizagem*(self.x[i].cords[ultimo-1] - n)*self.x[i].cords[k]
					erro = True
		print("O treino demorou %d epocas" %(epocas))
	def classifica(self, ponto):
		ans = -1*self.w[0]
		for i in range(len(ponto.cords)):
			ans += (ponto.cords[i] * self.w[i+1])

		n = g(ans)
		if(n == 1):
			return "Iris-virginica"
		else:
			return "Iris-versicolor"
#main

arq = open('iris.txt', 'r')

disney = arq.readlines()

pontos = []
contSetosa = 0
contVersi = 0

setosasTeste = []
versiTeste   = []

for linha in disney:

    x =linha.split(",")

    if(len(x) != 5): break
    
    cords = [float(x[0]) , float(x[1]), float(x[2]), float(x[3])]
    if(x[4] == 'Iris-virginica\n' and contSetosa < 45):
    	cords.append(1);contSetosa += 1;ponto = Ponto(cords);pontos.append(ponto)
    elif(x[4] == 'Iris-virginica\n'):
    	setosasTeste.append(Ponto(cords))
    elif (x[4] == 'Iris-versicolor\n' and contVersi < 45):
    	cords.append(-1);contVersi += 1;ponto = Ponto(cords);pontos.append(ponto)
    elif(x[4] == 'Iris-versicolor\n'):
    	versiTeste.append(Ponto(cords))
    else:
    	continue;
p = Perceptron(pontos)
p.treina()

print("Executando nos testes")

erros = 0
for i in setosasTeste:
	
	if(p.classifica(i) == 'Iris-virginica'):
		print("OK!\n")
	else:
		print("ERRO!\n")
		erros += 1

for i in versiTeste:
	
	if(p.classifica(i) == 'Iris-versicolor'):
		print("OK!\n")
	else:
		print("ERRO!\n")
		erros += 1

print("Taxa de acerto: %.5lf" % (((10-erros)*100)/10))

	

	

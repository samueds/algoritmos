import numpy as np

class Ponto:

	cords = []

	def __init__(self, cords):
		self.cords = cords



class Perceptron:


	x = []
	w = []


	def __init__(self, x):
		self.x = x
		self.w = np.random.rand(len(x[0]))

	def treina(self,):

		taxaAprendizagem = 0.01
		limiar = -1
		erro = True
		while(erro):
			erro = False

			ultimo = len(self.x[0])

			for i in range(len(self.x)):
				somatorio = limiar * w[0]
				for j in range(ultimo-1):
					somatorio += (x[i][j]*w[j+1])
				n = funcao(somatorio)
				if(n != x[i][ultimo]):
					for k in range(ultimo-1):
						w[k] = w[k] + taxaAprendizagem*(x[i][ultimo-1] - n)*x[i][k]
					erro = True

	def funcao(self,n):	
		if(n > 0):	return 1
		else :
			return -1		


#main


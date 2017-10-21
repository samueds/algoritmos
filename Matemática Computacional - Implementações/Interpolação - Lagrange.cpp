#include <bits/stdc++.h>

using namespace std;

void lagrange()
{
	printf("Algoritmo de Lagrange!\n");
	int m;

	printf("Digite o numero de pontos: ");
	scanf("%d",&m);

	double x[m];
	double y[m];
	double z;

	printf("Digite aqui os valores das abscissas:\n");
	for(int i = 0 ; i < m ; i++) scanf("%lf",&x[i]);

	printf("Digite aqui os valores das ordenadas:\n");
	for(int i = 0 ; i < m ; i++) scanf("%lf",&y[i]);

	printf("Digite o valor a ser interpolado: ");
	scanf("%lf",&z);

	double r = 0;

	for(int i = 0 ; i < m ;i++)
	{
		double p = y[i];

		for(int j = 0 ; j < m ;j++)
		{
			if(i != j)
				 p*= ((z - x[j])/(x[i] - x[j]));
		}
		cout << p << endl;
		r += p;
	}

	printf("Ponto e valor interpolado: %.5lf %.5lf\n",z,r);

	printf("Fim do metodo!\n\n");
}

int main()
{
	system("cls");
	lagrange();
}
#include <bits/stdc++.h>

using namespace std;

int m; // numero de intervalos
double a,b;

double f(double x)
{
	return(x + sin(x))/(1 + cos(x));
}

void trapezio()
{
	double h = (b - a)/m;

	double l1 = 0;
	double c;
	for(int j = 0 ; j <= m ; j++)
	{
		if (j == 0 || j == m)
			c = 1;
		else
			c = 2;

		double x = a + j * h;
		double y = f(x);

		l1 += (c * y);
	}

	printf("Valor final : %.5lf\n", (h/2)*l1);
}

void simp1terco()
{
	double h = (b - a)/m;

	double l1 = 0;
	double c;
	for(int j = 0 ; j <= m ; j++)
	{
		if (j == 0 || j == m)
			c = 1;
		else if(j & 1)
			c = 4;
		else
			c = 2;

		double x = a + j * h;
		double y = f(x);

		l1 += (c * y);
	}

	printf("Valor final : %.5lf\n", (h/3)*l1);
}

void simp3oitavos()
{
	double h = (b - a)/m;

	double l1 = 0;
	double c;
	for(int j = 0 ; j <= m ; j++)
	{
		if (j == 0 || j == m)
			c = 1;
		else if(!(j % 3))
			c = 2;
		else
			c = 3;

		double x = a + j * h;
		double y = f(x);
		
		l1 += (c * y);
	}

	printf("Valor final : %.5lf\n", ((h*3)/8)*l1);
}

int main()
{
	system("cls");
	printf("Integracao Numerica !\n");
	printf("Digite o numero de intervalos: ");

	scanf("%d",&m);

	printf("Digite o limite inferior e superior respectivamente: ");
	scanf("%lf %lf", &a, &b);

	printf("Deseja utilizar o metodo do trapezio para resolucao ?\n");
	printf("Digite S para Sim, e N para Nao: ");

	char op;

	scanf(" %c", &op);

	if(op == 'S')
	{
		printf("Iniciando o metodo do trapezio!\n");
		trapezio();
		
	}
	else
	{
		if(!(m & 1) && !(m % 3))
		{
			printf("Como o numero de intervalos eh par e multiplo de 3, podemos utilizar ambos os metodos, escolha 1:\n");
			printf("1 - Um terco de Simpson\n");
			printf("2 - Tres oitavos de Simpson\n");
			printf("Digite a opcao desejada: ");
			int op;
			scanf("%d",&op);

			if(op == 1)
				simp1terco();
			else
				simp3oitavos();
		}
		else if(!(m & 1))
		{
			printf("Numero de intervalos par, portanto, iniciando metodo de Um terco de Simpson!\n");
			simp1terco();
		}
		else if(!(m % 3))
		{
			printf("Numero de intervalos multiplo de 3, portanto, iniciando metodo de tres oitavos de Simpson!\n");
			simp3oitavos();
		}
		else
		{
			printf("Como o numero de intervalos nao se encaixa nas restricoes dos metodos de Simpson, iniciando metodo do trapezio!\n");
			trapezio();
		}
			


	}

}
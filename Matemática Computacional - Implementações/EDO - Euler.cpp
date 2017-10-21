#include <bits/stdc++.h>

using namespace std;

double f(double x) // se houver 2 variaveis, adicione o y aos parametros
{
	return cos(x);
}

void runge(double a, double b, int m, double y0)
{
	double VetX[m+1];
	double VetY[m+1];

	double h = (b - a)/m;
	double x = a;
	double y = y0;

	VetX[0] = x;
	VetY[0] = y;

	double fxy = f(x); // se houver 2 variaveis, adicione o y aos parametros
	for(int i = 1 ; i <= m ;i++)
	{
		x = a + i*h;
		y = y + h*fxy;

		fxy = f(x); // se houver 2 variaveis, adicione o y aos parametros

		printf("X = %.5lf | Y = %.5lf\n",x,y);

		VetX[i] = x;
		VetY[i] = y;
	}

	//retorne VetX e VetY
}

int main()
{
	double a,b,y0;
	int m;
	system("cls");
	printf("Algoritmo de Euler!\n");

	printf("Digite o limite inferior, superior, numero de intervalos e valor inicial, respectivamente:\n");
	scanf("%lf%lf%d%lf",&a,&b,&m,&y0);


	runge(a,b,m,y0);
}
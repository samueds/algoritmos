#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
	
	return (x*x*x) - 9*x + 3;
	
}
double deriv(double x)
{
	return 3*(x*x) - 9;
}

void NewtonRaphson()
{
	int iterMax;
	double toler;

	double x0;
	printf("Digite o valor incial: ");
	cin >> x0;

	printf("Digite o limite de iteracoes: ");
	cin >> iterMax;

	printf("Digite a tolerancia de erro: ");
	cin >> toler;

	double fx = f(x0);
	double dfx = deriv(x0);

	int iter = 0;
	double x = x0;

	double deltaX;
	printf("Iter = %d | x = %.4lf | fx = %.4lf | dfx = %.4lf | deltaX = %.4lf\n",iter, x, fx,dfx, deltaX);
	while(1)
	{
		deltaX = -fx/dfx;
		x = x + deltaX;
		fx = f(x); dfx = deriv(x);
		iter++;
		
		printf("Iter = %d | x = %.4lf | fx = %.4lf | dfx = %.4lf | deltaX = %.4lf\n",iter, x, fx,dfx, deltaX);

		if((fabs(deltaX) < toler && fabs(fx) < toler) || iter >= iterMax)
				break;
	}
	printf("X = %.4lf\n",x);
}


int main()
{
	
	system("cls");


	NewtonRaphson();
}
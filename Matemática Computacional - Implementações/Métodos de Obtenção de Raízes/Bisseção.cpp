#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
	return (x*x*x) -(3*x*x) -6*x + 8;

}

void Bissecao()
{
	int iterMax;
	double toler;

	double a,b;
	printf("Digite o intervalo: ");
	cin >> a >> b;

	printf("Digite o limite de iteracoes: ");
	cin >> iterMax;

	printf("Digite a tolerancia de erro: ");
	cin >> toler;

	double fa = f(a);
	double fb = f(b);

	if(fa * fb > 0)
	{
		printf("A funcao nao muda de sinal nos extremos do intervalo dado!\n");
		return;
	}

	double deltaX = fabs(b - a)/2;
	int iter = 0;
	double x,fx;
	for(;;)
	{
		iter++;
		x = (a + b)/2;
		fx = f(x);
		fb = f(b);
		printf("Iter = %d | x = %.4lf | a = %.4lf | b = %.4lf | fx = %.4lf | fa = %.4lf | fb = %.4lf |deltaX = %.4lf\n\n", iter, x,a,b,fx,fa,fb,deltaX);

		if((deltaX < toler && fabs(fx) < toler ) || iter >= iterMax)
		{
			printf("Fim do metodo!\n");
			break;
		}
		if(fa * fx > 0)
		{
			a = x;
			fa = fx;
		}
		else
		{
			b = x;
		}
			
		deltaX = deltaX/2;
	}	
}


int main()
{
	
	system("cls");
	Bissecao();
}
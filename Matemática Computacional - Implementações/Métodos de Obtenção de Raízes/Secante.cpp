#include <bits/stdc++.h>

using namespace std;

const double e =  2.718281828;

double f(double x)
{
	
	return sqrt(x) - 5*pow(e,-x);

}

void Secante()
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

	if(fabs(fa) < fabs(fb))
	{
		double t = a;
		a = b;
		b = t;
		t = fa;
		fa = fb;
		fb = t;
	}
	int iter = 0;
	double x = b;
	double fx = fb;
	double deltaX;
	while(1)
	{
		
		deltaX = -((fx/(fb - fa)) * (b-a));
		printf("Iter = %d | a = %.4lf | b = %.4lf | x = %.4lf | fa = %.4lf | fb = %.4lf | fx = %.4lf |deltaX = %.4lf\n\n", iter, a,b,x,fa,fb,fx,deltaX);
		x = x + deltaX;
		fx = f(x);
		
		
		a = b;
		fa = fb;
		b = x;
		fb = fx;
		iter++;
		if((fabs(deltaX) < toler && fabs(fx) < toler) || iter >= iterMax)
		{
			break;
		}
		
	}
	printf("Iter = %d | a = %.4lf | b = %.4lf | x = %.4lf | fa = %.4lf | fb = %.4lf | fx = %.4lf |deltaX = %.4lf\n\n", iter, a,b,x,fa,fb,fx,deltaX);
		
}


int main()
{
	
	system("cls");


	Secante();
}
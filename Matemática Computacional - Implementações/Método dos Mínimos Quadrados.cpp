#include <bits/stdc++.h>

using namespace std;

struct point
{
	double x,y;
};

int n;

int main()
{
	system("cls");
	printf("- Metodo dos Minimos Quadrados-\n\n");

	printf("Digite quantos pontos temos no plano: ");

	scanf("%d",&n);

	point pontos[n];

	printf("Digite aqui os pontos:\n");

	for(int i = 0 ; i < n ; i++) scanf("%lf%lf",&pontos[i].x,&pontos[i].y);


	double sum1 = n;
	double sum2 = 0;
	double sum3 = 0;
	double sum4 = 0;
	double sum5 = 0;
	

	///Adquirindo os somatórios

	for(int i = 0 ; i < n ; i++) sum2 += pontos[i].x;
	for(int i = 0 ; i < n ; i++) sum3 += (pontos[i].x * pontos[i].x);
	for(int i = 0 ; i < n ; i++) sum4 += pontos[i].y;
	for(int i = 0 ; i < n ; i++) sum5 += (pontos[i].x * pontos[i].y);

    
    double a,b,c,d,e,f;

	
	a = sum1;
	b = sum2;
	c = sum2;
	d = sum3;
	e = sum4;
	f = sum5;
	///Resolvendo o sistema linear

	b*= c;
	e*= c;
	d*= a;
	f*= a;

	if((a < 0 && c < 0) || (a > 0 && c > 0))
	{
		b*=-1;
		e*=-1;
	}
	
	double ansB = (e + f)/(b + d);

	double ansA = (sum4-(sum2 * ansB))/sum1;

	printf("Equacao da reta que passa proxima a todos os pontos dados:\n");
	printf("Y = %.4lf + (%.4lf)X\n",ansA,ansB);

}
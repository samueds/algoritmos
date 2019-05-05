#include <bits/stdc++.h>

using namespace std;

int t;
double q,lq,lr,lp;

int main()
{
	scanf("%d",&t);

	while(t--)
	{
		scanf("%lf%lf%lf%lf",&q,&lq,&lr,&lp);
		double x = (q*(lq + lr))/lp;
		int p = ceil(x);
		if( p == 1) printf("O livro contera %d pagina.\n",p);
		else printf("O livro contera %d paginas.\n",p);
	}

	return 0;
}
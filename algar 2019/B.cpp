#include <bits/stdc++.h>

using namespace std;

int t;
int q,lq,lr,lp;

int main()
{
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d%d%d",&q,&lq,&lr,&lp);
		int p = (int)ceil((q*(lq + lr))/(double)lp);
		printf("O livro contera %d pagina", p);
		if(p > 1) printf("s");
		printf("\n");
	}

	return 0;
}
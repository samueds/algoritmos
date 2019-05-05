#include <bits/stdc++.h>

using namespace std;

int t;
int x,y,k;

int main()
{
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d%d",&x,&y,&k);
		if(k >= (x+y))
		{
			printf("1/1\n");
			continue;
		}
		x++;y++,k++;
		long long possiveis = (x)*(y);
		long long deuk;
		int menor = min(x,y);
		int maior = max(x,y);
		
		else if(k <= menor)
		{
			
			k = min(k, min(x,y));
			deuk = (k*(1 + k))/2;
			
		}
		
		cout << deuk << " " << possiveis << endl;

		long long gcd = __gcd(possiveis, deuk);

		printf("%lld/%lld\n", deuk/gcd, possiveis/gcd);
	}

	return 0;
}

327699 / 1757204
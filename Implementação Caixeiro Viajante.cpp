#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;


int n,m;
int grafo[16][16];
int memo[16][1<<16];
int ini;
int pd(int pos, int mask)
{

	if(__builtin_popcount(mask) == n)
	{
		return grafo[pos][ini];
	}

	if(memo[pos][mask] != -1) return memo[pos][mask];

	int ans = oo;
	for(int i = 0 ; i < n ;i++)
	{
		if(pos != i && grafo[pos][i] != oo)
		{
			if(!((mask >> i) & 1))
			{
				
				ans = min(ans, pd(i, mask | (1 << i)) + grafo[pos][i]);

			}
		}
	}

	return memo[pos][mask] = ans;
}

vector<int>res;

void rec(int pos, int mask)
{
	int ans = oo;
	int melhorVet;
	if(__builtin_popcount(mask) == n)
		return;
	for(int i = 0 ; i < n ; i++)
	{
		if(pos != i && !((mask >> i) & 1))
		{
			if(ans > pd(i, mask | (1 << i)))
			{
				ans = pd(i, mask | (1 << i));
				melhorVet = i;
			}
		}
	}
	res.push_back(melhorVet+1);
	rec(melhorVet, mask | (1 << melhorVet));
}

int main()
{
	cin >> n >> m;

	memset(grafo, oo, sizeof grafo);
	memset(memo, -1, sizeof memo);
	for(int i = 0 ; i < m ; i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		grafo[--a][--b] = c;
		grafo[b][a] = c;
	}


	for(int i = 0 ; i < n ; i++)
	{
		printf("Valor da viagem do caixeiro iniciando o vertice %d: ", i+1);
		ini = i;
		int ans = pd(i,1 << i);
		if(ans >= oo)
			printf("Nao existe caminho!\n");
		else
			printf("%d\n",ans);
		res.clear();
		rec(i, 1 << i);
		printf("Caminho: ");
		cout << i+1 << " -> ";
		for(int i = 0 ; i < res.size() ; i++)
		{
			if(i)
				cout << " -> ";
			cout << res[i];
		}
		cout << endl << endl;
			
	}
	


}
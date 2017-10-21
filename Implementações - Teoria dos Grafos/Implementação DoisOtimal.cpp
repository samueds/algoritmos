#include <bits/stdc++.h>
#define oo 0x3f3f3f3f

using namespace std;

int n,m; // numero maximo de vertices = 15.

//Complexidade O(n * 2 ^ n)

int grafo[16][16];
int dp[16][1<<16];

int ini;
int pd(int pos, int mask)
{
	if(__builtin_popcount(mask) == n)
		return grafo[pos][ini];

	if(dp[pos][mask] != -1) return dp[pos][mask];

	int ans = oo;

	for(int i = 0 ; i < n ;i++)
	{
		if(pos != i && grafo[pos][i] != oo && !((mask >> i) & 1))
			ans = min(ans, pd(i, mask | (1 << i) + grafo[pos][i]));
	}

	return dp[pos][mask] = ans;

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

	scanf("%d%d",&n,&m);
	memset(dp, -1, sizeof dp); memset(grafo, oo, sizeof grafo);
	for(int i = 0 ; i < m ; i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		grafo[--a][--b] = c;
		grafo[b][a] = c;
	}

	//Busca por um ciclo hamiltoniano partindo de um vertice inicial 'i'
	for(int i = 0; i < n ;i++)
	{
		ini = i;
		int ans = pd(i, 1 << i);
		

		if(ans < oo)
		{

			res.clear();res.push_back(i+1);
			rec(i, 1 << i);
			break;
		}
	}
	if(res.size() < n)
	{
		printf("Nao ha ciclos hamiltonianos nesse grafo!\n");
		return 0;
	}

	res.push_back(res[0]);

	int pesoC = 0;
	printf("Ciclo hamiltoniano encontrado: \n");
	for(int i = 0 ; i <= n ; i++)
	{
		if(i)
			cout << " -> ";
		cout << res[i];

		if(i < n)
			pesoC += grafo[res[i]-1][res[i+1]-1];
	}
	cout << endl;

	int i = 1;
	int j = i + 2;

	///Iterações do algoritmo
	while(1)
	{
		vector<int>newCicle = res;



		int pos1=-1,pos2=-1;
		for(int k = 0 ;k < newCicle.size()-1; k++)
		{
			if(i == newCicle[k])
				pos1 = k;
			if(j == newCicle[k])
				pos2 = k;
		}
		
		swap(newCicle[pos1], newCicle[pos2]);

		int pesoNewC = 0;
		for(int k = 0 ; k < newCicle.size(); k++)
		{

			if(k < newCicle.size()-1)
				pesoNewC += grafo[newCicle[k]-1][newCicle[k+1]-1];

		}
		if(pesoNewC < pesoC)
		{

			pesoC = pesoNewC;
			res = newCicle;
			i = 1;
			j = i + 2;
		}
		else
		{
			j++;
			
			if(j <= n)
				continue;
			else
			{
				i++;
				
				if(i < n - 1)
				{

					j = i + 2;
				}
				else
					break;
			}

		}
		
	}
	printf("Valor da viagem : %d\n", pesoC);
	printf("Caminho: ");
	for(int i = 0 ; i <= n ; i++)
	{
		if(i)
			cout << " -> ";
		cout << res[i];
	}
	cout << endl;

}
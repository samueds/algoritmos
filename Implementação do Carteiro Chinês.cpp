#include <bits/stdc++.h>

using namespace std;


int g[405][405];
int ng[16][16];
int n,m;
vector<int>vis;
vector<int>impares;
int degs[405];



int cust = 0;

int dfs(int u)
{

	vis[u] = 1;

	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			ans += dfs(i)+1;
	}

	return ans;
}
bool isConect()
{
	vis.assign(n+1, 0);

	if(dfs(1)+1 != n)
		return false;


	return true;
}

int dp[1 << 17 +2];

int pd(int mask)
{
	if(__builtin_popcount(mask) == impares.size())
		return 0;

	if(dp[mask] != -1)
		return dp[mask];
	int ans = 0x3f3f3f3f;
	for(int i = 0 ; i < impares.size() ; i++)
	{
		for(int j = 0 ; j < impares.size(); j++)
		{
			if(i == j)
				continue;
			if((mask & (1 << i)) || (mask & (1 << j)))
				continue;
		
			
			ans = min(ans, pd( mask | (1 << i) | (1 << j))+ ng[i][j]);
		}
	}
	return dp[mask] = ans;
}



int main()
{

	cin >> n >> m;

	memset(g, 0x3f3f3f3f, sizeof g);
	int ans = 0;


	memset(dp, -1, sizeof dp);
	for(int i =0 ; i < m ; i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a][b] = c;
		g[b][a] = c;
		ans += c;
		degs[a]++;
		degs[b]++;
	}


	int origem;
	printf("Digite a origem do Carteiro:\n");
	cin >> origem;

	for(int i = 1 ; i <= n ; i++)
	{
		if(degs[i] & 1)
		{
				
				impares.push_back(i);
		}
	}


	if(impares.size() > 0)
	{
		if(impares.size() == 2 && (degs[origem] & 1))
		{

			goto fim;
		}
			
		cout << "Grafo nao tem um tour de Euler\n" << endl;
		cout << "Criando novas arestas para torna-lo de Euler" << endl;
		
		for(int k = 1 ; k <= n ; k++)
		{
			for(int i = 1 ; i <= n ; i++)
			{
				for(int j = 1 ; j <= n ; j++)
					g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
			}
		}

		for(int i = 0 ; i < impares.size(); i++)
		{
			for(int j = i+1 ; j < impares.size(); j++)
			{
				ng[i][j] = g[impares[i]][impares[j]];
				ng[j][i] = g[impares[j]][impares[i]];
			}
		}
		
		ans += pd(0);

		
	}
	fim:
	cout << "Custo do Carteiro Chines:\n" << endl;
	cout << ans << endl;
}
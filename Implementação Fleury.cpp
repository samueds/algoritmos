#include <bits/stdc++.h>

using namespace std;


vector<int>g[100003];
int n,m;
vector<int>vis;


int findOdd()
{
	int ans = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		if((int)g[i].size() & 1)
		{
			ans = i;
			break;
		}
			
	}

	return ans;
}

int dfs(int u)
{

	vis[u] = 1;

	int ans = 0;
	for(int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if(!vis[v])
			ans += dfs(v)+1;
	}

	return ans;
}
bool isEulerian()
{
	vis.assign(n+1, 0);
	
	if(dfs(1)+1 != n)
		return false;
	

	int odd = 0;
	for(int i = 1 ; i <= n ;i++)
	{
		if((int)g[i].size() & 1)
			odd++;
	}

	if(odd != 2 && odd != 0)
		return false;

	return true;
}

void removeEdge(int u, int v)
{
	g[u].erase(find(g[u].begin(), g[u].end(),v));
	g[v].erase(find(g[v].begin(), g[v].end(),u));
}

bool isValid(int u, int v)
{
	if(g[u].size() == 1)
		return true;

	vis.assign(n+1,0);

	int ans1 = dfs(u) + 1;

	vis.assign(n+1,0);

	removeEdge(u,v);

	int ans2 = dfs(u) + 1;

	g[u].push_back(v);
	g[v].push_back(u);

	if(ans1 != ans2)
		return false;

	return true;

}

void fleury(int u)
{
	
	for(int i=0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if(isValid(u,v))
		{
			cout << u <<"-" << v << endl;
			removeEdge(u,v);
			fleury(v);
		}
	}
}
int main()
{

	cin >> n >> m;

	for(int i =0 ; i < m ; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
		
	}

	if(!isEulerian())
		cout << "Grafo nao tem um tour de Euler\n" << endl;
	else
	{
		cout << "Tour de Euler" << endl;
		fleury(findOdd());
		
	}
	


}
#include <bits/stdc++.h>



using namespace std;
const int N = 1e5 + 2;
const int M = 20;

int lca[N][M];
int h[N];

int n,q;


vector<int >graph[N];
void dfs(int u, int p)
{
	
	lca[u][0] = p;
	
	for(int i = 1 ; i < M ; i++)
	{
		lca[u][i] = lca[lca[u][i-1]][i-1];
	}
	
	for(int i = 0 ; i < (int)graph[u].size(); i++)
	{
		int v = graph[u][i];
		if(v != p)
		{
			h[v] = h[u] + 1;
			dfs(v,u);
		}
			
	}
	
}

int fun(int a, int b)
{
	
	if(h[a] < h[b]) swap(a,b);

	int d = h[a] - h[b];
	
	for(int i = M-1; i >= 0 ; i--)
	{
		if((d >> i) & 1) a = lca[a][i];
	}
	
	if(a == b) return a;
	
	for(int i = M-1 ; i >= 0 ; i--)
	{
		
		if(lca[a][i] != lca[b][i])
		{
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}

int main()
{
		scanf("%d%d",&n,&q);
		for(int i = 1 ; i < n  ; i++)
		{
			int a,b; scanf("%d%d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1,1);
		for(int i = 0 ; i < q ; i++)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);

			int ab = fun(a,b);
			int ac = fun(a,c);
			int cd = fun(c,d);
			int bd = fun(b,d);
			int ad = fun(a,d);
			int bc = fun(b,c);
			
			int distAB = (h[a] - h[ab]) + (h[b] - h[ab]);
			int distCD = (h[c] - h[cd]) + (h[d] - h[cd]);
			
			int distAC = (h[a] - h[ac]) + (h[c] - h[ac]);
			int distBD = (h[b] - h[bd]) + (h[d] - h[bd]);
			int distAD = (h[a] - h[ad]) + (h[d] - h[ad]);
			int distBC = (h[b] - h[bc]) + (h[c] - h[bc]);
			
			int x = distAB + distCD;
			int y = min( distAC + distBD, distAD + distBC );
			
			if(y > x) printf("0\n");
			else printf("%d\n", (x - y)/2 + 1);
		}		
}
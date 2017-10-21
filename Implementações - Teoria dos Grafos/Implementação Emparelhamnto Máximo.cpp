#include <bits/stdc++.h>

#define vi vector<int>


using namespace std;


vector<vector<int> >g;
vi match, vis;
int Aug(int l)
{
    if (vis[l])
        return 0;
    vis[l] = 1;
    for (int j = 0; j < (int)g[l].size(); j++)
    {
        int r = g[l][j];
        if (match[r] == -1 || Aug(match[r]))
        {
            match[r] = l; return 1;
        }
    }
    return 0;
}

int n,m;

int main()
{
	cin >> n >> m;

	g.assign(n+1, vector<int>());
	match.assign(n+1,-1);

	for(int i = 0 ; i < m ; i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		g[a].push_back(b);
	}

	///considerando que o grafo está bipartido em dois grupos, sendo os vértices de 1 a n/2 em um grupo, e de n/2 + 1 a n

	int maxmatching = 0;

	for(int i = 1 ; i <= n/2 ; i++)
	{
		vis.assign(n+1, 0);
		maxmatching+= Aug(i);
	}

	printf("Emparelhamento maximo = %d\n",maxmatching);
}
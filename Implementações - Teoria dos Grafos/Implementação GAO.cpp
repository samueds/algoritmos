#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

int n,m;
vector<vector<pair<int,int> > >g;
stack<int>ordenacao;
int vis[10005];

void dfs(int u)
{
    vis[u] = 1;
    
    for(int i = 0 ; i < (int)g[u].size() ; i++)
    {
        int v = g[u][i].first;
        if(!vis[v])
            dfs(v);
    }
    ordenacao.push(u);
}

int main()
{
    cin >> n >> m;
    
    g.assign(n+1, vector<pair<int,int> >());
    
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back(make_pair(b,c));
    }
    memset(vis, 0, sizeof vis);
    
    for(char i = 1; i <= n ; i++)
    {
        if(!vis[i]) dfs(i);
    }
    int dist[10005]; memset(dist, oo, sizeof dist);
    int pai[10005]; memset(pai, -1, sizeof pai); // -1 == NULL
    int ori,dest; cin >> ori >> dest; // origem e destino
    dist[ori] = 0;
    
    while(!ordenacao.empty())
    {
        int u = ordenacao.top();
        ordenacao.pop();
        
        for(int i = 0 ; i < (int)g[u].size(); i++)
        {
            int v = g[u][i].first;
            int w = g[u][i].second;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pai[v] = u;
            }
        }
    }
    if(dist[dest] != oo)
        printf("Menor caminho de %d para %d = %d\n", ori, dest, dist[dest]);
    else
        printf("Nao existe caminho!\n");
    
    
}
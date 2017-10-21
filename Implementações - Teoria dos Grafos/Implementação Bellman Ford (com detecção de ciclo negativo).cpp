#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
vector<vector<pair<int,int> > >grafo;

int origem, destino;

int main()
{
    cin >> n >> m;
    
    grafo.assign(n+1, vector<pair<int,int> >());
    
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b,c));
        grafo[b].push_back(make_pair(a,c));
    }
    
    cin >> origem >> destino;
    
    vector<int> dist(n+1, INF); dist[origem] = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int u = 1; u <= n ; u++)
        {
            for (int j = 0; j < (int)grafo[u].size(); j++)
            {
                pair<int,int> v = grafo[u][j]; 
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
        
    }
    if(dist[destino] != INF)
     cout << "Menor caminho " << origem  << " a " << destino << " : " << dist[destino] << endl;
    else
     cout << "Nao existe caminho para o destino" << endl;
     
     bool hasNegativeCycle = false;
    for (int u = 1; u <= n; u++)
    {
        for (int j = 0; j < (int)grafo[u].size(); j++) {
        pair<int,int> v =grafo[u][j];
        if (dist[v.first] > dist[u] + v.second) 
                 hasNegativeCycle = true; 
        }
        
    }
    printf("Ciclo negativo existe? %s\n", hasNegativeCycle ? "Sim" : "Nao");
    
    
    
}
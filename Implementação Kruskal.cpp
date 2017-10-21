#include <bits/stdc++.h>

using namespace std;

const int MAXV = 10005; // Numero máximo de vertice, 1 indexado

struct aresta
{
    int a,b,w;

    bool operator <  (const aresta &q)const
    {
        return w < q.w;
    }
};

int p[MAXV];

int n,m; // Numero de vertices e numero de arestas

vector<aresta>grafo; // vetor das arestas (grafo);

int findset(int u)
{
    if(p[u] == u)
        return u;
    return p[u] = findset(p[u]);
}
void unionset(int a, int b)
{
    int x = findset(a);
    int y = findset(b);
    p[y] = x;
}

int main()
{
    printf("Digite o numero de vertices e arestas:\n");

    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++) p[i] = i;

    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c;

        cin >> a >> b >> c;

        grafo.push_back({a,b,c});
    }
    sort(grafo.begin(), grafo.end());

    int mst = 0; // valor da arvore geradora minima

    for(int i = 0 ; i < m ; i++)
    {
        int a = grafo[i].a;
        int b = grafo[i].b;
        int w = grafo[i].w;

        if(findset(a) != findset(b))
        {
            unionset(a,b);
            mst += w;
        }
    }

    printf("Valor da arvore spanning minima: %d\n",mst);


}
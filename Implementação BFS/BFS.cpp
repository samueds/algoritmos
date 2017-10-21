#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

int rotulos[MAXN],n,m;
int ori, fim;
vector<vector<int> >g;

int mi[MAXN];
int p[MAXN];

int bfs(int u)
{
    memset(rotulos, -1, sizeof rotulos);

    queue<int>fila;

    fila.push(u);

    rotulos[u] = 0;
    p[u] = u;

    while(!fila.empty())
    {
        int x = fila.front(); fila.pop();

        for(int i = 0 ; i < (int)g[x].size() ; i++)
        {
            int v = g[x][i];

            if(rotulos[v] == -1)
            {
                rotulos[v] = rotulos[x] + 1;
                fila.push(v);
                p[v] = x;
            }

        }
    }
}
vector<int>caminho;

void constroiCaminho(int u)
{
    if(u == p[u])
        return;
    constroiCaminho(p[u]);

    caminho.push_back(u);
}
int contaCaminhos(int u, int i)
{
    mi[u] = 1;
    for(int j = 0 ; j < (int)g[u].size() ; j++)
    {
        int v = g[u][j];
        if(i == rotulos[v])
            mi[v] = 0;
    }
    while(--i >= 0)
    {
        for(int j = 1 ; j <= n; j++)
        {
            if(rotulos[j] == i)
            {
                for(int k = 0 ; k < (int)g[j].size() ; k++)
                {
                    int x = g[j][k];
                    if(rotulos[x] == i + 1)
                       mi[j] += mi[x];
                }
            }
        }
    }
    return mi[ori];
}

int main()
{
    freopen("grafo.txt", "r" , stdin);
    cin >> n >> m; // numero de vertices e arestas
    g.assign(n+1, vector<int>());
    for(int i = 0 ; i < m ; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b); // leitura das arestas
        g[a].push_back(b);
    }
    cin >> ori >> fim; // origem e destino
    bfs(ori);
    if(rotulos[fim] == -1)
        printf("Nao ha caminhos de %d a %d\n", ori, fim);
    else
    {
        printf("Menor caminho de %d a %d = %d\n", ori, fim, rotulos[fim]);
        printf("Um desses caminhos eh: \n");
        caminho.push_back(ori);
        constroiCaminho(fim);

        for(int i = 0 ; i < caminho.size() ; i++)
        {
            printf("%d", caminho[i]);
            if(i == caminho.size() - 1)
                printf("\n");
            else
                printf(" -> ");
        }
        printf("Numero  de caminhos minimos de %d a %d = %d\n", ori, fim, contaCaminhos(fim, rotulos[fim]));
    }
}

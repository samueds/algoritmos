#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 405;

int adj[N][N];
int paths[N][N];

int n,m; // numero de vertices e arestas

int main()
{
    cin >> n >> m;
    memset(adj, oo, sizeof adj);
    memset(paths, -1, sizeof paths);
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a][b] = c;
        adj[b][a] = c;
        paths[a][b] = a;
        paths[b][a] = b;
    }

    for(int k = 0 ; k < n ; k++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    paths[i][j] = k;
                }
            }
        }
    }

    printf("Matriz de menores caminhos:\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i == j)
                printf("oo ");
            else
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz de caminhos:\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i == j)
                printf("-1 ");
            else
                printf("%d ",paths[i][j]);
        }
        printf("\n");
    }

}

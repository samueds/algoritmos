#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

int grafo[405][405];
int n,m,q;

int main()
{
    printf("Digite o numero de vertices e o numero de arestas:\n");
    scanf("%d%d", &n,&m);
    
    memset(grafo, oo, sizeof grafo);
    
    for(int i = 1 ; i<= n ; i++) grafo[i][i] = 0;
    printf("Digite agora todas as arestas do grafo:\n");
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        grafo[a][b] = c;
        grafo[b][a] = c;
    }
    ///FloydWarshal para encontrar todos os minimax do grafo O(n ^ 3)
    for(int k = 1 ; k <= n ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1; j <= n ;j++)
            {
                grafo[i][j] = min(grafo[i][j],max(grafo[i][k], grafo[k][j]));
            }
        }
    }
    printf("Digite quantas consultas quer fazer:\n");
    scanf("%d",&q);
    
    for(int i = 0 ; i < q ; i++)
    {
        int a,b; scanf("%d%d",&a,&b);
        printf("O minimax do caminho entre %d e %d eh : %d\n", a,b,grafo[a][b]);
    }
    
    return 0;
}
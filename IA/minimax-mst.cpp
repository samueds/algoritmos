#include <bits/stdc++.h>

using namespace std;

int minimax[10004][10004];
int p[10004];

struct edge
{
    int a,b,w;

    bool operator < (const edge&e)const
    {
        return w < e.w;
    }
};

int n,m,q;
vector<edge> g;
vector<vector<pair<int,int > > >mst;
vector<pair<int,int> >pai;

int findset(int u)
{
    if(u == p[u]) return u;
    return p[u] = findset(p[u]);
}

void unionset(int a, int b)
{
    a = findset(a);
    b = findset(b);

    p[b] = a;
}

int main()
{

    printf("Digite o numero de vertices e arestas:\n");
    scanf("%d%d",&n,&m);

    mst.assign(n + 1, vector<pair<int,int> > ());

    for(int i = 1 ; i <= n ; i++) p[i] = i;

    printf("Digite agora todas as arestas do grafo:\n");
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g.push_back({a,b,c});
    }

    sort(g.begin(), g.end());


    for(int i = 0 ; i < m ; i++)
    {
        int a = g[i].a;
        int b = g[i].b;
        int w = g[i].w;
        if(findset(a) != findset(b))
        {
            unionset(a,b);
            mst[a].push_back(make_pair(b,w));
            mst[b].push_back(make_pair(a,w));
        }
    }
    printf("Digite quantas consultas quer fazer:\n");
    scanf("%d",&q);

    while(q--)
    {
        printf("Digite os dois valores desejados:\n");
        int i,j;
        scanf("%d%d",&i,&j);

            pai.assign(n + 1 , pair<int, int> ());
            int dist[10004]; memset(dist, -1, sizeof dist);
            dist[i] = 0;
            queue<int> fila; fila.push(i);

            while(!fila.empty())
            {

                int u = fila.front(); fila.pop();
                for(int z = 0 ; z < (int)mst[u].size(); z++)
                {
                    int v = mst[u][z].first;
                    int custo = mst[u][z].second;

                    if(dist[v] == -1)
                    {
                        dist[v] = dist[u] + 1;
                        fila.push(v);
                        pai[v] = make_pair(u,custo);
                    }
                }

            }

                printf("Caminho do minimax:\n");
                int id = j;
                int ans = 0;
                vector<int>path;
                path.push_back(id);
                while(id != i)
                {

                    ans = max(ans, pai[id].second);
                    id = pai[id].first;
                    path.push_back(id);
                }
                reverse(path.begin(), path.end());
                for(int h = 0 ; h < (int)path.size(); h++)
                {
                    printf("%d", path[h]);
                    if(h == path.size() - 1)
                        printf("\n");
                    else
                        printf(" -> ");
                }
                minimax[i][j] = ans;
                printf("O minimax do caminho entre %d e %d eh : %d\n", i,j,minimax[i][j]);
        }
        return 0;
}

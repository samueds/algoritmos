#include <bits/stdc++.h>

using namespace std;


vector<int>visitados;
int n,m; // Numero de vertices e numero de arestas

vector<vector<pair<int,int> > >grafo; // lista de adjacencias
priority_queue<pair<int,int> >fila;

void process(int vtx)
{
  visitados[vtx] = 1;

  for (int j = 0; j < (int)grafo[vtx].size(); j++)
  {

    int u = grafo[vtx][j].first;
    int w = grafo[vtx][j].second;
    if (!visitados[u])
        fila.push(make_pair(-w, u));
   }

}



int main()
{
    printf("Digite o numero de vertices e arestas:\n");

    cin >> n >> m;

    int mst = 0;

    grafo.assign(n+1, vector<pair<int,int> >());

    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c;

        cin >> a >> b >> c;

        grafo[a].push_back(make_pair(b,c));
        grafo[b].push_back(make_pair(a,c));
    }
    visitados.assign(n+1,0);
    for(int i = 1 ; i <= n ; i++)
    {

        if(!visitados[i])
        {

            visitados[i] = 1;
            process(i);

            while(!fila.empty())
            {

                pair<int,int>aux = fila.top(); fila.pop();

                int u = aux.second;
                int w = -aux.first;

                if(!visitados[u])
                {
                    mst += w;
                    process(u);
                }
            }
        }
    }

    printf("Valor da arvore spanning minima: %d\n",mst);


}
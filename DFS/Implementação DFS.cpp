#include <bits/stdc++.h>

using namespace std;

int n,m; //numero de vertices e arestas

vector<vector<int> >g; // grafo

int d[1005];
int f[1005];
int vis[1005]; // 0 branco | 1 cinza | 2 preto
int tempo;

map<string, int>mp; // mapa para rotular os vertices

int get(string x)
{
    if(!mp.count(x))
        mp[x] = mp.size() - 1;

    return mp[x];
}

void dfs(int u)
{
    d[u] = ++tempo;

    vis[u] = 1;

    for(int i = 0 ; i < (int)g[u].size() ; i++)
    {
        int v = g[u][i];
        if(!vis[v])
            dfs(v);
    }
    vis[u] = 2;

    f[u] = ++tempo;

}

int main()
{
    freopen("grafo.txt", "r", stdin);
    cin >> n >> m;

    g.assign(n + 1 , vector<int>());

    vector<string>input;

    for(int i = 0 ; i < n ; i++)
    {
        string x; cin>>x;
        input.push_back(x);
    }
    sort(input.begin(), input.end());

    for(int i = 0 ; i < n ; i++) get(input[i]);

    for(int i = 0 ; i < m ; i++)
    {
        string x,y; cin >> x >> y;
        g[get(x)].push_back(get(y));
    }

    for(int i = 0 ; i < n ; i++) sort(g[i].begin(), g[i].end());

    memset(vis, 0, sizeof vis); // marcando tudo pra branco

    tempo = 0;
    for(int i = 0 ; i < mp.size() ; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%s -> in = %d | out = %d\n",input[i].c_str(), d[i], f[i]);
    }

}

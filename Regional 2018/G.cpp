#include <bits/stdc++.h>

using namespace std;

int p,refe,c;
int demanda[1005];
int estoques[1005];
vector<vector<int> >g;
int flow[2005][2005];

int getPosto(int u)
{
	return u + refe;
}

struct aresta
{
	int a,b,c;

	bool operator < (const aresta &q) const
	{
		return c < q.c;
	}
};

vector<aresta>temp;

void addEdge(int a, int b, int f)
{
	//cout << a <<"->" << b <<endl;
	flow[a][b] = f;
	g[a].push_back(b);
	g[b].push_back(a);
}


class MaxFlow
{
private:
  const int FLOWINF = numeric_limits<int>::max() / 2.0;
  const int eps = (int)(1e-9);
  struct Edge
  {
    int to;
    int cap;
    Edge(int a, int cp) { to = a; cap = cp; }
  };
  int n, sta, fin;
  vector< Edge > edge;
  vector< vector< int > > adj;
  vector< int > ptr;
  vector< int > dist;
  vector< int > que;
  bool bfs() 
  {
    int sq = 0, ed = 0;
    fill(dist.begin(), dist.end(), -1);
    que[ed++] = sta; dist[sta] = 0; 
    while(sq != ed)
    {
      int x = que[sq++];
      for(int i = 0; i < (int)adj[x].size(); ++i)
      {
        int ind = adj[x][i];
        int y = edge[ind].to;
        if(dist[y] == -1 && edge[ind].cap > eps)
        {
          dist[y] = dist[x] + 1;
          que[ed++] = y;
        }
      }
    }
    return dist[fin] != -1;
  }
  int dfs(int x, int f)
  {
    if(x == fin) return f;
    while(ptr[x] < adj[x].size())
    {
      int ind = adj[x][ptr[x]];
      int y = edge[ind].to;
      if(dist[y] == dist[x] + 1 && edge[ind].cap > eps)
      {
        int foo = dfs(y, min(f, edge[ind].cap));
        if(foo > 0)
        {
          edge[ind].cap -= foo;
          edge[ind ^ 1].cap += foo;
          return foo;
        }
      }
      ptr[x]++;
    }
    return 0;
  }
public:
  MaxFlow(){}
  MaxFlow(int _n, int _sta, int _fin)
  {
    n = _n;
    sta = _sta;
    fin = _fin;
    ptr.resize(n);
    adj.resize(n);
    dist.resize(n);
    que.resize(n);
  }
  void addEdge(int u, int v, int flw)
  {
    
    adj[u].push_back(edge.size());
    edge.push_back(Edge(v, flw));
    adj[v].push_back(edge.size());
    edge.push_back(Edge(u, 0));
  }
  int dinic()
  {
    int totFlow = 0, got = 0;
    while(bfs()) {
      fill(ptr.begin(), ptr.end(), 0);
      while((got = dfs(sta, FLOWINF)) > eps) totFlow += got;
    }
    return totFlow;
  }
};

int main()
{
	scanf("%d%d%d",&p,&refe,&c);

	int s = 0;
	int t = p + refe + 1;
	int totalDemanda = 0;
	g.assign(2005, vector<int>());
	for(int i = 1 ; i <= p ; i++)
	{
		scanf("%d", demanda + i);
		totalDemanda += demanda[i];
	}
	for(int i = 1 ; i <= refe ; i++)
		scanf("%d", estoques + i);

	for(int i = 0 ; i < c ; i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		temp.push_back({a,b,c});
	}
	sort(temp.begin(), temp.end());

	int l = 1;
	int r = 1e6;
	int ans = r+1;
	while(l <= r)
	{
		MaxFlow f(p + refe + 2,0,p + refe + 1);
		int m = (l+r)/2;
		
		for(int i = 1 ; i <= p ; i++)
		{
			f.addEdge(getPosto(i), t, demanda[i]);
		}
		for(int i = 1 ; i <= refe ; i++)
		{
			f.addEdge(s, i, estoques[i]);
		}
		for(int i =0 ; i < temp.size(); i++)
		{
			if(temp[i].c > m) break;

			f.addEdge(temp[i].b, getPosto(temp[i].a), estoques[temp[i].b]);
		}

		
		int maxflow = f.dinic();

		if(maxflow == totalDemanda)
		{
			if(ans > m)
			{
				ans = m;
				r = m - 1;
			}
			else
				l = m + 1;
		}
		else
			l = m + 1;
	}
	if(ans == 1e6 + 1) ans = -1;
	printf("%d\n",ans);
	return 0;
}

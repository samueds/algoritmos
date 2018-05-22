struct edge {
	int a, b, f, c;
};

int n, m,d[MAXN],lim,s,t;
vector <edge> e;
int pt[MAXN]; // very important performance trick
vector <int> g[MAXN];
long long flow = 0;
queue <int> q;

void add_edge(int a, int b, int c) {                                                                           
	edge ed;
	//keep edges in vector: e[ind] - direct edge, e[ind ^ 1] - back edge 
	ed.a = a; ed.b = b; ed.f = 0; ed.c = c;
	g[a].push_back(e.size());
	e.push_back(ed);
	ed.a = b; ed.b = a; ed.f = c; ed.c = c;
	g[b].push_back(e.size());
	e.push_back(ed);
}

bool bfs() {
	for (int i = s; i <= t; i++)
		d[i] = inf;
	d[s] = 0; 
	q.push(s);
	while (!q.empty() && d[t] == inf) {
		int cur = q.front(); q.pop();
		for (size_t i = 0; i < g[cur].size(); i++) {
			int id = g[cur][i];
			int to = e[id].b;
			//printf("cur = %d id = %d a = %d b = %d f = %d c = %d\n", cur, id, e[id].a, e[id].b, e[id].f, e[id].c);
			if (d[to] == inf && e[id].c - e[id].f >= lim) {
				d[to] = d[cur] + 1;
				q.push(to);
			}
		}
	}
	while (!q.empty()) 
		q.pop();
	return d[t] != inf;
}






bool dfs(int v, int flow) {
	if (flow == 0) 
		return false;
	if (v == t) {
		//cout << v << endl;
		return true;
	}
	for (; pt[v] < g[v].size(); pt[v]++) {
		int id = g[v][pt[v]];
		int to = e[id].b;
		//printf("v = %d id = %d a = %d b = %d f = %d c = %d\n", v, id, e[id].a, e[id].b, e[id].f, e[id].c);
		if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
			int pushed = dfs(to, flow); 
			if (pushed) {
				e[id].f += flow;
				e[id ^ 1].f -= flow;
				return true;
			}				
		}
	}
	return false;
}

void dinic() {
	for (lim = (1 << 30); lim >= 1;) {
		if (!bfs()) {
			lim >>= 1;
			continue;
		}
		for (int i = s; i <= t; i++) 
			pt[i] = 0;
		int pushed;
		while (pushed = dfs(s, lim)) { 
			flow = flow + lim;
		}
		cout << flow << endl;
	}
}

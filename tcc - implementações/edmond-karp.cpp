const int N = 105;        // Número máximo de vértices
const int oo = 0x3f3f3f3f // Representação de infinito (valor muito alto)


vector<int>grafo[N]; // Lista de adjacências
int fluxo[N][N];     // Matriz residual do grafo

int pai[N];          // Vetor de representação de pai dos vértices para a bfs
int dist[N];         // Vetor para armazenarmos as distâncias entre os vértices

//Função para adicionar arestas ao grafo e ao grafo residual
//Parâmetros (a = extremidade 1 da aresta, b = extremidade 2 da aresta, f = fluxo da aresta)
void adiciona_aresta(int a, int b, int f)
{
	g[a].push_back(b);
	g[b].push_back(a);
	fluxo[a][b] += f;
}

// Busca em largura para encontrar os melhores caminhos.
// Retorna verdadeiro ou falso, se encontrou algum caminho entre o vértice inicial e o final
// Parâmetros (_s = vértice inicial, _t = vértice final)
bool bfs(int _s, int _t)
{

	memset(dist, oo, sizeof dist);
	memset(pai, -1, sizeof dist);

	queue<int>fila;
	fila.push(_s);
	dist[_s] = 0;

	while(!fila.empty())
	{
		int u = fila.front();

		for(int i = 0 ; i < (int)grafo[u].size(); i++)
		{
			int v = grafo[u][i];

			if(dist[v] == oo)
			{
				dist[v] = dist[u] + 1;
				fila.push(v);
				pai[v] = u;
			}
		}
	}
	return dist[_t] != oo;
}

//Função principal do algoritmo
//Retorna qual o fluxo máximo entre os vértices inicial e final
// Parâmetros (_s = vértice inicial, _t = vértice final)
int edmonds_karp(int _s, int _t)
{
	int fluxoMaximo = 0;


	// Executa enquanto houver caminhos com fluxo positivo
	while(bfs(_s,_t))
	{

		int menorAresta = oo;
		int id = _t;
		// Primeiro procuramos a menor aresta do caminho
		while(id != _s)
		{
			menorAresta = min(menorAresta, fluxo[p[id]][id]);
			id = pai[id];
		}

		id = _t;

		// Depois retiramos o fluxo das aresta de ida, e somamos o fluxo das aresta de volta
		while(id != _s)
		{
			fluxo[p[id]][id] -= menorAresta;
			fluxo[id][p[id]] += menorAresta;
			id = pai[id];
		}
		fluxoMaximo += menorAresta;
	}

	return fluxoMaximo;

}

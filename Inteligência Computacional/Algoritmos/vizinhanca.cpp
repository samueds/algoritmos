#include <bits/stdc++.h>
using namespace std;

//constante para representar infinito
const int oo = 0x3f3f3f3f;
//constate para numero maximo de vértices
const int N = 1e4 + 1;

vector<vector<int> >grafo; //lista de adjacencias para representar o grafo
int grafoAux[N][N]; // matriz de adjacencias do grafo para auxilio
int removido[N];
int n,m; //respectivamente numero de vertices e arestas do grafo
int a,b; //represetam dois vértices que serão ligados por uma aresta

//função para encontrar o vértice de menor grau
int menorgrau()
{
	int menor = oo;
	int ans;
	for(int i = n ; i >= 0 ; i--)
	{
		if(!removido[i])
		{
			int x = grafo[i].size();
			int clique = (x*x-1)/2;
			int cont = 0;
			for(int j = 0 ; j < x ; j++)
			{
				int a = grafo[i][j];
				for(int k = j+1 ; k < x ; k++)
				{
					int b = grafo[i][k];
					if(g[a][b]) cont++;
				}	
			}
			if(menor < (clique - cont))
			{
				menor = clique - cont;
				ans = i;
			}
		}
	}
	return ans;
}

int heuristica()
{
	int treewidth = 0;

	//loop para remover n vértices
	for(int i = 1 ; i <= n ; i++)
	{
		//busca vértice de menor grau
		int menor = vizinhanca();
		treewidth = max(treewidth, (int)grafo[menor].size());
		//adiciona arestas para formar um clique na vizinhança do vértice de menor grau
		//e remove as arestas que ligavam a ele, ou seja, remove ele do grafo
		//printf("Bag: %d", menor);
		for(int j = 0 ; j < (int)grafo[menor].size(); j++)
		{
			int a = grafo[menor][j];
			//printf(" - %d", a);
			grafo[a].erase(find(grafo[a].begin(), grafo[a].end(), menor));
			
			grafoAux[a][menor] = 0;
			grafoAux[menor][a] = 0;
			for(int k = j+1 ; k < (int)grafo[menor].size(); k++)
			{
				int b = grafo[menor][k];
				if(grafoAux[a][b]) continue;
				//cout << "adiciona aresta " << a << " " << b << endl;
				grafo[a].push_back(b);
				grafo[b].push_back(a);
				grafoAux[a][b] = 1;
				grafoAux[b][a] = 1;
			}
		}
		//cout << endl;
		//remove o vertice de menor grau do grafo
		grafo[menor].clear();
		removido[menor] = 1;
	}
	return treewidth;
}

int main()
{
	string q,w;
	cin >> q >> w;
	scanf("%d%d",&n,&m);
	FILE *arq;

	arq = fopen("saida.txt", "a");

	//alocacao das listas para n vértices
	grafo.assign(n+1, vector<int>());

	for(int i = 0 ; i < m; i++)
	{
		scanf("%d%d",&a,&b);

		//adiciona a aresta (a-b) no grafo
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		grafoAux[a][b] = 1;
		grafoAux[b][a] = 1;
	}
	//obtem o tempo antes da execuçao
	auto start = chrono::steady_clock::now();
	int largura = heuristica();
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	
	//obtem o tempo pós a execucao
	
	fprintf(arq,"%d$%d$%f\n", n+m,largura,chrono::duration <double, milli> (diff).count());


	return 0;
}
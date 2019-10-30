#include <bits/stdc++.h>
using namespace std;

//constante para representar infinito
const int oo = 0x3f3f3f3f;
//constate para numero maximo de vértices
const int N = 1e4 + 1;

vector<vector<int> >grafo; //lista de adjacencias para representar o grafo
int grafoAux[N][N]; // matriz de adjacencias do grafo para auxilio
int removido[N];
vector<int> solucao;
int n,m; //respectivamente numero de vertices e arestas do grafo
int a,b; //represetam dois vértices que serão ligados por uma aresta
vector<int>maiores;
//função para encontrar o vértice de menor grau
int vizinhanca()
{
	int menor = oo;
	int ans;
	for(int i = n ; i >= 1 ; i--)
	{
		if(!removido[i])
		{
			int x = grafo[i].size();
			int clique = (x*(x-1))/2;
			int cont = 0;
			
			for(int j = 0 ; j < x ; j++)
			{
				int a = grafo[i][j];
				for(int k = j+1 ; k < x ; k++)
				{
					int b = grafo[i][k];
					if(grafoAux[a][b]) cont++;
				}	
			}
			if(menor > (clique - cont))
			{
				menor = clique - cont;
				ans = i;
			}
		}
	}
	return ans;
}

vector<pair<int,int> >ss;

int heuristica()
{
	int treewidth = 0;

	//loop para remover n vértices
	for(int i = 1 ; i <= n ; i++)
	{
		//busca vértice de menor grau
		int menor = vizinhanca();
		solucao.push_back(menor);
		//cout << menor << endl;
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

int calcula(vector<int>solucao,int x, int y, vector<vector<int> >grafo)
{
	int treewidth = 0;

	
	for(int i = 0 ; i < x ; i++)
	{
		
		int menor = solucao[i];
		
		treewidth = max(treewidth, (int)grafo[menor].size());
		
		for(int j = 0 ; j < (int)grafo[menor].size(); j++)
		{
			int a = grafo[menor][j];
			
			grafo[a].erase(find(grafo[a].begin(), grafo[a].end(), menor));
			
			for(int k = j+1 ; k < (int)grafo[menor].size(); k++)
			{
				int b = grafo[menor][k];
				if(find(grafo[a].begin(), grafo[a].end(), b) != grafo[a].end())
					continue;
				
				grafo[a].push_back(b);
				grafo[b].push_back(a);
				
			}
		}
		grafo[menor].clear();
	}

	for(int i = y ; i >= x ; i--)
	{
		
		int menor = solucao[i];
		
		treewidth = max(treewidth, (int)grafo[menor].size());
		
		for(int j = 0 ; j < (int)grafo[menor].size(); j++)
		{
			int a = grafo[menor][j];
			
			grafo[a].erase(find(grafo[a].begin(), grafo[a].end(), menor));
			
			for(int k = j+1 ; k < (int)grafo[menor].size(); k++)
			{
				int b = grafo[menor][k];
				if(find(grafo[a].begin(), grafo[a].end(), b) != grafo[a].end())
					continue;
				
				grafo[a].push_back(b);
				grafo[b].push_back(a);
				
			}
		}
		grafo[menor].clear();
	}

	for(int i = y+1 ; i < n ; i++)
	{
		
		int menor = solucao[i];
		
		treewidth = max(treewidth, (int)grafo[menor].size());
		
		for(int j = 0 ; j < (int)grafo[menor].size(); j++)
		{
			int a = grafo[menor][j];
			
			grafo[a].erase(find(grafo[a].begin(), grafo[a].end(), menor));
			
			for(int k = j+1 ; k < (int)grafo[menor].size(); k++)
			{
				int b = grafo[menor][k];
				if(find(grafo[a].begin(), grafo[a].end(), b) != grafo[a].end())
					continue;
				
				grafo[a].push_back(b);
				grafo[b].push_back(a);
				
			}
		}
		grafo[menor].clear();
	}
	return treewidth;
}

int busca_local_first(vector<int> s, vector<vector<int> >g, int melhor)
{
	int maior=-1;
	maiores.clear();
	for(int i = 0 ; i < s.size(); i++)
	{
		maior = max(maior, (int)g[s[i]].size());
	}

	for(int i = 0 ; i < s.size(); i++)
	{
		if(maior == g[s[i]].size())
			maiores.push_back(i);
	}
	cout << maior << endl;
	vector<int>cur;
	int left=-1, right=-1;
	left = maiores[0];
	if(maiores.size() > 1)
		right = maiores[maiores.size() - 1];
	
	for(int i = 0 ; i < n ; i++)
	{
		cur.clear();
		for(int j = i + 1 ; j < n ; j++)
		{
			// if(right != -1)
			 //{
			 	//if(i > left || j < right) continue;
			 //}
			// if(i > left) continue;
			 
			 cout << left << " " << right << endl;

			 int ans = calcula(s,i,j,g);
			 
			 //cout << i << " " <<  j << endl;
			
			 if(ans < melhor)
			 {
			 	cout << "melhorou! " << endl;
			 	cout << ans << endl;
			 	for(int k = 0 ; k < i ; k++)
			 		cur.push_back(s[k]);
			 	for(int k = j ; k >= i ; k--)
			 		cur.push_back(s[k]);
			 	for(int k = j+1 ; k < n ; k++)
			 		cur.push_back(s[k]);
			 	
			 	return busca_local_first(cur, g, ans);
			 }
		}
	}
	return melhor;
}


int main()
{
	string q,w;
	cin >> q >> w;
	scanf("%d%d",&n,&m);
	FILE *arq;

	arq = fopen("saidabusca.txt", "a");

	//alocacao das listas para n vértices
	grafo.assign(n+1, vector<int>());

	vector<vector<int> > h;
	h.assign(n+1, vector<int>());
	
	for(int i = 0 ; i < m; i++)
	{
		scanf("%d%d",&a,&b);

		//adiciona a aresta (a-b) no grafo
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		grafoAux[a][b] = 1;
		grafoAux[b][a] = 1;
		h[a].push_back(b);
		h[b].push_back(a);
		
	}

	auto start = chrono::steady_clock::now();
	
	int largura = heuristica();
	
	//cout << "Largura "  << largura<< endl;
	
	int melhor = busca_local_first(solucao, h, largura);

	printf("Ori: %d | Pos busca local: %d\n", largura, melhor);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	//obtem o tempo pós a execucao
	
	fprintf(arq,"%d$%d$%d$%f\n", n+m,largura,melhor,chrono::duration <double, milli> (diff).count());


	return 0;
}
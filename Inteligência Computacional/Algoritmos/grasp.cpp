#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;

//constante para representar infinito
const int oo = 0x3f3f3f3f;
//constate para numero maximo de vértices
const int N = 1e4 + 1;
int seed;
int removido[N];
vector<int> solucao;
int avada;
int n,m; //respectivamente numero de vertices e arestas do grafo
int a,b; //represetam dois vértices que serão ligados por uma aresta
vector<int>maiores;
//função para encontrar o vértice de menor grau
template <typename I>
I random_element(I begin, I end)
{
    const unsigned long n = std::distance(begin, end);
    const unsigned long divisor = (RAND_MAX + 1) / n;

    unsigned long k;
    do { k = std::rand() / divisor; } while (k >= n);

    std::advance(begin, k);
    return begin;
}



int vizinhanca(vector<vector<int> >grafo, double alpha)
{
	vector<pair<int,int> > pp;
	int menor = oo;
	int ans;
	int valores[N];
	for(int i = n ; i >= 1 ; i--)
	{

		if(removido[i]) continue;
			int x = grafo[i].size();
			int clique = (x*(x-1))/2;
			int cont = 0;
			
			for(int j = 0 ; j < x ; j++)
			{
				int a = grafo[i][j];
				for(int k = j+1 ; k < x ; k++)
				{
					int b = grafo[i][k];
					if(find(grafo[a].begin(), grafo[a].end(), b) != grafo[a].end())
						cont++;
				}	
			}
			pp.push_back(make_pair(clique - cont, i));
			if(menor > (clique - cont))
			{
				menor = clique - cont;
				ans = i;
			}
		
	}
	//return ans;
	int val = 0;
	for(int i = 0 ; i <(int)pp.size() ; i++) if(pp[i].first == menor) val++;
	sort(pp.begin(), pp.end());
	vector<int>possiveis;
	int tam = val * alpha;
	for(int i = 0 ; i <= tam; i++)
	{
		possiveis.push_back(pp[i].second);
	}
	
 	
 	seed = rand()%avada;
 	//cout << seed << endl;
 	//Mersene Twister 
	std::mt19937 generator (seed);


	std::uniform_int_distribution<int> dist(0, possiveis.size() - 1);

	return  possiveis[dist(generator)];
    
 
	
}

vector<pair<int,int> >ss;

int heuristica(vector<vector<int> >grafo,double alpha)
{	
	int treewidth = 0;
	//cout << grafo[1].size() << endl;
	
	for(int i = 1 ; i <= n ; i++)
	{
		
		int menor = vizinhanca(grafo,alpha);
		
		solucao.push_back(menor);
		
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
			
			 int ans = calcula(s,i,j,g);
			 
			
			
			 if(ans < melhor)
			 {
			 	
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



int main(int argc, char** argv)
{


	string q,w;
	cin >> q >> w;
	scanf("%d%d",&n,&m);
	FILE *arq;

	string modulo = argv[1];

	stringstream bruto;
	bruto << modulo;

	bruto >> avada;

	arq = fopen("saidatttX.txt", "a");
	vector<vector<int> >grafo; //lista de adjacencias para representar o grafo
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
		h[a].push_back(b);
		h[b].push_back(a);
		
	}

	auto start = chrono::steady_clock::now();
	int iter = 0;
	int itermax = 200;
	int bestseed;
	int resposta = oo;
	int target = 30;
	while(iter < itermax)
	{
		
		grafo.assign(n+1, vector<int>());
		for(int i = 1 ; i <= n ; i++)
		{
			grafo[i].clear();
			for(int j = 0 ; j < h[i].size(); j++)
				grafo[i].push_back(h[i][j]);
		}
		memset(removido, 0, sizeof removido);
		solucao.clear();
		int largura = heuristica(grafo,0.1);
	
		int melhor = busca_local_first(solucao, grafo, largura);
		
		if(melhor < resposta)
		{
			resposta = melhor;
			bestseed = seed;
		}
		
		
		//printf("Ori: %d | Pos busca local: %d\n", largura, melhor);
		if(melhor == target) break;
		iter++;
	}
	printf("Iteracoes %d\n", iter);
	
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	
	fprintf(arq,"%f\n",chrono::duration <double, milli> (diff).count());


	return 0;
}
#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
int cnt = 0;

//constante para representar infinito
const int oo = 0x3f3f3f3f;
//constate para numero maximo de vértices
const int N = 1e4 + 1;
const int MaxPopulacao = 100;
const int Geracoes = 200;
int seed;
int removido[N];
vector<int> solucao;
int avada;
int n,m; //respectivamente numero de vertices e arestas do grafo
int a,b; //represetam dois vértices que serão ligados por uma aresta



int vizinhanca(vector<vector<int> >grafo, double alpha)
{
	vector<pair<int,int> > pp;
	int menor = oo;
	int ans;
	
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
	if(alpha == 0) return ans;
	int val = 0;
	
	sort(pp.begin(), pp.end());
	vector<int>possiveis;

	int tam = pp.size() * alpha;

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

pair<int, vector<int> > heuristica(vector<vector<int> >grafo,double alpha)
{	
	int treewidth = 0;
	vector<int> solucao;
	
	
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

	return make_pair(treewidth, solucao);
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

vector<pair<int,vector<int> > >populacao;
void geraPopulacaoInicial(vector<vector<int> > g)
{

	for(int i = 0 ; i < MaxPopulacao; i++)
	{
		memset(removido, 0, sizeof removido);
		if(i < 10)
			populacao.push_back(heuristica(g,0.1));

		else if(i < 20)
			populacao.push_back(heuristica(g,0.2));
		else if(i < 30)
			populacao.push_back(heuristica(g,0.3));
		else if(i < 40)
			populacao.push_back(heuristica(g,0.4));
		else if(i < 50)
			populacao.push_back(heuristica(g,0.5));
		else if(i < 60)
			populacao.push_back(heuristica(g,0.6));
		else if(i < 70)
			populacao.push_back(heuristica(g,0.7));
		else if(i < 80)
			populacao.push_back(heuristica(g,0.8));
		else if(i < 90)
			populacao.push_back(heuristica(g,0.9));
		else 
			populacao.push_back(heuristica(g,0));
	}
}

int calcula(vector<int>solucao, vector<vector<int> >grafo)
{
	int treewidth = 0;

	
	for(int i = 0 ; i < solucao.size() ; i++)
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

int calcula2(vector<int>solucao,int x, int y, vector<vector<int> >grafo)
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

vector<pair<int,vector<int> > > cruzamentos(vector<pair<int,vector<int> > >antiga, vector<pair<int,vector<int> > > nova, vector<vector<int> >grafo)
{

	seed = rand()%avada;
 		

 	//Mersene Twister 
	std::mt19937 generator (seed);

	for(int i = 0 ; i < 70 ; i++)
	{
		std::uniform_int_distribution<int> dist(0, 24);
		pair<int, vector<int> >melhor = antiga[dist(generator)];

		std::uniform_int_distribution<int> dist2(25, 99);
		pair<int, vector<int> >pior = antiga[dist2(generator)];
  
		vector<int> mutante_s;
		for(int i = 0 ; i < melhor.second.size(); i++)
		{
			int a = melhor.second[i];
			int b = pior.second[i];

			if(a == b) mutante_s.push_back(a);
			else
			{
				std::uniform_int_distribution<int> dist3(0, 9);
				int x = dist(generator);
				if(x <= 6) mutante_s.push_back(a);
				else mutante_s.push_back(b);
			}
		}

		int mutante_v = calcula(mutante_s, grafo);
		//cout <<cnt++ << " "<< mutante_v << endl;
		nova.push_back(make_pair(mutante_v, mutante_s));
	}

	return nova;
}

pair<int,vector<int> > busca_local_first(vector<int> s, vector<vector<int> >g, int melhor)
{
	
	vector<int>cur;
	
	for(int i = 0 ; i < n ; i++)
	{
		cur.clear();
		for(int j = i + 1 ; j < n ; j++)
		{
			
			 int ans = calcula2(s,i,j,g);
			 
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
	return make_pair(melhor, s);
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

	arq = fopen("saidageneticoTTT.txt", "a");
	vector<vector<int> >grafo; //lista de adjacencias para representar o grafo
	//alocacao das listas para n vértices
	grafo.assign(n+1, vector<int>());
	
	vector<vector<int> > h;
	
	for(int i = 0 ; i < m; i++)
	{
		scanf("%d%d",&a,&b);

		//adiciona a aresta (a-b) no grafo
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		
	}
	auto start = chrono::steady_clock::now();
	geraPopulacaoInicial(grafo);
	sort(populacao.begin(), populacao.end());
	int geracao_atual = 0;

	while(geracao_atual < Geracoes)
	{
		

		vector<pair<int,vector<int> > >novapopulacao;

		for(int i = 0 ; i < 25; i++) novapopulacao.push_back(populacao[i]);
		for(int i = 99; i >= 95; i--) novapopulacao.push_back(populacao[i]);

		novapopulacao = cruzamentos(populacao, novapopulacao, grafo);
		populacao = novapopulacao;
		geracao_atual++;
		sort(populacao.begin(), populacao.end());
		if(populacao[0].first <= 30) break;
	}
	
    

	pair<int,vector<int> >ans = busca_local_first(populacao[0].second, grafo, populacao[0].first);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	printf("Melhor: %d\n", ans.first);
	fprintf(arq,"%f\n",chrono::duration <double, milli> (diff).count());


	return 0;
}
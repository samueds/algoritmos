#include <bits/stdc++.h>

using namespace std;

int n,m;
int l,k,x;
vector< vector<int> >g;
map<int, set<string> >mapa;

string gera(int qtd)
{
	string s = "";
	while(qtd--) s+="o";
	
	return s;
}

char troca(char s)
{
	if(s == 'x') return 'o';
	return 'x';
}

int main()
{
	scanf("%d%d",&n,&m);
	
	scanf("%d",&l);
	
	string procura = gera(m);
	
	for(int i = 0 ; i < l ; i++)
	{
		int x ; scanf("%d",&x);
		procura[x-1] = 'x';
	}
	
	g.assign(1003, vector<int>());
	
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&x);
			g[i].push_back(x-1);
		}
	}
	int passos = 0, inter = 0;
	string agora = gera(m);
	
	for(;;)
	{
		passos++;
		for(int i = 0 ; i < (int)g[inter].size(); i++)
		{
			int pos = g[inter][i];
			agora[pos] = troca(agora[pos]);
		}
		if(agora == procura) break;
		else if(mapa[inter].find(agora) != mapa[inter].end())
		{
			passos = -1; break;
		}
		else mapa[inter].insert(agora);
		
		inter++;
		inter%=n;
	}
	printf("%d\n", passos);
	
	
	return 0;
}

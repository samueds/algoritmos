#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,-1,1};

int n,m;
int mat[N][N];
int cor[N][N];
int mp[N][N];
int cont = 1;
int get(int x, int y)
{
	if(!mp[x][y])
		mp[x][y] = cont++;

	return mp[x][y];
}

int ans;

bool dentro(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}

int c[N];

int findset(int u)
{
	if(c[u] == u)
		return u;

	return c[u] = findset(c[u]);
}

void unionset(int a, int b)
{
	a = findset(a);
	b = findset(b);

	c[b] = a;
}

void doit(int x, int y)
{
	
	for(int i = 0 ; i < 8 ; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(dentro(xx,yy))
		{
			int foo = abs(mat[x][y] - mat[xx][yy]);
			if(foo <= 10)
			{
				
				int a = get(x,y);
				int b = get(xx,yy);
				if(findset(a) != findset(b))
				{
					unionset(a,b);
				}
			}
		}
	}
	
}
int main()
{
	scanf("%d%d",&n,&m);

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			scanf("%d", &mat[i][j]);
			c[get(i,j)] = get(i,j);
		}
	} 
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			doit(i,j);
		}
	}
	set<int>gandalf;

	for(int i = 1 ; i <= n*m ; i++) gandalf.insert(findset(i)); 
	
	printf("%d\n", (int)gandalf.size());
	return 0;
}
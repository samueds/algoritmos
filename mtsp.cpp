#include <bits/stdc++.h>

using namespace std;

const int oo = 0x3f3f3f3f;

int n,m;

struct point
{
	double x,y;
};

point casa[20],focos[20];

double dp[11][1<<12][6][1<<6];

double dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

double pd(int p, int vis, int atual, int used)
{
	if(__builtin_popcount(vis) == n) return dist(focos[p], casa[atual]);
	
	if(dp[p][vis][atual][used] != oo) return dp[p][vis][atual][used];
	
	double ans = 0x3f3f3f3f;
	
	/// retornar o amigo atual e ir pra um não usado
	for(int i = 0 ; i < m ; i++)
	{
		if(!(used >> i & 1))
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(j == p) continue;
				if(!(vis>>j & 1))
				{
					ans = min(ans, pd(j, vis | 1 << j , i, used | 1 << i) + dist(casa[atual], focos[p])+dist(casa[i], focos[j]));
				}
			}
		}
			
	}
	
	/// Continuar com o amigo
	
	for(int i = 0 ; i < n ; i++)
	{
		if(i == p) continue;
		if(!(vis>>i & 1))
		{
			ans = min(ans, pd(i, vis | 1 << i , atual, used) + dist(focos[p], focos[i]));
		}
	}
	
	return dp[p][vis][atual][used] = ans;
}

void zera()
{
	for(int i = 0 ; i < n; i++) for(int j = 0 ; j < 1 << n ; j++) 
	for(int k = 0 ; k < m ; k++) for(int a = 0 ; a < 1 << m ; a++) dp[i][j][k][a] = oo;
}

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%lf%lf",&casa[i].x, &casa[i].y);
	}
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%lf%lf",&focos[i].x, &focos[i].y);
	}
	
	double ans = 0x3f3f3f3f;
	zera();
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			
			ans = min(ans, pd(j,1 << j, i, 1 << i) + dist(casa[i], focos[j]));
		}
	}
	
	printf("%.2lf\n",ans);
	
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;
int tot = 0;
const int oo = 0x3f3f3f3f;

struct show
{
	int ini, fim, v, palco;


	bool operator < (const show& q) const
	{
		return ini < q.ini;
	}

}shows[1005];
int cnt;
int dp[1005][1 << 11 + 1];

int prox[1005];

int pd(int atual, int mask)
{
	if(atual == tot) return (__builtin_popcount(mask) == n) ? 0 : -oo;

	if(dp[atual][mask] != -1) return dp[atual][mask];

	int ans = pd(atual + 1, mask);

	int palco = shows[atual].palco;
	int v = shows[atual].v;

	if(prox[atual] != -1)
		ans = max(ans, pd(prox[atual], mask | (1 << palco)) + v);
	else
	{
		ans = max(ans, pd(tot, mask | (1 << palco)) + v);
	}

	return dp[atual][mask] = ans;

}

int main()
{
	memset(dp, -1, sizeof dp);
	memset(prox, -1, sizeof prox);
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; i++)
	{
		int x; scanf("%d",&x);
		tot += x;
		for(int j = 0 ; j < x ; j++)
		{
			int a,b,c; scanf("%d%d%d",&a,&b,&c);
			shows[cnt++] = {a,b,c,i};
		}
	}
	sort(shows, shows + tot);

	for(int i = 0 ; i < tot ; i++)
	{
		for(int j = i + 1 ; j < tot ; j++)
		{
			if(shows[i].fim <= shows[j].ini)
			{
				prox[i] = j;
				break;
			}
		}
	}

	int ans = pd(0,0);
	if(ans < 0) printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}

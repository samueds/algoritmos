#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 * 2 + 5; 

int n,m;
int v1[N],v2[N];

int main()
{
	scanf("%d%d",&n,&m);

	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d", v1 + i);
	}
	for(int i = 0 ; i < m ; i++) scanf("%d", v2 + i);

	map<int,int>mp;
	int x = 0;
	int ans = 0;

	while((n-x) >= m) 
	{
		int cont = 0;
		mp.clear();
		for(int i = x ; i < m + x ; i++)
		{
			mp[v1[i] - v2[cont++]] = 1;
		}
		if(mp.size() == 1) ans++;
		x++;
	}
	printf("%d\n", ans);

	return 0;
}
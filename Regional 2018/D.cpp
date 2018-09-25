#include <bits/stdc++.h>

using namespace std;


int n;

int main()
{
	scanf("%d",&n);
	int ans = 0;
	while(n--)
	{
		int x; scanf("%d",&x);
		ans += (x != 1);
	}

	printf("%d\n",ans);

	return 0;
}
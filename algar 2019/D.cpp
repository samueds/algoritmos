#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n;
int vet[N];
int divi, tot;
int dp[2][N*20][N*20];	


int main()
{
	scanf("%d",&n);

	for(int i = 1 ; i <= n ; i++) scanf("%d", vet + i);

	memset(dp, 0, sizeof dp);

	tot = accumulate(vet+1, vet+n+1, 0);
	divi = tot/3;
	
	if(tot%3 != 0)
	{
		printf("NAO\n");
		return 0;
	}
	
	dp[0][0][0] = 1;
			
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= divi ; j++)
		{
			for (int k = 0 ; k <= divi ; k++)
			{
					
					dp[i&1][j][k] |= dp[!(i&1)][j][k];
					if((j - vet[i]) >= 0)
						dp[i&1][j][k] |= dp[!(i&1)][j - vet[i]][k];
					
					if((k - vet[i]) >= 0)
						dp[i&1][j][k] |= dp[!(i&1)][j][k - vet[i]];

					//cout << dp[i&1][j][k] << endl;
			}
		}
	}
	
	printf("%s\n", dp[n&1][divi][divi] ? "SIM" : "NAO");

	return 0;
}
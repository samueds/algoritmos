#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int vet[N];
int divi, tot;
int dp[N][N*20][N*20];	

int pd(int pos, int s1, int s2)
{

	if(pos == n)
		return s1 == divi && s2 == divi && (tot - (s1 + s2)) == divi;

	if(dp[pos][s1][s2] != -1) return dp[pos][s1][s2];

	int ans = 0;
	
	if((s1 + vet[pos]) <= divi)
		ans |= pd(pos+1, s1 + vet[pos], s2);
	
	if((s2 + vet[pos]) <= divi)
		ans |= pd(pos+1, s1, s2 + vet[pos]);
	
	ans |= pd(pos+1, s1, s2);

	return dp[pos][s1][s2] = ans;
}

int main()
{
	scanf("%d",&n);

	for(int i = 0 ; i < n ; i++) scanf("%d", vet + i);

	memset(dp, -1, sizeof dp);

	tot = accumulate(vet, vet+n, 0);
	divi = tot/3;
	
	printf("%s\n", pd(0, 0, 0) ? "SIM" : "NAO");

	return 0;
}
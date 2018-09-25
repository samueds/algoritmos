#include <bits/stdc++.h>

using namespace std;

const int win = 1000;

int grid[101][101];

int n;

int calculaMex(int a, int b)
{
	int set[1001]; memset(set,0,sizeof set);
	for(int i = 0 ; i < a ; i++)
		set[grid[i][b]] = 1;
	for(int i = 0 ; i < b ; i++)
		set[grid[a][i]] = 1;
		
	int menor = min(a,b);
	
	for(int i = 1; i <= menor; i++)
            	set[grid[a - i][b - i]] = 1;

        for(int i = 0; i < 1000; i++)
            if(!set[i])
                return i;
}

int main()
{
	
	grid[0][0] = win;
	
	for(int i = 0 ; i <= 100 ; i++)
	{
		grid[i][0] = win;
		grid[0][i] = win;
		grid[i][i] = win;
	}
	
	for(int i = 1; i <= 100; i++)
	{
	        for(int j = 1; j <= 100; j++)
	        {
	            if(i != j)
	                grid[i][j] = calculaMex(i, j);
	        }
	}
	
	scanf("%d",&n);
	
	int ans = 0;
	
	while(n--)
	{
		int a,b; scanf("%d%d",&a,&b);
		ans ^= grid[a][b];
	}
	
	if(ans) printf("Y\n");
	else printf("N\n");
	return 0;
}

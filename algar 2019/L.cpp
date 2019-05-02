#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,k;
int q;

struct Matrix
{
	ll mat[25][25];

	Matrix operator +(const Matrix &q) const
	{
		Matrix x;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				x.mat[i][j]  = mat[i][j] + q.mat[i][j];
			}
		}

		return x;
	}
	void show()
	{
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
				printf("%d ", mat[i][j]);

			cout << endl;
		}
	}
};


Matrix matMul(Matrix a, Matrix b) 
{ 
	Matrix ans; int i, j, k;
	for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (ans.mat[i][j] = k = 0; k < n; k++)
            {

                ans.mat[i][j] += ((a.mat[i][k] * b.mat[k][j]));
            }
        }
            
    }		 
	return ans; 
}

Matrix matPow(Matrix base, int p)
{

	Matrix ans; int i, j;
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++)
			ans.mat[i][j] = (i == j); 
	while (p)
	{ 
		if (p & 1)
			ans = matMul(ans, base);			
	
		base = matMul(base, base);


		p >>= 1;
	}

	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	Matrix foo;
	memset(foo.mat, 0, sizeof foo.mat);
	for(int i = 0 ; i < m ; i++)
	{	
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		foo.mat[a][b] = c;
		foo.mat[b][a] = c;
	}
	Matrix ans = foo;
	scanf("%d",&q);
	for(int i = 2; i<= k ; i++)
	{
		ans = ans + matPow(foo, i);
		//ans.show();
	}
	while(q--)
	{
		int a,b; scanf("%d%d",&a,&b);
		a--;b--;
		printf("%d\n", ans.mat[a][b]);
	}

	return 0;
}
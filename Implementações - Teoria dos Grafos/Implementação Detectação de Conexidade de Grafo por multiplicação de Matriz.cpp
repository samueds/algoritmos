#include <bits/stdc++.h>

using namespace std;

int N;


struct Matrix
{
	int mat[105][105];

	Matrix operator + (const Matrix& q) const
	{
		Matrix w;
		for(int i = 0 ; i < N ; i++)
		{
			for(int j = 0 ; j < N; j++)
				w.mat[i][j] = mat[i][j] + q.mat[i][j];
		}

		return w;
	}
};

Matrix matMul(Matrix a, Matrix b) 
{ 
	Matrix ans;
	int k;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (ans.mat[i][j] = k = 0; k < N; k++)
					ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);
	return ans; 
}

int main()
{

	cin >> N;


	Matrix x;
	for(int i = 0 ; i < N ; i++)
	{
		for(int j = 0 ; j < N ; j++)scanf("%d",&x.mat[i][j]);
	}

	Matrix q = x;
	Matrix ans = x;
	for(int l = 2 ; l< N ; l++)
	{
		q = matMul(x,q);

		ans = ans + q;
	}

	bool conexo = true;
	for(int i = 0 ; i < N; i++)
	{
		for(int j = 0 ; j < N; j++)
		{
			if(i != j && !ans.mat[i][j])
			{
				conexo = false;
				goto fim;
			}
		}
	}
	fim:
	if(conexo)
		printf("Grafo conexo!\n");
	else
		printf("Grafo nao conexo!\n");

}
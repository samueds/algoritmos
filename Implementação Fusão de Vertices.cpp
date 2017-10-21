#include <bits/stdc++.h>

using namespace std;

int n; // numero de vertices

struct Matrix
{
    int mat[105][105];

    Matrix operator += (const Matrix& q) const
    {
        Matrix w;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n; j++)
                w.mat[i][j] = mat[i][j] + q.mat[i][j];
        }

        return w;
    }
};

void fusao(Matrix x)
{
    int tem = 1;
    while(tem && n)
    {
        // Transformando em grafo simples
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == j)
                   x.mat[i][j] = 0;
                else if(x.mat[i][j] > 1)
                   x.mat[i][j] = 1;
            }
        }
        
        // Procurando adjacencia para que seja possivel fundir os vertices
        tem = 0;

        int va,vb;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(x.mat[i][j])
                {
                    tem = 1;
                    va = i;
                    vb = j;
                    goto vai;
                }
            }
        }
        vai:
        // fusao
        if(!tem)
            break;
        Matrix nova;

        for(int i = 0 ; i < n ; i++)
        {
            x.mat[va][i] += x.mat[vb][i];
        }
        for(int i = 0 ; i < n ; i++)
        {
            x.mat[i][va] += x.mat[i][vb];
        }
        int p,q;
        for(int i = 0 , p = 0; i < n ; i++, p++)
        {
            if(i == vb)
            {
                p--;
                continue;
            }
            for(int j = 0 ,q = 0; j < n ; j++, q++)
            {
                if(j == vb)
                {
                    q--;
                    continue;
                }
                nova.mat[p][q] = x.mat[i][j];
            }
        }
        n--;
        x = nova;
    }

    if(n == 1)
        printf("Grafo conexo!\n");
    else
        printf("Grafo nao conexo | %d componentes!\n", n);
}

int main()
{
    cin >> n;
    
    Matrix x;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < n ; j++) cin >> x.mat[i][j];
    }
    
    fusao(x);
}
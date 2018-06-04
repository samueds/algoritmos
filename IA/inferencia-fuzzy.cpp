#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

double X[N],Y[N];
double sinalA;

double A[N], Alinha[N];
double B[N], Blinha[N];
double Mamdani[N][N];
int x,y;
void max_min()
{
    double max_min[1][y];
    for(int i = 0 ; i < 1 ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            double maior = -0x3f3f3f3f;
            for(int k = 0 ; k < x ; k++)
            {
                maior = max(maior,min(Alinha[k], Mamdani[k][j]));
            }
            B[j] = maior;
        }
    }
    printf("\n\nB'\n\n");

        for(int j = 0 ; j < y ; j++)
        {
            printf("%.2lf ", B[j]);
        }
        printf("\n");

}

int main()
{

    printf("Digite o tamanho do universo de discuros de X:\n");
    scanf("%d",&x);
    printf("Digite o universo de discurso de X:\n");
    for(int i = 0 ; i < x ; i++) scanf("%lf", X + i);

    printf("Digite o tamanho do universo de discuros de Y:\n");
    scanf("%d",&y);
    printf("Digite o universo de discurso de Y:\n");
    for(int i = 0 ; i < y ; i++) scanf("%lf", Y + i);

    printf("Digite o sinal de A':\n");
    scanf("%lf",&sinalA);

    double aux = 1.0/((x/2)+1);
    double acum = 0;
    for(int i = 0 ; i < x ; i++)
    {

       if(i >= ((x/2)+1))
          acum -= aux;
       else
          acum += aux;
        A[i] = acum;
       printf("%lf - > %lf\n",X[i],A[i]);
    }
    cout << "\n\n";
    aux = 1.0/((y/2)+1);
    acum = 0;
    for(int i = 0 ; i < y ; i++)
    {
        if(i >= ((y/2)+1))
          acum -= aux;
       else
          acum += aux;
       B[i] = acum;
      // cout << i << " " << ((y/2)+1) << endl;


       printf("%lf - > %lf\n",Y[i],B[i]);
    }

    /// Fazendo o Min de Mandani de A -> B
    for(int i = 0 ; i < x ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            Mamdani[i][j] = min(A[i],B[j]);
            cout << Mamdani[i][j] << " ";
        }
        cout << endl;
    }

    /// Preenchendo o A'
    for(int i = 0 ; i < x ; i++)
    {
        //cout << X[i] << " " << sinalA << endl;
        Alinha[i] = double(X[i] == sinalA);
        printf("%lf ", Alinha[i]);
    }
    cout << "\n";
    max_min();

    return 0;
}

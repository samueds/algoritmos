#include <bits/stdc++.h>

using namespace std;

int n,m;
int x,y;

void max_min(double a[10][5], double b[5][15])
{
    double max_min[n][y];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            double maior = -0x3f3f3f3f;
            for(int k = 0 ; k < x ; k++)
            {
                maior = max(maior,min(a[i][k], b[k][j]));
            }
            max_min[i][j] = maior;
        }
    }
    printf("\t\t\tComposicao Max_Min\n\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            printf("%.2lf ", max_min[i][j]);
        }
        printf("\n");
    }
}

void max_prod(double a[10][5], double b[5][15])
{
    double max_min[n][y];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            double maior = -0x3f3f3f3f;
            for(int k = 0 ; k < x ; k++)
            {
                maior = max(maior,a[i][k]* b[k][j]);
            }
            max_min[i][j] = maior;
        }
    }
    printf("\t\t\tComposicao Max_Prod\n\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            printf("%.2lf ", max_min[i][j]);
        }
        printf("\n");
    }
}

void max_media(double a[10][5], double b[5][15])
{
    double max_min[n][y];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            double maior = -0x3f3f3f3f;
            for(int k = 0 ; k < x ; k++)
            {
                maior = max(maior,(a[i][k]+ b[k][j])/2);
            }
            max_min[i][j] = maior;
        }
    }
    printf("\t\t\tComposicao Max_Media\n\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < y ; j++)
        {
            printf("%.2lf ", max_min[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    n = 10;
    m = 5;
    
    x = 5;
    y = 15;
    double R[10][5] = {{0.58, 0.54, 0.40, 0.70, 0.35}, 
                       {0.54, 0.65, 0.45, 0.09, 0.15},
                       {0.87, 0.54, 0.37, 0.53, 0.59},
                       {0.26, 0.72, 0.76, 0.53, 0.26},
                       {0.32, 0.52, 0.63, 0.86, 0.04},
                       {0.12, 0.99, 0.77, 0.48, 0.75},
                       {0.94, 0.22, 0.93, 0.39, 0.24},
                       {0.65, 0.11, 0.97, 0.67, 0.44},
                       {0.48, 0.11, 0.19, 0.74, 0.69},
                       {0.64, 0.06, 0.14, 0.52, 0.36}
                      };
    double S[5][15] = {{0.74, 0.02, 0.82, 0.40, 0.79, 0.83, 0.51, 0.41, 0.53, 0.50, 0.85, 0.82, 0.61, 0.23, 0.74},
                       {0.39, 0.33, 0.43, 0.81, 0.95, 0.77, 0.88, 0.75, 0.09, 0.19, 0.56, 0.88, 0.99, 0.50, 0.59},
                       {0.68, 0.42, 0.89, 0.76, 0.33, 0.17, 0.59, 0.83, 0.11, 0.50, 0.93, 0.99, 0.53, 0.90, 0.25},
                       {0.70, 0.27, 0.39, 0.38, 0.67, 0.86, 0.15, 0.79, 0.14, 0.15, 0.70, 0.00, 0.48, 0.57, 0.67},
                       {0.44, 0.20, 0.77, 0.22, 0.44, 0.99, 0.20, 0.32, 0.68, 0.05, 0.58, 0.87, 0.80, 0.85, 0.08}
                      };
    
    printf("\n\n");
    max_min(R,S);
    printf("\n\n");
    max_prod(R,S);
    printf("\n\n");
    max_media(R,S);
    return 0;
}
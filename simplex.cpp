///Metodo Simplex
//Autor : Samuel Eduardo da Silva 
//E-mail : samueleduardo1609@hotmail.com

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

///Constantes
const int N = 1005; // numero limite para numero de variaveis
const int M = 1005; // numero limite para o numero de inequações
const double oo = 0x3f3f3f3f; // simboliza um valor muito alto (infinito)

///Variaveis globais

int var; // Numero de variaveis
int ine; // Numero de inequações
double objetivo[N]; // Vetor com os coeficientes da função objetivo
double inequacoes[M][N+1]; // Matriz com as inequações obs N + 1 pois são N variaveis + 1 valor que é o resultado da inequação
double matSimplex[M+1][N+M+2];// Matriz usada pra resolver usando o metodo
/// M + 1 pois são M inequaçoes mais a função objetivo para linhas
/// N + M + 2 pois são M inequações + N variaveis de folga + 1 coluna pro Z e + uma coluna pro 'b'

int linhas,colunas; // variaveis para delimitar a matriz do metodo

void mostraMatriz(int q)
{
	if(!q)
	{
		system("cls");
		printf("Mostrando matriz do metodo:\n");
	}
	else
	{
		printf("\n");
		printf("Mostrando matriz do metodo apos a iteracao %d:\n\n",q);
	}
	for(int i = 0 ; i < linhas; i++)
	{
		for(int j = 0 ; j < colunas ; j++)
		{
						
			printf("%*.4lf ",7,matSimplex[i][j]);
		}
		cout << endl;
	}
	printf("Digite qualquer tecla para continuar...\n");
	getch();
	
}
void simplex()
{
	int iter = 0;
	//Looping para continuar o método até não haver elementos negativos na primeira linha
	while(1)
	{

		///Procurando o numero mais negativo
		iter++;
		double maisNegativo = oo;
		int colunaMaisNegativa;
		for(int i = 0 ; i < colunas ; i++)
		{
			if(matSimplex[0][i] < maisNegativo)
			{
				maisNegativo = matSimplex[0][i];
				colunaMaisNegativa = i;
			}
		}
		if(maisNegativo >= 0)
		{
			printf("Fim do metodo!");
			printf("\n\n----Solucao----\n");
			printf("Variaveis Basicas:\n");
			vector<int>naoBasicas;
			for(int i = 1 ; i < colunas-1; i++)
			{
				int flag = 0;
				int aux;
				for(int j = 0 ; j < linhas; j++)
				{
					if(flag)
					{
						if(matSimplex[j][i] != 0)
						{

							naoBasicas.push_back(i);
							goto hell;
						}
							
					}
					else if(matSimplex[j][i] == 1)
					{
						flag = 1;
						aux = j;
					}
					else if(matSimplex[j][i] != 0)
					{
						
						naoBasicas.push_back(i);
						goto hell;
					}
						
				}
				
				if(i <= var)
					printf("x%d = %.4lf\n",i,matSimplex[aux][colunas-1]);
				else
					printf("xF%d = %.4lf\n",i- var, matSimplex[aux][colunas-1] );
				hell:;
			}
			printf("\nVariaveis nao Basicas:\n");
			for(int i = 0 ; i < naoBasicas.size() ; i++)
			{
				if(naoBasicas[i] <= var)
					printf("x%d = 0\n",naoBasicas[i]);
				else
					printf("xF%d = 0\n",naoBasicas[i] - var);
			}

			printf("\nValor de Z = %.4lf !\n\n", matSimplex[0][colunas-1]);

			return;
		}
		/// Identificando a linha que sai e sera a pivo
		double menorPositivo = oo;
		int linhaPivo;
		for(int i = 1 ; i < linhas ; i++)
		{
			if(matSimplex[i][colunaMaisNegativa] == 0)
				continue;
			double aux = matSimplex[i][colunas-1] / matSimplex[i][colunaMaisNegativa];
			
			if(aux > 0 && aux < menorPositivo)
			{
				menorPositivo = aux;
				linhaPivo = i;
			}
		}
		double ElementoPivo = matSimplex[linhaPivo][colunaMaisNegativa];
		// calculando a nova linha pivo
		for(int i = 0 ; i < colunas; i++)
			matSimplex[linhaPivo][i]/=ElementoPivo;

		//Calculando as novas linhas

		for(int i = 0 ; i < linhas ; i++)
		{
			if(linhaPivo == i)
				continue;
			double opost = -matSimplex[i][colunaMaisNegativa];
			for(int j = 0 ; j < colunas; j++)
			{
				
				matSimplex[i][j] += (matSimplex[linhaPivo][j]*opost);
			}
		}
		mostraMatriz(iter);
	}
}


int main()
{
	system("cls");
	printf("----Metodo Simplex----\n");
	printf("Digite o numero de variaveis: ");
	cin >> var;

	printf("Digite a funcao objetivo:\n");

	for(int i = 0 ; i < var ; i++)
	{
		printf("x%d = ",i+1);
		double x;

		cin >> x;
		objetivo[i] = x;
	}

	printf("Digite o numero de inequacoes: ");
	cin >> ine;

	for(int i = 0 ; i < ine ; i++)
	{

		printf("Inequacao %d\n",i+1);
		for(int j = 0 ; j <= var ; j++)
		{
			if(j != var)
				printf("x%d = ",j+1);
			else
				printf("<= ");
			cin >> inequacoes[i][j];
		}
	}


	system("cls");

	printf("Montando a Matriz Simplex:\n");

	matSimplex[0][0] = 1;
	int i;
	for(i = 1 ; i <= var ; i++)
		matSimplex[0][i] = -(objetivo[i-1]);
	for(; i <= var+ine+1; i++)
	    matSimplex[0][i] = 0;

	for(int i = 1 ; i <= ine ; i++)
		matSimplex[i][0] = 0;
	int aux = 0;
	for(int i = 1 ; i <= ine ; i++)
	{
		for(int j = 1 ; j < ine + var + 2 ; j++)
		{
			if(j <= var)
				matSimplex[i][j] = inequacoes[i-1][j-1];
			else if(j == var + 1 + aux)
				matSimplex[i][j] = 1;	
			else if(j != var + 1 + ine)
				matSimplex[i][j] = 0;
			else
				matSimplex[i][j] = inequacoes[i-1][var];	
		}
		aux++;
	}
	linhas = ine+1;
	colunas = var + ine + 2;
	printf("\n\nDigite qualquer tecla para continuar...\n");
	getch();
	mostraMatriz(0);
	system("cls");
	printf("Iniciando o metodo!\n");
	simplex();



}
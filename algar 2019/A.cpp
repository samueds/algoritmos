#include <bits/stdc++.h>

using namespace std;

long long t;
int n;
char s[10005];

int main()
{
	scanf("%d",&n);

	while(n--)
	{
		cin >> t;
		getchar();
		scanf("%[^\n]", s);

		int tam = strlen(s);
		string aux = s;
		for(int i = 0 ; i < tam ; i++)
		{
			int x = t%tam;
			int novo = i - x;
			if(novo < 0)
				novo += tam;
			s[novo] = aux[i];
		}
		printf("%s\n",s);
	}

	return 0;
}
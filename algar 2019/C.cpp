#include <bits/stdc++.h>

using namespace std;

set<string>s;
int n;
string x;


int main()
{
	scanf("%d",&n);

	for(int i = 0 ; i < n ; i++)
	{
		cin >> x;
		s.insert(x);
	}
	if(s.size() == n) printf("A funcao eh boa.\n");
	else printf("A funcao nao eh boa.\n");
	return 0;
}
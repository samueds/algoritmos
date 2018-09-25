#include <bits/stdc++.h>

using namespace std;

string a,b;

int main()
{
	cin >> a >> b;
	int dif = a.size() - b.size();
	int ans = 0;
	for(int i = 0 ; i <= dif; i++)
	{
		bool pegou = false;
		for(int j = 0 ; j < b.size(); j++)
		{
			if(a[j + i] == b[j])
			{
				pegou = true;
				break;
			}
		}
		if(!pegou) ans++;
	}
	printf("%d\n",ans);

	return 0;
}

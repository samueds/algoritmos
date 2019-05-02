#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 * 2 + 5; 
const int oo = 0x3f3f3f3f;
int n,m;


vector<int> z_function(vector<int> v1)
{
   
   	int n = (int)v1.size();
   
    vector<int> z(n,0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && v1[z[i]] == v1[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int v1[N],v2[N];
int v11[N], v22[N];
int main()
{
	scanf("%d%d",&n,&m);
	int aa=0;
	for(int i = 0 ; i < n ; i++)
	{

		scanf("%d", v1 + i);
		
		if(i > 0)
			v11[aa++] = v1[i] - v1[i-1];
		

	}
	aa=0;
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%d", v2 + i);
		if(i > 0)
		{
			v22[aa++] = v2[i] - v2[i-1];
			
		}
		
	}

	int ans = 0;
	if(m == 1)
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(v1[i] == v2[0]) ans++;
		}
	}
	else
	{
		vector<int> a(v22, v22 + (m-1));
		a.push_back(oo);
		a.insert(a.end(), v11, v11 + (n-1));
		
		
		vector<int> z = z_function(a);
		for(int i = 0 ; i < z.size(); i++)
		{
			
			if(z[i] == m-1)ans++;
		}
	}
	

	printf("%d\n", ans);

	return 0;
}
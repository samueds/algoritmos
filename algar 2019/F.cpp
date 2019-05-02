#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int n,m;
struct event
{
	int a,b,v;

	bool operator <(const event &q) const
	{
		if(a == q.a) return b < q.b;
		return a < q.b;
	}
}events[N];


int main()
{
	scanf("%d%d",&n,&m);


	for(int i = 0 ; i < m ; i++)
	{
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		events[i] = {a,b,c};
	}

	sort(events, events + m);

	int ult = events[0].a;

	for(int i = 0 ; i < m-1 ; i++)
	{
		if(ult < events[i+1].a) ult = events[i+1].a;
		else if(events[i].v == events[i+1].v || 
			((events[i].v & events[i+1].v) == events[i+1].v && events[i].b < events[i+1].b))
		 	ult = min(events[i].b+1,events[i+1].b);
		else
		{
			printf("NAO\n");
			return 0;
		}
	}
	printf("SIM\n");

	return 0;
}
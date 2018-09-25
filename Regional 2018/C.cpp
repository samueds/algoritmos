#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
long long h, v;
int seilapraquetemX, seilapraquetemY;
vector<pair<int, int> > horizontais, verticais;
typedef tree<int,null_type,greater<int>,rb_tree_tag, tree_order_statistics_node_update> arvoreTop;

int main()
{
    scanf("%d%d",&seilapraquetemX, &seilapraquetemY);
    scanf("%lld%lld",&h,&v);
    
    for(int i = 0 ; i < h ; i++)
    {
    	int a,b; scanf("%d%d",&a,&b);
    	horizontais.push_back(make_pair(a,b));
    }
    sort(horizontais.begin(), horizontais.end());
    for(int i = 0 ; i < v ; i++)
    {
    	int a,b; scanf("%d%d",&a,&b);
    	verticais.push_back(make_pair(a,b));
    }
    sort(verticais.begin(), verticais.end());
    long long ans = (h + 1) * (v + 1);
    arvoreTop treeh, treev;
    for(int i = 0 ; i < h ; i++)
    {
        int x = horizontais[i].second;
        ans += treeh.order_of_key(x);
        treeh.insert(x);
    }
    for(int i = 0 ; i < v ; i++)
    {
        int x = verticais[i].second;
        ans += treev.order_of_key(x);
        treev.insert(x);
    }
    printf("%lld\n",ans);
}

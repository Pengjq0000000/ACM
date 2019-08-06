#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n;
long long ans1,ans2;
struct entity
{
	int in;
	int out;
	int cost;
	int id;
}e[1005],e2[1005];
bool cmp1(entity a,entity b)
{
	return a.out>b.out;
}
bool cmp2(entity a,entity b)
{
	return a.cost>b.cost;
}
bool vis[1005];
int main()
{
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&e[i].out,&e[i].in,&e[i].cost); e[i].id=i;
		e2[i]=e[i];
		ans1+=(long long)e[i].in*e[i].cost;
	}
	sort(e+1,e+1+n,cmp1);
	sort(e2+1,e2+1+n,cmp2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[e2[j].id]) continue;
			if(e[i].out<e2[j].in)
			{
				ans2+=(long long)e[i].out*e2[j].cost;
				vis[e2[j].id]=1;
				break;
			}
		}
	}
	printf("%lld",ans1-ans2);
	return 0;
}



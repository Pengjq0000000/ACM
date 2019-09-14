#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
struct edge
{
	int to,next,w;
}e[20005];
int cnt;
int head[10005];
void ins(int u,int v,int w)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
ll dp[10005][3];
ll num[10005][3];
ll t1[10005][3];
ll t2[10005][3];
ll ans[3];
void dfs(int u,int fa)
{
	for(int x=0;x<3;x++)
		dp[u][x]=num[u][x]=t1[u][x]=t2[u][x]=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		int w=e[i].w;
		if(v==fa) continue;
		dfs(v,u);
		for(int x=0;x<3;x++)
		{
			t1[v][(x+w)%3]=MOD(dp[v][x]+num[v][x]*w);
			t2[v][(x+w)%3]=num[v][x];
		}
		t1[v][w%3]=MOD(t1[v][w%3]+w);
		t2[v][w%3]=MOD(t2[v][w%3]+1);
		for(int x=0;x<3;x++)
			dp[u][x]=MOD(dp[u][x]+t1[v][x]),num[u][x]=MOD(num[u][x]+t2[v][x]);
	}
	for(int x=0;x<3;x++)
		ans[x]=MOD(ans[x]+dp[u][x]);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		for(int x=0;x<3;x++)
			for(int y=0;y<3;y++)
				ans[(x+y)%3]=MOD(ans[(x+y)%3]+t1[v][x]*(num[u][y]-t2[v][y]));
	}
}
void ini()
{
	cnt=0;
	for(int i=0;i<=n;i++)
		head[i]=0;
	for(int x=0;x<3;x++)
		ans[x]=0;
}
int main()
{
	while(~scanf("%d",&n))
	{
		ini();
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			ins(u,v,w); ins(v,u,w);
		}
		dfs(0,-1);
		for(int i=0;i<3;i++)
		{
			printf("%lld",MOD(ans[i]*2));
			if(i==2) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}



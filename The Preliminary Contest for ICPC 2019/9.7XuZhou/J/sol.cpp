#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
using namespace std;
int n,m;
struct edge
{
	int to,next;
}e[2000005];
int cnt;
int head[1000005];
void ins(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
ll ksm(ll x,ll a)
{
	ll b=1;
	while(a)
	{
		if(a&1) b=MOD(b*x);
		x=MOD(x*x);
		a>>=1;
	}
	return b;
}
ll inv(ll x)
{
	return ksm(x,mod-2);
}
ll dp[1000005];
int dep[1000005];
int son[1000005];
int maxd;
void dfs1(int u,int fa,int depth)
{
	dep[u]=depth;
	maxd=max(maxd,dep[u]);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		son[u]++;
		dfs1(v,u,depth+1);
	}
}
void dfs2(int u,int fa)
{
	if(!son[u])
	{
		if(dep[u]==maxd) dp[u]=0;
		else dp[u]=1;
		return;
	}
	ll sum=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs2(v,u);
		sum=MOD(sum+dp[v]);
	}
	ll p=MOD(sum*inv(son[u]));
	dp[u]=ksm(p,son[u]);
}
ll cal(ll x)
{
	return MOD(1+mod-x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ins(u,v);
		ins(v,u);
	}
	dfs1(1,0,1);
	dfs2(1,0);
	printf("%lld",cal(dp[1]));
	return 0;
}


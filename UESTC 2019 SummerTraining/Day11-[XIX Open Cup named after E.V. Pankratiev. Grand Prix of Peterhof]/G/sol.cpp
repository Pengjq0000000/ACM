#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int n;
struct edge
{
    int to,next;
}e[100005];
int cnt;
int head[100005];
void ins(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int dp[100005];
int f[100005];
int fid[100005];
int s[100005];
int sid[100005];
void dfs(int u)
{
    if(head[u]==0)
    {
        dp[u]=-1000000;
        return;
    }
    int num=0;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        dfs(v);
        if(dp[v]==-1000000) num++;
        else dp[u]+=dp[v];
    }
    dp[u]=dp[u]+num-1;
    dp[u]=max(dp[u],0);
}
void print(int x)
{
    printf("%d\n",x);
    exit(0);
}
void dfs2(int u)
{
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(dp[v]==-1000000)
            print(v);
    }
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(dp[v]>0)
            dfs2(v);
    }
}
void dfs3(int u)
{
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(dp[v]==-1000000)
            print(v);
    }
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        dfs3(v);
    }
}
int main()
{
	scanf("%d",&n);
    for(int v=2,u;v<=n;v++)
    {
        scanf("%d",&u);
        ins(u,v);
    }
    dfs(1);
    //for(int i=1;i<=n;i++)
    //    printf("%d %d\n",i,dp[i]);
    if(dp[1]>0)
    {
        printf("SECOND\n");
        return 0;
    }
    else if(dp[1]==0)
        printf("FIRST\n"),dfs2(1);
    dfs3(1);
	return 0;
}

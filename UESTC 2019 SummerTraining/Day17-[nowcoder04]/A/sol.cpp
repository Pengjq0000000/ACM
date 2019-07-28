#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
struct edge
{
    int to,next,w;
}e[200005];
int cnt;
int head[100005];
void ins(int u,int v,int w)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int keyy[100005];
int f[100005];
int fi[100005];
int s[100005];
int si[100005];
int fa[100005];
int ans[100005];
int fff[100005];
int out[100005];
int vis[100005];
void dfs(int x,int y)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==y) continue;
        out[x]++;
        fff[v]=x;
        dfs(v,x);
    }
}
void del(int x)
{
    if(keyy[x]==0)
    {
        vis[x]=1;
        if(fff[x]==0) return;
        out[fff[x]]--;
        if(out[fff[x]]==0) del(fff[x]);
    }
}
void dfs1(int x,int y)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==y) continue;
        if(vis[v]) continue;
        dfs1(v,x);
        if(f[v]+e[i].w>f[x])
        {
            s[x]=f[x];
            si[x]=fi[x];
            f[x]=f[v]+e[i].w;
            fi[x]=v;
        }
        else if(f[v]+e[i].w>s[x])
        {
            s[x]=f[v]+e[i].w;
            si[x]=v;
        }
    }
}
void dfs2(int x,int y)
{
    ans[x]=max(f[x],fa[x]);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==y) continue;
        if(vis[v]) continue;
        if(fi[x]==v) fa[v]=max(s[x],fa[x])+e[i].w;
        else fa[v]=max(f[x],fa[x])+e[i].w;
        dfs2(v,x);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    {
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d",&u,&v);
            ins(u,v,1);
            ins(v,u,1);
        }
        int k;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&k);
            keyy[k]=1;
        }
        dfs(k,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            if(out[i]==0) del(i);
        }
        dfs1(k,0);
        dfs2(k,0);
        int minn=n+10;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            minn=min(minn,ans[i]);
        }
        if(minn==n+10) minn=0;
        printf("%d\n",minn);
    }
    return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)
#define pb push_back

using namespace std;
const int maxn = 2e5+7;
vector<int> p[maxn],E[maxn];
int a[maxn],b[maxn],vis[maxn][8],dis[maxn][8];
int ans=0,n;
int maxdep,st;

int getpos(int u,int x)
{
    return lower_bound(p[u].begin(),p[u].end(),x)-p[u].begin();
}

void dfs(int u,int x,int deep)
{
    if (deep>maxdep)
    {
        maxdep=deep;st=u;
    }
    vis[u][getpos(u,x)]++; // 0->1
    for (int i=0;i<E[u].size();i++)
    {
        int v=E[u][i];
        if (b[v]%x==0 && vis[v][getpos(v,x)]==0)
        {
            dfs(v,x,deep+1);
        }
    }
}

void DFS(int u,int x,int deep)
{
    maxdep=max(maxdep,deep);
    vis[u][getpos(u,x)]++; // 1->2
    for (int i=0;i<E[u].size();i++)
    {
        int v=E[u][i];
        if (b[v]%x==0 && vis[v][getpos(v,x)]==1)
        {
            DFS(v,x,deep+1);
        }
    }
}

void deal(int u,int x)
{
    maxdep=st=0;
    dfs(u,x,1);
    maxdep=0;
    DFS(st,x,1);
    ans=max(ans,maxdep);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);b[i]=a[i]; 
        for (int d=2;d*d<=a[i];d++)
        {
            if (a[i]%d==0)
            {
                p[i].pb(d);
                while (a[i]%d==0) a[i]/=d;
            }
        }
        if (a[i]>1) p[i].pb(a[i]);
    }
    for (int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        E[u].pb(v);E[v].pb(u);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<p[i].size();j++)
        {
            if (!vis[i][j]) deal(i,p[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

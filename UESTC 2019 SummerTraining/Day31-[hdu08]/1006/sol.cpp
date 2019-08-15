#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LL long long
#define inf (long long)(1e16)
#define int long long
using namespace std;
int n,m;
int T;
LL a[100005];
LL b[100005];
LL c[100005];
LL d[100005];
LL f[100005][2];
LL fid[100005][2];
LL s[100005][2];
LL fa[100005][2];
int r;
struct edge
{
    int to,next;
}e[200005];
int cnt;
int head[100005];
void ins(int u,int v)
{
    d[v]++;
    cnt++;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int x,int u,int pre)
{
    int y=(x^1);
    fid[u][x]=0;
    if(x==0) f[u][x]=s[u][x]=fa[u][x]=-inf;
    else f[u][x]=s[u][x]=fa[u][x]=inf;
    if(d[u]==1&&e[head[u]].to==pre) f[u][x]=c[u];
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==pre) continue;
        dfs(y,v,u);
        if(x==0)
        {
            LL t=f[v][y]+c[u];
            if(f[u][x]<=t) s[u][x]=f[u][x],f[u][x]=t,fid[u][x]=v;
            else s[u][x]=max(s[u][x],t);
        }
        else
        {
            LL t=f[v][y]+c[u];
            if(f[u][x]>=t) s[u][x]=f[u][x],f[u][x]=t,fid[u][x]=v;
            else s[u][x]=min(s[u][x],t);
        }
    }
}
void dfs2(int x,int u,int pre)
{
    int y=(x^1);
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==pre) continue;
        if(y==0)
        {
            if(v==fid[u][x])
            {
                if(fa[u][x]==inf&&s[u][x]==inf) fa[v][y]=c[u]+c[v];
                else fa[v][y]=min(fa[u][x],s[u][x])+c[v];
            }
            else
            {
                if(fa[u][x]==inf&&f[u][x]==inf) fa[v][y]=c[u]+c[v];
                else fa[v][y]=min(fa[u][x],f[u][x])+c[v];
            }
        }
        else
        {
            if(v==fid[u][x])
            {
                   if(fa[u][x]==-inf&&s[u][x]==-inf) fa[v][y]=c[u]+c[v];
                else fa[v][y]=max(fa[u][x],s[u][x])+c[v];
            }
            else
            {
                if(fa[u][x]==-inf&&f[u][x]==-inf) fa[v][y]=c[u]+c[v];
                else fa[v][y]=max(fa[u][x],f[u][x])+c[v];
            }
        }
        dfs2(y,v,u);
    }
}
void ini()
{
    cnt=0;
    for(int i=1;i<=n;i++)
        head[i]=0;
}
signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        ini();
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%lld",&b[i]);
        for(int i=1;i<=n;i++)
            c[i]=a[i]-b[i],d[i]=0;
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%lld%lld",&u,&v);   
            ins(u,v); ins(v,u);
        }
        for(int i=1;i<=n;i++)
            if(d[i]>1) r=i;
        if(n==1)
        {
            printf("%lld\n",c[1]);
            continue;
        }
        if(n==2)
        {
            printf("%lld\n",c[1]+c[2]);
            continue;
        }
        dfs(0,r,0);
        dfs(1,r,0);
        dfs2(0,r,0);
        dfs2(1,r,0);
        LL ans=-inf;
        for(int i=1;i<=n;i++)
        {
            if(d[i]==1) ans=max(ans,fa[i][1]);
            ans=max(ans,min(f[i][1],fa[i][1]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

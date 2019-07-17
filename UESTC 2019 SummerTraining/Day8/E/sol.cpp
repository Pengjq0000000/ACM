#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int T;
int n;
struct edge
{
    int to,next,id;
    long long w;
}e[200005];
int cnt;
int head[100005];
void ins(int u,int v,long long w,int id)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].id=id;
    e[cnt].next=head[u];
    e[cnt].w=w;
    head[u]=cnt;
}
long long minw[100005];
int minv[100005];
int minid[100005];
struct EDGE
{
    int u,v;
    long long w;
    bool friend operator <(EDGE a,EDGE b)
    {
        return a.w<b.w;
    }
}a[400005];
int num;
void add(int u,int v,long long w)
{
    num++;
    a[num].u=u;
    a[num].v=v;
    a[num].w=w;
}
void dfs(int u,int fa)
{
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        int w=e[i].w;
        int id=e[i].id;
        if(v==fa) continue;
        dfs(v,u);
        if(minw[u]>w)
        {
            minw[u]=w;
            minv[u]=v;
            minid[u]=id;
        }
    }
    if(minw[u]>2e9) return;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        int w=e[i].w;
        int id=e[i].id;
        if(v==minv[u]) continue;
        add(minid[u],id,minw[u]+w);
    }
}

void ini()
{
    cnt=0;
    num=0;
    for(int i=1;i<=n;i++)
    {
        head[i]=0;
        minw[i]=1e10;
    }
}
int fa[100005];
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
long long ans;
void kruscal()
{
    ans=0;
    for(int i=1;i<n;i++)
        fa[i]=i;
    sort(a+1,a+num);
    for(int i=1;i<=num;i++)
    {
        int u=find(a[i].u);
        int v=find(a[i].v);
        long long w=a[i].w;
        //printf("%d %d %lld\n",u,v,w);
        if(u!=v)
        {
            fa[u]=v;
            ans+=w;
        }
    }
}
int main()
{
	scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ini();
        for(int i=1;i<n;i++)
        {
            int u,v;
            long long w;
            scanf("%d%d%lld",&u,&v,&w);
            ins(u,v,w,i);
            ins(v,u,w,i);
        }
        dfs(1,0);
        /*for(int i=1;i<=num;i++)
        {
            int u=a[i].u;
            int v=a[i].v;
            long long w=a[i].w;
            printf("%d %d %lld\n",u,v,w);
        } */
        kruscal();
        printf("%lld\n",ans);
    }
	return 0;
}

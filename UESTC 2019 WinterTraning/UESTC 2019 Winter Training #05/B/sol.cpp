#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 3e5+7;

struct node
{
    int u,v;LL w;
    node(int u,int v,LL w):u(u),v(v),w(w){}
    node(){}
    bool operator < (const node &rhs) const
    {
        return w<rhs.w;
    }
}edge[maxn];

int f[maxn];
int find(int x)
{
    if (f[x]==x) return x;
    return f[x]=find(f[x]);  
}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=m;i++) scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    sort(edge+1,edge+1+m);
    int cnt=0,mx;
    LL ans=0;
    for (int i=1;i<=m;i++)
    {
        int u=find(edge[i].u);
        int v=find(edge[i].v);
        if (u!=v)
        {
            f[u]=v;
            cnt++;
            ans+=edge[i].w;
        }
        if (cnt==n-1)
        {
            mx=edge[i].w;
            break;
        }
    }
    for (int i=1;i<=n;i++) f[i]=i;
    int num=0;
    for (int i=1;i<=m;i++)
    {
        int u=find(edge[i].u);
        int v=find(edge[i].v);
        if (u!=v)
        {
            if (edge[i].w>=mx) num++;
            else f[u]=v;
        }
    }
    printf("%lld %d\n",ans-mx,num);
    return 0;
}


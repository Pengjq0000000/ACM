#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 2e5+7;
int f[maxn];
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

struct P
{
    int id;LL val;
    P(int id,LL val):id(id),val(val){}
    P(){}
    bool operator < (const P &rhs) const
    {
        return val<rhs.val;
    }
}x[maxn],y[maxn];

int find(int x)
{
    if (x==f[x]) return x;
    return f[x]=find(f[x]);
}

int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=2*n;i++) f[i]=i;
    for (int i=1;i<=n;i++)
    {
        scanf("%lld %lld",&x[i].val,&y[i].val);
        x[i].id=y[i].id=i;
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    
    int tot=0;
    for (int i=2;i<=n;i++)
    {
        edge[++tot]=node(x[i-1].id,x[i].id,x[i].val-x[i-1].val);
        edge[++tot]=node(y[i-1].id,y[i].id,y[i].val-y[i-1].val);
    }
    
    sort(edge+1,edge+1+tot);
    
    int cnt=0;LL ans=0;
    for (int i=1;i<=tot;i++)
    {
        int u=find(edge[i].u),v=find(edge[i].v);
        if (u!=v)
        {
            ++cnt;
            f[u]=v;
            ans+=edge[i].w;
        }
        if (cnt==n-1) break; 
    }
    printf("%lld\n",ans);
    return 0;
}






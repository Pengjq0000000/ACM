#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)
#define pb push_back

using namespace std;
const int maxn = 3e5+7;
struct node
{
    int d;LL x;
    node(int d,LL x):d(d),x(x){}
    node(){}
};
vector<node>opt[maxn];
vector<int>E[maxn];

int n,m,vis[maxn];
LL lazy[maxn],val[maxn];

void dfs(int u,int dep,LL sum)
{
    vis[u]=1;
    for (node &op:opt[u])
    {
        lazy[dep]+=op.x;
        lazy[min(n,dep+op.d)+1]-=op.x;
    }
    
    val[u]=sum+lazy[dep];
    for (int &v:E[u])
    {
        if (vis[v]) continue;
        dfs(v,dep+1,sum+lazy[dep]);
    }
    
    for (node &op:opt[u])  //back
    {
        lazy[dep]-=op.x;
        lazy[min(n,dep+op.d)+1]+=op.x;
    }
}


int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++) 
    {
        int u,v;scanf("%d%d",&u,&v);
        E[u].pb(v);E[v].pb(u);
    }
    scanf("%d",&m);
    while (m--)
    {
        int v,d;LL x;
        scanf("%d%d%lld",&v,&d,&x);
        opt[v].pb(node(d,x));
    }
    
    dfs(1,1,0);
    for (int i=1;i<=n;i++) printf("%lld ",val[i]);
    printf("\n");
    return 0;
}

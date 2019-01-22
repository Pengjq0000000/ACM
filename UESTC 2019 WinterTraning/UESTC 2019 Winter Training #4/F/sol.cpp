#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 2e5+7;
struct node
{
    int u,v;
}edge[maxn];


LL deg[maxn];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,m,k;scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=n;i++) deg[i]=0;
        for (int i=1;i<=m;i++) deg[i+n]=0;
        for (int i=1;i<=k;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            edge[i].u=u;edge[i].v=v+n;
            deg[u]++;deg[v+n]++;
        }
        LL ans=0;
        for (int i=1;i<=k;i++)
        {
            int u=edge[i].u,v=edge[i].v;
            ans+=(LL)2*(deg[u]-1)*(deg[v]-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

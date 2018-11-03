#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1007;
struct node
{
    int u,v,w;
    node(){}
    node(int u,int v,int w):u(u),v(v),w(w){}
    bool operator < (const node &rhs )const
    {
        return w<rhs.w;
    }
}E[maxn];
int f[maxn];


int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}

void unite(int x,int y)
{
    x=find(x);y=find(y);
    if (x!=y) f[x]=y;
}

int n,m,ans;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
    sort(E,E+m);
    ans=1e9;
    for (int low=0;low<m;low++)
    {
        for (int i=1;i<=n;i++) f[i]=i;
        for (int i=low;i<m;i++)
        {
            unite(E[i].u,E[i].v);
            if (find(1)==find(n))
            {
                ans=min(ans,E[i].w-E[low].w);
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}














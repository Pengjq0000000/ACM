#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 1e5+7;
struct node
{
    int v,nex;
    node(int v,int nex):v(v),nex(nex){}
    node(){}
}E[maxn*4];
int deg[maxn],head[maxn],flag[maxn],tot,n,vis[maxn];
vector<int> ans;
void init()
{
    for (int i=1;i<=n;i++) 
    {
        deg[i]=vis[i]=head[i]=flag[i]=0;
    }
    tot=0;ans.clear();
}

void add_edge(int u,int v)
{
    E[++tot]=node(v,head[u]);
    head[u]=tot;
}

int dfs(int u)
{
    if (deg[u]!=2) return u;
    vis[u]=1;
    for (int i=head[u];i;i=E[i].nex)
    {
        int v=E[i].v;
        if (vis[v]) continue;
        return dfs(v);
    }
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        init();
        for (int i=1;i<n;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
            deg[u]++,deg[v]++;
        }
        for (int i=1;i<=n;i++)
        {
            if (deg[i]==1 && !vis[i])
            {
                vis[i]=1;
                int to=dfs(E[head[i]].v); // find the real father
                if (!flag[to]) flag[to]=1;
                else ans.pb(i);
            }
        }
        
        if (!ans.size())
        {
            for (int i=1;i<=n;i++)
            {
                if (deg[i]==1) ans.pb(i);
                break;
            }
        }
        printf("%d\n",(int)ans.size());
        for (int &x:ans) printf("%d ",x);
        printf("\n");
    }
    return 0;
}





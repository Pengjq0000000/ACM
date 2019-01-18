#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
const int maxn = 1e5+7;
vector<int>E[maxn];
vector<int>G[maxn];
int son[maxn],n,m,k,cnt,tot,last[maxn]; 

struct node
{
    int v,nxt;
}e[maxn*2];

void add(int u, int v)
{
  tot++;
  e[tot].v = v;
  e[tot].nxt = last[u];
  last[u] = tot;
}

void dfs(int u,int fa)
{
    son[u]=1;
    /*
    for (int i=0;i<E[u].size();i++)
    {
        int v=E[u][i];
        if (v==fa) continue;
        dfs(v,u);
        son[u]+=son[v];
    }
    */
    for (int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if (v==fa) continue;
        dfs(v,u);
        son[u]+=son[v];
    }
    if (son[u]%k==0) cnt++;
}

void DFS(int u,int fa,int color)
{
    if (son[u]%k==0) color=++cnt;
    G[color].push_back(u);
    /*
    for (int i=0;i<E[u].size();i++)
    {
        int v=E[u][i];
        if (v==fa) continue;
        DFS(v,u,color);
    }
    */
    for (int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if (v==fa) continue;
        DFS(v,u,color);
    }
}

int main()
{
     int T;scanf("%d",&T);
     while (T--)
     {  
        tot=1;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) last[i]=0;
        for (int i=1;i<n;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            //E[u].push_back(v);
            //E[v].push_back(u);
            add(v,u);
            add(u,v);
        }
        cnt=0;
        dfs(1,0);
        if (cnt!=n/k) puts("NO");
        else
        {
            puts("YES");
            cnt=0;
            DFS(1,0,0);
            for (int i=1;i<=cnt;i++)
            {
                printf("%d",G[i][0]);
                for (int j=1;j<G[i].size();j++) printf(" %d",G[i][j]);
                printf("\n");
                G[i].clear();
            }
        }
     } 
     return 0;
}

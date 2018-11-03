#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e6+7;
const int det = 2e5+7;

struct node
{
    int u,v,nex=-1;
    node(){nex-=1;}
}edge[maxn];

int cnt=0,head[maxn],color[maxn],deg[maxn],vis[maxn];
int xroot=2*det,yroot=2*det+1;
void add(int u,int v)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].nex=head[u];
    head[u]=cnt++;
}

void dfs(int u,int last)
{
    for (int i=head[u];i!=-1;i=edge[i].nex)
    {
        if (vis[i])
        {
            int tmp=i;while (edge[tmp].nex!=-1 && vis[edge[tmp].nex]) tmp=edge[tmp].nex;
            head[u]=edge[tmp].nex;
            continue;
        }
        head[u]=edge[i].nex;
        vis[i]=vis[i^1]=1;
        color[i/2]=last^1;
        dfs(edge[i].v,last^1);
    }
}

int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=2*det;i++) head[i]=-1;
    for (int i=1;i<=n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        add(u,v+det);
        add(v+det,u);
        deg[u]++;deg[v+det]++;
    }
    for (int i=1;i<det;i++) 
    {
        if (deg[i]&1) {add(i,xroot);add(xroot,i);deg[xroot]++;}
        if (deg[i+det]&1) {add(i+det,yroot);add(yroot,i+det);deg[yroot]++;}
    }
    if (deg[xroot]) dfs(xroot,2);
    if (deg[yroot]) dfs(yroot,2);
    for (int i=1;i<=n;i++)
    {
        if (!color[i]) 
        {
            dfs(i,2);
        }
    }
    for (int i=0;i<n;i++)
        printf("%c",color[i]==3?'b':'r');
    return 0;
}














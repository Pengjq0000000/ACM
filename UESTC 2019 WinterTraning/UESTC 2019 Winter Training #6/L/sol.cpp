#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 2e5+7;
struct node {int v,flow,nxt;}e[maxn];
int tot=1,head[maxn],dep[maxn];
// tot starting from 1
void add(int u,int v,int w)
{
    ++tot;
    e[tot].v=v;e[tot].flow=w;e[tot].nxt=head[u];
    head[u]=tot;
}

bool bfs(int S,int T)
{
    MEM(dep,0);
    dep[S]=1;
    queue<int>q;
    q.push(S);
    while (!q.empty())
    {
        int u=q.front();q.pop();
        for (int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            if (e[i].flow && !dep[v])
            {
                dep[v]=dep[u]+1;
                q.push(e[i].v);
            }
        }
    }
    return dep[T];
}

int aim;
int dfs(int now,int flow)
{
    if (now==aim) return flow;
    int f=0;
    for (int i=head[now];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if (e[i].flow && dep[v]==dep[now]+1)
        {
            int x=dfs(v,min(flow,e[i].flow));
            e[i].flow-=x;e[i^1].flow+=x;flow-=x;f+=x;
        }
    }
    if (!f) dep[now]=-2;
    return f;
}

int maxflow(int S,int T)
{
    aim=T;int res=0;
    while (bfs(S,T)) res+=dfs(S,1<<30);
    return res;
}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    int S=1000,T=1001;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            char c;scanf(" %c",&c);
            if (c=='o') 
            {
                add(i,j+n,1);add(j+n,i,1);
            }
            else if (c=='S')
            {
                add(S,i,1e8);add(i,S,0);
                add(S,j+n,1e8);add(j+n,S,0);
            }
            else if (c=='T')
            {
                add(i,T,1e8);add(T,i,0);
                add(j+n,T,1e8);add(T,j+n,0);
            }
        }
    }
    
    int ans=maxflow(S,T);
    printf("%d\n",ans>=1e8?-1:ans);
    
    return 0;
}


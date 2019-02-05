#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;

struct node {int v,flow,nxt;}e[100005];
int tot=1,head[3005],dep[3005];
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




const int maxn = 1007;
int rr,pp,c,sum=0;
int r[maxn],p[maxn];
struct edge{int u,v,t;}E[maxn*20];

int check(int x)
{
    tot=1;MEM(head,0);MEM(dep,0);
    for (int i=1;i<=c;i++)
    {
        if (E[i].t<=x)
        {
            add(E[i].u,E[i].v+rr,p[E[i].v]);
            add(E[i].v+rr,E[i].u,0);
        }
    }
    int S=2001,T=2002;
    for (int i=1;i<=pp;i++)
    {
        add(i+rr,T,p[i]);
        add(T,i+rr,0);
    }
    for (int i=1;i<=rr;i++)
    {
        add(S,i,r[i]);
        add(i,S,0);
    }
    int tmp=maxflow(S,T);
    if (tmp==sum) return 1;
    return 0;
}

int main()
{
    scanf("%d%d%d",&pp,&rr,&c);
    for (int i=1;i<=pp;i++) scanf("%d",&p[i]),sum+=p[i];
    for (int i=1;i<=rr;i++) scanf("%d",&r[i]);
    int up=0;
    for (int i=1;i<=c;i++)
    {
        scanf("%d%d%d",&E[i].v,&E[i].u,&E[i].t);
        up=max(up,E[i].t);
    }
    int l=1,r=up;
    while (l<r)
    {
        int mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    if (!check(l)) l=-1;
    printf("%d\n",l);
    return 0;
}









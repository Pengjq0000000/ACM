struct node {int v,flow,nxt;}e[100005];
int tot=1,head[1005],dep[1005];
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


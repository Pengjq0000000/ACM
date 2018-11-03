#define MEM(x,y) memset(x,y,sizeof(x))

struct node
{
    int v,w;
    node(){}
    node(int v,int w):v(v),w(w){}
    bool operator < (const node &rhs) const
    {
        return w>rhs.w;
    }
}

int vis[maxn],dis[maxn];
priority_queue<node>q;

void dijkstra(int s)
{
    MEM(vis,0);MEM(dis,0x3f3f3f3f);
    q.push(node(s,0));
    dis[s]=0;
    while (!q.empty())
    {
        int u=q.top().to;q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=0;i<E[u].size();i++)
        {
            int v=E[now][i].to;
            if (dis[u]+E[now][i].w<dis[v])
            {
                dis[v]=dis[u]+E[now][i].w;
                q.push(node(v,dis[v]));
            }
        }
    }    
}



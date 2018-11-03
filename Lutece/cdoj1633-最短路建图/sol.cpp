#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int a[20005],n,m,qq,mi;
int dis[500005],vis[500005];
struct node
{
    int to,w;
    node(){}
    node(int to,int w):to(to),w(w){}
    bool operator < (const node &rhs) const
    {
        return w>rhs.w;
    }
};
priority_queue<node>q;

void dijkstra(int s)
{
    MEM(vis,0);MEM(dis,0x3f3f3f3f);
    dis[s]=0;
    q.push(node(s,0));
    while (!q.empty())
    {
        int now=q.top().to;q.pop();
        if (vis[now]) continue;
        vis[now]=1;
        for (int i=0;i<n;i++)
        {
            int to=(now+a[i])%mi;
            if (dis[now]+a[i]<dis[to])
            {
                dis[to]=dis[now]+a[i];
                q.push(node(to,dis[to]));
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    mi=1e9;
    for (int i=0;i<n;i++) scanf("%d",&a[i]),mi=min(mi,a[i]);
    dijkstra(0);
    scanf("%d",&qq);
    while (qq--)
    {
        scanf("%d",&m);
        if (dis[m%mi]<=m) puts("YES");
        else puts("NO");
    }
    return 0;
}





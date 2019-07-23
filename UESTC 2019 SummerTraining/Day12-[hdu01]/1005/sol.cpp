#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 10007;
////////////////////////////////////////////////////////////////
struct node
{
    int v, next;
    LL w;
    node(){}
    node(int v, int next, LL w):v(v), next(next), w(w){}
    node(int v, LL w):v(v), w(w){}
    bool operator < (const node &rhs) const 
    {
        return w > rhs.w;
    }
};
int uu[maxn], vv[maxn], ww[maxn];
int all = 0;
vector<node>E[maxn], G[maxn];
int n, m;
priority_queue<node>pq;
LL dis[maxn], DIS[maxn];
int vis[maxn];
void dijkstra(int s, int t)
{
    for (int i = 1; i <= n; i++) dis[i] = 1e18, vis[i] = 0;
    dis[s] = 0;
    pq.push(node(s, 0));
    while (!pq.empty())
    {
        node now = pq.top(); pq.pop();
        if (vis[now.v]) continue;
        vis[now.v] = 1;
        for (node x : E[now.v])
        {
            if (dis[x.v] > dis[now.v] + x.w)
            {
                dis[x.v] = dis[now.v] + x.w;
                pq.push(node(x.v, dis[x.v]));
            }
        }
    }
}
void Dijkstra(int s, int t)
{
    for (int i = 1; i <= n; i++) DIS[i] = 1e18, vis[i] = 0;
    pq.push(node(s, 0));
    DIS[s] = 0;
    while (!pq.empty())
    {
        node now = pq.top(); pq.pop();
        if (vis[now.v]) continue;
        vis[now.v] = 1;
        for (node x : G[now.v])
        {
            if (DIS[x.v] > DIS[now.v] + x.w)
            {
                DIS[x.v] = DIS[now.v] + x.w;
                pq.push(node(x.v, DIS[x.v]));
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////
int VIS[100010];
int q[100010],head,tail,d[100010];
struct E{
    int next,to;
    long long flow;
} e[200011];
const long long Inf=1e18;
int tot,last[100010],cur[100010];
long long ans;
long long Min(long long u,long long v){return u>v?v:u;}
void  add(int u,int v,long long f){
    e[++tot].next=last[u];
    last[u]=tot;
    e[tot].to=v;
    e[tot].flow=f;
    e[++tot].next=last[v];
    last[v]=tot;
    e[tot].to=u;
    e[tot].flow=0;
}
bool BFS(){
    for (int i = 1; i <= n ; i++) VIS[i] = d[i] = 0;
    q[1]=1;d[1]=0;VIS[1]=1;
    head=0;tail=1;
    while(head<tail){
        for(int i=last[q[++head]];i;i=e[i].next){
            if(!VIS[e[i].to]&&e[i].flow>0){
                VIS[e[i].to]=1;
                d[e[i].to]=d[q[head]]+1;
                q[++tail]=e[i].to;
            }
        }
    }
    return VIS[n];
}
LL DFS(int u,LL a){
    if(u==n||a==0)return a;
    long long f,flow=0;
    if(cur[u]==0)
        cur[u]=last[u];
    for(int& i=cur[u];i;i=e[i].next){
        if(d[u]+1==d[e[i].to]&&(f=DFS(e[i].to,Min(a,e[i].flow)))>0){
            e[i].flow-=f;
            e[i^1].flow+=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    return flow;
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) E[i].clear(), G[i].clear();
        for (int i = 1, u, v, w; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            E[u].pb(node(v, w));
            G[v].pb(node(u, w));
        }
        dijkstra(1, n);
        Dijkstra(n, 1);
        all = 0;
        for (int u = 1; u <= n; u++)
            for (node x : E[u])
            {
                int v = x.v, w = x.w;
                if (dis[u] + DIS[v] + x.w == dis[n])
                {
                    ++all;
                    uu[all] = u; vv[all] = v; ww[all] = w;
                }
            }
        ans=0;
        tot=1;
        for (int i = 0; i <= n; i++) last[i] = 0;
        for (int i = 1; i <= all; i++)
        {
            add(uu[i],vv[i],ww[i]);
        }
        while(BFS()){
            //memset(cur,0,sizeof cur);
            for (int i = 0; i <= n; i++) cur[i] = 0;
            ans+=DFS(1,Inf);
        }
        cout<<ans<<endl;
    }
	return 0;
}

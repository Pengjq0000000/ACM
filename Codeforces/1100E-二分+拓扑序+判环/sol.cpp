#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)
#define pb push_back
using namespace std;
const int maxn = 1e5+7;

struct node
{
    int u,v,w,next;
    node(int u,int v,int w,int next):u(u),v(v),w(w),next(next){}
    node(){}
}E[maxn];
int n,m,tot,head[maxn];
vector<int>ans;

void add(int u,int v,int w)
{
    E[++tot]=node(u,v,w,head[u]);
    head[u]=tot;
}

queue<int>q;
int deg[maxn],level[maxn];
int check(int x)
{
    while (!q.empty()) q.pop();
    MEM(deg,0);MEM(level,0);
    for (int i=1;i<=tot;i++)
    {
        if (E[i].w>x) deg[E[i].v]++;
    }
    for (int i=1;i<=n;i++) if (deg[i]==0) q.push(i);
    int cnt=0;
    while (!q.empty())
    {
        int u=q.front();q.pop();
        level[u]=++cnt;
        for (int i=head[u];i;i=E[i].next)
        {
            int v=E[i].v;
            if (E[i].w>x) 
            {
                deg[v]--;
                if (deg[v]==0) q.push(v);
            }
        }
    }
    return cnt==n;
}

void print(int x)
{
    for (int i=1;i<=tot;i++)
    {
        int u=E[i].u,v=E[i].v;
        if (E[i].w<=x && level[u]>level[v]) ans.pb(i); 
    }
    printf("%d\n",(int)ans.size());
    for (int num:ans) printf("%d ",num);
    printf("\n");
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    int l=0,r=1e9+7;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    check(l);
    printf("%d ",l);
    print(l);
    return 0;
}

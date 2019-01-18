#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int x,y,n,m,f[2010],good,bad,vis[1005];


int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}

void unite(int x,int y)
{
    x=find(x);y=find(y);
    f[x]=y;
}

void ini()
{
    for (int i=1;i<=2*(n+1);i++) f[i]=i;
    for (int i=1;i<=n;i++) vis[i]=0;
    good=2*n+1;bad=2*n+2;
}

int main()
{
    while (scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)
    {
        int flg=0,u,v;
        ini();
        while (m--)
        {
            scanf("%d%d",&u,&v);
            unite(u,v+n);
            unite(u+n,v);
            if (find(u)==find(u+n) || find(v)==find(v+n)) 
            {
                flg=1;
            }
            vis[u]=vis[v]=1;
        }
        while (x--)
        {
            scanf("%d",&u);vis[u]=1;
            unite(good,u);
            if (find(u)==find(u+n)) flg=1;
        }
        while (y--)
        {
            scanf("%d",&v);vis[v]=1;
            unite(bad,v);
            if (find(v)==find(v+n)) flg=1;
        }
        for (int i=1;i<=n;i++) if (!vis[i]) flg=1;
        //for (int i=1;i<=2*n;i++) printf("%d ",f[i]);
        if (flg) puts("NO");
        else puts("YES");
    }
    return 0;
}

#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstdio>

#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 1e6+7;
const int up = 1e6;
int has[maxn],vis[maxn],f[maxn],a[maxn],t[maxn];
int tot;

int find(int x)
{
    if (x==f[x]) return x;
    return f[x]=find(f[x]);
}


void unite(int u,int v)
{
    u=find(u);v=find(v);
    if (u!=v)
    {
        f[u]=v;tot--;
    }
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        MEM(has,0);MEM(vis,0);
        int n;scanf("%d",&n);
        tot=n;
        for (int i=1;i<=up;i++) f[i]=i;
        for (int i=1;i<=n;i++)
        {
            int x;scanf("%d",&a[i]);
            has[a[i]]=1;
        }
        sort(a+1,a+1+n);
        for (int i=1;i<n;i++)
        {
            if (a[i]==1) continue;
            if (a[i]==a[i+1]) tot--;
        }
        for (int u=2;u<=up;u++)
        {
            if (!vis[u])
            {
                int cnt=0;
                for (int j=1;j*u<=up;j++)
                {
                    int v=j*u;vis[v]=1;
                    if (has[v])
                    {
                        t[cnt++]=v;
                    }
                }
                for (int k=1;k<cnt;k++)
                {
                    unite(t[k-1],t[k]);
                }
            }
        }
        LL ans=1;
        for (LL i=1;i<=tot;i++) ans=MOD(ans*2);
        ans=MOD(ans-2+mod);
        printf("%lld\n",ans);
    }
    return 0;
}

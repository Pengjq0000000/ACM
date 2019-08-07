#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
int h[400005];
int deg[400005];
int fa[400005];
void ins(int u,int v)
{
    fa[u]=v;
    deg[v]++;
}
long long ans[2];
void ini()
{
    for(int i=1;i<=n;i++)
        deg[i]=0,fa[i]=0;
    ans[0]=ans[1]=0;
}
priority_queue<pii,vector<pii>,less<pii> >q;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ini();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
            ins(i,i/2);
        }
        for(int i=1;i<=n;i++)
            if(deg[i]==0) q.push(mp(h[i],i) );
        int now=0;
        while(!q.empty())
        {
            pii t=q.top();
            q.pop();
            int x=t.first,y=t.second;
            ans[now]+=(long long)x;
            int z=fa[y];
            deg[z]--;
            if(deg[z]==0) q.push(mp(h[z],z));
            now=!now;
        }
        printf("%lld %lld\n",ans[0],ans[1]);
    }
    return 0;
}

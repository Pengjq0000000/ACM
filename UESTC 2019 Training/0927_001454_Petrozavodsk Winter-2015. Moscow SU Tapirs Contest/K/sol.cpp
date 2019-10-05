#include <bits/stdc++.h>
#define pii pair<long double,int>
#define mp(a,b) make_pair(a,b)
#define eps 1e-8
using namespace std;
int n,m;
struct edge
{
    int to,next;
}e[200005];
int cnt;
int head[100005];
void ins(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int sz[100005];
long double dp[100005];
long double sum[100005];
priority_queue<pii,vector<pii>,greater<pii> >q;
priority_queue<long double,vector<long double>,less<long double> >s[100005];
int vis[100005];
void dij()
{
    q.push({0,n});
    while(!q.empty())
    {
        pii t=q.top(); q.pop();
        long double d=t.first;
        int u=t.second;
        if(u==1) break;
        if(vis[u]==2) continue;
        //if(fabs(dp[u]-d)>eps) continue;
        vis[u]=2;
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            if(vis[v]==2) continue;
            if(vis[v]==0)
            {
                vis[v]=1;
                dp[v]=dp[u]+m;
                sum[v]+=dp[u];
                s[v].push(dp[u]);
                sz[v]=1;
                q.push(mp(dp[v],v));
                continue;
            }
            if(dp[v]>(sum[v]+m+dp[u])/(sz[v]+1))
            {
                sum[v]+=dp[u];
                s[v].push(dp[u]);
                sz[v]++;
                while(sz[v]>1&&s[v].top()>(sum[v]-s[v].top()+m)/(sz[v]-1))
                {
                    sum[v]-=s[v].top();
                    s[v].pop();
                    sz[v]--;
                }
                dp[v]=(sum[v]+m)/sz[v];
                q.push(mp(dp[v],v));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    n--; n++;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ins(u,v); ins(v,u);
    }
    dp[n]=0;
    dij();
    //for(int i=1;i<=n;i++)
    //    printf("%lf\n",dp[i]);
    printf("%.10lf",(double)dp[1]);
    return 0;
}
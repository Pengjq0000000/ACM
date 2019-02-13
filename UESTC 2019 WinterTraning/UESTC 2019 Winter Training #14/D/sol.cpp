#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 98765431
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
struct node
{
    int u,sta;
    node(int u,int sta):u(u),sta(sta){}
    node(){}
};
queue<node>q;
int E[20][20],id[20],p[20];
LL dp[15][35000];
bool in[15][35000];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        MEM(in,0);MEM(dp,0);
        int n;scanf("%d",&n);if (n==0) break;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&E[i][j]);
        int m;scanf("%d",&m);
        MEM(id,0);
        for (int i=1;i<=m;i++)  scanf("%d",&p[i]),id[p[i]]=i;
        int s=p[1],st=(1<<p[1]);
        q.push(node(s,st));
        dp[s][st]=1;in[s][st]=true;
        int bits=(1<<n)-1;
        LL ans=0;
        
        while (!q.empty())
        {
            node now=q.front();q.pop();
            if (now.sta==bits)
            {
                if (E[now.u][p[1]]) ans=MOD(ans+dp[now.u][now.sta]);
                continue;
            }
            int nexp=0;
            for (int i=0;i<n;i++)
                if (now.sta&(1<<i)) nexp=max(nexp,id[i]+1);  
            for (int v=0;v<n;v++)
            {
                if (E[now.u][v]==0) continue;
                if (now.sta&(1<<v)) continue;
                if (id[v]!=0 && id[v]!=nexp) continue;
                
                int st=now.sta|(1<<v);
                dp[v][st]=MOD(dp[v][st]+dp[now.u][now.sta]);
                if (!in[v][st]) q.push(node(v,st)),in[v][st]=true;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
4
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
2
1
2
2
0 1
1 0
1 
0

*/

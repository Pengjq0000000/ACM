#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 2e6+7;

struct node
{
    int id,val;
    node(int id,int val):id(id),val(val){}
    node(){}
}q[maxn];

int dp[maxn];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int x,k,t;scanf("%d%d%d",&x,&k,&t);
        for (int i=1;i<=x;i++) dp[i]=1e9;dp[1]=0;
        int head=0,tail=-1;
        q[++tail]=node(1,dp[1]);
        for (int now=2;now<=x;now++)
        {
            while (head<tail && q[head].id<now-t) head++;
            dp[now]=min(dp[now],q[head].val+1);
            if (k>0 && now%k==0) dp[now]=min(dp[now],dp[now/k]+1);
            while (head<=tail && dp[now]<=q[tail].val) tail--;
            q[++tail]=node(now,dp[now]);
        }
        printf("%d\n",dp[x]);
    }
    return 0;
}

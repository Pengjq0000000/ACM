#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
__int128 n,m;
struct block
{
    __int128 w,h;
    bool friend operator < (block a,block b)
    {
        return a.h<b.h;
    }
}b[5005];
__int128 h[5005];
__int128 w[5005];
__int128 sum[5005];
__int128 sumw[5005];
__int128 q[5005];
__int128 dp[5005][2005];
__int128 head,tail;
__int128 p;
__int128 get(__int128 i,__int128 j)
{
    return dp[j][p-1]+sum[i]-sum[j]-h[j+1]*(sumw[i]-sumw[j]);
}
__int128 f(__int128 x)
{
    return dp[x][p-1]-sum[x]+h[x+1]*sumw[x];
}
__int128 g(__int128 x)
{
    return h[x+1];
}
int main()
{
    long long N,M;
    scanf("%lld%lld",&N,&M);
    n=N,m=M;
    for(__int128 i=1;i<=n;i++)
    {
        long long t1,t2;
        scanf("%lld%lld",&t1,&t2);
        b[i].w=t1; b[i].h=t2;
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        w[i]=b[i].w; h[i]=b[i].h;
        sum[i]=sum[i-1]+w[i]*h[i];
        sumw[i]=sumw[i-1]+w[i];
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        dp[i][0]=1e18;
    for(p=1;p<=m;p++)
    {
        head=tail=0;
        for(__int128 i=1;i<=n;i++)
        {
            while(head<tail&&f(q[head+1])-f(q[head])<=sumw[i]*(g(q[head+1])-g(q[head])))head++;
            dp[i][p]=get(i,q[head]);
            while(head<tail&&(f(q[tail])-f(q[tail-1]))*(g(i)-g(q[tail]))>=(f(i)-f(q[tail]))*(g(q[tail])-g(q[tail-1])))tail--;
            q[++tail]=i;
        }
    }
    /*for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
            printf("%lld ",(long long)dp[i][j]);
        printf("\n");
    }*/
    printf("%lld",(long long)dp[n][m]);
    return 0;
}

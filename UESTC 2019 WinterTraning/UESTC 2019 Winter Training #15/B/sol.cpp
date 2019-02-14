#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 5007;
int a[maxn],dp[maxn][maxn];
int main()
{
    int n;scanf("%d",&n);
    MEM(dp,0);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),dp[i][i]=1;
    sort(a+1,a+1+n);
    int ans=1;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<i;j++)
        {
            int d=a[i]-a[j];
            dp[i][j]=2;ans=max(ans,dp[i][j]);
            int pos=lower_bound(a+1,a+1+n,a[j]-d)-a;
            if (a[pos]!=a[j]-d) continue;
            dp[i][j]=max(dp[i][j],dp[j][pos]+1);
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}


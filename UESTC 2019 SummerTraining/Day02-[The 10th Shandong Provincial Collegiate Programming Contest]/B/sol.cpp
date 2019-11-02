#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 998244353
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int T;
int n,k,m;
char s1[105],s2[105];
long long dp[105][105];
long long fac[1005], inv[1005];
LL ksm(LL a, LL b)
{
    LL res = 1, base = a;
    while (b)
    {
        if (b & 1) res = MOD(res * base);
        base = MOD(base * base);
        b /= 2;
    }
    return res;
}
long long C(int n,int m)
{
    if (n < m) return 0;
    return MOD(MOD(fac[n] * inv[n - m]) * inv[m]);
}
int main()
{
    fac[0] = 1; for (int i = 1; i <= 1000; i++) fac[i] = MOD(fac[i - 1] * i);
    inv[1000] = ksm(fac[1000], mod - 2); inv[0] = 1;
    for (int i = 1000 - 1; i >= 1; i--) inv[i] = MOD(inv[i + 1] * (i + 1));
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k,&m);
        scanf(" %s %s",s1,s2);
        int num=0;
        for(int i=0;i<n;i++)
            if(s1[i]!=s2[i]) num++;
        memset(dp,0,sizeof dp);
        dp[0][num]=1;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int low,up;
                low=max(0,m+j-n);
                up=min(m,j);
                for(int t=low;t<=up;t++)
                {
                    dp[i+1][j+m-t*2]=MOD(dp[i+1][j+m-t*2]+MOD(dp[i][j]*MOD(C(j,t)*C(n-j,m-t))));
                }
            }
        }
        printf("%lld\n",dp[k][0]);
    }
	return 0;
}

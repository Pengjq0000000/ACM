#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
LL f[maxn];
int main()
{
    f[0]=1;for (int i=1;i<=100000;i++) f[i]=MOD(f[i-1]*i);
    
    int n,m;scanf("%d%d",&n,&m);
    LL ans;
    if (abs(n-m)>1) ans=0;
    else if (abs(n-m)==1) ans=MOD(f[n]*f[m]);
    else if (n==m) ans=MOD(2*f[n]*f[m]);
    printf("%lld\n",ans);
    return 0;
}


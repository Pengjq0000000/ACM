#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
char s[maxn];
LL sum[26][maxn];
LL fac[maxn],inv[maxn];

LL quick(LL x,LL n)
{
    LL res=1,base=x;
    while (n)
    {
        if (n&1) res=MOD(res*base);
        base=MOD(base*base);
        n>>=1;
    }
    return res;
}

int main()
{
    scanf("%s",s);int L=strlen(s);
    for (int i=0;i<L;i++)
    {
        for (int j=0;j<26;j++)
        {
            sum[j][i+1]=sum[j][i]+(s[i]==j+'a');
        }
    }
    fac[0]=1;
    for (int i=1;i<=L;i++) fac[i]=MOD(fac[i-1]*(LL)i);
    inv[L]=quick(fac[L],mod-2);
    for (int i=L-1;i>=0;i--) inv[i]=MOD(inv[i+1]*(i+1));
    
    int q;scanf("%d",&q);
    while (q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        int cnt=0;LL center=0,below=1;
        for (int i=0;i<26;i++) 
        {
            LL tmp=sum[i][r]-sum[i][l-1];
            cnt+=tmp/2;
            if (tmp&1) center++;
        }
        if (center==0) center=1;
        LL ans=MOD(fac[cnt]*center);
        for (int i=0;i<26;i++)
        {
            int tmp=sum[i][r]-sum[i][l-1];
            ans=MOD(ans*inv[tmp/2]);
        }
        printf("%lld\n",ans);
    }
            
    return 0;
}


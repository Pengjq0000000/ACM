#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 200;
LL quick(LL a,LL b)
{
    LL base=a,res=1;
    while (b)
    {
        if (b&1) res=MOD(res*base);
        base=MOD(base*base);
        b/=2;
    }
    return res;
}

int change(char c)
{
    if (c>='2' && c<='9') return c-'0';
    if (c=='A') return 1;
    if (c=='1') return 10;
    if (c=='J') return 11;
    if (c=='Q') return 12;
    if (c=='K') return 13;
}

char s[maxn];
int a[maxn],cnt[20],have[20];
LL fac[100],inv[100];

LL cal(int num)
{
    LL res=fac[num];
    for (int i=1;i<=13;i++) res=MOD(res*inv[have[i]]);
    return res;
}


int main()
{
    fac[0]=1;inv[0]=1;
    for (int i=1;i<=60;i++) fac[i]=MOD(fac[i-1]*i);
    inv[60]=quick(fac[60],mod-2);
    for (int i=60-1;i>=0;i--) inv[i]=MOD(inv[i+1]*(i+1));
    
    
    while (scanf("%s",s)!=EOF)
    {
        int L=strlen(s);
        int tot=0;MEM(cnt,0);MEM(a,0);
        for (int i=0;i<L;i++)
        {
            a[++tot]=change(s[i]);
            cnt[a[tot]]++;
            if (a[tot]==10) i++;
        }
        //for (int i=1;i<=tot;i++) printf("%d ",a[i]);
        for (int i=1;i<=13;i++) have[i]=4-cnt[i];
        LL ans=0;
        int pos;
        for (int i=1;i<=tot;i++)
        {
            int up=a[i];
            for (int j=1;j<up;j++)
            {
                if (!have[j]) continue;
                have[j]--;
                ans=MOD(ans+cal(52-tot-i));
                have[j]++;
            }
            if (!have[up]) {pos=i;break;}
            else have[up]--;
        }
        if (pos<=tot && pos-1==52-tot) ans=MOD(ans+1);
        printf("%lld\n",ans);
    }
    
    return 0;
}


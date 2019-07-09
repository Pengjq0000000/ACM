#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL a;
LL p;
LL mod;
long long num[40];
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
void dabiao()
{
    int a = 134531;
    for (int y = 1; y <= 20; y++)
    {
        printf("y = %d:", y);
        p = (1 << y);
        for (int x = 1; x <= p; x += 2)
        {
            if (ksm(a, x) == ksm(x, a)) printf("%d %d\n", x, a);
        }
    }
}
int cal(int x)
{
    int cnt=0;
    while(x%2==0)
    {
        cnt++;
        x/=2;
    }
    return cnt;
}
bool check(LL x)
{
    if (ksm(a, x) == ksm(x, a)) return 1;
    return 0;
}
int main()
{
    int T;
	scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&a,&p);
        if(a%2)
        {
            printf("1\n");
            continue;
        }
        mod=(1<<p);
        num[p]=1;
        num[p-1]=1;
        for(LL i=p-2;i>=1;i--)
            num[i]=num[i+1]*2;
        LL ans=0;
        for(LL x=2;x<p;x+=2)
        {
            int cnt=cal(x);
            num[cnt]--;
            if(check(x))
            {
                ans++;
            }
        }
        for(LL b=1;b<=p;b++)
        {
            if(a*b<p) continue;
            ans+=num[b];
        }
        printf("%lld\n",ans);
    }
	return 0;
}

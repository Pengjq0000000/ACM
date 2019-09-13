#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

long double p;
long double s[21];
int main()
{
    double x;
    while(~scanf("%lf", &x))
    {
        p = x;
        //s[0]=(p+(1-p)*1)/p;
        s[0]=1/p;
        s[1]=(p+(1-p)*(1+s[0]))/p;
        for(int i=2;i<=20;i++)
            s[i]=(p+(1-p)*(1+s[i-2]+s[i-1]))/p;
        long double ans=0;
        for(int i=0;i<=18;i++)
            ans+=s[i]*2;
        ans+=s[19];
        printf("%.7lf\n", (double)ans);
    }

    return 0;
}

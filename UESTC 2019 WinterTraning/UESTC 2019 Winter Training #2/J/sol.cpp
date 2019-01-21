#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
int cnt[1000];
double table[1000];
int main()
{
    table[0]=2;
    table[1]=1;
    table[2]=1/2.0;
    table[4]=1/4.0;
    table[8]=1/8.0;
    table[16]=1/16.0;
    double ans=0;
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        cnt[x]++;
    }
    ans+=table[0]*cnt[0];
    for (int i=1;i<=16;i=i*2)
    {
        ans+=table[i]*cnt[i];
    }
    printf("%lf",ans);
    return 0;
}

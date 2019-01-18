#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;

int main()
{
    int q;scanf("%d",&q);
    while (q--)
    {
        int h1,m1,h2,m2,k;
        scanf("%d%d%d%d%d",&h1,&m1,&h2,&m2,&k);
        int ans=(h1+k)*60+m1-(h2*60+m2);
        printf("%d\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
int a[1007];
int main()
{
    int n,sum=0;scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    if (sum%2==0)
    {
        puts("0");
    }
    else
    {
        if (n==1) puts("-1");
        else puts("1");
    }
    return 0;
}


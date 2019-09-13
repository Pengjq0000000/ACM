#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int main()
{
    LL k, p;
    while (~scanf("%lld%lld", &k, &p))
    {
        LL num = k / (p - 1);
        if (num & 1) puts("YES");
        else puts("NO");
    }
    return 0;
}

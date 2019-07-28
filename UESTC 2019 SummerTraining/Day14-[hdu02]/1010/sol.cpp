#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000003
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
LL f[maxn];
int main()
{
	f[0] = 1;
    for (LL i = 1; i <= 1e6 + 3; i++) f[i] = MOD(f[i - 1] * i);
    int n; 
    while (scanf("%d", &n) != EOF)
    {
        if (n >= 1000003) puts("0");
        else printf("%lld\n", f[n]);
    }
	return 0;//
}

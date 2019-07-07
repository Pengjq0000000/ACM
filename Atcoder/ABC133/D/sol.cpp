#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
LL a[maxn], b[maxn];
int main()
{
	int n; scanf("%d", &n);
    LL op = 1;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%lld", &a[i]);
        b[1] += op * a[i];
        op = -op;
    }
    for (int i = 2; i <= n; i++) b[i] = 2 * a[i - 1] - b[i - 1];
    for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
	return 0;
}

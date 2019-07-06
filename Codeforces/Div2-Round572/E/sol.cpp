#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%p)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e5 + 7;
map<LL, LL>cnt;
LL a[maxn];
int main()
{
	int n; LL p, k; scanf("%d%lld%lld", &n, &p, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        LL x = MOD(a[i] * MOD(a[i] * MOD(a[i] * a[i]) - k + p));
        cnt[x]++;
    }
    LL ans = 0;
    for (auto iter = cnt.begin(); iter != cnt.end(); iter++)
    {
        LL num = iter->second;
        ans += num * (num - 1) / 2;
    }
    printf("%lld\n", ans);
	return 0;
}

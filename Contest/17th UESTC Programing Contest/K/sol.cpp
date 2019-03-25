#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL a[100005];
int main()
{
	int n; scanf("%d", &n);
	LL ans = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), ans += (a[i] - 1);
	ans++;
	printf("%lld\n", ans);
	return 0;
}

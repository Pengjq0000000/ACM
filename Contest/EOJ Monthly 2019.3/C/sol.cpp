#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const LL up = 2e9;
LL ans, flag;
void dfs(LL l, LL r)
{
	if (l == 1 || r >= ans) {ans = min(ans, r); flag = 1; return;}
	LL len = r - l + 1;
	if (len > l - 1) return;
	if (l - len > 0) dfs(l - len, r);
	if (l - len - 1 > 0) dfs(l - len - 1, r);
	if (r + len - 1 <= up && len > 1) dfs(l, r + len - 1);
	if (r + len <= up) dfs(l, r + len);
}
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		LL l, r; scanf("%lld%lld", &l, &r);
		ans = 3e9; flag = 0; dfs(l, r);
		printf("%lld\n", ans == 3e9 ? -1 : ans);		
	}
	return 0;
}


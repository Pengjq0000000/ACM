#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int Lpos[maxn], Rpos[maxn], a[maxn];
int main()
{
	int n;LL x; scanf("%d%lld", &n, &x);
	for (int i = 1; i <= x + 1; i++) Lpos[i] = 1e9, Rpos[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		Lpos[a[i]] = min(Lpos[a[i]], i);
		Rpos[a[i]] = max(Rpos[a[i]], i);
	}
	sort(a + 1, a + 1 + n);
	LL L = 1, R = a[n];
	int pos = n;
	int nowLmin = 1e9 + 7;
	while (R > 1 && Rpos[R] <= nowLmin)
	{
		nowLmin = min(nowLmin, Lpos[R]);
		R--;
	}
	pos = lower_bound(a + 1, a + 1 + n, R) - a;
	LL ans = 0;
	int maxR = 0;
	while (L <= x)
	{
		ans += (LL)(x - R + 1);
		if (maxR > Lpos[L]) break;
		R = max(R, L + 1);
		while (pos < n && R >= a[pos]) pos++;
		if (a[pos] > R) pos--;
		while (pos < n && R < x && Lpos[a[pos + 1]] <= Rpos[L]) R = a[++pos];
        maxR = max(maxR, Rpos[L]);
		L++;
	}
	printf("%lld\n", ans);
	return 0;
}

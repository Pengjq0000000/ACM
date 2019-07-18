#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int n, m, blocks = 200;
struct node
{
	int l, r, id;
	bool operator < (const node &rhs) const
	{
		if (l / blocks == rhs.l / blocks) return r < rhs.r;
		return l / blocks < rhs.l / blocks;
	}
}q[maxn];
LL ans[maxn], fac[maxn], inv[maxn];
LL quick(LL a, LL b)
{
	LL res = 1, base = a;
	while (b)
	{
		if (b & 1) res = MOD(res * base);
		base = MOD(base * base);
		b /= 2;
	}
	return res;
}
const int N = 1e5 + 2;
void init()
{
	fac[0] = 1;
	for (LL i = 1; i <= N; i++) fac[i] = MOD(fac[i - 1] * i);
	inv[N] = quick(fac[N], mod - 2);
	for (LL i = N - 1; i >= 1; i--) inv[i] = MOD(inv[i + 1] * (i + 1));
	inv[0] = 1;
}
LL C(int n, int m)
{
	if (n < m || n < 0 || m < 0) return 0;
	return MOD(MOD(fac[n] * inv[m]) * inv[n - m]);
}


void test()
{
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%lld\n", C(x, y));
	exit(0);
}
int main()
{
	init();
	//test();
	int x; scanf("%d", &x);
	for (int i = 1; i <= x; i++)
	{
		q[i].id = i;
		scanf("%d%d", &q[i].l, &q[i].r);
	}
	sort(q + 1, q + 1 + x);
	int L = 0, R = 0;
	LL tmp = 1;
	for (int i = 1; i <= x; i++)
	{
	    while (L < q[i].l)
		{
			tmp = MOD(MOD(tmp * 2) - C(L, R) + mod + mod);
			L++;
		}
		while (L > q[i].l)
		{
			tmp = MOD(MOD(tmp + C(L - 1, R)) * inv[2]);
			L--;
		}
		while (R < q[i].r)
		{
			tmp = MOD(tmp + C(L, R + 1));
			R++;
		}
		while (R > q[i].r)
		{
			tmp = MOD(tmp - C(L, R) + mod);
			R--;
		}

		ans[q[i].id] = tmp;
	}
	for (int i = 1; i <= x; i++) printf("%lld\n", ans[i]);
	return 0;
}

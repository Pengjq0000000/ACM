#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 998244353
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
#define hash HASH
using namespace std;
const int maxn = 1007;
char s[maxn][maxn];
LL hash[maxn][maxn], mi[maxn];
LL base = 2;
LL get(int i, int l, int r)
{
	return (LL)MOD(hash[i][r] - MOD(hash[i][l - 1] * mi[r - l + 1]) + mod);
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf(" %s", s[i] + 1);
	mi[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		hash[i][0] = 0; mi[i] = MOD(mi[i - 1] * base);
		for (int j = 1; j <= m; j++) 
		{
			s[i][j] -= '0'; 
			hash[i][j] = MOD(MOD(hash[i][j - 1] * base) + s[i][j]);
		}
	}
	int q; scanf("%d", &q);
	while (q--)
	{
		int a, b, c, d, aa, bb, cc, dd;
		scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &aa, &bb, &cc, &dd);
		a++; b++; c++; d++; aa++; bb++; cc++; dd++;
		int cnt = 0;
		while (a <= c)
		{
			if (cnt >= 2) break;
			LL x = get(a, b, d), y = get(aa, bb, dd);
			if (x == y) continue;
			int i = b, j = bb;
			while (i <= d)
			{
				if (s[a][i] != s[aa][j]) cnt++;
				i++; j++; if (cnt >= 2) break;
			}
			a++; aa++;
		}
		if (cnt == 0) puts("Perfect");
		else if (cnt == 1) puts("One difference");
		else puts("Wrong");
	}
	return 0;
}

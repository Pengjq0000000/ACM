#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
char mp[maxn][maxn];
int len[maxn][maxn], h[maxn][maxn], LEN[maxn][maxn], H[maxn][maxn];
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			{
				scanf(" %c", &mp[i][j]);
				len[i][j] = h[i][j] = 1;
				LEN[i][j] = H[i][j] = 1;
			}
	for (int i = 1; i <= n; i++)
		for (int j = m; j > 1; j--)
		{
			if (mp[i][j - 1] == mp[i][j]) 
			{
				len[i][j - 1] += len[i][j];
				LEN[i][j - 1] += LEN[i][j];
			}
		}
	for (int j = 1; j <= m; j++)
		for (int i = n; i > 1; i--)
		{
			if (mp[i - 1][j] == mp[i][j]) 
			{
				h[i - 1][j] += h[i][j];
				len[i - 1][j] = min(len[i - 1][j], len[i][j]);
			}
		}
	for (int j = 1; j <= m;j ++)
		for (int i = 1; i < n; i++)
		{
			if (mp[i + 1][j] == mp[i][j])
			{
				H[i + 1][j] += H[i][j];
				LEN[i + 1][j] = min(LEN[i + 1][j], LEN[i][j]);
			}
		}
	/* 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) printf("%d ", len[i][j]);
		puts("");
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) printf("%d ", h[i][j]);
		puts("");
	}
	*/
	LL ans = 0;
	for (int i = 1; i <= n - 2; i++)
		for (int j = 1; j <= m; j++)
		{
			int d = h[i][j];
			if (i + d > n || i + 2 * d > n) continue;
			if (h[i + d][j] != h[i][j]) continue;
			if (h[i + d + d][j] != h[i][j]) 
			{
				if (i + 3 * d - 1 > n) continue;
				if (H[i + 3 * d - 1][j] != d) continue;
				else ans += (LL)min(len[i][j], min(len[i + d][j], LEN[i + 3 * d - 1][j]));
			}
			else 
			{
				if (mp[i][j] == mp[i + d][j] || mp[i + d][j] == mp[i + d + d][j]) continue;
				ans += (LL)min(len[i][j], min(len[i + d][j], len[i + d + d][j]));
			}
		}
	/* 
	for (int i = n; i >= 3; i--)
		for (int j = 1; j <= m; j++)
		{
			int d = H[i][j];
			if (d > 1) continue;
			if (i - d <= 0 || i - 2 * d <= 0) continue;
			if (H[i - d][j] != H[i][j]) continue;
			if (H[i - d - d][j] != H[i][j]) continue;
			if (mp[i][j] == mp[i - d][j] || mp[i - d][j] == mp[i - d - d][j]) continue;
			ans += (LL)min(LEN[i][j], min(LEN[i - d][j], LEN[i - d - d][j]));
		} 
	*/
	printf("%lld\n", ans);
	return 0;
}

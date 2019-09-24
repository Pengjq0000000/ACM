// oydy nb
#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL dp1[55][55][2505], dp2[55][2505], dp3[55][55][55];
LL DP[55][55][55][4];
int a[55][4], tot[4], cnt[4];
inline void add(LL &x, LL y) {x = MOD(x + y);}
void cal_num()
{
	DP[1][0][0][0] = DP[1][0][0][1] = 1;
	DP[0][1][0][0] = DP[0][1][0][2] = 1;
	DP[0][0][1][0] = DP[0][0][1][3] = 1;
	for (int i = 0; i <= cnt[1]; i++)
		for (int j = 0; j <= cnt[2]; j++)
			for (int k = 0; k <= cnt[3]; k++)
			{
				if (i + j + k <= 1) continue;
				if (i) add(DP[i][j][k][1], MOD((DP[i - 1][j][k][2] + DP[i - 1][j][k][3]) * i));
				if (j) add(DP[i][j][k][2], MOD((DP[i][j - 1][k][1] + DP[i][j - 1][k][3]) * j));
				if (k) add(DP[i][j][k][3], MOD((DP[i][j][k - 1][1] + DP[i][j][k - 1][2]) * k));
				
				for (int c = 1; c <= 3; c++) add(DP[i][j][k][0], DP[i][j][k][c]);
			}
}


int main()
{
	int n, T; scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; i++)
	{
		int x, g; scanf("%d%d", &x, &g);
		a[++cnt[g]][g] = x;
		tot[g] += x; 
	}
	// color-1
	dp1[0][0][0] = 1; 
	int up = tot[1];
	for (int k = 1; k <= cnt[1]; k++)
		for (int i = k; i > 0; i--)
			for (int t = up; t >= a[k][1]; t--)
			{
				add(dp1[i][0][t], dp1[i - 1][0][t - a[k][1]]);
			}
	// color-1 && 2
	up = tot[1] + tot[2];
	for (int k = 1; k <= cnt[2]; k++)
		for (int i = 0; i <= cnt[1]; i++)
			for (int j = k; j > 0; j--)
				for (int t = up; t >= a[k][2]; t--)
				{
					add(dp1[i][j][t], dp1[i][j - 1][t - a[k][2]]);
				}
	// color-3
	dp2[0][0] = 1;
	up = tot[3];
	for (int k = 1; k <= cnt[3]; k++)
		for (int i = k; i > 0; i--)
			for (int t = up; t >= a[k][3]; t--)
			{
				add(dp2[i][t], dp2[i - 1][t - a[k][3]]);
			}
	// color-1 & 2 & 3
	up = min(T, tot[1] + tot[2]);
	for (int i = 0; i <= cnt[1]; i++)
		for (int j = 0; j <= cnt[2]; j++)
			for (int t = 0; t <= up; t++)
			{
				if (!dp1[i][j][t]) continue;
				for (int k = 0; k <= cnt[3]; k++)
				{
					add(dp3[i][j][k], MOD(dp1[i][j][t] * dp2[k][T - t]));
				}
			}
	cal_num();
	LL ans = 0;
	for (int i = 0; i <= cnt[1]; i++)
		for (int j = 0; j <= cnt[2]; j++)
			for (int k = 0; k <= cnt[3]; k++)
				add(ans, MOD(DP[i][j][k][0] * dp3[i][j][k]));
	printf("%lld\n", ans);
	return 0;
}

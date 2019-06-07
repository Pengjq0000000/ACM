#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int maxn = 5e5 + 7;
pii seg[maxn];
int rg[maxn][21];
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int mx = 0;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d%d", &seg[i].fir, &seg[i].sec);
		seg[i].fir++; seg[i].sec++;
		mx = max(seg[i].sec, mx);
	}
	sort(seg + 1, seg + 1 + n);
	int now = 1, mxr = -1;
	for (int i = 1; i <= mx; i++)
	{
		while (now <= n && seg[now].fir == i) 
		{
			mxr = max(mxr, seg[now].sec);
			if (now <= n) now++;
		}
		if (mxr <= i) mxr = -1;
		rg[i][0] = mxr;
		//printf("%d ", rg[i][0]);
	}
	//puts("");
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= mx; i++)	
		{
			rg[i][j] = rg[i][j - 1] == -1 ? -1 : rg[rg[i][j - 1]][j - 1];
		}
	while (m--)
	{
		int x, y; scanf("%d%d", &x, &y); x++; y++;
		int ans = 0;
		for (int j = 20; j >= 0; --j)
		{
			int tmpy = rg[x][j];
			if (tmpy == -1) continue;
			if (tmpy < y) 
			{
				ans += (1 << j);
				x = tmpy;
			}
		}
		if (rg[x][0] == -1) puts("-1");
		else if (rg[x][0] >= y) printf("%d\n", ans + 1);
		else puts("-1");
	}
	return 0;
}
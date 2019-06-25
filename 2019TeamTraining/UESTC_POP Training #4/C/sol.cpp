#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e5 + 7;
int n, k, a[maxn], root[maxn];
struct node{int l, r, sum;}T[maxn * 25];
int cnt = 0;
int pos[maxn], pre[maxn], nxt[maxn];
int l[100], r[100];
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k); 
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d", &a[i]); pos[a[i]] = i;
			pre[i] = i - 1;
			nxt[i] = i + 1;
		}
		nxt[n + 1] = n + 1;
		pos[n + 1] = n + 1;
		int now, cnt;
		LL ans = 0, tmp;
		for (int i = 1; i <= n; i++)
		{
			now = pos[i]; cnt = 0;
			l[0] = r[0] = now;
			for (int j = 1; j <= k + 1; j++) now = pre[now], l[++cnt] = now;
			now = pos[i]; cnt = 0;
			for (int j = 1; j <= k + 1; j++) now = nxt[now], r[++cnt] = now;
			tmp = 0;
			for (int j = 0; j < k; j++)
			{
				int jj = k - 1 - j;
				tmp += (l[j] - l[j + 1]) * (r[jj + 1] - r[jj]);
			}
			ans += tmp * i;
			now = pos[i];
			pre[nxt[now]] = pre[now];
			nxt[pre[now]] = nxt[now];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

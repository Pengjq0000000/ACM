#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e5 + 7;
int f[maxn], cnt[maxn];
int a[maxn];

int find(int x)
{
	if (x == f[x]) return f[x];
	return f[x] = find(f[x]);
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) f[i] = i, cnt[i] = 1;
	while (m--)
	{
		int x; scanf("%d", &x);
		for (int i = 1; i <= x; i++) scanf("%d", &a[i]);
		for (int i = 1; i < x; i++) 
		{
			int fx = find(a[i]), fy = find(a[i + 1]);
			if (fx != fy)
			{
				f[fy] = fx;
				cnt[fx] += cnt[fy];
			}
		}
	}	
	for (int i = 1; i <= n; i++) printf("%d ", cnt[find(i)]);
	puts("");
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
LL id[maxn];
int p[maxn];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		LL a; int b, c;
		scanf("%lld%d%d", &a, &b, &c);
		id[b] = a; p[b] = c;
	}
	int q; scanf("%d", &q);
	while (q--)
	{
		int x; scanf("%d", &x);
		printf("%lld %d\n", id[x], p[x]);
	}
	return 0;
}

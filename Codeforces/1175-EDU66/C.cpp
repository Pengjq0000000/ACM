#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
int a[maxn];
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int pos = 0, res = 2e9;
		int det = (k + 1) / 2;
		for (int i = 1; i <= n - k; i++)
		{
			LL dis = a[i + k] - (a[i] + a[i + k]) / 2;
			if (dis < res) {res = dis; pos = (a[i] + a[i + k]) / 2;}
		}
		printf("%d\n", pos);
	}
	return 0;
}

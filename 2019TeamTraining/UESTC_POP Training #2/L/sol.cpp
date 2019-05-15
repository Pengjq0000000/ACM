#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int w[maxn];
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
		printf("%d\n", (int)sqrt(abs(w[1] - w[n])));
	}
	return 0;
}

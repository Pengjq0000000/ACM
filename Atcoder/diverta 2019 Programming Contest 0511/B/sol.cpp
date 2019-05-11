#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int main()
{
	int r, b, g, n; scanf("%d%d%d%d", &r, &g, &b, &n);
	int ans = 0;
	for (int i = 0; i * r <= n; i++)
		for (int j = 0; j * g <= n; j++)
		{
			if (n - i * r - j * g < 0) break;
			if ((n - i * r - j * g) % b == 0) ans++;
		}
	printf("%d\n", ans);
	return 0;
}

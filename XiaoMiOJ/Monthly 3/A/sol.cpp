#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
map<int, int>lcnt, rcnt;
int main()
{
	int a, b, c, d, e; scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	for (int i = -50; i <= 50; i++)
		for (int j = -50; j <= 50; j++)
			for (int k = -50; k <= 50; k++)
			{
				if (i == 0 || j == 0 || k == 0) continue;
				int tmp = a * i * i * i + b * j * j * j + c * k * k * k;
				lcnt[tmp]++;
			}
	for (int i = -50; i <= 50; i++)
		for (int j = -50; j <= 50; j++)
		{
			if (i == 0 || j == 0) continue;
			int tmp = d * i * i * i + e * j * j * j;
			rcnt[tmp]++;
		}
	LL ans = 0;
	for (auto x : rcnt)
	{
		if (lcnt.count(x.first))
		{
			ans += x.second * lcnt[x.first];
		}
	}
	printf("%lld\n", ans);
	return 0;
}

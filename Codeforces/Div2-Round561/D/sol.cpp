#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 107;
LL mi[maxn], x[maxn], r[maxn];
int main()
{
	mi[0] = 1; for (int i = 1; i <= 60; i++) mi[i] = mi[i - 1] * 2;
	int q; scanf("%d", &q);
	while (q--)
	{
		LL a, b, m; scanf("%lld%lld%lld", &a, &b, &m);
		if (a == b)
		{
			printf("1 %lld\n", a);
			continue;
		}
		int flag = 0;
		for (LL k = 2; k <= 50; k++)
		{
			LL tmp = b - mi[k - 2] * a;
			if (tmp < 0) break;
			if (mi[k - 2] <= tmp && tmp <= mi[k - 2] * m)
			{
				flag = 1; 
				for (int i = 2; i <= k; i++) r[i] = tmp / mi[k - 2];
				tmp %= mi[k - 2];
				int cnt = k - 3;
				for (int i = 2; i <= k; i++)
				{
					if (tmp == 0) break;
					r[i] += tmp / mi[cnt];
					tmp %= mi[cnt]; cnt = max(0, cnt - 1);
				}
				x[1] = a;
				LL sum = x[1];
				//for (int i = 2; i <= k; i++) printf("%lld ", r[i]);puts("");
				for (int i = 2; i <= k; i++)
				{
					x[i] = sum + r[i];
					sum += x[i];
				}
				printf("%lld", k);
				for (int i = 1; i <= k; i++) printf(" %lld", x[i]);
				break;
			}
			
		}
		if (!flag) puts("-1");else puts("");
	}

	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn << 1];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	int ans = 1e9;
	for (int i = 1; i <= n; i++)
	{
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			res += abs(a[i + j] - j - 1);
		}
		//cout<<res<<endl;
		ans = min(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}

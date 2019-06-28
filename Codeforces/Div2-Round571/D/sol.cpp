#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define eps 1e-6
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
double a[maxn];
LL aa[maxn];
int main()
{
	int n; scanf("%d", &n);
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &a[i]);
		aa[i] = a[i];
		//printf("%lld ", aa[i]);
		sum += aa[i];
	}
	if (sum > 0)
	{
		for (int i = 1; i <= n; i++)
		{
			if (abs(a[i] - aa[i]) < eps) continue;
			if (a[i] < 0) aa[i]--, sum--;
			if (sum == 0) break;
		}
	}
	else if (sum < 0) 
	{
		for (int i = 1; i <= n; i++)
		{
			if (abs(a[i] - aa[i]) < eps) continue;
			if (a[i] > 0) aa[i]++, sum++;
			if (sum == 0) break;
		} 
	}
	for (int i = 1; i <= n; i++) printf("%lld\n", aa[i]);
	return 0;
}

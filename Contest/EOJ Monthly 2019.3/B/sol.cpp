#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
LL a[maxn];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	int i = 1, j = n;
	int ans = 0;
	while (i < j)
	{
		if (a[i] < a[j]) {a[i + 1] += a[i]; i++; ans++;}
		if (a[i] > a[j]) {a[j - 1] += a[j]; j--; ans++;}
		if (a[i] == a[j]) {i++; j--;}  
	}
	printf("%d\n", ans);
	return 0;
}

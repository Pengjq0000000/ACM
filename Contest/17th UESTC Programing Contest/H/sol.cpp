#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
LL step[maxn], S[maxn], A[maxn], B[maxn];
int now = 1;
void print()
{
	for (int i = 1; i <= 20; i++)
	{
		printf("%d: S:%lld, step:%lld\n", i, S[i], step[i]);
	}
	printf("%lld", S[now]);
}
int main()
{
	S[1] = 2, step[1] = 4;
	LL a = 1, b = 1;
	for (int i = 2; i <= 100000; i++)
	{
		now++; a++; S[now] = a * b * 2; step[now] = (a + b) * 2; A[now] = a;
		now++; b++; S[now] = a * b * 2; step[now] = (a + b) * 2; B[now] = b;
	} 
	//print();
	int T; scanf("%d", &T);
	while (T--)
	{
		LL x; scanf("%lld", &x);
		int pos = lower_bound(S + 1, S + 1 + now, x) - S;
		LL ans = step[pos];
		if (S[pos] > x)
		{
			pos--; LL tmp = max(A[pos], B[pos]);
			LL det = (2 * tmp - 1) / 2;
			if (S[pos] + det >= x) ans--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

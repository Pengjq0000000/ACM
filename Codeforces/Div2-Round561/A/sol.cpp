#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
char s[1007];
int cnt[1007];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		cnt[s[0] - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		int a = cnt[i] / 2;
		int b = cnt[i] - a;
		ans += a * (a - 1) / 2 + b * (b - 1) / 2;
	}
	printf("%d\n", ans);
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e4 + 7;
vector<int>pos[maxn];
char s[maxn];
int main()
{
	int n; scanf("%d", &n);
	int tot = 0;
	LL ans = 0;
	while (n--)
	{
		char c; scanf(" %c", &c);
		if (c == '-')
		{
			ans -= pos[tot].size();
			pos[tot--].clear();
		}
		else
		{
			s[++tot] = c;
			if (tot != 1)
			{
			    if (s[tot - 1] == s[tot]) pos[tot].pb(tot - 1);
				for (int x : pos[tot - 1])
				{
                    if (x >= 1 && s[tot] == s[x - 1]) pos[tot].pb(x - 1);
				}
			}
			pos[tot].pb(tot);
			ans += pos[tot].size();
		}
		printf("%lld ", ans);
	}
	return 0;
}

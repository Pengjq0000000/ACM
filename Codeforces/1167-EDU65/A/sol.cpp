#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
char s[1007];
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		int flag = 0;
		scanf(" %s", s);
		for (int i = 0; i < n - 10; i++)
		{
			if (s[i] == '8') flag = 1;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}

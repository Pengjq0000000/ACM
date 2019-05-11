#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int n, bx, xa, ba;
int main()
{
	scanf("%d", &n);
	int ans = 0;
	char s[20];
	for (int i = 1; i <= n; i++)
	{
		scanf(" %s", s);
		int L = strlen(s);
		for (int j = 0; j < L - 1; j++)
		{
			if (s[j] == 'A' && s[j + 1] == 'B') ans++;
		}
		if (s[0] == 'B' && s[L - 1] != 'A') bx++;
		else if (s[0] != 'B' && s[L - 1] == 'A') xa++;
		else if (s[0] == 'B' && s[L - 1] == 'A') ba++;
	}
	if (xa > 0 && bx > 0)
	{
		ans += (ba + 1);
		xa--; bx--;
		ans += min(xa, bx);
	}
	else if (xa == 0 && bx == 0) 
	{
		if (ba > 0)	ans += (ba - 1);
	}
	else 
	{
		ans += ba;
	}
	printf("%d\n", ans);
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
stack<LL>sta;
const LL MAX = (1ll << 32) - 1;
int main()
{
	int n; scanf("%d", &n);
	char s[20]; LL x;
	sta.push(1);
	LL res = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf(" %s", s);
		if (s[0] == 'a') 
		{
			res += sta.top();
			if (res > MAX) 
			{
				puts("OVERFLOW!!!");
				return 0;
			}
		}
		else if (s[0] == 'e') sta.pop();
		else if (s[0] == 'f')
		{
			scanf("%lld", &x);
			sta.push(min(MAX * 10, x * sta.top()));
		}
	}
	printf("%lld\n", res);
	return 0;
}

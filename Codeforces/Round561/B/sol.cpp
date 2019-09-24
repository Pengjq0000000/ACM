#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
char ans[2007][2007];
char table[6] = {'a', 'e', 'i', 'o', 'u'};
int main()
{
	int k; scanf("%d", &k);
	int tmp = sqrt(k + 0.5);
	int flag= 0;
	int n, m;
	for (n = tmp; n >= 5; n--)
	{
		if (k % n) continue;
		m = k / n;
		if (m >= 5)
		{
			flag = 1;
			break;
		}
	}
	if (!flag) puts("-1");
	else
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				printf("%c", table[(i + j) % 5]);
			}
	}
	
	return 0;
}

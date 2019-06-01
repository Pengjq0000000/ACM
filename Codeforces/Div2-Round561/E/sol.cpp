#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int a[55][10007], num[10007], vis[10007];
int main()
{
	int n, m; scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &num[i]);
		for (int j = 1; j <= num[i]; j++) scanf("%d", &a[i][j]);
	}
	int flag = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++) vis[j] = 0;
		for (int j = 1; j <= num[i]; j++) vis[a[i][j]] = 1; 
		
		for (int j = i + 1; j <= m; j++)
		{
			int ff = 0;
			for (int k = 1; k <= num[j]; k++)
				if (vis[a[j][k]])
				{
					ff = 1;
				}
			if (!ff) 
			{
				puts("impossible");
				return 0;
			}
		}
		
	}
	puts("possible");
	return 0;
}

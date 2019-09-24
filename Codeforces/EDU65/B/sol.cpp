#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int ask(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}
int table[10];
int a[6] = {4, 8, 15, 16, 23, 42};
int numa[6], numb[6], vis[60000];
int ans[10];
int main()
{
	for (int x = 1; x <= 4; x++)
	{
		table[x] = ask(x, x + 1);
	}
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 6; k++)
			{
				if (i != j && j != k && k != i)
					if (!numb[1] && a[i] * a[j] == table[1] && a[j] * a[k] == table[2])
					{
						ans[1] = a[i]; ans[2] = a[j]; ans[3] = a[k];
						vis[ans[1]] = vis[ans[2]] = vis[ans[3]] = 1;
					}
			}
	
	ans[4] = table[3] / ans[3];
	ans[5] = table[4] / ans[4];
	vis[ans[4]] = vis[ans[5]] = 1;
	for (int j = 0; j < 6; j++) if (!vis[a[j]]) ans[6] = a[j];
	printf("!");
	for (int i = 1; i <= 6; i++) printf(" %d", ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}

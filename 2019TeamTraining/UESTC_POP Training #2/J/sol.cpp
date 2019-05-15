#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
struct node
{
	int x, y;
	node(int x, int y) : x(x), y(y) {}
	node() {}
}pos[20][20][5];
char a[20][20], mp[20][20];
int ans;
void print(int x, int y, int k)
{
	for (int i = 4 * x + 1; i <= 4 *x + 4; i++)
	{
		for (int j = 4 * y + 1; j <= 4 * y + 4; j++)
		{
			printf("(%d,%d)  ", pos[i][j][k].x, pos[i][j][k].y);
		}
		puts("");
	}
	puts("");
}
void printt()
{
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= 16; j++) printf("%c", mp[i][j]);
		puts("");
	}
	puts("");
}
void init(int x, int y)
{
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
		{
			pos[4 * x + i][4 * y + j][0] = node(4 * x + i, 4 * y + j);
			pos[4 * x + j][4 * y + 5 - i][1] = node(4 * x + i, 4 * y + j);
		}
	//print(x, y, 1);
	for (int k = 2; k <= 4; k++)
	{
		for (int i = 4 * x + 1; i <= 4 * x + 4; i++)
			for (int j = 4 * y + 1; j <= 4 * y + 4; j++)
			{
				pos[i][j][k] = pos[pos[i][j][1].x][pos[i][j][1].y][k - 1];
			}
		//print(x, y, k);
	}
}
int vis[18];
int change(char x)
{
	if (x >= '0' && x <= '9') return (x - '0');
	return (x - 'A' + 10);
}
bool check(int x)
{
	
	for (int i = 4 * x + 1; i <= 4 * x + 4; i++)
	{
		MEM(vis, 0);
		for (int j = 1; j <= 16; j++)
		{
			int x = change(mp[i][j]);
			vis[x]++;
			if (vis[x] > 1) return false;
		}
	}
	return true;
}
bool checkk()
{
	for (int j = 1; j <= 16; j++)
	{
		MEM(vis, 0);
		for (int i = 1; i <= 16; i++)
		{
			int x = change(mp[i][j]);
			vis[x]++;
			if (vis[x] > 1) return false;
		}
	}
	return true;
}
int cnt = 0;
void dfs(int x, int y, int res)
{
	if (res >= ans) return;
	if (y == 4) 
	{
		x++; y = 0;
		if (!check(x - 1)) return;
		if (x == 4) 
		{
			if (!checkk()) return;
			ans = min(ans, res); return;
		}
	}
	for (int k = 0; k < 4; k++)
	{
		for (int i = 4 * x + 1; i <= 4 * x + 4; i++)
			for (int j = 4 * y + 1; j <= 4 * y + 4; j++)
			{
				mp[i][j] = a[pos[i][j][k].x][pos[i][j][k].y];
			} 
		//printt();
		//exit(0);
		dfs(x, y + 1, res + k);
	}
}
int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			init(i, j);
		}
	//return 0;
	int T; scanf("%d", &T);
	while (T--)
	{
		for (int i = 1; i <= 16; i++)
			for (int j = 1; j <= 16; j++)
			{
				scanf(" %c", &a[i][j]);
				mp[i][j] = a[i][j];
			}
		ans = 10000;
		dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	
	return 0;
}

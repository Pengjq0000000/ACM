#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define x first
#define y second
#define mkp(x, y) make_pair(x, y)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2007;
char mp[maxn][maxn];
vector<pii>pos[30];
pii ans[30][2];

bool check1(int id)
{
	int sz = pos[id].size();
	for (int i = 1; i < sz; i++) if (pos[id][i].x != pos[id][i - 1].x) return false;
	return true;
}
bool check2(int id)
{
	int sz = pos[id].size();
	for (int i = 1; i < sz; i++) if (pos[id][i].y != pos[id][i - 1].y) return false;
	return true;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 26; i++) pos[i].clear();
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf(" %c", &mp[i][j]);
				if (mp[i][j] != '.') pos[mp[i][j] - 'a'].pb(mkp(i, j));
			}
		}
		int flg = 1;
		for (int id = 0; id < 26; id++)
		{
			int sz = pos[id].size();
			if (sz == 0) continue;
			if (sz == 1)
			{
				ans[id][0] = ans[id][1] = pos[id][0];
				continue;
			}
			char ch = id + 'a';
			if (pos[id][0].x == pos[id][1].x)
			{
				if (!check1(id)) {flg = 0; break;}
				int i = pos[id][0].x;
				for (int j = pos[id][0].y; j <= pos[id][sz - 1].y; j++)
				{
					if (mp[i][j] < ch) {flg = 0; break;}
				}
				if (flg) {ans[id][0] = pos[id][0]; ans[id][1] = pos[id][sz - 1];}
			}
			else if (pos[id][0].y == pos[id][1].y)
			{
				if (!check2(id)) {flg = 0; break;}
				int j = pos[id][0].y;
				for (int i = pos[id][0].x; i <= pos[id][sz - 1].x; i++)
				{
					if (mp[i][j] < ch) {flg = 0; break;}
				}
				if (flg) {ans[id][0] = pos[id][0]; ans[id][1] = pos[id][sz - 1];}
			}
			else flg = 0;
			if (!flg) break;
		}
		if (!flg) puts("NO");
		else
		{
			int k = 0;
			for (int id = 25; id >= 0; id--)
			{
				if (pos[id].size() != 0) k++;
				if (id > 0 && pos[id].size() != 0 && pos[id - 1].size() == 0)
				{
				    pos[id - 1].pb(mkp(0, 0));
					ans[id - 1][0] = ans[id][0];
					ans[id - 1][1] = ans[id][1];
				}
			}
			puts("YES");
			printf("%d\n", k);
			for (int i = 0; i < k; i++)
			{
				printf("%d %d %d %d\n", ans[i][0].x, ans[i][0].y, ans[i][1].x, ans[i][1].y);
			}
		}
	}
	return 0;
}

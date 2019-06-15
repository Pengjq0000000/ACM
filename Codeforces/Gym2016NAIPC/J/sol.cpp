#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e7 + 7;
int n, m, q;
char mp[maxn];
vector<LL>tag[maxn][4];
LL tim[maxn];
map<LL, bool>vis;
struct node
{
	LL id, val;
	bool operator < (const node &rhs) const 
	{
		return val < rhs.val;
	}
};
priority_queue<node>pq;
inline int pos(int x, int y) {return (x - 1) * m + y;}

void DOIT(int init_i, int init_j, int dx, int dy, int k)
{
	int j = init_j;
	while (j >= 1 && j <= m)
	{
		int i = init_i;
		while (!pq.empty()) 
		{
			vis[pq.top().id] = 0;
			pq.pop();
		}
		int now = 0;
		while (i >= 1 && i <= n)
		{
			int pp = pos(i, j);
			for (LL x : tag[pp][k]) 
			{
				if (x > 0) pq.push({x, x - now});
			}
			while (pq.size() && vis[pq.top().id])
			{
				vis[pq.top().id] = 0;
				pq.pop();
			}
			for (LL x : tag[pp][k])
			{
				if (x <= 0) vis[-x] = 1;
			}
			if (pq.size()) tim[pp] = max(tim[pp], pq.top().val + now);
			i += dx;
			now++;
		}
		j += dy;
	}
}

void doit(int init_i, int init_j, int dx, int dy, int k)
{
	int i = init_i;
	while (i >= 1 && i <= n)
	{
		while (!pq.empty()) 
		{
			vis[pq.top().id] = 0;
			pq.pop();
		}
		int now = 0;
		int j = init_j;
		while (j >= 1 && j <= m)
		{
			int pp = pos(i, j);
			for (LL x : tag[pp][k]) 
			{
				if (x > 0) pq.push({x, x - now});
			}
			while (pq.size() && vis[pq.top().id])
			{
				vis[pq.top().id] = 0;
				pq.pop();
			}
			for (LL x : tag[pp][k])
			{
				if (x <= 0) vis[-x] = 1;
			}
			if (pq.size()) tim[pp] = max(tim[pp], pq.top().val + now);
			j += dy;
			now++;
		}
		i += dx;
	}
}


int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			{
				int pp = pos(i, j);
				scanf(" %c", &mp[pp]);
				tim[pp] = -1;
			}
	
	int nowx = n, nowy = 1;
	tim[pos(n, 1)] = 0;
	LL cnt = 0;
	char s[10];
	while (q--)
	{
		scanf(" %s", s); int d; scanf("%d", &d);
		if (s[0] == 'u')
		{
			tag[pos(nowx - 1, nowy)][0].pb(cnt + 1);
			tag[pos(nowx - d, nowy)][0].pb(-cnt - 1);
			nowx -= d;
		}
		else if (s[0] == 'd')
		{
			tag[pos(nowx + 1, nowy)][1].pb(cnt + 1);
			tag[pos(nowx + d, nowy)][1].pb(-cnt - 1);
			nowx += d;
		}
		else if (s[0] == 'l')
		{
			tag[pos(nowx, nowy - 1)][2].pb(cnt + 1);
			tag[pos(nowx, nowy - d)][2].pb(-cnt - 1);
			nowy -= d;
		}
		else // s[0] == 'r'
		{
			tag[pos(nowx, nowy + 1)][3].pb(cnt + 1);
			tag[pos(nowx, nowy + d)][3].pb(-cnt - 1);
			nowy += d;
		}
		cnt += d;
	}
	DOIT(n, 1, -1, 1, 0);
	DOIT(1, 1, 1, 1, 1);
	doit(1, m, 1, -1, 2);
	doit(1, 1, 1, 1, 3);

	LL L = 0, R = cnt + 1;
	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= m; j++)
		{
			
			int pp = pos(i, j);
			if (tim[pp] == -1) 
			{
				if (mp[pp] == '#') 
				{
					puts("-1 -1");
					return 0;
				}
				continue;
			}
			if (mp[pp] == '.') R = min(R, tim[pp]);
			else L = max(L, tim[pp] + 1);
		}
	}
	if (L > R) puts("-1 -1");
	else printf("%lld %lld\n", L, R);
	return 0;
}

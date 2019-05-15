#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define mkpii make_pair
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
struct node
{
	int v, w, next;
	node(int v, int w) : v(v), w(w) {}
	node(){}
	bool operator < (const node &rhs) const 
	{
		return w > rhs.w;
	}
}e[maxn << 1];
map<pii, int> mp;
int n, m;
int head[maxn], tot = 0;
void add(int u, int v, int w)
{
	++tot; 
	e[tot].v = v; e[tot].w = w; 
	e[tot].next = head[u]; head[u] = tot;
}
int getid(int x, int y)
{
	pii tmp = mkpii(x, y);
	if (!mp.count(tmp)) mp[tmp] = ++n;
	return mp[tmp];
}
priority_queue<node>q;
int dis[maxn], vis[maxn];
int dijkstra(int s, int t)
{
	MEM(dis, 0x3f3f3f3f);
	q.push(node(s, 0)); dis[s] = 0;
	while (!q.empty())
	{
		int u = q.top().v; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].v;
			if (dis[v] > dis[u] + e[i].w)
			{
				dis[v] = dis[u] + e[i].w;
				q.push(node(v, dis[v]));
			}
		}
	}
	return dis[t] >= 0x3f3f3f3f ? -1 : dis[t] / 2;
}
int main()
{
	scanf("%d%d", &n, &m);
	int s = 1, t = n;
	while (m--)
	{
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		int uc = getid(u, c), vc = getid(v, c);
		add(u , uc, 1); add(uc, u, 1);
		add(uc, vc, 0); add(vc, uc, 0);
		add(vc, v, 1); add(v, vc, 1);
	}
	printf("%d\n", dijkstra(s, t));
	return 0;
}
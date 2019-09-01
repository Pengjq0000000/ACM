#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int head[1010], cnt;
struct node{int v; LL w; int next;}e[1010];
void add(int u, int v, LL w)
{
    e[++cnt] = {v, w, head[u]};
    head[u] = cnt;
}
queue<int>q;
int n, m; 
int inq[1010];
LL dis[1010];
LL SPFA(int s, int t)
{
    for (int i = 0; i < n; i++) dis[i] = 1e16;
    while (q.size()) q.pop();
    q.push(s); inq[s] = 1; dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                if (!inq[v]) 
                {
                    inq[v] = 1; q.push(v);
                }
            }
        }
    }
    return dis[t];
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) head[i] = -1;
        cnt = 0;
        for (int i = 1, u, v; i <= m; i++)
        {
            LL w; scanf("%d%d%lld", &u, &v, &w);
            add(u, v, w);
        }
        for (int q = 1; q <= 6; q++)
        {
            int s, t; scanf("%d%d", &s, &t);
            LL val = SPFA(t, s);
            add(s, t, -val);
            printf("%lld\n", -val);
        }
    }
	return 0;
}

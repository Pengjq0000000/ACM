#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
const LL base = 2742;
int n, q, tot, nxt[maxn * 10][26];
bool table[maxn * 10];
char s[maxn * 10], t[maxn * 10];

struct node
{
    int v, next, w;
    node(int v, int w) : v(v), w(w) {}
    node(){}
    bool operator < (const node &rhs) const
    {
        return w > rhs.w;
    }
}e[(maxn * 30) << 1];
int cnt = 0, head[maxn * 10];
void add(int u, int v, int w)
{
    ++cnt;
    e[cnt].v = v; e[cnt].w = w; e[cnt].next = head[u];
    head[u] = cnt;
}

void insert(char *s)
{
    int len = strlen(s);
    int now = 0;
    for (int i = 0; i < len; i++)
    {
        int ch = s[i] - 'a';
        if (!nxt[now][ch])
        {
            nxt[now][ch] = ++tot;
        }
        now = nxt[now][ch];
    }
    int aim = now;
    now = 0;
    for (int i = 0; i < len; i++)
    {
        int ch = s[i] - 'a';
        now = nxt[now][ch];
        if (!table[now])
        {
            table[now] = 1;
            add(now, aim, 1);
        }
    }
}

int dis[maxn * 10], VIS[maxn * 10];
priority_queue<node>pq;
void dijkstra(int s)
{
    for (int i = 0; i <= tot; i++) dis[i] = 1e9, VIS[i] = 0;
    dis[s] = 0;
    pq.push(node(s, 0));
    while (!pq.empty())
    {
        int u = pq.top().v; pq.pop();
        if (VIS[u]) continue; VIS[u] = 1;
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                pq.push(node(v, dis[v]));
            }
        }
    }
}
int main()
{
	scanf("%d%d", &n, &q);
    tot = 0;
    MEM(head, -1);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %s", s);
        insert(s);
    }
    for (int i = 0; i <= tot; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (nxt[i][j])
            {
                add(i, nxt[i][j], 1);
                add(nxt[i][j], i, 1);
            }
        }
    }
    dijkstra(0);
    while (q--)
    {
        scanf(" %s", t);
        int lt = strlen(t);
        int ans = lt;
        int now = 0;
        for (int i = 0; i < lt; i++)
        {
            int ch = t[i] - 'a';
            if (!nxt[now][ch]) break;
            now = nxt[now][ch];
            ans = min(ans, dis[now] + lt - (i + 1));
        }
        printf("%d\n", ans);
    }
	return 0;
}

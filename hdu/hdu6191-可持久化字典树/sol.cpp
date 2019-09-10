#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct Nd{int nxt[2], cnt;}T[maxn * 35];
int rt[maxn], tot;
int newp() {++tot; T[tot].nxt[0] = T[tot].nxt[1] = T[tot].cnt = 0; return tot;}
void ins(int *s, int rt, int pre)
{
    int now = rt;
    for (int i = 0; i < 30; i++)
    {
        T[now] = T[pre];
        T[now].nxt[s[i] ^ 1] = T[pre].nxt[s[i] ^ 1];
        T[now].nxt[s[i]] = newp();
        T[now].cnt = T[pre].cnt + 1;
        now = T[now].nxt[s[i]]; pre = T[pre].nxt[s[i]];
    }
    T[now].cnt = T[pre].cnt + 1;
}
int query(int *s, int pre, int now)
{
    int res = 0;
    for (int i = 0; i < 30; i++)
    {
        if (T[T[now].nxt[s[i] ^ 1]].cnt - T[T[pre].nxt[s[i] ^ 1]].cnt > 0)
        {
            now = T[now].nxt[s[i] ^ 1], pre = T[pre].nxt[s[i] ^ 1];
            res = res * 2 + 1;
        }
        else
        {
            now = T[now].nxt[s[i]], pre = T[pre].nxt[s[i]];
            res *= 2;
        }
    }
    return res;
}
vector<int>E[maxn];
int tim, in[maxn], id[maxn], out[maxn];
void dfs(int u, int fa)
{
    in[u] = ++tim; id[tim] = u;
    for (int v : E[u]) if (v != fa) dfs(v, u);
    out[u] = tim;
}
int a[maxn], t[maxn];
int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), E[i].clear();
        for (int u = 2, v; u <= n; u++) scanf("%d", &v), E[u].push_back(v), E[v].push_back(u);
        tim = 0; dfs(1, 0);
        tot = 0;
        for (int i = 1; i <= n; i++)
        {
            rt[i] = newp();
            int x = a[id[i]];
            for (int i = 1; i <= 30; i++, x >>= 1) t[30 - i] = (x & 1);
            ins(t, rt[i], rt[i - 1]);
        }
        while (q--)
        {
            int u, x; scanf("%d%d", &u, &x);
            for (int i = 1; i <= 30; i++, x >>= 1) t[30 - i] = (x & 1);
            printf("%d\n", query(t, rt[in[u] - 1], rt[out[u]]));
        }
    }
    return 0;
}

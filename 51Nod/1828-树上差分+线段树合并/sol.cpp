#include<bits/stdc++.h>
#define lson ls[rt]
#define rson rs[rt]
#define MOD(x) ((x) % mod)
#define LL long long
#define mod 1000000007
using namespace std;
int read() 
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int N = 5e5 + 7;
const int M = (5e5 + 7) * 20;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {LL res = (LL)x * y; res -= res / mod * mod; return res;}
int n, m;
vector<int>append[N], del[N];
int head[N], tot = 0;
struct edge{int v, next, w;}e[N << 1];
void adde(int u, int v, int w)
{
    e[++tot] = {v, head[u], w};
    head[u] = tot;
}
inline LL C(LL x) {return MOD(x * (x + 1) / 2);}
int ls[M], rs[M], pre[M], suf[M], res[M];
int root[N], cnt = 0;
void pushup(int rt, int l, int r)
{
    int mid = (l + r) >> 1;
    pre[rt] = pre[ls[rt]]; if (pre[ls[rt]] == mid - l + 1) pre[rt] += pre[rs[rt]]; 
    suf[rt] = suf[rs[rt]]; if (suf[rs[rt]] == r - mid) suf[rt] += suf[ls[rt]];
    res[rt] = add(res[ls[rt]], res[rs[rt]]);
    int det = C(suf[ls[rt]] + pre[rs[rt]]) - add(C(suf[ls[rt]]), C(pre[rs[rt]]));
    if (det < 0) det += mod;
    res[rt] = add(res[rt], det); 
}
void update(int &rt, int l, int r, int pos)
{
    if (!rt) rt = ++cnt;
    if (l == r) {pre[rt] ^= 1; suf[rt] ^= 1; res[rt] = C(pre[rt]); return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, l, mid, pos);
    else update(rson, mid + 1, r, pos);
    pushup(rt, l, r);
}
int merge(int u, int v, int l, int r)
{
    if (!u || !v) return u + v;
    if (l == r) 
    {
        pre[u] = suf[u] = res[u] = res[u] ^ res[v];
        return u;
    }
    int mid = (l + r) >> 1;
    ls[u] = merge(ls[u], ls[v], l, mid);
    rs[u] = merge(rs[u], rs[v], mid + 1, r);
    pushup(u, l, r);
    return u;
}
LL ans = 0;
void cal(int u, int val, int fa)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa) continue;
        cal(v, e[i].w, u);
        root[u] = merge(root[u], root[v], 1, m);
    }
    for (int x : append[u]) update(root[u], 1, m, x);
    ans = add(ans , mul(res[root[u]], val));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v, z; i < n; i++)
    {
        //scanf("%d%d%d", &u, &v, &z);
        u = read(); v = read(); z = read();
        adde(u, v, z); adde(v, u, z);
    }
    scanf("%d", &m);
    for (int i = 1, u, v; i <= m; i++)
    {
        //scanf("%d%d", &u, &v);
        u = read(); v = read();
        append[u].push_back(i);
        append[v].push_back(i);    
    }
    ans = 0; cal(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}
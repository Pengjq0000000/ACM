    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
    const int MAXN = 1e5 + 7;
    const int mod = 1e9 + 7;
    inline int lowbit(int x) {return x & -x;}
    inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;} 
    inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
    inline void upd(int &x, int y) {x = add(x, y);}
    int inv[MAXN];
    int ksm(int a, int b) {int res = 1; for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a); return res;}
    struct BIT
    {
        int c[MAXN];
        inline void update(int x, int v) {for (; x < MAXN; x += lowbit(x)) upd(c[x], v);}
        inline int get(int x) {int res = 0; for (; x; x -= lowbit(x)) upd(res, c[x]); return res;}
        inline int query(int x, int y) {return add(get(y), mod - get(x - 1));}
        inline void clr(int x) {for (; x < MAXN; x += lowbit(x)) c[x] = 0;}
    }T[4];
    int P = 1;
    vector<int>G[MAXN];
    int lp[MAXN], rp[MAXN], ans;
     
    bool del[MAXN];
    int rt, tot, rt_sz, sz[MAXN], son[MAXN], dis[MAXN];
    void dfs(int u, int fa)
    {
        sz[u] = 1, son[u] = 0; 
        for (int v : G[u]) if (v != fa && !del[v])
        {
            dfs(v, u), sz[u] += sz[v]; 
            son[u] = max(son[u], sz[v]);
        }
        if (rt_sz > (max(son[u], tot - sz[u]))) rt_sz = max(son[u], tot - sz[u]), rt = u;
    }
    vector<int>vec;
    void dfs1(int u, int fa)
    {
        sz[u] = 1; vec.push_back(u); 
        for (int v : G[u]) if (v != fa && !del[v])
            dis[v] = dis[u] + 1, dfs1(v, u), sz[u] += sz[v];
    }
    void dfs2(int u, int fa)
    {
        vec.push_back(u);
        for (int v : G[u]) if (v != fa && !del[v])
            dfs2(v, u);
    }
    bool cmp(int &x, int &y) {return lp[x] < lp[y];}
    void cal(int sig)
    {
        sort(vec.begin(), vec.end(), cmp);
        // T[0] : 1 / v[j]
        // T[1] : dis[j] / v[j]
        // T[2] : rp[j] / v[j]
        // T[3] : dis[j] * rp[j] / v[j]
        int temp = 0;
        for (int i : vec)
        {
            upd(temp, mul(dis[i], T[0].query(rp[i] + 1, MAXN - 1)));
            upd(temp, T[1].query(rp[i] + 1, MAXN - 1));
            upd(temp, mul(T[0].query(lp[i], rp[i]), mul(dis[i], mul(inv[i], 1 + mod - lp[i])))); 
            upd(temp, mul(T[1].query(lp[i], rp[i]), mul(inv[i], 1 + mod - lp[i])));
            upd(temp, mul(T[2].query(lp[i], rp[i]), mul(dis[i], inv[i])));
            upd(temp, mul(T[3].query(lp[i], rp[i]), inv[i]));
            T[0].update(rp[i], inv[i]);
            T[1].update(rp[i], mul(dis[i], inv[i]));
            T[2].update(rp[i], mul(rp[i], inv[i]));
            T[3].update(rp[i], mul(dis[i], mul(rp[i], inv[i])));
        }
        for (int i : vec)
            for (int j = 0; j < 4; j++)
                T[j].clr(rp[i]);
        upd(ans, mul(temp, sig));
    }
    void solve(int u)
    {
        rt_sz = tot; dfs(u, 0); u = rt;
        vec.clear(); dis[rt] = 0; dfs1(rt, 0); cal(1);
        for (int v : G[u]) if (!del[v])
            vec.clear(), dfs2(v, rt), cal(mod - 1);
        del[u] = 1;
        for (int v : G[u]) if (!del[v])
            tot = sz[v], solve(v);
    }
    int main()
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) 
        {
            scanf("%d%d", &lp[i], &rp[i]);
            inv[i] = ksm(rp[i] - lp[i] + 1, mod - 2); 
            P = mul(P, rp[i] - lp[i] + 1);
        }
        for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
        tot = n; solve(1);
        printf("%d\n", mul(ans, P));
        return 0;
    }
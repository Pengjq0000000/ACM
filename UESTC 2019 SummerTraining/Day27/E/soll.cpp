#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE = 30000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init() {
#ifdef LOCAL
    freopen("2049.txt", "r", stdin);
#else
    // freopen("sdoi2008_cave.in","r",stdin);
    // freopen("sdoi2008_cave.out","w",stdout);
#endif
    buf[fread(buf, 1, MAXSIZE, stdin)] = '\0';
    bufpos = 0;
}
#if NEG
int readint() {
    bool isneg;
    int val = 0;
    for (; !isdigit(buf[bufpos]) && buf[bufpos] != '-'; bufpos++)
        ;
    bufpos += (isneg = buf[bufpos] == '-');
    for (; isdigit(buf[bufpos]); bufpos++) val = val * 10 + buf[bufpos] - '0';
    return isneg ? -val : val;
}
#else
int readint() {
    int val = 0;
    for (; !isdigit(buf[bufpos]); bufpos++)
        ;
    for (; isdigit(buf[bufpos]); bufpos++) val = val * 10 + buf[bufpos] - '0';
    return val;
}
#endif
char readchar() {
    for (; isspace(buf[bufpos]); bufpos++)
        ;
    return buf[bufpos++];
}
int readstr(char* s) {
    int cur = 0;
    for (; isspace(buf[bufpos]); bufpos++)
        ;
    for (; !isspace(buf[bufpos]); bufpos++) s[cur++] = buf[bufpos];
    s[cur] = '\0';
    return cur;
}
const int maxn = 500002;
struct ufs {
    int rk[maxn], fa[maxn];
    pair<int, int> stk[maxn * 2];  // 0 :rk[second]++,>0:set fa first,orginal second
    int tp;
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int getf(int x) {
        while (x != fa[x]) x = fa[x];
        return x;
    }
    void mer(int x, int y) {
        x = getf(x), y = getf(y);
        if (x == y)
            return;
        if (rk[x] > rk[y])
            swap(x, y);
        stk[++tp] = make_pair(x, fa[x]);
        fa[x] = y;
        if (rk[x] == rk[y]) {
            rk[y]++;
            stk[++tp] = make_pair(0, y);
        }
    }
    int getver() { return tp; }
    void roolback(int p) {
        while (tp != p) {
            if (stk[tp].first)
                fa[stk[tp].first] = stk[tp].second;
            else
                rk[stk[tp].second]--;
            tp--;
        }
    }
} s;
struct edge {
    int u, v;
    bool operator<(const edge& rhs) const { return u == rhs.u ? v < rhs.v : u < rhs.u; }
};
struct segtree {
    int n;
    vector<edge> t[(1 << 20) + 3];
    int ul, ur;
    edge v;
    void update(int o, int l, int r) {
        if (ul <= l && ur >= r) {
            t[o].push_back(v);
            return;
        }
        int mid = (l + r) / 2;
        if (ul <= mid)
            update(o * 2, l, mid);
        if (ur > mid)
            update(o * 2 + 1, mid + 1, r);
    }
    void update(int l, int r, edge v) {
        // printf("update %d %d %d %d\n",l,r,v.u,v.v);
        if (l > r)
            return;
        ul = l, ur = r;
        this->v = v;
        update(1, 1, n);
    }
    edge q[maxn];
    int ans[maxn];
    void dfs(int o, int l, int r) {
        int ver = s.getver();
        for (int i = 0; i < t[o].size(); i++) s.mer(t[o][i].u, t[o][i].v);
        if (l == r)
            ans[l] = s.getf(q[l].u) == s.getf(q[l].v);
        else {
            int mid = (l + r) / 2;
            dfs(o * 2, l, mid);
            dfs(o * 2 + 1, mid + 1, r);
        }
        s.roolback(ver);
    }
    void work(int qwq) {
        s.init(qwq);
        dfs(1, 1, n);
    }
} t;
map<edge, int> mp;
struct query {
    edge e;
    int l, r;
} q[maxn];
int main() {
    init();
    int n = readint(), m = readint(), tim = 0, cur = 0;
    while (m--) {
        char c = readchar();
        int u = readint(), v = readint();
        if (u > v)
            swap(u, v);
        edge e = (edge){ u, v };
        if (c == '2')
            t.q[++tim] = e;
        else if (c == '0')
            mp[e] = tim;
        else
            q[++cur] = (query){ e, mp[e] + 1, tim }, mp[e] = -1;
    }
    // puts("WTF");
    if (!tim)
        return 0;
    t.n = tim;
    for (map<edge, int>::iterator it = mp.begin(); it != mp.end(); it++)
        if (it->second != -1)
            t.update(it->second + 1, tim, it->first);
    for (int i = 1; i <= cur; i++) t.update(q[i].l, q[i].r, q[i].e);
    // puts("WTF");
    t.work(n);
    for (int i = 1; i <= tim; i++) puts(t.ans[i] ? "Y" : "N");
}

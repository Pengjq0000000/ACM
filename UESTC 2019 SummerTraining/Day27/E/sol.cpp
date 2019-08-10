#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000002;
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
    vector<edge> t[maxn << 2];
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

int uu[maxn], vv[maxn], lll[maxn], rrr[maxn];
vector<int>vec;
struct node{
    int opt, u, v;
    node(int opt, int u, int v) : opt(opt), u(u), v(v) {}
    node(){}
};
vector<node>qq[maxn];
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
ll xx[maxn], yy[maxn];
int main() {
    //init();
    //int nn = readint(), mm = readint();
    int nn, mm; scanf("%d%d", &nn, &mm);
    for (int i = 1; i <= mm; i++)
    {
        //uu[i] = readint(); vv[i] = readint();
        //lll[i] = readint(); rrr[i] = readint() + 1;
        scanf("%d%d%d%d", &uu[i], &vv[i], &lll[i], &rrr[i]);
        rrr[i]++;
        vec.push_back(lll[i]); vec.push_back(rrr[i]);        
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int N = vec.size();
    //printf("N:%d\n", N);
    for (int i = 1; i <= mm; i++)
    {
        lll[i] = getid(lll[i]); rrr[i] = getid(rrr[i]);
    }
    int tot = 0;
    for (int i = 1; i <= mm; i++)
    {
        qq[lll[i]].push_back(node(0, uu[i], vv[i]));
        qq[rrr[i]].push_back(node(1, uu[i], vv[i]));
        tot++;
    }
    int n = nn, m = tot, tim = 0, cur = 0;
    for (int i = 1; i <= N; i++) {
        for (node x : qq[i])
        {
            int u = x.u, v = x.v;
            if (u > v) swap(u, v);
            edge e = (edge){ u, v };
            char c = '0' + x.opt;
            //printf("tim=%d,opt:%c %d %d\n",vec[i], c, u, v);
            if (c == '2')
                t.q[++tim] = e;
            else if (c == '0')
                mp[e] = tim;
            else
                q[++cur] = (query){ e, mp[e] + 1, tim }, mp[e] = -1;
        }
        edge e = (edge) {1, n};
        t.q[++tim] = e;
        if (i == N) xx[tim] = yy[tim] = 0;
        else 
        {
            xx[tim] = vec[i - 1]; yy[tim] = vec[i];
        }
        //printf("xx=%d, yy=%d\n", xx[tim], yy[tim]);
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
    ll res = 0;
    for (int i = 1; i <= tim; i++) 
    {
        if (t.ans[i])
        {
            res += yy[i] - xx[i];
        }
        //puts(t.ans[i] ? "Y" : "N");
    }
    printf("%lld\n", res);
}
/*
7 9
1 2 10 10
2 6 10 10
1 3 40 40
3 6 40 40
6 7 10 40
1 4 30 50
4 7 30 50
1 5 20 20
5 7 20 20
 */
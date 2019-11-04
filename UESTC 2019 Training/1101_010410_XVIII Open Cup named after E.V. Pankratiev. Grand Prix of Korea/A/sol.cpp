#include<bits/stdc++.h>
#define pii pair<ll, ll>
#define fir first
#define sec second
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
using namespace std;
const int maxn = 2e5 + 7;

int T[maxn << 6], lazy[maxn << 6];
void pushup(int rt) {T[rt] = max(T[lson], T[rson]);}
void upd(int rt, int v) {T[rt] += v; lazy[rt] += v; return;}
void pushdown(int rt)
{
    if (lazy[rt] == 0) return;
    upd(lson, lazy[rt]); upd(rson, lazy[rt]);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, int v)
{
    if (L <= l && r <= R) {upd(rt, v); return;}
    int mid = (l + r) >> 1;
    pushdown(rt);
    if (L <= mid) update(lson, l, mid, L, R, v);
    if (mid <  R) update(rson, mid + 1, r, L, R, v);
    pushup(rt);
}
vector<ll>vec;
pii p[maxn]; int c[maxn];
inline int id(ll x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}

struct line{ll l, r; int v;};
vector<line>opts[maxn << 5];
bool check(int x) {return x >= -1000000000 && x <= 1000000000;}
int main()
{
    int n; ll L, R; scanf("%d%lld%lld", &n, &L, &R);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%d", &p[i].fir, &p[i].sec, &c[i]);
        ll x = p[i].fir, y = p[i].sec;
        vec.push_back(x - R); vec.push_back(x + R + 1);
        vec.push_back(y - R); vec.push_back(y + R); 
        vec.push_back(x - L + 1); vec.push_back(x + L); 
        vec.push_back(y - L + 1); vec.push_back(y + L - 1);

        vec.push_back(y + L); vec.push_back(y - L);
        vec.push_back(x - L); vec.push_back(x + L);
        vec.push_back(x - R); vec.push_back(x + R);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int N = vec.size();
    for (int i = 1; i <= n; i++)
    {
        ll x = p[i].fir, y = p[i].sec;
        opts[id(x - R)].push_back({id(y - R), id(y + R), c[i]});
        opts[id(x - L + 1)].push_back({id(y - L + 1), id(y + L - 1), -c[i]});
        opts[id(x + L)].push_back({id(y - L + 1), id(y + L - 1), c[i]});
        opts[id(x + R + 1)].push_back({id(y - R), id(y + R), -c[i]});
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (line opt : opts[i]) update(1, 1, N, opt.l, opt.r, opt.v);
        ans = max(ans, T[1]);
    }
    printf("%d\n", ans);
    return 0;
}
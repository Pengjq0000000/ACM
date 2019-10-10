#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxm = 2e5 + 7;
const int maxn = 4e4 + 7;
int n, m; 
// segment tree for |S| < bound
struct node{int l, r, sum;}T[maxm * 20];
int root[maxn], cnt = 0;
void update(int &rt, int l, int r, int pos)
{
    if (!rt) rt = ++cnt;
    T[rt].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(T[rt].l, l, mid, pos);
    else update(T[rt].r, mid + 1, r, pos);
}
int query(int rt, int l, int r, int L, int R)
{
    if (!rt) return 0;
    if (L <= l && r <= R) return T[rt].sum;
    int mid = (l + r) >> 1, res = 0;
    if (L <= mid) res += query(T[rt].l, l, mid, L, R);
    if (mid <  R) res += query(T[rt].r, mid + 1, r, L, R);
    return res;
}

// B.I.T for |S| >= bound
inline int lowbit(int x) {return x & -x;}
LL c[407][maxn];
void upd(int i, int p, int v) {for (int x = p; x <= n; x += lowbit(x)) c[i][x] += v;}
LL qsum(int i, int l, int r)
{
    LL res = 0;
    for (int x = r; x; x -= lowbit(x)) res += c[i][x];
    for (int x = l - 1; x; x -= lowbit(x)) res -= c[i][x];
    return res;
}
int id[maxn], tot = 0;

struct query{int type, p, l, r, w;}Q[maxm];
vector<int>vec, pos[maxm], S[maxn];
int vis[407][maxm];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        char s[2]; scanf(" %s", s);
        if (s[0] == 'I') scanf("%d%d", &Q[i].p, &Q[i].w), Q[i].type = 1, vec.push_back(Q[i].w);
        else scanf("%d%d%d", &Q[i].p, &Q[i].l, &Q[i].r), Q[i].type = 2;
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 1; i <= m; i++)
        if (Q[i].type == 1) Q[i].w = lower_bound(vec.begin(), vec.end(), Q[i].w) - vec.begin() + 1;
    int bound = 500;
    for (int i = 1; i <= m; i++)
    {
        int p = Q[i].p, l = Q[i].l, r = Q[i].r, w = Q[i].w;
        if (Q[i].type == 1) 
        {
            update(root[w], 1, n, p);
            
            for (int j = 1; j <= tot; j++) if (vis[j][w]) upd(j, p, vec[w - 1]);
            
            S[p].push_back(w); pos[w].push_back(p);
            if (S[p].size() > bound)
            {
                vis[id[p]][w] = 1;
                for (int x : pos[w]) upd(id[p], x, vec[w - 1]);
            }
            else if (S[p].size() == bound)
            {
                id[p] = ++tot;
                for (int num : S[p]) 
                {
                    vis[id[p]][num] = 1;
                    for (int x : pos[num]) upd(id[p], x, vec[num - 1]);
                }
            }
        }
        else 
        {
            LL res = 0;
            if (S[p].size() < bound) 
            {
                for (int num : S[p]) 
                    res += (LL)vec[num - 1] * query(root[num], 1, n, l, r);
            }
            else res = qsum(id[p], l, r);
            printf("%lld\n", res);
        }
    }
    return 0;
}
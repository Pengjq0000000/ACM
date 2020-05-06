#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;

#define lson (rt << 1)
#define rson (rt << 1 | 1)
int T[MAXN << 2];
void pushup(int rt) {T[rt] = max(T[lson], T[rson]);}
void update(int rt, int l, int r, int pos, int v){
    if (l == r) {T[rt] = v; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, l, mid, pos, v);
    else update(rson, mid + 1, r, pos, v);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R){
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1, res = 0;
    if (L <= mid) res = max(res, query(lson, l, mid, L, R));
    if (mid <  R) res = max(res, query(rson, mid + 1, r, L, R));
    return res;
}

int N;
vector<int>vec;
vector<int>G[MAXN];
int a[MAXN], ans[MAXN];
void dfs(int u, int fa){
    assert(a[u] <= N);
    int backup = query(1, 1, N, a[u], a[u]);
    int now = query(1, 1, N, 1, a[u] - 1) + 1;
    update(1, 1, N, a[u], now);
    ans[u] = T[1];
    assert(now >= backup);
    for (int v : G[u]) if (v != fa) 
        dfs(v, u);
    update(1, 1, N, a[u], backup);
}

inline int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 2;}
int main(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vec.push_back(a[i]);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 1; i <= n; i++) a[i] = getid(a[i]);
    for (int i = 1, u, v; i < n; i++){
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    N = vec.size() + 1;
    dfs(1, 0);
    for (int u = 1; u <= n; u++) printf("%d\n", ans[u]);
    for (int i = 1; i <= 4 * N; i++) assert(T[i] == 0);
    return 0;
}
#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
int n, m; 
int f[maxn], sz[maxn], L[maxn], R[maxn];
int fa(int x) {return x == f[x] ? f[x] : fa(f[x]);}
vector<int>vec;
vector<pii>q[maxn << 2];
pii e[maxn];

void update(int rt, int l, int r, int id)
{
    if (L[id] <= l && r < R[id])
    {
        q[rt].pb(e[id]);
        //printf("update l=%d r=%d add %d-%d\n", l, r, e[id].fir, e[id].sec);
        return;
    }
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (L[id] <= mid) update(rt << 1, l, mid, id);
    if (mid <  R[id]) update(rt << 1 | 1 , mid + 1, r, id);
}
LL ans = 0;
void dfs(int rt, int l, int r)
{
    vector<pair<int*, int> >op;
    for (pii edge : q[rt])
    {
        int u = fa(edge.fir), v = fa(edge.sec);
        if (u == v) continue;
        //printf("[l=%d, r=%d] add edge [%d-%d]", l, r, edge.fir, edge.sec);
        if (sz[u] > sz[v]) swap(u, v);
        op.pb({&f[u], f[u]}); f[u] = v; 
        op.pb({&sz[v], sz[v]}); sz[v] += sz[u];
    }
    if (l == r)
    {
        if (fa(1) == fa(n)) 
        {
            //for (int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
            ans += vec[l] - vec[l - 1];
        }
    }
    else 
    {
        int mid = (l + r) >> 1;
        dfs(rt << 1, l, mid);
        dfs(rt << 1 | 1, mid + 1, r);
    }
    //rollback
    for (auto iter = op.rbegin(); iter != op.rend(); iter++) (*iter->fir) = iter->sec;
}
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &e[i].fir, &e[i].sec);
        scanf("%d%d", &L[i], &R[i]);
        R[i]++;
        vec.pb(L[i]); vec.pb(R[i]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int N = vec.size();
    for (int i = 1; i <= m; i++) 
    {
        L[i] = getid(L[i]), R[i] = getid(R[i]);
        update(1, 1, N, i);
    }
    for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
    dfs(1, 1, N);
    printf("%lld\n", ans);
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 10007;
vector<int>vec;
int L[maxn], R[maxn], S[maxn];
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
struct node{int v, next, w;}e[maxn * 20];
int head[maxn], tot;
void add(int u, int v, int w)
{
    e[++tot] = {v, head[u], w};
    head[u] = tot;
    //printf("%d %d %d\n", u, v, w);
}
int N;
queue<int>q;
int vis[maxn], cnt[maxn];
LL dis[maxn];
LL SPFA1()
{
    for (int i = 1; i <= N; i++) vis[i] = cnt[i] = 0, dis[i] = -1e18;
    while (!q.empty()) q.pop();
    q.push(1); dis[1] = 0; vis[1] = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop(); vis[u] = 0;
        cnt[u]++;
        if (cnt[u] >= max(100, 2 * N)) return -1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] < dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v]) {q.push(v); vis[v] = 1;}
            }
        }
    }
    return dis[N] == -1e18 ? -1 : dis[N];
}
LL SPFA2()
{
    for (int i = 1; i <= N; i++) vis[i] = cnt[i] = 0, dis[i] = 1e18;
    while (!q.empty()) q.pop();
    q.push(1); dis[1] = 0; vis[1] = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop(); vis[u] = 0;
        cnt[u]++;
        if (cnt[u] >= max(100, 2 * N)) return -1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v]) {q.push(v); vis[v] = 1;}
            }
        }
    }
    return dis[N] == 1e18 ? -1 : dis[N];
}
int v[maxn];
int main()
{
    //freopen("jordan.in", "r", stdin);
    //freopen("jordan.out", "w", stdout);
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &L[i], &R[i], &S[i]);
        L[i] *= 2; L[i]--; R[i] *= 2;
        vec.push_back(R[i]); vec.push_back(L[i]);
        //vec.push_back(L[i] - 1);
    }
    //vec.push_back(-2e9 - 1);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    N = vec.size();
    for (int i = 1; i <= n; i++)
    {
        L[i] = getid(L[i]), R[i] = getid(R[i]);
        for (int j = L[i]; j < R[i]; j++) v[j] = 1;
    }
    for (int i = 1; i <= n; i++) 
    {
        add(L[i], R[i], S[i]);
        add(R[i], L[i], -S[i]);
    }
    for (int i = 1; i < N; i++) 
    {
        add(i + 1, i, 0);
        if (!v[i]) add(i, i + 1, 0);
    }
    LL ans_max = SPFA2();

    tot = 0; memset(head, 0, sizeof(head));
    for (int i = 1; i <= n; i++) 
    {
        add(L[i], R[i], S[i]);
        add(R[i], L[i], -S[i]);
    }
    for (int i = 1; i < N; i++) 
    {
        add(i, i + 1, 0);
        if (!v[i]) add(i + 1, i, 0);
    }
    LL ans_min = SPFA1();

    printf("%lld %lld\n", ans_min, ans_max);
    return 0;
}
#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 4e5 + 7;
int uu[maxn], vv[maxn];
vector<int>froma[maxn], fromb[maxn];
int n, m, a, b;
int head[maxn], tot = 1;
struct node{int u, v, next, w;}E[maxn];
void add(int u, int v, int w)
{
    ++tot;
    E[tot].u = u; E[tot].v = v; E[tot].next = head[u]; E[tot].w = w; 
    head[u] = tot;
}
bool check(int x)
{
    if (x == m + 1) return false;
    for (int i = 1; i <= n; i++)
    {
        froma[i].clear(); fromb[i].clear();
    }
    for (int i = head[a]; i; i = E[i].next)
    {
        if (i / 2 > x) continue;
        int u = E[i].v;
        if (u == b) continue;
        for (int j = head[u]; j; j = E[j].next)
        {
            if (j / 2 > x) continue;
            int v = E[j].v;
            if (v != a && v != b) froma[v].pb(u);
        }
    }
    for (int i = head[b]; i; i = E[i].next)
    {
        if (i / 2 > x) continue;
        int u = E[i].v;
        if (u == a) continue;
        for (int j = head[u]; j; j = E[j].next)
        {
            if (j / 2 > x) continue;
            int v = E[j].v;
            if (v != a && v != b) fromb[v].pb(u);
        }
    }
    //assert(cnt > 4 * n);
    for (int i = 2; i <= 2 * x + 1; i++)
    {
        int u = E[i].u, v = E[i].v;
        int ua = froma[u].size(), vb = fromb[v].size();
        if (ua == 0 || vb == 0) continue;
        if (ua >= 3 && vb >= 3) return true;
        if (ua <= 2 && vb >= 3)
        {
            for (int ii = 0; ii < ua; ii++)
                if (froma[u][ii] != v) return true;
            continue;
        }
        if (vb <= 2 && ua >= 3)
        {
            for (int ii = 0; ii < vb; ii++)
                if (fromb[v][ii] != u) return true;
            continue;
        }
        for (int ii = 0; ii < ua; ii++)
            for (int jj = 0; jj < vb; jj++)
                if (froma[u][ii] != fromb[v][jj] && froma[u][ii] != v && fromb[v][jj] != u) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &uu[i], &vv[i]);
        add(uu[i], vv[i], i); add(vv[i], uu[i], i); 
    }
    scanf("%d%d", &a, &b);
    int l = 1, r = m + 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l <= m ? l : -1);
    return 0;
}

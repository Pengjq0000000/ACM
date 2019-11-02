#include<bits/stdc++.h>
#define ull unsigned long long
#define mod 1000000007
using namespace std;
ull k1, k2;
ull xorShift128Plus()
{
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
const int N = 100001;
int n, m, u[N], v[N];
ull w[N];
unordered_map<ull, int>cnt;
void gen()
{
    scanf("%d%d%llu%llu", &n, &m, &k1, &k2);
    for (int i = 1; i <= m; i++)
    {
        u[i] = xorShift128Plus() % n + 1;
        v[i] = xorShift128Plus() % n + 1;
        w[i] = xorShift128Plus();
    }
}
struct node{int u, v; ull w;}e[N];
bool cmp(node &x, node &y) {return x.w < y.w;}
int f[N];
int fa(int x) {return x == f[x] ? x : f[x] = fa(f[x]);}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        gen();
        for (int i = 1; i <= m; i++) e[i] = {u[i], v[i], w[i]};
        sort(e + 1, e + 1 + m, cmp);
        for (int i = 1; i <= n; i++) f[i] = i;
        int tot = 0; ull ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int x = fa(e[i].u), y = fa(e[i].v);
            if (x != y) f[x] = y, ans = (ans + e[i].w) % mod, tot++;
        }
        if (tot == n - 1) printf("%llu\n", ans);
        else puts("0");
    }
    return 0;
}
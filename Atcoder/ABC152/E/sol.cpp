#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
int vis[maxn];
int prime[maxn], mu[maxn], minprim[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) 
{
    minprim[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i])
        {
            prime[++tot] = i; minprim[i] = i;
        }
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            minprim[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) 
            {
            	break;
            }
        }
    }
    //vis[i] == 0 -> i is a prime
}
int inv[maxn];
void init_inv()
{
    inv[1]=1;
    for (int i = 2; i < maxn; i++) inv[i] = 1ll* inv[mod % i] * (mod - mod / i) % mod;
}
int po[maxn], cnt[maxn];
vector<int>ft[maxn];
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int ksm(int a, int b)
{
    int res = 1;
    while (b) 
    {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int main()
{
    get_prime(1000000);
    init_inv();
    int n; scanf("%d", &n);
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        while (minprim[x] > 1) 
        {
            ft[i].push_back(minprim[x]);
            cnt[minprim[x]]++;
            x /= minprim[x];
        }
        for (int p : ft[i]) po[p] = max(po[p], cnt[p]), cnt[p] = 0;
    }
    int all = 1, ans = 0;
    for (int i = 1; i <= 1000000; i++) all = mul(all, ksm(i, po[i]));
    for (int i = 1; i <= n; i++)
    {
        int t = all;
        for (int p : ft[i]) t = mul(t, inv[p]);
        ans = add(ans, t);
    }
    printf("%d\n", ans);
    return 0;
}
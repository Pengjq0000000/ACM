#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5e5 + 7;
int vis[maxn];
int prime[maxn], mu[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
{
	mu[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i]) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
            	mu[i * prime[j]] = 0;
            	break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    //vis[i] == 0 -> i is a prime
}
int cnt[maxn], a[maxn], in[maxn];
vector<int>ft[maxn];

ll ans, all;
void update(int x, int sig)
{
    for (int d : ft[x]) cnt[d] += sig;
    all += sig;
}
int cal(int x)
{
    int res = all;
    for (int d : ft[x]) res += mu[d] * cnt[d];
    return res; 
}
int main()
{
    get_prime(5e5 + 5);
    for (int i = 2; i <= 5e5 + 5; i++)
    {
        if (!mu[i]) continue;
        for (int j = i; j <= 5e5 + 5; j += i) ft[j].push_back(i);
    }
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    while (q--)
    {
        int x; scanf("%d", &x);
        if (in[x]) update(a[x], -1), ans -= cal(a[x]);
        else ans += cal(a[x]), update(a[x], 1);
        in[x] ^= 1;
        printf("%lld\n", ans);
    }
    return 0;
}
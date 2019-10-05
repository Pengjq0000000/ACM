#include<bits/stdc++.h>
#define LL long long
using namespace std;
/// O(n)
const int maxn = 1e6+7;
int vis[maxn];
int prime[maxn], minprim[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
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


int f[maxn];
int p[maxn], k[maxn];
LL cal(int n)
{
    int tmp = pow(n, (double)1 / 3);
    int flag = 0;
    for (int x = max(1, tmp - 5); x <= tmp + 5; x++)
    {
        if (x * x * x == n) flag = 1;
    }
    if (n == 1) return 0;
    int cnt = 0;
    while (n > 1)
    {
        int x = minprim[n];
        p[++cnt] = x; k[cnt] = 0;
        while (n % x == 0) n /= x, k[cnt]++;
    }
    LL ans = 1;
    for (int i = 1; i <= cnt; i++)
    {
        int tmp = k[i] + 2;
        ans *= tmp * (tmp - 1) / 2;
    }
    LL det = 1;
    for (int i = 1; i <= cnt; i++)
    {
        det *= (k[i] / 2 + 1);
    }
    //printf("%lld %lld %d", ans, det, flag);
    LL res;
    if (flag) res = (ans - det * 3 + 2) / 6;
    else res = (ans - det * 3) / 6;
    return res;
}
int main()
{
    get_prime(1e6+2);
    //cal(8);
    for (int i = 1; i <= 1000000; i++) f[i] = cal(i);
    for (int i = 1; i <= 1000000; i++) f[i] += f[i - 1];
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        printf("%lld\n", f[n]);
    }
    return 0;
}
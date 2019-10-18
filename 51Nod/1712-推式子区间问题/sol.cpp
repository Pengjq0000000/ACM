#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
using namespace std;
const int maxn = 1e6 + 7;
uint read() 
{
    uint x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
uint a[maxn], pre[maxn], sum[maxn];
uint cnt[maxn], b[maxn], c[maxn], d[maxn], e[maxn];
uint lst[maxn];
int main()
{
    uint n; scanf("%u", &n);
    for (uint i = 1; i <= n; i++) 
    {
        a[i] = read();
        pre[i] = pre[i - 1] + a[i];
        sum[i] = sum[i - 1] + pre[i];
    }
    uint ans = 0;
    for (uint k = 1; k <= n; k++)
    {
        if (cnt[a[k]])
        {
            ans += cnt[a[k]] * (k * pre[k] - 2 * sum[k - 1]);
            ans += b[a[k]] * k;
            ans -= c[a[k]];
            ans -= d[a[k]] * pre[k];
            ans += e[a[k]];
        }
        cnt[a[k]]++;
        b[a[k]] += pre[k - 1];
        c[a[k]] += k * pre[k - 1];
        d[a[k]] += k;
        e[a[k]] += 2 * sum[k - 1];
    }
    printf("%u\n", ans);
    return 0;
}
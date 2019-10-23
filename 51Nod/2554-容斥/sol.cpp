#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 7;
const int M = 255;
ll cnt[N][M + 1];
int main()
{
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        for (int j = 0; j <= M; j++) cnt[i][j] = cnt[i - 1][j];
        x ^= M;
        int j = x;
        while (j != -1)
        {
            cnt[i][j ^ M]++;
            if (!j) j--;
            else j = (j - 1) & x;
        }
    }
    while (q--)
    {
        int l, r, x; scanf("%d%d%d", &l, &r, &x);
        ll ans = 0;
        int f = __builtin_popcount(x) & 1;
        int j = x;
        while (j != -1) 
        {
            ll num = cnt[r][j] - cnt[l - 1][j];
            int g = __builtin_popcount(j) & 1;
            if (f ^ g) ans -= num * (num - 1) * (num - 2) / 6;
            else ans += num * (num - 1) * (num - 2) / 6; 
            if (!j) j--;
            else j = (j - 1) & x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
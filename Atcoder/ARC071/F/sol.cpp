#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int sub(int x, int y) {int res = x - y; if (res < 0) res += mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int dp[MAXN], sum[MAXN];
int main()
{
    int n; scanf("%d", &n);
    dp[1] = sum[1] = n;
    dp[2] = sum[2] = mul(n, n); sum[2] += sum[1];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = sub(sum[i - 1], dp[i - 2]);
        dp[i] = add(dp[i], mul(n - 1, n - 1));
        dp[i] = add(dp[i], n - i + 2);
        sum[i] = add(sum[i - 1], dp[i]);
    }
    printf("%d\n", dp[n]);
    return 0;
}
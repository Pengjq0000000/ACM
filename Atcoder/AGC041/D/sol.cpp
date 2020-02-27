#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5007;
int n, mod;
inline void add(int &x, int y) {x += y; if (x >= mod) x -= mod;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int dp[MAXN], w[MAXN];
int main()
{
    scanf("%d%d", &n, &mod);
    for (int i = 1, j = n - 1, c = 1; i <= j; i++, j--, c++) w[j] = c + 1, w[i] = c;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = w[i]; j < n; j++) add(dp[j], dp[j - w[i]]);
    int ans = 0;
    for (int i = 0; i < n; i++) add(ans, mul(dp[i], n - i));
    printf("%d\n", ans);
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 401;
const int mod = 1e9 + 7;
inline int add(ll x, ll y) {return (x + y) % mod;}
inline int mul(ll x, ll y) {return x * y % mod;}
inline int sub(ll x, ll y) {return (x - y + mod) % mod;}
int dp[N][N], sum[N][N], A[N], B[N];

int main()
{
    int n, c; scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int y = 1; y <= 400; y++)
        for (int x = 0, v = 1; x <= 400; x++, v = mul(v, y)) sum[x][y] = v;
    for (int x = 0; x <= 400; x++)
        for (int y = 1; y <= 400; y++) sum[x][y] = add(sum[x][y], sum[x][y - 1]);
    memset(dp, -1, sizeof(dp));
    dp[0][c] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= c; j++)
            for (int k = j; k <= c; k++) if (dp[i - 1][k] != -1)
            {
                if (dp[i][j] == -1) dp[i][j] = 0;
                int use = k - j;
                dp[i][j] = add(dp[i][j], mul(dp[i - 1][k], sub(sum[use][B[i]], sum[use][A[i] - 1])));
            }
    printf("%d\n", dp[n][0]);
    return 0;
}
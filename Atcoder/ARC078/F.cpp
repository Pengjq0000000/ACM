#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 15;
int dp[MAXN][1 << MAXN], sum[1 << MAXN];
int w[MAXN][MAXN];
inline void upd(int &x, int y) {x = max(x, y);}
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    int all = 0;
    for (int i = 0, u, v, c; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        u--; v--;
        w[u][v] = w[v][u] = c;
        all += c;
    }
    int U = (1 << n) - 1;
    for (int s = 0; s <= U; s++)
    {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) if ((s >> i & 1) && (s >> j & 1))
                sum[s] += w[i][j];
    }
    for (int i = 0; i < n; i++)
        for (int s = 0; s <= U; s++)
            dp[i][s] = -1;
    dp[0][1] = 0;
    for (int s = 1; s <= U; s++)
    {
        for (int i = 0; i < n; i++) if (((s >> i) & 1) && (dp[i][s] != -1))
        {
            for (int j = 0; j < n; j++) if (!((s >> j) & 1) && w[i][j])
                upd(dp[j][s ^ (1 << j)], dp[i][s] + w[i][j]);

            int rU = U ^ s;
            for (int x = rU; x; x = (x - 1) & rU)
            {
                assert((s & x) == 0);
                upd(dp[i][s ^ x], dp[i][s] + sum[x ^ (1 << i)]);
            }
        }
    }
    printf("%d\n", all - dp[n - 1][U]);
    return 0;   
}
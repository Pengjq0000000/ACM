#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int MAXM = 101;
const int INF = 0x3f3f3f3f;
int dp[MAXM][MAXN];
int l[MAXM], r[MAXM];
struct node{int val, pos;}q[MAXN];
int main()
{
    int n, k; scanf("%d%d", &n, &k);
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= k; i++) scanf("%d%d", &l[i], &r[i]);
    dp[0][0] = 0;
    for (int i = 1, head, tail; i <= k; i++)
    {
        int len = r[i] - l[i];
        for (int j = 0; j <= r[i]; j++) dp[i][j] = dp[i - 1][j]; // flip 0
        head = tail = 0;
        for (int j = r[i]; j >= 0; j--) // filp 1
        {
            while (head < tail && q[head].pos < r[i] - j - len) head++;
            while (head < tail && dp[i - 1][r[i] - j] <= q[tail - 1].val) tail--;
            q[tail++] = {dp[i - 1][r[i] - j], r[i] - j};
            dp[i][j] = min(dp[i][j], q[head].val + 1);
        }   
        head = tail = 0;
        for (int j = 0; j <= r[i]; j++) // filp 2
        {
            while (head < tail && q[head].pos < j - len) head++;
            while (head < tail && dp[i - 1][j] <= q[tail - 1].val) tail--;
            q[tail++] = {dp[i - 1][j], j}; 
            dp[i][j] = min(dp[i][j], q[head].val + 2); 
        }
        // for (int j = 1; j <= n; j++) printf("%d%c", dp[i][j], " \n"[j == n]);
    }
    int ans = dp[k][n];
    if (ans >= INF) puts("Hungry");
    else printf("Full\n%d\n", ans);
    return 0;
}
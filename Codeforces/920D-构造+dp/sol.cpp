#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int n, k, V; 
int a[MAXN], b[MAXN], cnt[MAXN];
bool key[MAXN], dp[MAXN][MAXN];
inline int sub(int x, int y) {int res = x - y; if (res < 0) res += k; return res;}
int main()
{
    scanf("%d%d%d", &n, &k, &V);
    int all = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[i] = a[i] / k, b[i] = a[i] % k, all += a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            dp[i][j] |= dp[i - 1][sub(j, b[i])] | dp[i - 1][j];
    if (!dp[n][V % k] || all < V) puts("NO");
    else 
    {
        puts("YES");
        int now = V % k, aimx = 0, aimy = 0;
        for (int i = n; i; --i) if (dp[i - 1][sub(now, b[i])]) 
        {
            key[i] = 1; aimx = i;
            now = sub(now, b[i]);
        }
        aimy = 1; while (key[aimy]) aimy++;
        int sumx = a[aimx], sumy = a[aimy];
        for (int i = 1; i <= n; i++)
        {
            if (i == aimx || i == aimy) continue;   
            if (key[i]) printf("%d %d %d\n", cnt[i] + 1, i, aimx), sumx += a[i];
            else printf("%d %d %d\n", cnt[i] + 1, i, aimy), sumy += a[i];
        }
        if (aimy > n) aimy = n;
        while (aimy == aimx) aimy--;
        if (aimx == 0) aimx = 1;
        while (aimx == aimy) aimx++;
        if (sumx < V) printf("%d %d %d\n", (V - sumx) / k, aimy, aimx);
        else if (sumx > V) printf("%d %d %d\n", (sumx - V) / k, aimx, aimy);
    }
    return 0;
}
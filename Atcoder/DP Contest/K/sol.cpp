#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
bool dp[MAXN];
int a[101];
int main()
{
    int n, K; scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= K; i++)
    {
        bool f = 0;
        for (int j = 1; j <= n; j++) if (i >= a[j])
            if (!dp[i - a[j]]) {f = 1; break;}
        dp[i] = f;
    }
    dp[K] ? puts("First") : puts("Second");
    return 0;
}
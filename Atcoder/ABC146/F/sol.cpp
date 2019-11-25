#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 1e5 + 7;
char s[MAXN];
int dp[MAXN], lazy[MAXN], lst[MAXN], ans[MAXN];
priority_queue<pii, vector<pii>, greater<pii>>pq;
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    scanf(" %s", s);
    for (int i = 0; i <= n; i++) lst[i] = 1e9;
    pq.push({0, n});
    for (int i = n; i >= 0; i--)
    {
        while (pq.size() && pq.top().sec > i) pq.pop();
        if (pq.empty())
        {
            puts("-1");
            return 0;
        }
        if (s[i] == '1') continue;
        dp[i] = pq.top().fir;
        lst[dp[i]] = min(lst[dp[i]], i);
        int val = dp[i] + 1;
        pq.push({val, i - m});
    }
    int now = dp[0], tot = 0;
    while (now >= 0) ans[++tot] = lst[now--];
    for (int i = 2; i <= tot; i++) printf("%d%c", ans[i] - ans[i - 1], i == tot ? '\n' : ' ');
    return 0;
}
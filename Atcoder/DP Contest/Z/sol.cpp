#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
struct node{ll x, y;}q[MAXN];
int n; ll C; 
ll h[MAXN], dp[MAXN];
inline bool check(node &a, node &b, node &c) {return (c.y - b.y) * (b.x - a.x) < (b.y - a.y) * (c.x - b.x);}
inline ll cal(node &a, ll h) {return a.y - a.x * h + h * h + C;}

int main()
{
    scanf("%d%lld", &n, &C);
    for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
    int head = 0, tail = 0; q[tail++] = {h[1] * 2, dp[1] + h[1] * h[1]};
    for (int i = 2; i <= n; i++)
    {
        while (head + 1 < tail && cal(q[head + 1], h[i]) < cal(q[head], h[i])) head++;
        dp[i] = cal(q[head], h[i]);
        node now = {h[i] * 2, dp[i] + h[i] * h[i]};
        while (tail - head >= 2 && check(q[tail - 2], q[tail - 1], now)) tail--;
        q[tail++] = now;
    }
    printf("%lld\n", dp[n]);
    return 0;
}
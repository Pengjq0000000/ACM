#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
inline int lowbit(int x) {return x & (-x);}
int c1[maxn], c2[maxn], cnt[maxn];
int n, q;
void init(int n)
{
    for (int i = 1; i <= n; i++) c1[i] = c2[i] = cnt[i] = 0;
}
void update1(int x){for (; x <= n; x += lowbit(x)) c1[x] += 1;}
void update2(int x)
{
    x = n + 1 - x;
    for (; x <= n; x += lowbit(x)) c2[x] += 1;
}
int query1(int x)
{
    if (x > n) return 0;
    int res = 0;
    for (; x; x -= lowbit(x)) res += c1[x];
    return res;
}
int query2(int x)
{
    if (x > n) return 0;
    x = n + 1 - x;
    int res = 0;
    for (; x > 0; x -= lowbit(x)) res += c2[x];
    return res;
}
int main()
{
    while (scanf("%d%d", &n, &q) == 2)
    {
        init(n); int tot = 0;
        while (q--)
        {
            int t, l, r; scanf("%d%d%d", &t, &l, &r);
            if (t == 1) 
            {
                tot++;
                update1(r); update2(l);
                if (l == r) cnt[l]++;
            }
            else 
            {
                int ans = tot - query1(r - 1) - query2(l + 1);
                if (r - l == 2) ans += cnt[l + 1];
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
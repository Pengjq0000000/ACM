#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 7;
unsigned x, y, z, A, B, C;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}
int n, m;
unsigned a[maxn], ans[200];
pair<int, int>b[200];
int main()
{
    int cas = 0;
    while (~scanf("%d%d%u%u%u", &n, &m, &A, &B, &C))
    {
        x = A, y = B, z = C;
        for (int i = 0; i < n; i++) a[i] = rng61();
        for (int i = 1; i <= m; i++) scanf("%d", &b[i].first), b[i].second = i;
        printf("Case #%d:", ++cas);
        sort(b + 1, b + 1 + m);
        b[m + 1].first = n;
        for (int i = m; i >= 1; i--)
        {
            nth_element(a, a + b[i].first, a + b[i + 1].first);
            ans[b[i].second] = a[b[i].first];
        }
        for (int i = 1; i <= m; i++) printf(" %u", ans[i]); puts("");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int a[N], cnt[N], vis[N];
int random(int x) {return rand() * rand() % x + 1;}
int main()
{
    srand(time(0));
    int n; scanf("%d", &n);
    int MAX = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++, MAX = max(MAX, a[i]);
    int T = min(233, n), ans = 1;
    while (T--)
    {
        int p = random(n); while (vis[p]) p = random(n);
        vis[p] = 1;
        int M;
        for (M = 100000; M; --M)
        {
            int r = a[p] % M, tot = 0;
            for (int x = r; x <= MAX; x += M) tot += cnt[x];
            if (tot >= (n + 1) / 2) break; 
        }
        ans = max(ans, M);
    }
    printf("%d\n", ans);
    return 0;
}
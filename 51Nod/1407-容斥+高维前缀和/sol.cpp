#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
const int N = 20;
const int M = (1 << N) - 1;
int cnt[M + 1], po[M + 1], a[M + 1];
int main()
{
    po[0] = 1; for (int i = 1; i <= 1000000; i++) po[i] = add(po[i - 1], po[i - 1]);
    int n; 
    while (~scanf("%d", &n))
    {
        int MAX = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), MAX = max(a[i], MAX); 
        int U = 0; while (MAX) U = U * 2 + 1, MAX /= 2; if (!U) U = 1;
        for (int i = 0; i <= U; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[a[i] ^ U]++;
        for (int i = 0; i < N; i++)
            for (int s = 0; s <= U; s++)
                if (s & (1 << i)) cnt[s] = add(cnt[s], cnt[s ^ (1 << i)]);
        int ans = 0;
        int s = U; int f = __builtin_popcount(U) & 1;
        while (s != -1)
        {
            int g = __builtin_popcount(s) & 1;
            if (f ^ g) ans = add(ans, mod - po[cnt[s]]);
            else ans = add(ans, po[cnt[s]]);
            if (!s) s = -1;
            else s = (s - 1) & M;
        }
        printf("%d\n", ans);
    }
    return 0;
}
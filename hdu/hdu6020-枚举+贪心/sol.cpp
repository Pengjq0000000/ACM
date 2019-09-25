#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn], cnt[3], has[3];
bool check(int tot, int f)
{
    if (!tot) return f == 0;
    for (int i = 0; i <= min(2, cnt[0]); i++)
        for (int j = 0; j <= min(2, cnt[1]); j++)
            for (int k = 0; k <= min(2, cnt[2]); k++)
            {
                int lft = tot - (i + j + k);
                if (lft < 0) continue;
                if ((j + 2 * k) % 3 == f) 
                {
                    int can = (cnt[0] - i) / 3 + (cnt[1] - j) / 3 + (cnt[2] - k) / 3;
                    if (lft % 3 == 0 && can >= lft / 3) return true;
                }
            }
    return false;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n, k; scanf("%d%d", &n, &k);
        for (int i = 0; i < 3; i++) cnt[i] = has[i] = 0;
        for (int i = 1; i <= n; i++) scanf("%1d", &a[i]), cnt[a[i] % 3]++;
        int f = (cnt[1] + 2 * cnt[2]) % 3;
        bool flag = 0;
        if (k == n - 1) 
        {
            if (cnt[0]) puts("yes");
            else puts("no");
            continue;
        }
        for (int i = 1; i <= k + 1; i++)
        {
            if (!a[i]) {has[0]++; cnt[0]--; continue;}
            cnt[a[i] % 3]--; 
            int need = (f - (has[1] + 2 * has[2]) % 3 + 3) % 3;
            if (check(k - (i - 1), need)) {flag = 1; break;}
            has[a[i] % 3]++; 
        }
        if (flag) puts("yes");
        else puts("no");
    }
    return 0;
}
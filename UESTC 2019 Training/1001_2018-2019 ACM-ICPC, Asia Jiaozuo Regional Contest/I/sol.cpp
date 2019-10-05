#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 7;
LL a[maxn], sum[maxn], ans[maxn];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        LL all = 0; int n; scanf("%d", &n);
        for (int i = 1; i < n; i++) scanf("%ld", &a[i]), sum[i] = sum[i - 1] + a[i];
        LL tmp = 0; int r = n - 1, l = 1;
        for (int i = 1; i <= n; i++)
        {
            ans[i] = ans[i - 1] + tmp;
            if (i % 2 == 0) 
            {
                r--, l++;
            }
            else tmp += sum[r] - sum[l - 1];
        }
        for (int i = 1; i <= n; i++) 
            printf("%lld%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
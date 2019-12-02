#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
int n, m, a[MAXN], ans;
int check(int x)
{
    ans = 0;
    for (int i = 1, sum; i <= x; i++) 
    {
        if (a[i] + a[2 * x + 1 - i] >= m) return 1;
        sum = a[i] + a[2 * x + 1 - i];
        ans = max(ans, sum >= m ? sum - m : sum);
    }
    for (int i = 2 * x + 1, sum; i <= 2 * n; i++)
    {
        if (a[i] + a[2 * (n + x) + 1 - i] < m) return 2;
        sum = a[i] + a[2 * (n + x) + 1 - i];
        ans = max(ans, sum >= m ? sum - m : sum);
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + 2 * n);
    int l = 0, r = n; 
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int ck = check(mid);
        if (ck == 0 || ck == 1) r = mid;
        else l = mid + 1;
    }
    check(l);
    printf("%d\n", ans);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[107];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int bs = 2048;
        for (int i = n; i >= 1; i--) if (a[i] <= bs) bs -= a[i];
        if (!bs) puts("YES");
        else puts("NO");
    }
    return 0;
}
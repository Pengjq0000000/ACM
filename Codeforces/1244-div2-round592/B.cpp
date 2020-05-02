#include<bits/stdc++.h>
using namespace std;
char s[1007];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        scanf(" %s", s + 1);
        int l = n + 1, r = 0;
        for (int i = 1; i <= n; i++) 
            if (s[i] == '1') l = min(l, i), r = max(r, i);
        int ans = n;
        ans = max(ans, 2 * (n - l + 1));
        ans = max(ans, 2 * r);
        printf("%d\n", ans);
    }
    return 0;
}
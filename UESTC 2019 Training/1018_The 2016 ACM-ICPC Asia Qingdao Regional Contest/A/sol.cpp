#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        int ans = 0;
        for (int i = 1, x, y; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            ans += x * y;
        }
        printf("%d\n", ans);
    }
}
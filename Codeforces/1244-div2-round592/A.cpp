#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int a, b, c, d, k; scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int x = a / c; if (a % c) x++;
        int y = b / d; if (b % d) y++;
        if (x + y <= k) printf("%d %d\n", x, y);
        else puts("-1");
    }
    return 0;
}
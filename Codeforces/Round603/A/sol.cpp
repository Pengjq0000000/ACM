#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int a[3]; scanf("%d%d%d", &a[0], &a[1], &a[2]);
        sort(a, a + 3);
        int ans = 0; 
        int d = min(a[0], a[2] - a[1]); 
        a[0] -= d; a[2] -= d; ans += d;
        ans += a[0] + a[1] - (a[0] + 1) / 2;
        printf("%d\n", ans);
    }
    return 0;
}
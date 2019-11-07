#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 2e9;
    int n; scanf("%d", &n);
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i) continue;
        int j = n / i; ans = min(ans, 2 * (i + n / i));
    }
    printf("%d\n", ans);
    return 0;
}
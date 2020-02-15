#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, n; scanf("%d%d%d", &h, &w, &n);
    int t = max(h, w);
    int ans = n / t; if (n % t) ans++;
    printf("%d\n", ans);
    return 0;
}
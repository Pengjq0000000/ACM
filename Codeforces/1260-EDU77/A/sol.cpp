#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ll ans = 0;
        int c, sum; scanf("%d%d", &c, &sum);
        int k1 = sum / c; int k2 = k1, num2 = sum % c;
        if (num2) k2++;
        int num1 = c - num2;
        printf("%lld\n", (ll)num1 * k1 * k1 + (ll)num2 * k2 * k2);
    }
    return 0;
}
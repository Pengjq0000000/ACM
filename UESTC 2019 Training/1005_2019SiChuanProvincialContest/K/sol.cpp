#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e6 + 7;
const int g = 5;
int rid[3000], a[maxn];
bitset<2016>dp;
int main()
{
    LL base = 1; int cnt = 0;
    for (int i = 1; i <= 2016; i++)
    {
        base = (base * g) % 2017;
        rid[base] = i;
    }
    int n, r;
    while (~scanf("%d %d", &n, &r))
    {
        r = rid[r] % 2016; 
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] = rid[a[i] % 2017] % 2016;
        dp.reset();
        dp.set(0);
        for(int i=1;i<=n;i++)
            dp^=(dp<<a[i])|(dp>>(2016-a[i]));
        printf("%d\n",(int)dp[r]);
    }
    return 0;
}
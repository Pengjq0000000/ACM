#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;} 
const int N = 1e6 + 7;
int dp[N];
int main()
{
    int n; scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        if (i & 1) dp[i] = dp[i - 1];
        else dp[i] = add(dp[i - 2], dp[i / 2]);
    printf("%d\n", dp[n]);
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5001;
const int mod = 1e9 + 7;
inline int add(ll x, ll y) {return (x + y) % mod;}
inline int mul(ll x, ll y) {return x * y % mod;}
inline int sub(ll x, ll y) {return (x - y + mod) % mod;}
int dp[N][N];
char s[N];
int main()
{
    int n; scanf("%d", &n);
    scanf("%s", s); int m = strlen(s);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
        {
            dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]); // match
            if (j > 0) dp[i + 1][j - 1] = add(dp[i + 1][j - 1], mul(dp[i][j], 2)); // back
            else dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]); 
        }
    printf("%d\n", dp[n][m]);
    return 0;
}
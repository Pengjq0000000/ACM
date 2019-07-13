#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int out[21][27];
LL dp[1 << 20][27];
char s[100005];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	{
        scanf(" %s", s);
        int len = strlen(s);
        for (int st = 0; st < 27; st++)
        {
            int tmp = st;
            for (int j = 0; j < len; j++)
            {
                if (tmp == 26) tmp = s[j] - 'a';
                else if (s[j] - 'a' == tmp) tmp = 26;
            }
            out[i][st] = tmp;
        }
    }
    int tot = (1 << n);
    dp[0][26] = 1;
    for (int bits = 0; bits < tot; bits++)
        for (int i = 0; i < n; i++)
        {
            if (!(bits & (1 << i)))
            {
                for (int j = 0; j < 27; j++) dp[bits | (1 << i)][out[i + 1][j]] += dp[bits][j];
            }
        }
    LL ans = 0;
    for (int i = 0; i < 26; i++) ans += dp[tot - 1][i];
    printf("%lld\n", ans);
	return 0;
}

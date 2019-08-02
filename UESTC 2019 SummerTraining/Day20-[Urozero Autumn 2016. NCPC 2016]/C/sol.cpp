#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
pii x[60];
int getnum(char x)
{
    if (x >= '2' && x <= '9') return x - '0';
    if (x == 'T') return 10;
    if (x == 'J') return 11;
    if (x == 'Q') return 12;
    if (x == 'K') return 13;
    if (x == 'A') return 14;
}
int getcolor(char x)
{
    if (x == 's') return 0;
    if (x == 'h') return 1;
    if (x == 'd') return 2;
    if (x == 'c') return 3;
}

int a[60];
int table[4] = {0, 1, 2, 3};
int val[4] = {100000, 10000, 1000, 100};
int n;
int dp[100];
int cal()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    return n - res;
}
int main()
{
	scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char s[10]; scanf(" %s", s);
        x[i].fir = getnum(s[0]);
        x[i].sec = getcolor(s[1]);
    }
    int ans = 100;
    do
    {
        int bits = (1 << 4);
        for (int sta = 0; sta < bits; sta++)
        {
            for (int i = 1; i <= n; i++)
            {
                int color = x[i].sec, num = x[i].fir;
                if ((1 << color) & sta) a[i] = val[table[color]] + num;
                else a[i] = val[table[color]] - num;
            }
            ans = min(ans, cal());
        }
    } while (next_permutation(table, table + 4));
    printf("%d\n", ans);
	return 0;
}

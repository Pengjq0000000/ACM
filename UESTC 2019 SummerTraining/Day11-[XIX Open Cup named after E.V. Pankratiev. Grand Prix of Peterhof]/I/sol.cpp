#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int dp[20000007], pre[10000007];
int ans = 1e9, tot = 0;
int path[100007];
int ANS[100007], TOT = 0, tmp = 0;
void dfs(int x, int now)
{
    if (now >= ans) return;
    if (x == 1)
    {
        if (ans > now)
        {
            tmp = now;
            TOT = tot;
            for (int i = 1; i <= tot; i++) ANS[i] = path[i];
            ans = now;
        }
        return ;
    }
    ++tot;
    path[tot] = x / 2;
    if (x % 2 == 0) dfs(x / 2, now);
    path[tot] = x / 3;
    if (x % 3 == 0) dfs(x / 3, now);
    path[tot] = x + 1;
    dfs(x + 1, now + 1);
    tot--;
}
int main()
{
    int x; scanf("%d", &x);
    path[++tot] = x;
    dfs(x, 0);
    printf("%d\n", ans);
    for (int i = 1; i <= TOT; i++) printf("%d ", ANS[i]);
	return 0;
}

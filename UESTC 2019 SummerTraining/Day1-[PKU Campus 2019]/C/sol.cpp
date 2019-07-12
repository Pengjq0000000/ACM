#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
LL cnt[maxn][3];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) cnt[i][1] = cnt[i][2] = 0;
        LL ans = 0;
        for (int i = 1; i <= 2 * n; i++)
        {
            int x, y; scanf("%d%d", &x, &y);
            if (y > 2) ans += y - 2, y = 2;
            else if (y < 1) ans += 1 - y, y = 1;
            if (x < 1) ans += 1 - x, x = 1;
            else if (x > n) ans += x - n, x = n;
            cnt[x][y]++;
        } 
        for (int i = 1; i <= n; i++)
        {
            cnt[i][1]--; cnt[i][2]--;
            if (cnt[i][1] * cnt[i][2] < 0) 
            {
                LL dt = min(abs(cnt[i][1]), abs(cnt[i][2]));
                ans += dt;
                if (cnt[i][1] > 0) cnt[i][1] -= dt, cnt[i][2] += dt;
                else cnt[i][2] -= dt, cnt[i][1] += dt; 
            }
            for (int j = 1; j <= 2; j++) ans += abs(cnt[i][j]), cnt[i + 1][j] += cnt[i][j];
        }
        printf("%lld\n", ans);
    }
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 507;
int a[maxn][maxn], mx[maxn], mi[maxn];
int n, m;
int mxq[maxn], miq[maxn];
int inq[maxn];
int pos[maxn];
int postot, segtot;
int deal()
{
    for (int i = 1; i <= n; i++) inq[i] = 0;
    int res = 0;
    int head_mx = 0, tail_mx = 0, head_mi = 0, tail_mi = 0;
    int now = 1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head_mx < tail_mx && mx[mxq[tail_mx - 1]] <= mx[i]) tail_mx--;
        mxq[tail_mx++] = i;
        while (head_mi < tail_mi && mi[miq[tail_mi - 1]] >= mi[i]) tail_mi--;
        miq[tail_mi++] = i;
        inq[i] = 1; cnt++;
        while (head_mx < tail_mx && head_mi < tail_mi)
        {
            int now_mx = mx[mxq[head_mx]], now_mi = mi[miq[head_mi]];
            if (now_mx - now_mi <= m) break;
            inq[now++] = 0; cnt--;
            while (head_mx < tail_mx && !inq[mxq[head_mx]]) head_mx++;
            while (head_mi < tail_mi && !inq[miq[head_mi]]) head_mi++;
        }
        res = max(res, cnt);
    }
    return res;
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        int ans = 0;
        for (int up = 1; up <= n; up++)
        {
            for (int i = 1; i <= n; i++) mx[i] = -1e9, mi[i] = 1e9;
            for (int down = up; down <= n; down++)
            {
                for (int i = 1; i <= n; i++)
                {
                    mx[i] = max(mx[i], a[down][i]);
                    mi[i] = min(mi[i], a[down][i]);
                }
                int res = deal();
                ans = max(ans, res * (down - up + 1));
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}

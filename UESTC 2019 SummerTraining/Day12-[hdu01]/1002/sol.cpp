
#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int N_bs = 30;
const int maxn = 1e6 + 7;
int bs[maxn][N_bs + 1], tim[maxn][N_bs + 1];
void insert(int id, int x)
{
    for (int i = N_bs; i >= 0; i--) bs[id][i] = bs[id - 1][i], tim[id][i] = tim[id - 1][i];
    int t = id;
    for (int i = N_bs; i >= 0; i--)
    {
        if (x & (1 << i))
            if (!bs[id][i]) {bs[id][i] = x; tim[id][i] = t; break;}
            else 
            {
                if (t > tim[id][i]) {swap(x, bs[id][i]); x ^= bs[id][i]; swap(t, tim[id][i]);}
                else x ^= bs[id][i];
            }
    }
}
int getmax(int l, int id)
{
    int res = 0;
    for (int i = N_bs; i >= 0; i--)
    {
        if (tim[id][i] >= l) res = max(res, (res ^ bs[id][i]));
    }
    return res;
}
int a[maxn];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= n + m; i++) {MEM(bs[i], 0); MEM(tim[i], 0);}
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), insert(i, a[i]);
        int lastans = 0;
        while (m--)
        {
            int op; scanf("%d", &op);
            if (op == 1)
            {
                n++;
                scanf("%d", &a[n]); a[n] ^= lastans;
                insert(n, a[n]);
            }
            else
            {
                int l, r; scanf("%d%d", &l, &r);
                l = (l ^ lastans) % n + 1;
                r = (r ^ lastans) % n + 1;
                if (l > r) swap(l, r);
                int ans = getmax(l, r);
                printf("%d\n", ans);
                lastans = ans;
            }
        }
    }
	return 0;
}

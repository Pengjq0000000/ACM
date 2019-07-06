#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 4e5 + 7;
int a[maxn];
int ans[maxn][20], sum[maxn][20];
int main()
{
	int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum[i][0] = a[i], ans[i][0] = 0;
    int up = log(n) / log(2) + 1;
    for (int k = 1, len = 1; len <= n; k++, len *= 2)
    {
        for (int i = 1; i <= n; i++)
        {
            sum[i][k] = sum[i][k - 1] + sum[i + len][k - 1];
            ans[i][k] = ans[i][k - 1] + ans[i + len][k - 1];
            ans[i][k] += sum[i][k] / 10;
            sum[i][k] %= 10;
        }
    }
    int q; scanf("%d", &q);
    while (q--)
    {
        int l, r; scanf("%d%d", &l, &r);
        int k = 0, base = 1, ll = l;
        while (l < r) {k++; l += base; base *= 2;}
        printf("%d\n", ans[ll][k]);
    }
	return 0;
}

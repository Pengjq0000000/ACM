#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
bool v[20];
int f(int n, int m, int k)
{
    if (k > n) k %= n;
    if (k % m == 0) return k / m;
    if (n <= m)
    {
        for (int i = 1; i <= m; i++) v[i] = 0;
        int now = 0, res = 0;
        while (1)
        {
            int cnt = 0;
            while (cnt < m)
            {
                now = now % n + 1;
                while (v[now]) now = now % n + 1;
                cnt++;
            }
            v[now] = 1; res++;
            if (now == k) return res;
            if (res == n - 1) return n;
        }
    }
    return f(n - n / m, m, n % m + (k / m) * (m - 1) + k % m) + n / m;
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        n--; m++;
        int q; scanf("%d", &q);
        while (q--)
        {
            int k; scanf("%d", &k);
            if (k == 1) puts("1");
            else printf("%d\n", f(n, m, k - 1) + 1);
        }
    }
	return 0;
}

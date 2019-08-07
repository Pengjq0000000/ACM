#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL k; int m;
LL f(LL x, int m)
{
    LL res = x;
    while (m > 0)
    {
        res++; if (__gcd(x, res) == 1) m--;
    }
    return res;
}
bool check(LL x)
{
    LL y = f(x, m);
    if (((y - x) ^ x) == k) return true;
    else return false;
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
         scanf("%lld%d", &k, &m);
        LL down = max(1ll, k - 3000), up = k + 3000;
        LL ans = -1;
        for (LL n = down; n <= up; n++)
        {
            if (check(n))
            {
                ans = n; break;
            }
        }
        printf("%lld\n", ans);
    }
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL n, k; 
LL cal(LL b)
{
    LL a = n - b;
    return a * (a - 1) / 2 + b * (b - 1) / 2;
}
bool check(LL a, LL b)
{
    return b * (b - 1) / 2 <= k && k <= b * (b - 1) / 2 + a * b;   
}
void baoli()
{
    LL ans, num;
    for (LL b = 0; b <= n; b++)
    {
        LL a = n - b;
        if (check(a, b)) 
        {
            if (ans <= cal(b))
            {
                ans = cal(b);
                num = b;
            }
        }
    }
    printf("%lld num:%lld\n", ans, num);
}
int main()
{
    scanf("%lld%lld", &n, &k);
    LL ans = -1; LL num = 0;
    ans = -1;
    LL tmp = sqrt(1 + 8 * k);
    LL y = min(n, (1 + tmp) / 2);
    tmp = sqrt((2 * n - 1) * (2 * n - 1) - 8 * k);
    LL x = max((LL)0, ((2 * n - 1) - tmp) / 2);
    //printf("%lld %lld\n", x, y);
    for (LL b = max((LL)0, x - 100); b <= x + 100; b++)
    {
        if (check(n - b, b)) ans = max(ans, cal(b));
    }
    for (LL b = max((LL)0, y - 100); b <= y + 100; b++)
    {
        if (check(n - b, b)) ans = max(ans, cal(b));
    } 
    printf("%lld\n", ans);
	return 0;
}

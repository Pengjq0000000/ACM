#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
/// O(n)
const int maxn = 1e6+7;
int vis[maxn];
int prime[maxn], mu[maxn], minprim[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
{
    minprim[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i])
        {
            prime[++tot] = i; minprim[i] = i;
        }
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            minprim[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) 
            {
            	break;
            }
        }
    }
    //vis[i] == 0 -> i is a prime
}
bool flag;
bool check2(LL x)
{
    LL l = 1, r = sqrt(x) + 1000;
    while (l < r)
    {
        LL mid = (l + r) / 2;
        if (mid * mid >= x) r = mid;
        else l = mid + 1;
    }
    return (l * l == x);
}
bool check3(LL x)
{
    LL l = 1, r = pow(x, (double)1.0 / 3) + 1000;
    while (l < r)
    {
        LL mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid + 1;
    }
    return (l * l * l == x);
}
bool check4(LL x)
{
    LL l = 1, r = sqrt(sqrt(x + 10) + 10) + 1000;
    while (l < r)
    {
        LL mid = (l + r) / 2;
        if (mid * mid * mid * mid >= x) r = mid;
        else l = mid + 1;
    }
    return (l * l * l *l == x);
}
int main()
{
	get_prime(10007);
    int T; scanf("%d", &T);
    while (T--)
    {
        LL n; scanf("%lld", &n);
        LL tmp = n;
        int ans = 1e9;
        for (int i = 1; i <= tot; i++)
        {
            if (tmp % prime[i] == 0)
            {
                int cnt = 0;
                while (tmp % prime[i] == 0) tmp /= prime[i], cnt++;
                ans = min(ans, cnt);
            }
        }
        if (tmp == 1) {printf("%d\n", ans); continue;}

        flag = false;
        if (check4(tmp)) ans = min(ans, 4), flag = true;
        else if (check2(tmp)) ans = min(ans, 2), flag = true;
        if (check3(tmp)) ans = min(ans, 3), flag = true;
        if (!flag) ans = 1;
        printf("%d\n", ans);
    }
	return 0;
}

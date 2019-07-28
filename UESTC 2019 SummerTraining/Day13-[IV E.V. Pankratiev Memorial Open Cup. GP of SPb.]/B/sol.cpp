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
const int maxn = 2e6+7;
int vis[maxn];
int prime[maxn], mu[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
{
	mu[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i]) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
            	mu[i * prime[j]] = 0;
            	break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    //vis[i] == 0 -> i is a prime
    vis[1] = 1;
}
vector<pii>ans;
int main()
{
    freopen("equation.in", "r", stdin);
    freopen("equation.out", "w", stdout);
    get_prime(2000000);
    LL a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
    if (a == 0 && b == 0)
    {
        if (c == 0) puts("TOO MANY");
        else puts("NO SOLUTIONS");
        return 0;
    }
    if (a == 0)
    {
        if (c % b == 0 && vis[c / b] == 0 && c / b > 1) puts("TOO MANY");
        else puts("NO SOLUTIONS");
        return 0;
    }
    if (b == 0)
    {
        if (c % a == 0 && vis[c / a] == 0 && c / a > 1) puts("TOO MANY");
        else puts("NO SOLUTIONS");
        return 0;
    }
    for (int i = 1; i <= tot; i++)
    {
        LL x = prime[i];
        if ((c - a * x > 0) && (c - a * x) % b == 0)
        {
            LL y = (c - a * x) / b;
            if (vis[y] != 0 || y == 1) continue;
            //if (x > y) swap(x, y);
            ans.pb(make_pair(x, y));
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if (!ans.size()) puts("NO SOLUTIONS");
    else
    {
        for (pii x : ans) printf("%d %d\n", x.fir, x.sec);
    }
	return 0;
}

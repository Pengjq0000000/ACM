#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
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
}

vector<int>ft[maxn], pos[maxn];
int a[maxn];
int main()
{
    get_prime(1e5 + 5);
    for (int i = 2; i <= 1e5 + 5; i++)
        for (int j = i; j <= 1e5 + 5; j += i)
        {
            if (mu[i] != 0) ft[j].pb(i);
        }
	int T; scanf("%d", &T);
    while (T--)
    {
        int n, q; scanf("%d%d", &n, &q);
        for (int i = 1; i <= 1e5 + 5; i++) pos[i].clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            for (int x : ft[a[i]]) pos[x].pb(i);
        }
        int ans, lastans = 0;
        while (q--)
        {
            int l, r, d; scanf("%d%d%d", &l, &r, &d);
            l ^= lastans; r ^= lastans; d ^= lastans;
            ans = r - l + 1;
            for (int x : ft[d])
            {
                int num = upper_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l);
                ans += mu[x] * num;
            }
            lastans = ans;
            printf("%d\n", ans);
        }
    }
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
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
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int p, n, m; scanf("%d%d%d", &p, &n, &m);
        if (p == 2 || p == 5) 
        {
            puts("0");
            continue;
        }
        
    }
	return 0;
}

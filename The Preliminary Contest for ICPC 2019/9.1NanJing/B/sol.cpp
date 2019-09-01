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
int prime[maxn], tot = 0; //1 ~ tot
int phi[maxn];
void get_prime(int maxl) // get prime <= maxl
{
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i])
        {
            prime[++tot] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
            	break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    //vis[i] == 0 -> i is a prime
}
bool flag;
LL ksm(LL a, LL b, LL p)
{
    LL res = 1, base = a;
    while (b)
    {
        if (b & 1)
        {
            res = res * base;
            if (res > p) {res %= p; flag = 1;}
        }
        base = (base * base) % p;
        b /= 2;
    }
    return res;
}
int CNT;
LL deal(LL a, int cnt, LL p)
{
	if (p == 1) return 0;
    if (cnt == 0) return a%p; 
	if(a==2){
		if(cnt==1) return 4%p;
		if(cnt==2) return 16%p;
		if(cnt==3) return 65536%p;
	}
	if(cnt==1){
		if(a==3) return 27%p;
		if(a==4) return 256%p;
		if(a==5) return 3125%p;
		if(a==6) return 46656%p;
	}
	return ksm(a, deal(a, cnt - 1, phi[p]) + phi[p], p);
}
int main()
{
    get_prime(1e6 + 1);
	int T; scanf("%d", &T);
    while (T--)
    {
        int a, b, m; scanf("%d%d%d", &a, &b, &m);
        if (b == 0)
        {
            printf("%d\n", 1 % m);
            continue;
        }
        if (m == 1)
        {
            puts("0");
            continue;
        }
        
        int pphi = phi[m];
        LL now = a, last = -1;
        flag = 0;
        LL ans = deal(a, b - 1, m);
        printf("%lld\n", ans % m);
    }
	return 0;
}
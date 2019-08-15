#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct team
{
    char s[20];
    int p, t;
    bool operator < (const team &rhs) const 
    {
        if (p == rhs.p) return t < rhs.t;
        return p > rhs.p;
    }
}a[maxn];

int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n, k; scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf(" %s %d %d", a[i].s, &a[i].p, &a[i].t);
        }
        if ((n * k) % 10 != 5) {puts("Quailty is very great"); continue;}
        sort(a + 1, a + 1 + n);
        printf("%s\n", a[(n * k) / 10 + 1].s); 
    }
	return 0;
}

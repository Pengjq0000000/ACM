#include<bits/stdc++.h>
#define uLL unsigned long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e5 + 7;
unsigned long long k1, k2, mod;
unsigned long long rng() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

uLL a[maxn], b[maxn], cnta[maxn], cntb[maxn], ida[maxn], idb[maxn];
struct node
{
    uLL A, B;
    bool operator < (const node &rhs) const
    {
        if ((A + B) == (rhs.A + rhs.B)) return A > rhs.A;
        return (A + B) > (rhs.A + rhs.B);
    }
}t[maxn];
uLL opa, opb;
vector<uLL>vec;
int getid(uLL x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        vec.clear();
        int n, m, p; scanf("%d%d%d", &n, &m, &p);
        opa = 0; opb = 0;
        if (p == 1)
        {
            for (int i = 1; i <= n; i++) scanf("%llu", &a[i]), vec.pb(a[i]);
            for (int i = 1; i <= m; i++) scanf("%llu", &b[i]), vec.pb(b[i]);
        }
        else if (p == 2)
        {
            scanf("%llu%llu%llu", &k1, &k2, &mod);
            for (int i = 1; i <= n; ++i) a[i] = rng() % mod, vec.pb(a[i]);
            scanf("%llu%llu%llu", &k1, &k2, &mod);
            for (int i = 1; i <= m; ++i) b[i] = rng() % mod, vec.pb(b[i]);
        }
        //printf("a:");for (int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
        //printf("b:");for (int i = 1; i <= m; i++) printf("%d ", b[i]); puts("");
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int N = vec.size();
        for (int i = 1; i <= N; i++) cnta[i] = cntb[i] = 0;
        for (int i = 1; i <= n; i++) {ida[i] = getid(a[i]); cnta[ida[i]]++;}
        for (int i = 1; i <= m; i++) {idb[i] = getid(b[i]); cntb[idb[i]]++;}
        int tot = 0;
        for (int i = 1; i <= N; i++)
        {
            if (cnta[i] && cntb[i]) t[++tot] = {cnta[i], cntb[i]};
            else if (cnta[i]) opa += cnta[i];
            else if (cntb[i]) opb += cntb[i];
        }
        sort(t + 1, t + 1 + tot);
        for (int i = 1; i <= tot; i++)
        {
            if (i & 1) opa += t[i].A;
            else opb += t[i].B;
        }
        if (opa > opb) puts("Cuber QQ"); else puts("Quber CC");
    }
	return 0;
}

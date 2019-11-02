#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int N_bs = 64;
struct LinearBase
{
    LL bs[N_bs + 1];
    LL num[N_bs + 1];
    int tot = 0;
    void init() {tot = 0; MEM(bs, 0);}
    void add(LL x) {num[tot++] = x;}
    bool insert(LL x)
    {
        LL tmp = x;
        for (int i = N_bs; i >= 0; i--)
        {
            if ((x >> i) & 1) 
                if (!bs[i]) {bs[i] = x; add(tmp); return 1;}
                else x ^= bs[i];
        }
        return 0;
    }
    inline void build() {for (int i = 0; i < tot; i++) insert(num[i]);}
    inline bool check(LL x)
    {
        for (int i = N_bs; i >= 0; i--)
        {
            if ((x >> i) & 1)
                if (!bs[i]) return false;
                else x ^= bs[i];
        }
        return true;
    }
    inline LL getmax(LL x)
    {
    	LL res = 0;
    	for (int i = N_bs; i >= 0; i--)
    		if (bs[i]) res = max(res, (res ^ bs[i]));
    	return res;
    }
}lbs, A, B;
LL ksm(LL a, LL b)
{
    LL res = 1, base = a;
    while (b) {if (b & 1) res = MOD(res * base); base = MOD(base * base); b /= 2;}
    return res;
}
vector<LL>v;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        lbs.init(); A.init(); B.init();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            LL x; scanf("%lld", &x);
            if (!lbs.insert(x)) A.insert(x), cnt++;
        }
        if (cnt == 0) {puts("0"); continue;} 
        LL ans = MOD((LL)cnt * ksm(2, cnt - 1));
        //for (int i = 0; i < lbs.tot; i++) printf("%lld ", lbs.num[i]); puts("");
        for (int i = 0; i < lbs.tot; i++)
        {
            B = A;
            for (int j = 0; j < lbs.tot; j++)
            {
                if (i == j) continue;
                B.insert(lbs.num[j]);
            }
            if (B.check(lbs.num[i])) ans = MOD(ans + ksm(2, n - 1 - B.tot));
        }
        printf("%lld\n", ans);
    }
	return 0;
}

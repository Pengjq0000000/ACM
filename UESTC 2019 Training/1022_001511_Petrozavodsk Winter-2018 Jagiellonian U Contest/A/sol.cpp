#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N_bs = 62;
struct LinearBase
{
    LL bs[N_bs + 1];
    LL num[N_bs + 1];
    int tot = 0;
    void init() {tot = 0; memset(bs, 0, sizeof(bs));}
    void add(LL x) {num[tot++] = x;}
    void insert(LL x)
    {
        for (int i = N_bs; i >= 0; i--)
        {
            if ((x >> i) & 1) 
                if (!bs[i]) {bs[i] = x; break;}
                else x ^= bs[i];
            else continue;
        }
    }
    inline void build() {for (int i = 0; i < tot; i++) insert(num[i]);}
    inline bool check(LL x)
    {
        for (int i = N_bs; i >= 0; i--)
        {
            if ((x >> i) & 1)
                if (!bs[i]) return false;
                else x ^= bs[i];
            else continue;
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
    void deal()
    {
        for (int i = N_bs; i >= 0; i--)
        {
            if (!bs[i]) continue;
            for (int j = i - 1; j >= 0; j--)
            {
                if (bs[j]) bs[i] ^= bs[j];
            }
        }
    }
    LL get(LL S)
    {
        LL res = 0;
        int i;
        for (i = N_bs; i >= 0; i--)
        {
            if ((S >> i) & 1)
            {
                if (bs[i]) {res ^= bs[i]; break;}
            }
        }
        i--;
        for (; i >= 0; i--)
        {
            if (((S >> i) & 1) && ((res >> i) & 1))
            {
                if (bs[i]) res ^= bs[i];
            }
        }
        return res;
    }
}lbs;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        lbs.init();
        int n; scanf("%d", &n);
        LL S = 0;
        for (int i = 1; i <= n; i++)
        {
            LL x; scanf("%lld", &x);
            lbs.insert(x);
            S ^= x;
        }
        lbs.deal();
        LL res = lbs.get(S);
        assert(res >= (S ^ res));
        printf("%lld\n", res - (S ^ res));
    }
    return 0;
}
const int N_bs = 62;
struct LinearBase
{
    LL bs[N_bs + 1];
    LL num[N_bs + 1];
    int tot = 0;
    void init() {tot = 0; MEM(bs, 0);}
    void add(LL x) {num[tot++] = x;}
    void insert(LL x)
    {
        for (int i = N_bs; i >= 0; i--)
        {
            if (x & (1 << i)) 
                if (!bs[i]) {bs[i] = x; break;}
                else x ^= bs[i];
        }
    }
    inline void build() {for (int i = 0; i < tot; i++) insert(num[i]);}
    inline bool check(LL x)
    {
        for (int i = N_bs; i >= 0; i--)
        {
            if (x & (1 << i))
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
}

void GetCross(Lbs A, Lbs B, Lbs &res)
{
    res.init();
    LL d[N_bs + 1], all[N_bs + 1];
    for (int i = 0; i <= N_bs; i++) all[i] = A.bs[i], d[i] = 0;
    for (int i = N_bs; i >= 0; i--)
    {
        if (B.bs[i])
        {
            LL k = (1ll << i), v = B.bs[i];
            bool can = true;
            for (int j = N_bs; j >= 0; j--)
            {
                if (v & (1ll << j))
                {
                    if (!all[j]) {can = false; all[j] = v; d[j] = k; break;}
                    else k ^= d[j], v ^= all[j];
                }
            }
            if (can)
            {
                v = 0;
                for (int j = 0; j <= N_bs; j++)
                {
                    if (k & (1ll << j)) v ^= B.bs[j];
                }
                res.add(v);
            }
        }
    }
    res.build();
}

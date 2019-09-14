#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct info
{
    LL val;
    int id, p;
    bool operator < (const info &rhs) const
    {
        if (val == rhs.val) return id > rhs.id;
        return val < rhs.val;
    }
};
set<info>s;
const int maxn = 5e4 + 7;
int  d[maxn], m[maxn], p[maxn];
int e[maxn], R[maxn], E[maxn];
LL c[maxn], cc[maxn], sumE[maxn];
signed main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int k; scanf("%d", &k);
        for (int i = 1; i <= k; i++) scanf("%lld%d%d%d", &cc[i], &d[i], &m[i], &p[i]);
        for (int i = 1; i < k; i++) scanf("%d%d%d", &e[i], &R[i], &E[i]);
        LL tmp = 1e16, sum = 0;
        for (int i = 1; i <= k; i++) 
        {
            c[i] = min(cc[i], tmp + sum);
            tmp = min(tmp, c[i] - sum);
            sum += R[i];
        }
        s.clear();
        LL ans = 0;
        int tag = 0, num = 0; bool flag = 1;
        for (int i = 1; i <= k; i++)
        {
            s.insert({-tag + c[i] + m[i], i, p[i]});
            num += p[i]; 
            int need = d[i];
            while (need)
            {
                if (!s.size()) {flag = 0; break;}
                auto x = (*s.begin()); s.erase(x);
                int det = min(x.p, need);
                x.p -= det; need -= det; num -= det;
                ans += (LL)det * (x.val + tag);
                if (x.p) s.insert(x);
            }
            tag += E[i];
            while (num > e[i])
            {
                auto x = (*s.rbegin()); s.erase(x);
                int det = min(x.p, num - e[i]);
                x.p -= det; num -= det;
                if (x.p) s.insert(x);
            }
            if (!flag) {puts("-1"); break;}
        }
        if (flag) printf("%lld\n", ans);
    }
    return 0;
}

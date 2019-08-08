#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
inline int lowbit(int x) {return (x & -x);}
LL c[maxn * 2];
int cnum[maxn * 2];
void update(int x, LL val) {for (x; x < maxn * 2; x += lowbit(x)) c[x] += val;}
LL query(int x) {LL res = 0; for(x; x; x -= lowbit(x)) res += c[x]; return res;}

void UPDATE(int x, int val) {for (x; x < maxn * 2; x += lowbit(x)) cnum[x] += val;}
int QUERY(int x) {int res = 0; for(x; x; x -= lowbit(x)) res += cnum[x]; return res;}

int E[maxn], L[maxn], C[maxn];
struct node
{
    int tim, l, r;
}q[maxn];
vector<int>in[maxn], out[maxn];
set<int>times;
int main()
{
	int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 0; i < maxn * 2; i++) c[i] = cnum[i] = 0;
        for (int i = 1; i <= n + 1; i++) in[i].clear(), out[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d%d%d", &E[i], &L[i], &C[i]);
        int m; scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &q[i].tim, &q[i].l, &q[i].r);
            in[q[i].l].pb(q[i].tim);
            out[q[i].r + 1].pb(q[i].tim);
        }
        LL ans = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            int pre = 0, nxt = 0, det;
            for (int x : in[i])
            {
                pre = nxt = 0;
                times.insert(x);
                auto it = times.find(x);
                if (it != times.begin()) {it--; pre = (*it);}
                it = times.find(x);
                it++; if (it != times.end()) nxt = (*it);
                if (nxt) {det = nxt - x; update(det, det); UPDATE(det, 1);}
                if (pre)
                {
                    det = x - pre; update(det, det); UPDATE(det, 1);
                    if (nxt) {det = nxt - pre; update(det, -det); UPDATE(det, -1);}
                }
            }
            for (int x : out[i])
            {
                pre = nxt = 0;
                auto it = times.find(x);
                if (it != times.begin()) {it--; pre = (*it);}
                it = times.find(x);
                it++; if (it != times.end()) nxt = (*it);
                if (nxt) {det = nxt - x; update(det, -det); UPDATE(det, -1);}
                if (pre)
                {
                    det = x - pre; update(det, -det); UPDATE(det, -1);
                    if (nxt) {det = nxt - pre; update(det, det); UPDATE(det, 1);}
                }
                times.erase(x);
            }
            int sz = times.size(); 
            if (!sz) continue;
            int fir = *(times.begin());
            ans += min((LL)C[i], (LL)L[i] * fir + E[i]);
            if (L[i] == 0) continue;
            int k = min(C[i] / L[i], 200000);
            int num = QUERY(k);
            LL sum = query(k);
            ans += sum * (LL)L[i] + (LL)C[i] * (sz - 1 - num);
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int n, q, a[maxn], pos[21][maxn * 10], ans[maxn];

int gcdT[maxn << 2];
void build_gcd(int rt, int l, int r)
{
    if (l == r) {gcdT[rt] = a[l]; return;}
    int mid = (l + r) >> 1;
    build_gcd(lson, l, mid);
    build_gcd(rson, mid + 1, r);
    gcdT[rt] = __gcd(gcdT[lson], gcdT[rson]);
}
int query_gcd(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return gcdT[rt];
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid) res = __gcd(res, query_gcd(lson, l, mid, L, R));
    if (mid <  R) res = __gcd(res, query_gcd(rson, mid + 1, r, L, R));
    return res;  
}

int T[maxn << 2], lazy[maxn << 2];
void pushup(int rt) {T[rt] = T[lson] + T[rson];}
void build(int rt, int l, int r)
{
    T[rt] = lazy[rt] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void pushdown(int rt, int l, int r)
{
    if (lazy[rt] == 0) return;
    int mid = (l + r) >> 1;
    lazy[lson] += lazy[rt];
    T[lson] += lazy[rt] * (mid - l + 1);
    lazy[rson] += lazy[rt];
    T[rson] += lazy[rt] * (r - mid);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R)
    {
        T[rt] += (r - l + 1) * val;
        lazy[rt] += val;
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(lson, l, mid, L, R, val);
    if (mid <  R) update(rson, mid + 1, r, L, R, val);
    pushup(rt);
}

int query(int rt, int l, int r, int pos)
{
    if (l == r) return T[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (pos <= mid) return query(lson, l, mid, pos);
    else return query(rson, mid + 1, r, pos);
}

struct node{int qL, id;};
vector<node>qR[maxn], tt;

long long aa;bool bb;char ch;
long long scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}

int main()
{
    int tt = 0;
	while (~scanf("%d%d", &n, &q))
    {
        tt++;
        int mx = 0;
        for (int i = 1; i <= n; i++) a[i] = scan(), mx = max(mx, a[i]);
        for (int i = 1; i <= n; i++) qR[i].clear();
        for (int i = 1; i <= q; i++)
        {
            int l, r; 
            l = scan(); r = scan();
            qR[r].pb({l, i});
        }
        build_gcd(1, 1, n);
        build(1, 1, n);
        for (int i = 1; i <= n; i++)
        {
            if (pos[tt][a[i]] < i) 
            {
                update(1, 1, n, pos[tt][a[i]] + 1, i, 1);
                pos[tt][a[i]] = i;
            }
            int now = a[i];
            int l = 1, r = i;
            while (1)
            {
                while (l < r)
                {
                    int mid = (l + r) / 2;
                    int gg = query_gcd(1, 1, n, mid, i);
                    if (gg != now) l = mid + 1;
                    else r = mid;
                }
                int p = l - 1;  
                if (p < 1) break;
                now = query_gcd(1, 1, n, p, i);
                if (pos[tt][now] < p) 
                {
                    update(1, 1, n, pos[tt][now] + 1, p, 1);
                    pos[tt][now] = p;
                }
                l = 1; r = p;  
            }
            for (node x : qR[i])
            {
                int qL = x.qL, id = x.id;
                ans[id] = query(1, 1, n, qL);
            }
        }
        for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    }
	return 0;
}

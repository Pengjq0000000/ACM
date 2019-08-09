#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 250000 + 7;
struct task
{
    int A, B, rk, tim;
    bool operator < (const task &rhs) const
    {
        if (A * rhs.B == rhs.A * B) return A < rhs.A;
        return A * rhs.B < rhs.A * B;
    }
}a[maxn], b[maxn];
bool cmp(const task &x, const task & y) {return x.tim < y.tim;}
struct node
{
    LL sumA, sumB;
    node(LL sumA, LL sumB) : sumA(sumA), sumB(sumB) {}
    node(){}
    node operator + (const node &rhs) const
    {
        return {sumA + rhs.sumA, sumB + rhs.sumB};
    }
}T[maxn << 2];
void build(int rt, int l, int r)
{
    T[rt].sumA = T[rt].sumB = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void pushup(int rt) {T[rt] = T[rt << 1] + T[rt << 1 | 1];}
void update(int rt, int l, int r, int pos, node x)
{
    if (l == r) {T[rt] = T[rt] + x; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(rt << 1, l, mid, pos, x);
    else update(rt << 1 | 1, mid + 1, r, pos, x);
    pushup(rt);
}
pair<LL, LL>res, ans;
void query(int rt, int l, int r)
{
    if (l == r)
    {
        ans.fir = T[rt].sumA * T[rt].sumB + res.fir * T[rt].sumB + res.sec * T[rt].sumA;
        ans.sec = T[rt].sumA + T[rt].sumB;
        LL gg = __gcd(ans.fir, ans.sec);
        ans.fir /= gg; ans.sec /= gg;
        return;
    }
    int mid = (l + r) >> 1;
    LL SUMA = res.fir + T[rt << 1].sumA - b[mid].A;
    LL SUMB = res.sec + T[rt << 1 | 1].sumB;
    LL up = SUMB - SUMA + b[mid].B, down = b[mid].A + b[mid].B;
    if (up < 0 || up <= down)
    {
        res.sec += T[rt << 1 | 1].sumB;
        query(rt << 1, l, mid);
    }
    else
    {
        res.fir += T[rt << 1].sumA;
        query(rt << 1 | 1, mid + 1, r);
    }
}
int main()
{
	int tt; scanf("%d", &tt);
    while (tt--)
    {
        int n; scanf("%d", &n);
        build(1, 1, n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i].A, &a[i].B); a[i].tim = i;
            b[i].A = a[i].A; b[i].B = a[i].B;
        }
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; i++) a[i].rk = i;
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
        {
            update(1, 1, n, a[i].rk, node(a[i].A, a[i].B));
            res.fir = res.sec = 0;
            query(1, 1, n);
            printf("%lld/%lld\n", ans.fir, ans.sec);
        }
    }
	return 0;
}

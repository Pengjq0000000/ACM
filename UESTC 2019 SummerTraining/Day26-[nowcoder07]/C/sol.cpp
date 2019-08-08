#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 207;
struct Node
{
    int h, c, p;
    bool operator < (const Node &rhs) const
    {
        return h > rhs.h;
    }
}a[100007];
LL cnt[maxn];
struct node{LL num, cost;} T[maxn << 2];
void pushup(int rt)
{
    T[rt].num = T[rt << 1].num + T[rt << 1 | 1].num;
    T[rt].cost = T[rt << 1].cost + T[rt << 1 | 1].cost;
}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        T[rt].num = cnt[l]; T[rt].cost = T[rt].num * (LL)l;
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos, LL x)
{
    if (l == r)
    {
        T[rt].num -= x; T[rt].cost = T[rt].num * (LL)l;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(rt << 1, l, mid, pos, x);
    else update(rt << 1 | 1, mid + 1, r, pos, x);
    pushup(rt);
}
LL res;
void query(int rt, int l, int r, LL need)
{
    if (l == r)
    {
        res += need * (LL)l;
        return;
    }
    int mid = (l + r) / 2;
    if (T[rt << 1].num >= need) query(rt << 1, l, mid, need);
    else
    {
        res += T[rt << 1].cost;
        need -= T[rt << 1].num;
        query(rt << 1 | 1, mid + 1, r, need);
    }
}

int main()
{
	int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= 200; i++) cnt[i] = 0;
        LL tot = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i].h, &a[i].c, &a[i].p);
            cnt[a[i].c] += (LL)a[i].p;
            tot += a[i].p;
        }
        sort(a + 1, a + 1 + n);
        LL ans = 1e18, low_cost = 0;
        build(1, 1, 200);
        int i = 1;
        while (i <= n)
        {
            LL mxh = a[i].h, sum = 0, tmp = 0;
            while (mxh == a[i].h && i <= n)
            {
                sum += a[i].p; tmp += (LL)a[i].p * a[i].c;
                update(1, 1, 200, a[i].c, a[i].p);
                i++;
            }
            LL need = max(0ll, tot - 2 * sum + 1);
            res = 0; if (need) query(1, 1, 200, need);
            ans = min(ans, low_cost + res);
            //printf("mxh:%lld ans:%lld\n", mxh, low_cost + res); 
            low_cost += tmp;
            tot -= sum;
        }
        printf("%lld\n", ans); 
    }
	return 0;
}

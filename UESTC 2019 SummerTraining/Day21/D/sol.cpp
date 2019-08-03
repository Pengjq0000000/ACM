#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1000 + 7;
int T[maxn << 2];
void pushup(int rt) {T[rt] = max(T[rt << 1], T[rt << 1 | 1]);}
void build(int rt, int l, int r, int x)
{
    if (l == r) {T[rt] = x; return;}
    int mid = (l + r) / 2;
    build(rt << 1, l, mid, x);
    build(rt << 1 | 1, mid + 1, r, x);
    pushup(rt);
}
void update(int rt, int l, int r, int pos, int x)
{
    if (l == r) {T[rt] -= x; return;}
    int mid = (l + r) / 2;
    if (pos <= mid) update(rt << 1, l, mid, pos, x);
    else update(rt << 1 | 1, mid + 1, r, pos, x);
    pushup(rt);
}
int query(int rt, int l, int r, int x)
{
    if (l == r)
    {
        if (T[rt] >= x)
        return l;
        else return -1;
    }
    int mid = (l + r) / 2;
    if (T[rt << 1] >= x) return query(rt << 1, l, mid, x);
    else if (T[rt << 1 | 1] >= x) return query(rt << 1 | 1, mid + 1, r, x);
    else return -1;
}
int n, k;
int s[maxn], a[maxn];
bool check(int m)
{
    build(1, 1, k, m);
    for (int i = n; i >= 1; i--)
    {
        int pos = query(1, 1, k, a[i]);
        if (pos == -1) return false;
        update(1, 1, k, pos, a[i]);
    }
    return true;
}
int main()
{
	int tt, cas = 0;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d%d", &n, &k);
        int mx = 0, sum = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]), sum += a[i];
        sort(a + 1, a + 1 + n);
        int pos;
        int base = 1;
        mx = 2000;
        for (int i = 1; i <= n; i++)
            if (check(i * mx))
            {
                pos = i;
                break;
            }
        
        //while (!check(base)) base *= 2;
        //printf("mx: %d,debug:%d\n",mx,  mx * pos);
        int ans = sum;
        int l = (pos - 1) * mx , r = pos * mx;
        //int l = base / 2, r = base; 
        for (int i = l; i <= r; i++)
            if (check(i))
            {
                ans = i;
                break;
            }
        printf("Case #%d: %d\n", ++cas, ans);
    }
	return 0;
}

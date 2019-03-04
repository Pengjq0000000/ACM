#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e6 + 7;
int T[maxn << 2];
void pushup(int rt) {T[rt] = min(T[rt << 1], T[rt << 1 | 1]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = -1; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos, int val)
{
    if (l == r) {T[rt] = val; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    pushup(rt);
}
int query(int rt, int l, int r, int val)
{
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (T[rt << 1] < val) return query(rt << 1, l, mid, val);
    else return query(rt << 1 | 1, mid + 1, r, val);
}
int main()
{
    int n; scanf("%d", &n);
    build(1, 1, n);
    update(1 ,1, n, 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int c; scanf("%d", &c);
        int ans = query(1, 1, n, i - c);
        printf("%d ",ans);
        update(1, 1, n, ans, i);
    }
    return 0;
}


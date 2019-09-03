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
const int maxn = 1e6 + 7;
int T[maxn << 2][4], a[maxn];
bool lazy[maxn << 2];
void pushup(int rt)
{
    T[rt][0] = T[lson][0] + T[rson][0];
    T[rt][1] = T[lson][1] + T[rson][1];
    T[rt][2] = max(T[lson][0] + T[rson][1], max(T[lson][2] + T[rson][1], T[lson][0] + T[rson][2]));
    T[rt][3] = max(T[lson][1] + T[rson][0], max(T[lson][3] + T[rson][0], T[lson][1] + T[rson][3]));
}
void build(int rt, int l, int r)
{
    MEM(T[rt], 0);
    if (l == r)
    {
        T[rt][a[l]] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void change(int rt)
{
    swap(T[rt][0], T[rt][1]);
    swap(T[rt][2], T[rt][3]);
}
void pushdown(int rt)
{
    if (!lazy[rt]) return;
    lazy[lson] ^= lazy[rt]; lazy[rson] ^= lazy[rt];
    change(lson); change(rson);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        lazy[rt] ^= 1; change(rt);
        return;
    }
    pushdown(rt);
    int mid = (l + r) / 2;
    if (L <= mid) update(lson, l, mid, L, R);
    if (mid <  R) update(rson, mid + 1, r, L, R);
    pushup(rt);
}
char s[maxn];
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) a[i] = (s[i] == '7');
    build(1, 1, n);
    int l, r;
    while (m--)
    {
        scanf("%s", s);
        if (s[0] == 'c') 
        {
            printf("%d\n", max(T[1][0], max(T[1][1], T[1][2])));
        }
        else
        {
            scanf("%d%d", &l, &r);
            update(1, 1, n, l, r);
        }
    }
	return 0;
}

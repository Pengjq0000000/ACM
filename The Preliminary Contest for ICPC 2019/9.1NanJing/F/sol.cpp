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
int T[maxn << 2];
void pushup(int rt) {T[rt] = max(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    T[rt] = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void update(int rt, int l, int r, int pos, int val)
{
    if (l == r) {T[rt] = val; return;}
    int mid = (l + r) / 2;
    if (pos <= mid) update(lson, l, mid, pos, val);
    else update(rson, mid + 1, r, pos, val);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) / 2, res = -1e9;
    if (L <= mid) res = max(res, query(lson, l, mid, L, R));
    if (mid <  R) res = max(res, query(rson, mid + 1, r, L, R));
    return res;
}
int a[maxn], pos[maxn], ans[maxn], dp[maxn];

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
	int tt; scanf("%d", &tt);
    while (tt--)
    {
        int n, k; scanf("%d%d", &n, &k);
        build(1, 1, n);
        for (int i = 1; i <= n; i++) 
        {
            a[i] = scan();
            pos[a[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            int now = pos[i];
            int val = dp[query(1, 1, n, max(1, now - k), min(n, now + k))] + 1;
            update(1, 1, n, now, i);
            dp[i] = val;
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", dp[i], i == n ? '\n' : ' ');
    }
	return 0;
}

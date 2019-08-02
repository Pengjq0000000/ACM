#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
const int N = 1e6;
struct node{int l, r, sum;}T[maxn * 22];
int a[maxn], root[maxn];

int cnt = 0;
void update(int &rt, int pre, int l, int r, int pos)
{
	T[rt = ++cnt] = T[pre]; //每次更新先复制先前版本
	T[rt].sum++; //在新版本上更新
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) update(T[rt].l, T[pre].l, l, mid, pos);
	else update(T[rt].r, T[pre].r, mid + 1, r, pos);
}

int query(int rt, int pre, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].sum - T[pre].sum;
    int mid = (l + r) / 2, res = 0;
    if (L <= mid) res += query(T[rt].l, T[pre].l, l, mid, L, R);
    if (mid <  R) res += query(T[rt].r, T[pre].r, mid + 1, r, L, R);
    return res;
}


int l, r, p, k; 
bool check(int x)
{
    int up = min(N, p + x), low = max(1, p - x);
    int cnt = query(root[r], root[l - 1], 1, N, low, up);
    return cnt >= k;
}
int main()
{
	int tt; scanf("%d", &tt);
    while (tt--)
    {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        MEM(T, 0);
        for (int i = 1; i <= n; i++) update(root[i], root[i - 1], 1, N, a[i]);
        int ans = 0;
        while (m--)
        {
            scanf("%d%d%d%d", &l, &r, &p, &k);
            l ^= ans; r ^= ans; p ^= ans; k ^= ans;
            int L = 0, R = 1e6;
            while (L < R)
            {
                int mid = (L + R) / 2;
                if (check(mid)) R = mid;
                else L = mid + 1;
            }
            ans = L;
            printf("%d\n", ans);
        }
    }
	return 0;
}

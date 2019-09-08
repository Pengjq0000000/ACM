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
const int maxn = 2e6 + 7;
int T[maxn << 2];
void pushup(int rt) {T[rt] = T[lson] + T[rson];}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = 1; return;}
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos)
{
    if (l == r) {T[rt]--; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, l, mid, pos);
    else update(rson, mid + 1, r, pos);
    pushup(rt); 
}
int query(int rt, int l, int r, int L, int R)
{
    int mid = (l + r) >> 1;
    if (L <= l && r <= R)
    {
        if (l == r) return T[rt] > 0 ? l : -1;
        if (T[lson]) return query(lson, l, mid, L, R);
        else return query(rson, mid + 1, r, L, R);
    }
    int res = -1;
    if (L <= mid) res = query(lson, l, mid, L, R);
    if (res > 0) return res;
    if (mid <  R) res = query(rson, mid + 1, r, L, R);
    return res;
}
int op[maxn], x[maxn];
int n, q;
vector<int>vec;
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int main()
{
	scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &op[i], &x[i]);
        vec.pb(x[i]);
        if (x[i] < n) vec.pb(x[i] + 1);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int N = vec.size();
    build(1, 1, N);
    for (int i = 1; i <= q; i++)
    {
        if (op[i] == 1) update(1, 1, N, getid(x[i]));
        else 
        {
            int pos = query(1, 1, N, getid(x[i]), N);
            if (pos == -1) printf("-1\n");
            else printf("%d\n", vec[pos - 1]);
        }
    }
	return 0;
}

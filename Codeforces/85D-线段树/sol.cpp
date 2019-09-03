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
struct node
{
    LL sum[5]; int cnt;
}T[maxn << 2];
int op[maxn], a[maxn];
vector<int>vec;
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
void pushup(int rt)
{
    for (int i = 0; i < 5; i++)
        T[rt].sum[i] = T[lson].sum[i] + T[rson].sum[(i - T[lson].cnt % 5 + 5) % 5];
    T[rt].cnt = T[lson].cnt + T[rson].cnt;
}
void update(int rt, int l, int r, int pos, int val)
{
    if (l == r) 
    {
        if (val > 0) T[rt].cnt++;
        else T[rt].cnt--;
        T[rt].sum[1] += val; 
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(lson, l, mid, pos, val);
    else update(rson, mid + 1, r, pos, val);
    pushup(rt);
}
int main()
{
	int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char s[10]; scanf("%s", s);
        if (s[0] == 'a') {op[i] = 1; scanf("%d", &a[i]); vec.pb(a[i]);}
        else if (s[0] == 'd') {op[i] = 2; scanf("%d", &a[i]);}
        else op[i] = 3;
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 1; i <= n; i++)
    {
        if (op[i] == 1) update(1, 1, n, getid(a[i]), a[i]);
        else if (op[i] == 2) update(1, 1, n, getid(a[i]), -a[i]);
        else printf("%lld\n", T[1].sum[3]);
    }
	return 0;
}

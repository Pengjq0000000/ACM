#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6+7;
int vis[maxn];
int prime[maxn], mu[maxn], tot = 0; //1 ~ tot
int minprim[maxn];
int id[maxn];
void get_prime(int maxl) // get prime <= maxl
{
	mu[1] = 1;
    minprim[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i])
        {
            prime[++tot] = i, mu[i] = -1; minprim[i] = i;
            id[i] = tot; 
        }
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            minprim[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) 
            {
            	mu[i * prime[j]] = 0;
            	break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    //vis[i] == 0 -> i is a prime
}

bitset<50004>sta[41550], rev_sta[41550];
int a[maxn];
vector<int>ft[maxn];
int n, m; 
void DEBUG()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d:", a[i]);
        for (int p : ft[i]) printf("%d ", p);
        puts("");
    }
}
int posL[maxn], posR[maxn];
bitset<50004>mask, rev_mask;

struct node{int lpos, rpos;} T[200005];
void pushup(int rt)
{
    T[rt].lpos = max(T[rt << 1].lpos, T[rt << 1 | 1].lpos);
    T[rt].rpos = min(T[rt << 1].rpos, T[rt << 1 | 1].rpos);
    return;
}
void build(int rt, int l, int r)
{
    if (l == r) 
    {
        T[rt].lpos = posL[l];
        T[rt].rpos = posR[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
int querymx(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].lpos;
    int mid = (l + r) / 2;
    int res = -1;
    if (L <= mid) res = max(res, querymx(rt << 1, l, mid, L, R));
    if (mid <  R) res = max(res, querymx(rt << 1 | 1, mid + 1, r, L, R));
    return res; 
}
int querymi(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].rpos;
    int mid = (l + r) / 2;
    int res = 1e9;
    if (L <= mid) res = min(res, querymi(rt << 1, l, mid, L, R));
    if (mid <  R) res = min(res, querymi(rt << 1 | 1, mid + 1, r, L, R));
    return res; 
}
int main()
{
    get_prime(5e5);
    for (int i = 1; i <= tot; i++) 
    {
        sta[i].set();
        rev_sta[i].set();
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        int tmp = a[i];
        while (tmp > 1)
        {

            int x = minprim[tmp];
            while (tmp % x == 0) tmp /= x;
            sta[id[x]][i] = 0;
            rev_sta[id[x]][n - i + 1] = 0;
            ft[i].pb(id[x]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        mask.set();
        rev_mask.set();
        for (int p : ft[i])
        {
            mask &= sta[p];
            rev_mask &= rev_sta[p];
        }
        int r = mask._Find_next(i);
        if (r > n) r = n + 1;
        int l = rev_mask._Find_next(n - i + 1);
        l = n - l + 1;
        posR[i] = r;
        posL[i] = l;
    }
    // for (int i = 1; i <= n; i++) printf("%d ", posL[i]); puts("");
    // for (int i = 1; i <= n; i++) printf("%d ", posR[i]); puts("");
    // return 0;
    // DEBUG();
    build(1, 1, n);
    while (m--)
    {
        int l, r; scanf("%d%d", &l, &r);
        int tmp;
        tmp = querymx(1, 1, n, l, r);
        //printf("maxl:%d,", tmp);
        if (l <= tmp && tmp <= r) 
        {
            puts("S");
            continue;
        }
        tmp = querymi(1, 1, n, l, r);
        //printf("minr:%d\n", tmp);
        if (l <= tmp && tmp <= r)
        {
            puts("S");
        }
        else puts("N");
    }
	return 0;
}

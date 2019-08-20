#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 4e5 + 100;

int T[maxn << 2];
void pushup(int rt) {T[rt] = T[lson] + T[rson];}
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
    if (l == r) {T[rt] += val; return;}
    int mid = (l + r) / 2;
    if (pos <= mid) update(lson, l, mid, pos, val);
    else update(rson, mid + 1, r, pos, val);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) / 2, res = 0;
    if (L <= mid) res += query(lson, l, mid, L, R);
    if (mid <  R) res += query(rson, mid + 1, r, L, R);
    return res;
}


vector<int>vec;
pii qL[maxn], qR[maxn], qU[maxn], qD[maxn];
int totL, totR, totU, totD;
bool cmp1(pii a, pii b) {return a.sec < b.sec;}
bool cmp2(pii a, pii b) {return a.sec > b.sec;}
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        vec.clear();
        int n, m, k; scanf("%d%d%d", &n, &m, &k);
        vec.pb(0); vec.pb(n); vec.pb(m);
        totL = totR = totU = totD = 0;
        for (int i = 1, x, y; i <= k; i++)
        {
            char ch;
            scanf("%d %d %c", &x, &y, &ch);
            if (ch == 'L') qL[++totL] = make_pair(x, y);
            else if (ch == 'R') qR[++totR] = make_pair(x, y);
            else if (ch == 'U') qU[++totU] = make_pair(x, y);
            else if (ch == 'D') qD[++totD] = make_pair(x, y);
            vec.pb(x); vec.pb(y);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int N = vec.size();
        for (int i = 1; i <= totL; i++)
        {
            qL[i].fir = getid(qL[i].fir);
            qL[i].sec = getid(qL[i].sec);
        }
        for (int i = 1; i <= totR; i++)
        {
            qR[i].fir = getid(qR[i].fir);
            qR[i].sec = getid(qR[i].sec);
        }
        for (int i = 1; i <= totU; i++)
        {
            qU[i].fir = getid(qU[i].fir);
            qU[i].sec = getid(qU[i].sec);
        }
        for (int i = 1; i <= totD; i++)
        {
            qD[i].fir = getid(qD[i].fir);
            qD[i].sec = getid(qD[i].sec);
        }

        LL ans = 1;
        sort(qD + 1, qD + 1 + totD, cmp1);
        build(1, 1, N);
        sort(qL + 1, qL + 1 + totL, cmp1);
        int now = 1;
        for (int i = 1; i <= totD; i++)
        {
            while (now <= totL && qD[i].sec >= qL[now].sec)
            {
                update(1, 1, N, qL[now].fir, 1);
                now++;
            }
            ans += query(1, 1, N, qD[i].fir, N);
        }


        build(1, 1, N);
        sort(qR + 1, qR + 1 + totR, cmp1);
        now = 1;
        for (int i = 1; i <= totD; i++)
        {
            while (now <= totR && qD[i].sec >= qR[now].sec)
            {
                update(1, 1, N, qR[now].fir, 1);
                now++;
            }
            ans += query(1, 1, N, 1, qD[i].fir);
        }

        sort(qU + 1, qU + 1 + totU, cmp2);
        build(1, 1, N);
        sort(qL + 1, qL + 1 + totL, cmp2);
        now = 1;
        for (int i = 1; i <= totU; i++)
        {
            while (now <= totL && qU[i].sec <= qL[now].sec)
            {
                update(1, 1, N, qL[now].fir, 1);
                now++;
            }
            ans += query(1, 1, N, qU[i].fir, N);
        }

        build(1, 1, N);
        sort(qR + 1, qR + 1 + totR, cmp2);
        now = 1;
        for (int i = 1; i <= totU; i++)
        {
            while (now <= totR && qU[i].sec <= qR[now].sec)
            {
                update(1, 1, N, qR[now].fir, 1);
                now++;
            }
            ans += query(1, 1, N, 1, qU[i].fir);
        }
        printf("%lld\n", ans);
    }
	return 0;
}

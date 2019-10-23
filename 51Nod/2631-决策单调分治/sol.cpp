#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
#define inf 2e9
using namespace std;
const int maxn = 5e5 + 7;
vector<int>vec;
inline int id(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
pii A[maxn], B[maxn], S[maxn], T[maxn];
int MINY_A[maxn << 2], MAXY_B[maxn << 2];
ll ans;
ll cal(pii &x, pii &y) {return (ll)(y.fir - x.fir) * (y.sec - x.sec);}
void deal(int l, int r, int L, int R)
{
    int mid = (l + r) >> 1;
    ll res = 0; int pos = 0;
    for (int i = L; i <= R; i++)
    {
        ll tmp = cal(S[mid], T[i]);
        if (tmp > res) res = tmp, pos = i;
    }
    ans = max(ans, res);
    if (l == r) return;
    deal(l, mid, L, pos);
    deal(mid + 1, r, pos, R);
}


int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &A[i].fir, &A[i].sec);
        vec.push_back(A[i].fir); vec.push_back(A[i].sec);
    }
    for (int i = 1; i <= m; i++) 
    {
        scanf("%d%d", &B[i].fir, &B[i].sec);
        vec.push_back(B[i].fir); vec.push_back(B[i].sec);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int N = vec.size();
    for (int i = 1; i <= m; i++) 
    {
        int x = id(B[i].fir), y = id(B[i].sec);
        MAXY_B[x] = max(MAXY_B[x], y);
    }
    int totS = 0, totT= 0;
    T[0] = {-2e9, 2e9};
    for (int i = 1; i <= N; i++)
    {
        if (!MAXY_B[i]) continue;
        pii p = {vec[i - 1], vec[MAXY_B[i] - 1]};
        while (totT && T[totT].sec <= p.sec) totT--;
        T[++totT] = p;
    }
    
    for (int i = N; i; i--) MAXY_B[i] = max(MAXY_B[i + 1], MAXY_B[i]);

    for (int i = 1; i <= N; i++) MINY_A[i] = inf;
    for (int i = 1; i <= n; i++)
    {
        int x = id(A[i].fir), y = id(A[i].sec);
        MINY_A[x] = min(MINY_A[x], y);
    }
    S[0] = {-2e9, 2e9};
    for (int i = 1; i <= N; i++) 
    {
        if (MINY_A[i] == inf) continue;
        pii p = {vec[i - 1], vec[MINY_A[i] - 1]};
        if (p.sec < S[totS].sec && MAXY_B[i + 1] > MINY_A[i]) S[++totS] = p;
    }


    if (totS && totT) deal(1, totS, 1, totT);
    printf("%lld\n", ans);
    return 0;
}
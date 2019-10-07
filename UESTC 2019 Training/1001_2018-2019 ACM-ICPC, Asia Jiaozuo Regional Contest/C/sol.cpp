#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 3e5 + 7;
int n, m;
int cntLL, cntLR, cntRR, cntRL;
bool vis[maxn];
void check(int x);
struct Info
{
    int pos[maxn], id[maxn];
    int L, R, det;
    void reset() {L = 1; R = n; det = 0;}
    void init(){check(id[1]); check(id[n]);}
    void set(int p, int index) {pos[index] = p; id[p] = index;}
    void Move_left(int k)
    {
        while (L < R && L + det - k < 1) check(id[++L]);
        if (L + det - k >= 1) det -= k;
        else det = 1 - L; // L + det == 1
    }
    void Move_right(int k)
    {
        while (L < R && R + det + k > n) check(id[--R]);
        if (R + det + k <= n) det += k;
        else det = n - R; // R + det == n 
    }
    int Ask(int x)
    {
        if (pos[x] < L) return L + det;
        if (pos[x] > R) return R + det;
        return pos[x] + det;
    }
}LR, UD;
void check(int x)
{
    //printf("x = %d, pos : %d %d\n", x, UD.pos[x], LR.pos[x]);
    if (vis[x]) return;
    if (LR.pos[x] <= LR.L && UD.pos[x] <= UD.L) cntLL++, vis[x] = 1;
    else if (LR.pos[x] <= LR.L && UD.pos[x] >= UD.R) cntLR++, vis[x] = 1;
    else if (LR.pos[x] >= LR.R && UD.pos[x] >= UD.R) cntRR++, vis[x] = 1;
    else if (LR.pos[x] >= LR.R && UD.pos[x] <= UD.L) cntRL++, vis[x] = 1;
    //printf("cntLL = %d, cntLR = %d, cntRR = %d, cntRL = %d\n", cntLL, cntLR, cntRR, cntRL);
}
LL C[maxn];
LL cal()
{
    //printf("cntLL = %d, cntLR = %d, cntRR = %d, cntRL = %d\n", cntLL, cntLR, cntRR, cntRL);
    if (LR.L == LR.R && UD.L == UD.R) return C[cntLL + cntLR + cntRR + cntRL];
    if (LR.L == LR.R) return C[cntLL + cntRL] + C[cntLR + cntRR];
    if (UD.L == UD.R) return C[cntLL + cntLR] + C[cntRL + cntRR];
    return C[cntLL] + C[cntRL] + C[cntLR] + C[cntRR];
}
int main()
{
    for (int i = 1; i <= 300000; i++) C[i] = (LL)i * (i - 1) / 2;
    int T; scanf("%d", &T);
    while (T--)
    {
        cntLL = cntLR = cntRR = cntRL = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1, x, y; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            LR.set(y, i);
            UD.set(x, i);
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        LR.reset(); UD.reset();
        LR.init(); UD.init();
        while (m--)
        {
            char s[10]; scanf(" %s", s);
            if (s[0] == '!') {printf("%lld\n", cal()); continue;}
            int k; scanf("%d", &k);
            if (s[0] == '?') printf("%d %d\n", UD.Ask(k), LR.Ask(k));
            else if (s[0] == 'L') LR.Move_left(k);
            else if (s[0] == 'R') LR.Move_right(k);
            else if (s[0] == 'U') UD.Move_left(k);
            else if (s[0] == 'D') UD.Move_right(k);
        }
    }
    return 0;
}
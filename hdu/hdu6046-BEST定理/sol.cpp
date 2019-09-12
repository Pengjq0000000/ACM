#include<bits/stdc++.h>
#define LL long long
#define MOD(x) ((x) % mod)
#define mod 998244353
using namespace std;
const int maxn = 407;
LL ksm(LL a, LL b)
{
    LL res = 1;
    while (b) {if (b & 1) res = MOD(res * a); a = MOD(a * a); b >>= 1;}
    return res;
}
struct Mat
{
    LL mat[maxn][maxn];
    int n;
    Mat(int _n){n = _n;}
    inline void init() 
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                mat[i][j] = 0;
    }
    LL A[maxn][maxn];
    LL Pminor_det(int p)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                A[i][j] = mat[i][j];
        int sig = 0;
        swap(A[p], A[n]);
        for (int i = 1; i <= n; i++)
            swap(A[i][p], A[i][n]);
        for (int i = 1; i < n; i++)
        {
            int pivot = i;
            for (int j = i + 1; j < n; j++)
                if (A[i][j]) {pivot = i; break;}
            swap(A[i], A[pivot]);
            if (i != pivot) sig ^= 1;
            for (int j = i + 1; j < n; j++)
            {
                LL x = MOD(A[j][i] * ksm(A[i][i], mod - 2));
                for (int k = i; k < n; k++) 
                    A[j][k] = MOD(A[j][k] - MOD(A[i][k] * x) + mod);
            }
        }
        LL res = 1; for (int i = 1; i < n; i++) res = MOD(res * A[i][i]);
        return res;
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                printf("%lld%c", mat[i][j], j == n ? '\n' : ' ');
    }
};
int m, D[maxn][maxn], ind[maxn], outd[maxn];
LL fac[507 * 507], inv[507 * 507];
int main()
{
    fac[0] = 1; for (int i = 1; i <= 250000; i++) fac[i] = MOD(fac[i - 1] * i);
    inv[250000] = ksm(fac[250000], mod - 2);
    for (int i = 250000; i >= 1; i--) inv[i - 1] = MOD(inv[i] * i);
    int cas = 0;
    while (~scanf("%d", &m))
    {
        for (int i = 1; i <= m; i++) ind[i] = outd[i] = 0;
        Mat L(m);
        L.init();
        LL dv = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &D[i][j]);
                outd[i] += D[i][j], ind[j] += D[i][j];
                L.mat[i][j] -= D[i][j];
                L.mat[i][i] += D[i][j];
                dv = MOD(dv * inv[D[i][j]]);
            }
        
        bool flag = 1;
        for (int i = 1; i <= m; i++)
            if (ind[i] != outd[i]) flag = 0;
        if (!flag) 
        {
            printf("Case #%d: 0\n", ++cas); 
            continue;
        }
        LL ans = L.Pminor_det(1); 
        ans = MOD(ans * fac[outd[1]]);
        for (int i = 2; i <= m; i++)
            if (outd[i]) ans = MOD(ans * fac[outd[i] - 1]);
        ans = MOD(ans * dv);
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}
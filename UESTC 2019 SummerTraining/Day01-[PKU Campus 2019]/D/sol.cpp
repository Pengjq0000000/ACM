#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod P
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
LL P, inv2;
void fwt(int *a, int n)
{
    for (int k = 1; k < n; k <<= 1)
        for (int m = k << 1, i = 0; i < n; i += m)
            for (int j = 0; j < k; j++)
            {
                int x = a[i + j], y = a[i + j + k];
                a[i + j] = MOD(x + y); 
                a[i + j + k] = MOD(x - y + mod);
            }
}
void ifwt(int *a, int n)
{
    for (int k = 1; k < n; k <<= 1)
        for (int m = k << 1, i = 0; i < n; i += m)
            for (int j = 0; j < k; j++)
            {
                int x = a[i + j], y = a[i + j + k];
                a[i + j] = MOD(MOD(x + y) * inv2);
                a[i + j + k] = MOD(MOD(x - y + mod) * inv2);
            }
}
LL ksm(LL a, LL b)
{
    LL res = 1, base = a;
    while (b)
    {
        if (b & 1) res = MOD(res * base);
        base = MOD(base * base);
        b >>= 1;
    }
    return res;
}
int a[maxn], b[maxn], c[maxn];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n, x, y, z; scanf("%d%d%d%d%lld", &n, &x, &y, &z, &P);
        int tot = (1 << n);
        for (int i = 0; i < tot; i++) a[i] = b[i] = c[i] = 0;
        for (int i = 1; i <= x; i++)
        {
            int l, r, val; scanf("%d%d%d", &l, &r, &val);
            a[r + 1] = MOD(a[r + 1] - val + P); a[l] = MOD(a[l] + val);
        }
        for (int i = 1; i < tot; i++) a[i] = MOD(MOD(a[i] + a[i - 1]) + P);
        for (int i = 1; i <= y; i++)
        {
            int l, r, val; scanf("%d%d%d", &l, &r, &val);
            b[r + 1] = MOD(b[r + 1] - val + P); b[l] = MOD(b[l] + val);
        }
        for (int i = 1; i < tot; i++) b[i] = MOD(MOD(b[i] + b[i - 1]) + P);
        fwt(a, tot);
        fwt(b, tot);
        inv2 = ksm(2, P - 2);
        for (int i = 0; i < tot; i++) c[i] = MOD(a[i] * b[i]);
        ifwt(c, tot);
        for (int i = 1; i < tot; i++) c[i] = MOD(MOD(c[i] + c[i - 1]) + P);
        for (int i = 1; i <= z; i++)
        {
            int l, r; scanf("%d%d", &l, &r);
            int rsum = c[r], lsum = (l ? c[l - 1] : 0);
            printf("%d%c", (int)MOD(rsum - lsum + P), (i == z ? '\n' : ' '));
        }
    }
 	return 0;
}

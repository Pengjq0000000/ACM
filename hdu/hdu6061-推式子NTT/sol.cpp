#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 998244353
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
// --------------------------------------------NTT---------------------------------------------- //
const int maxn = 1e6 + 7;
LL ksm(LL a, LL b) {LL res = 1; while (b) {if (b & 1) res = MOD(res * a); a = MOD(a * a); b >>= 1;} return res;}
namespace NTT
{
    LL g = 3; // mod == 998244353
    const double PI = acos(-1);
    int R[maxn], N;
    void init(int lena, int lenb)
    {
        N = 1;
        while (N < lena + lenb) N <<= 1;
        for (int i = 0; i < N; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) ? N >> 1 : 0);
    }
    void DFT(LL *A, int flag, int N)
    {
        for (int i = 0; i < N; i++) 
            if (i < R[i]) swap(A[i], A[R[i]]);
        for (int len = 1; len < N; len <<= 1)
        {
            LL e = (mod - 1) / (len << 1);
            LL wn = ksm(g, flag == 1 ? e : mod - 1 - e);
            //comp wn(cos(PI / len), flag * sin(PI / len));
            for (int i = 0; i < N; i += (len << 1))
            {
                LL w = 1;
                for (int j = 0; j < len; j++, w = MOD(w * wn))
                {
                    LL Nx = A[i + j], Ny = MOD(w * A[i + len + j]);
                    A[i + j] = MOD(Nx + Ny);
                    A[i + len + j] = MOD(Nx - Ny + mod); 
                }   
            }
        }
    }
    LL A[maxn], B[maxn];
    void Convolution(LL *a, int lena, LL *b, int lenb, LL *res)
    {
        init(lena, lenb);
        // three times DFT
        for (int i = 0; i < N; i++) A[i] = MOD(a[i]), B[i] = MOD(b[i]);
        DFT(A, 1, N); DFT(B, 1, N);
        for (int i = 0; i < N; i++) A[i] = MOD(A[i] * B[i]);
        DFT(A, -1, N);
        LL invN = ksm(N, mod - 2);
        for (int i = 0; i < N; i++) res[i] = MOD(A[i] * invN);
        for (int i = 0; i < N; i++) A[i] = B[i] = a[i] = b[i] = 0;
    }
}
// --------------------------------------template end------------------------------------------ //
LL A[maxn], B[maxn], c[maxn], res[maxn];
LL fac[maxn], inv[maxn];
int n, m;

int main()
{
    fac[0] = 1; for (int i = 1; i <= 200000; i++) fac[i] = MOD(fac[i - 1] * i);
    inv[200000] = ksm(fac[200000], mod - 2); for (int i = 200000; i > 0; i--) inv[i - 1] = MOD(inv[i] * i);
	while (~scanf("%d", &n))
    {
        for (int i = 0; i <= n; i++) scanf("%lld", &c[i]);
        LL s = 0, x; scanf("%d", &m);
        while (m--) {scanf("%lld", &x); s = MOD(s + mod - x);}
        for (int i = 0; i <= n; i++) 
        {
            A[i] = MOD(c[i] * fac[i]);
            B[i] = MOD(ksm(s, n - i) * inv[n - i]);
        }
        NTT::Convolution(A, n + 1, B, n + 1, res);
        for (int i = 0; i <= n; i++) 
            printf("%lld ", MOD(inv[i] * res[n + i]));
        puts("");
    }
	return 0;
}

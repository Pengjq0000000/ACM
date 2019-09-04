#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 998244353
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
namespace NTT
{
    LL g = 3; // mod == 998244353
    const double PI = acos(-1);
    int R[maxn], N;
    LL ksm(LL a, LL b) {LL res = 1; while (b) {if (b & 1) res = MOD(res * a); a = MOD(a * a); b >>= 1;} return res;}
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
    }
}
LL a[maxn], b[maxn], C[maxn], can[maxn];
int main()
{
	int n, mx = 0; scanf("%d", &n);
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        a[x] = b[x] = C[x] = 1;
        mx = max(mx, x);
    }
    NTT::Convolution(a, mx, b, mx, can);
    int m, ans = 0; scanf("%d", &m);
    while (m--) 
    {
        int x; scanf("%d", &x);
        if (can[x] || C[x]) ans++; 
    }
    printf("%d\n", ans);
	return 0;
}

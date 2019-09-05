#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 998244353
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int phi[maxn];
void phi_table(int n)
{
    for (int i = 2; i <= n; i++) phi[i] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++) if (!phi[i]) 
        for (int j = i; j <= n; j += i)
        {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
}
LL ksm(LL a, LL b)
{
    LL res = 1; 
    while (b) {if (b & 1) res = MOD(res * a); a = MOD(a * a); b >>= 1;}
    return res;
}
namespace NTT
{
	const int maxn = 1e6 + 7;
    LL g = 3; // mod == 998244353
    const double PI = acos(-1);
    int R[maxn], N;
    LL ksm(LL a, LL b) {LL res = 1; while (b) {if (b & 1) res = MOD(res * a); a = MOD(a * a); b >>= 1;} return res;}
    void init(int lena, int lenb)
    {
        N = 1;
        while (N <= lena + lenb) N <<= 1;
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
        for (int i = 0; i < N; i++) A[i] = B[i] = 0;
        //根据情况判断是否要清空a和b
    }
}
const LL sqrt2 = 116195171;
LL cnt[maxn], A[maxn], B[maxn], res[maxn];
int main()
{
    phi_table(1e5);
	int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 0; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cnt[phi[i]]++;
        LL s = 0;
        for (LL i = 1; i <= n; i++)
            s = MOD(s + MOD(MOD(MOD(cnt[i] * cnt[i]) * MOD(i * i)) * ksm(2, i * i)));
        for (LL j = 0; j <= n; j++)
        {
            B[j] = ksm(sqrt2, j * j);
            A[j] = MOD(MOD(j * cnt[j]) * B[j]);
            B[j] = ksm(B[j], mod - 2);
        }
        NTT::Convolution(A, n, B, n, res);
        LL ans = 0;
        for (int i = 1; i <= n; i++)
            ans = MOD(ans + A[i] * res[i]);
        ans = MOD(ans * 2 - s + mod);
        printf("%lld\n", ans);
        for (int i = 0; i <= n; i++) A[i] = B[i] = 0;
    }
	return 0;
}

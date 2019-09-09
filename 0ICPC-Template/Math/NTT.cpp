/*
mod r   k   g (mod == r * 2 ^ k + 1)
3   1   1   2
5   1   2   2
17  1   4   3
97  3   5   5
193 3   6   5
257 1   8   3
7681    15  9   17
12289   3   12  11
40961   5   13  3
65537   1   16  3
786433  3   18  10
5767169 11  19  3
7340033 7   20  3
23068673    11  21  3
104857601   25  22  3
167772161   5   25  3
469762049   7   26  3
1004535809  479 21  3
2013265921  15  27  31
2281701377  17  27  3
3221225473  3   30  5
75161927681 35  31  3
77309411329 9   33  7
206158430209    3   36  22
2061584302081   15  37  7
2748779069441   5   39  3
6597069766657   3   41  5
39582418599937  9   42  5
79164837199873  9   43  5
263882790666241 15  44  7
1231453023109121    35  45  3
1337006139375617    19  46  3
3799912185593857    27  47  5
4222124650659841    15  48  19
7881299347898369    7   50  6
31525197391593473   7   52  3
180143985094819841  5   55  6
1945555039024054273 27  56  5
4179340454199820289 29  57  3
*/

// --------------------------------------------NTT---------------------------------------------- //

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
// --------------------------------------template end------------------------------------------ //

LL a[maxn], b[maxn], c[maxn];
NTT::Convolution(a, lena + 1, b, lenb + 1, c); // c = a * b


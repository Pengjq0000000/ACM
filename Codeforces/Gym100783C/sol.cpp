#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
const double PI = acos(-1);
int lowbit(int x) {return x & -x;}
struct comp
{
    double x, y;
    comp(double xx = 0, double yy = 0):x(xx), y(yy){}
    comp operator * (comp &rhs)
    {
        return comp(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
    }
    comp operator + (comp &rhs)
    {
        return comp(x + rhs.x, y + rhs.y);
    }
    comp operator - (comp &rhs)
    {
        return comp(x - rhs.x, y - rhs.y);
    }
};
int R[maxn];


void DFT(comp *A, int flag, int N)
{
    for (int i = 0; i < N; i++) 
        if (i < R[i]) swap(A[i], A[R[i]]);
    for (int len = 1; len < N; len <<= 1)
    {
        comp wn(cos(PI / len), flag * sin(PI / len));
        for (int i = 0; i < N; i += (len << 1))
        {
            comp w(1, 0);
            for (int j = 0; j < len; j++, w = w * wn)
            {
                comp Nx = A[i + j], Ny = w * A[i + len + j];
                A[i + j] = Nx + Ny;
                A[i + len + j] = Nx - Ny; 
            }   
        }
    }
}

comp A[maxn], B[maxn];
void Convolution(int *a, int *b, int *res, int N)
{
    // three times DFT
    for (int i = 0; i < N; i++)
    {
        A[i].x = a[i];
        B[i].x = b[i];
    }
    DFT(A, 1, N); DFT(B, 1, N);
    for (int i = 0; i < N; i++) A[i] = A[i] * B[i];
    DFT(A, -1, N);
    for (int i = 0; i < N; i++) res[i] = (int)(A[i].x / N + 0.5);
}
int a[maxn], b[maxn], C[maxn], can[maxn];
int main()
{
	int n, mx = 0; scanf("%d", &n);
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        a[x] = b[x] = C[x] = 1;
        mx = max(mx, x);
    }
    int N = (mx << 2);
    while (N != lowbit(N)) N -= lowbit(N);
    int L = __builtin_ctz(lowbit(N));
    for (int i = 0; i < N; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    Convolution(a, b, can, N);
    int m, ans = 0; scanf("%d", &m);
    while (m--) 
    {
        int x; scanf("%d", &x);
        if (can[x] || C[x]) ans++; 
    }
    printf("%d\n", ans);
	return 0;
}

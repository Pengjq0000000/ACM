// -----------------------------------FFT---------------------------------------//
const int maxn = 1e6 + 7;
namespace FFT
{
    const double PI = acos(-1);
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
    int R[maxn], N;
    void init(int lena, int lenb)
    {
        N = 1;
        while (N < lena + lenb) N <<= 1;
        for (int i = 0; i < N; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) ? N >> 1 : 0);
    }
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
    void Convolution(int *a, int lena, int *b, int lenb, int *res)
    {
        init(lena, lenb);
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
        for (int i = 0; i < N; i++) A[i] = B[i] = comp(0, 0);
        //根据情况判断是否需要清空a和b
    }
}
// -------------------------------template end---------------------------------- //


int a[maxn], b[maxn], c[maxn];
int main()
{
	Convolution(a, lena + 1, b, lenb + 1, c);  // c = a * b
}




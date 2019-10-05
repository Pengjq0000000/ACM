#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define LL long long
#define MOD(x) ((x) % mod)
using namespace std;
int n, m;
LL mod;
inline int mul(LL x, LL y) {LL res = x * y; return res - res / mod * mod;}
struct Mat
{
    int mat[5][5];
    void init()
    {
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < m; j++)
                mat[i][j] = (i == j);
    }
    Mat operator * (const Mat &rhs) const 
    {
        Mat res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
            {
                res.mat[i][j] = 0;
                for (int k = 0; k < m; k++)
                {
                    res.mat[i][j] = res.mat[i][j] + mul(mat[i][k], rhs.mat[k][j]);
                    if (res.mat[i][j] >= mod) res.mat[i][j] -= mod;
                }
            }
        return res;
    }
    void print()
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                printf("%d%c", mat[i][j], j == m - 1 ? '\n' : ' ');
    }
};

const int maxn = 1e6 + 7;
int c[maxn], L, R;
Mat stk1[maxn], stk2[maxn];
int top1, top2;
Mat ans[maxn];
int main()
{
    while (~scanf("%d%d%lld", &n, &m, &mod))
    {
        Mat I; I.init();
        Mat A, B;
        Mat stk2_res; stk2_res.init();
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < m; j++)
                scanf("%d", &A.mat[i][j]);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &B.mat[i][j]);
        for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
        top1 = 0; top2 = 0;
        stk1[++top1] = I; stk2[++top2] = I;
        ans[0] = A;
        stk2[++top2] = stk2_res = ans[0]; 
        int L = 0, R = 0;
        for (int i = 1; i <= n; i++)
        {
            while (L < c[i])
            {
                if (top1 > 1) top1--;
                else 
                {
                    while (1)
                    {
                        if (top2 == 2) {top2--; stk2_res = I; break;}
                        else 
                        {
                            stk1[top1 + 1] = stk2[top2--] * stk1[top1];
                            top1++;
                        }
                    }
                }
                L++;
            }
            ans[i] = stk1[top1] * stk2_res;
            ans[i] = ans[i] * B;
            stk2_res = stk2_res * ans[i];
            stk2[++top2] = ans[i];
            R++;
        }
        ans[n].print();
    }
    return 0;
}
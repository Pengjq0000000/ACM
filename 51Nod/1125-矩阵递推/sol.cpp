#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
struct Mat
{
    int mat[4][4];
    Mat() {memset(mat, 0, sizeof(mat));}
    void set(int A[4][4]) 
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                mat[i][j] = A[i][j];
    }
    Mat operator * (const Mat &rhs) const 
    {
        Mat res;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    res.mat[i][j] = add(res.mat[i][j], mul(mat[i][k], rhs.mat[k][j]));
        return res;
    }
};
int I[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
int bs[4][4] = {{1, 1, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 1, 1}};
int main()
{
    int n; scanf("%d", &n);
    Mat res, base;
    res.set(I); base.set(bs);
    while (n)
    {
        if (n & 1) res = res * base;
        base = base * base;
        n >>= 1;
    }
    int p[4] = {0, 1, 2, 3};
    int ans = 0;
    do
    {
        int tmp = 1;
        for (int i = 0; i < 4; i++) tmp = mul(tmp, res.mat[i][p[i]]);
        ans = add(ans, tmp);
    } while (next_permutation(p, p + 4));
    printf("%d\n", ans);
    return 0;
}
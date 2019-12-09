#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
struct Mat
{
    int mat[N][N], n;
    Mat(int _n):n(_n){memset(mat, 0, sizeof(mat));}
    Mat(){}
    void init() { for (int i = 0; i < n; i++) mat[i][i] = 1;}
    Mat operator * (const Mat &rhs) const 
    {
        Mat res(n);
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res.mat[i][j] = add(res.mat[i][j], mul(mat[i][k], rhs.mat[k][j]));
        return res;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                printf("%d%c", mat[i][j], j == n - 1? '\n' : ' ');
    }
};
int main()
{
    int n; ll k; scanf("%d%lld", &n, &k); 
    Mat bs(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &bs.mat[i][j]);
    Mat res(n); res.init(); 
    while (k)
    {
        if (k & 1) res = res * bs;
        bs = bs * bs;
        k /= 2;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = add(ans, res.mat[i][j]);
    printf("%d\n", ans);
    return 0;
}
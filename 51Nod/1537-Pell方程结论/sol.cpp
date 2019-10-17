#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
inline ll add(ll x, ll y) {ll res = x + y; if (res >= mod) res -= mod; return res;}
inline ll mul(ll x, ll y) {ll res = x * y; res -= res / mod * mod; return res;}
struct Mat
{
    ll mat[2][2];
    Mat() {memset(mat, 0, sizeof(mat));}
    Mat operator * (const Mat &rhs) const
    {
        Mat res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    res.mat[i][j] = add(res.mat[i][j], mul(mat[i][k], rhs.mat[k][j]));
        return res;
    }
};
int main()
{
    Mat base;
    base.mat[0][0] = 1; base.mat[0][1] = 2;
    base.mat[1][0] = 1; base.mat[1][1] = 1;
    Mat res;
    res.mat[0][0] = 1; res.mat[0][1] = 0;
    res.mat[1][0] = 0; res.mat[1][1] = 1;
    ll n; scanf("%lld", &n);
    ll b = n - 1;
    while (b)
    {
        if (b & 1) res = res * base;
        base = base * base;
        b >>= 1; 
    }
    ll x = add(res.mat[0][0], res.mat[0][1]);
    ll y = add(res.mat[1][0], res.mat[1][1]);
    if (n & 1) printf("%lld\n", mul(2, mul(y, y)));
    else printf("%lld\n", mul(x, x));
}
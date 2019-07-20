#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 50007;
struct Mat
{
    int n;
    LL mat[11][11];
    Mat(){n = 10; MEM(mat, 0);}
    Mat operator * (const Mat &rhs) const 
    {
        Mat res;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                LL tmp = 0;
                for (int k = 1; k <= n; k++) tmp = MOD(tmp + mat[i][k] * rhs.mat[k][j]);
                res.mat[i][j] = tmp;
            }
        return res;
    }
};
char mp[maxn][11];
int n, m, q;
Mat T[maxn << 2];
Mat getmat(int x)
{
    Mat res;
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j++)
        {
            if (mp[x][j] == '0') break;
            res.mat[i][j] = res.mat[j][i] = 1;
        }
    return res;
}
void pushup(int rt) {T[rt] = T[rt << 1] * T[rt << 1 | 1];}
void build(int rt, int l, int r)
{
    if (l == r){T[rt] = getmat(l); return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos)
{
    if (l == r){T[rt] = getmat(l); return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(rt << 1, l, mid, pos);
    else update(rt << 1 | 1, mid + 1, r, pos);
    pushup(rt);
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf(" %c", &mp[i][j]);
            mp[i][j] = (mp[i][j] == '1' ? '0' : '1');
        }
    build(1, 1, n);
    while (q--)
    {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            mp[x][y] = (mp[x][y] == '1' ? '0' : '1');
            update(1, 1, n, x);
        }
        else printf("%lld\n", T[1].mat[x][y]);
    }
	return 0;
}

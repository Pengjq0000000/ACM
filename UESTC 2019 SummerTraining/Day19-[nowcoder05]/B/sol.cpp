#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
LL mod; 
struct Mat
{
    int n;
    LL mat[3][3];
    Mat(){n = 2; MEM(mat, 0);}
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
    void put()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) printf("%lld%c", mat[i][j], j == n ? '\n' : ' ');
    }
};
Mat g[11];
char s[maxn];
int num[maxn];
int main()
{
	LL x1, x2, a, b;
    scanf("%lld%lld%lld%lld", &x1, &x2, &a, &b);
    scanf(" %s", s);
    int len = strlen(s); for (int i = 0; i < len; i++) num[i] = s[i] - '0';
    num[len - 1] -= 1;
    for (int i = len - 1; i > 0; i--)
    {
        if (num[i] < 0)
        {
            num[i] += 10;
            num[i - 1]--;
        }
    }
    int st = 0;
    while (num[st] == 0 && st < len - 1) st++;

    scanf("%lld", &mod);
    Mat bs;
    bs.mat[1][1] = a; bs.mat[1][2] = 1;
    bs.mat[2][1] = b; bs.mat[2][2] = 0;
    Mat res;
    res.mat[1][1] = x2; res.mat[1][2] = x1;
    res.mat[2][1] = 0; res.mat[2][2] = 0;
    g[1] = bs;
    for (int i = 2; i <= 9; i++) 
    {
        g[i] = g[i - 1] * bs;
    }
    Mat base;
    base.mat[1][1] = 1; base.mat[1][2] = 0;
    base.mat[2][1] = 0; base.mat[2][2] = 1;

    //for (int i = st; i < len; i++) printf("%d", num[i]);puts("");
    for (int i = st; i < len; i++)
    {
        int now = num[i];
        Mat r; r.mat[1][1] = r.mat[2][2] = 1;
        Mat b = base;
        int x = 10;
        while (x)
        {
            if (x & 1) r = r * b;
            b = b * b;
            x /= 2;
        }
        base = r;
        if (now > 0) base = base * g[now];
    }
    res = res * base;
    printf("%lld\n", res.mat[1][1]);
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        double ww, dd, vv;
        long double w, d, v, A, B, C;
        scanf("%lf%lf%lf", &vv, &dd, &ww);
        v = vv; d = dd; w = ww;
        A = -2 * v * v;
        B = 6 * v * d;
        C = -1 * (w * w + 4 * d * d);
        long double det = B * B - 4 * A * C;
        long double ans = (v * v) / (2 * d);
        if (det < 0)
        {
            double ans = (v * v) / (2 * d);
            printf("%.20f\n", (double)ans);
            continue;
        }
        long double x = (-B + sqrtl(det)) / (2 * A);
        long double ax, ay;
        ax = (2 * v * x - 2 * d) / (x * x);
        ay = w / (x * x);
        ans = min(ans, sqrtl(ax * ax + ay * ay));
        printf("%.20f\n", (double)ans);
    }
    return 0;
}

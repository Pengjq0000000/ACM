#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
#define eps 1e-15
#define fir first
#define sec second
using namespace std;
const int maxn = 1e5 + 7;
long double a[maxn], b[maxn];
int n;
struct node
{
    long double x, y;
    bool operator < (const node &rhs) const 
    {
        return x < rhs.x;
    }
}p[maxn];
long double mx, mi;
pair<long double, long double>Y[maxn];
long double X[maxn];
void deal()
{
    mx = -1e18, mi = 1e18;
    sort(p + 1, p + 1 + n);
    Y[1].fir = Y[1].sec = p[1].y;
    X[1] = p[1].x;
    int tot = 1;
    for (int i = 2; i <= n; i++)
    {
        if (fabsl(p[i].x - X[tot]) <= eps)
        {
            Y[tot].fir = max(Y[tot].fir, p[i].y);
            Y[tot].sec = min(Y[tot].sec, p[i].y);
        }
        else 
        {
            X[++tot] = p[i].x;
            Y[tot].fir = Y[tot].sec = p[i].y;
        }
    }
    for (int i = 1; i < tot; i++)
    {
        long double dx = X[i + 1] - X[i];
        mx = max(mx, (Y[i + 1].fir - Y[i].sec) / dx);
        mi = min(mi, (Y[i + 1].sec - Y[i].fir) / dx);
    }
}
int main()
{
    scanf("%d", &n);
	for (int i = 1; i <= n; i++)
    {
        double aa, bb; scanf("%lf%lf", &aa, &bb);
        a[i] = aa; b[i] = bb;
    }
    long double mxx, mix, mxy, miy;
    for (int i = 1; i <= n; i++) p[i].x = a[i], p[i].y = b[i];
    deal(); mxx = mx; mix = mi;
    for (int i = 1; i <= n; i++) p[i].x = 1.0 / a[i], p[i].y = -b[i] / a[i];
    deal(); mxy = mx; miy = mi;
    printf("%.10lf %.10lf %.10lf %.10lf\n", (double)mix, (double)miy, (double)mxx, (double)mxy);
	return 0;
}

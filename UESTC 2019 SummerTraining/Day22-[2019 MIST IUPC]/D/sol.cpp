#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
#define eps 1e-9
const int maxn = 207;
double dis[maxn][maxn], cost[maxn][maxn];
struct node {double x, y;} p[maxn];
double getdis(int i, int j)
{
    double ans = 0;
    ans = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
    return sqrt(ans);
}
int n;
long double A, B, C, D;
long double ksm(long double a, LL b)
{
    long double res = 1, base = a;
    while (b)
    {
        if (b & 1) res = res * base;
        base = base * base;
        b /= 2;
    }
    return res;
}
bool check(long double F, LL L)
{
    long double k = (D - 1) / D;
    long double f1 = F;
    long double g1 = f1 + A;
    long double fL = ksm(k, L) * g1 - A;
    if (fL > eps) return true;
    else return false;
}
double getcost(LL dist)
{
    long double k = (D - 1) / D;
    double F = A / ksm(k, dist) - A;
    return F * C + B;
}
int main()
{
	int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        int AA, BB, CC, DD;
        scanf("%d%d%d%d%d", &n, &AA, &BB, &CC, &DD);
        A = AA; B = BB; C = CC; D = DD;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            for (int j = 1; j < i; j++)
            {
                dis[i][j] = dis[j][i] = ceil(getdis(i, j));
                cost[i][j] = cost[j][i] = getcost(dis[i][j]);
            }
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
        printf("%.12f\n", cost[1][n]);
    }
	return 0;
}
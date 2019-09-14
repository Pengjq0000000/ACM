#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
long double f[1000010];
char s[1000010];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf(" %s", s);
        int len = strlen(s);
        double a; scanf("%lf", &a);
        long double x = a, y = a;
        f[1] = x * (x + y) / (2 * x + y) + x;
        long double t = f[1] * a / (f[1] + a);
        for (int i = 2; i <= 1000000; i++)
        {
            f[i] = (x * (x + t)) / (2 * x + t) + x;
            t = f[i] * a / (f[i] + a);
        }
        if (len >= 6) 
        {
            printf("%.10lf\n", (double)f[1000000]);
        }
        else 
        {
            int tmp = 0;
            for (int i = 0; i < len; i++) tmp = tmp * 10 + (s[i] - '0');
            printf("%.10lf\n", (double)f[tmp]);
        }
    }
    return 0;
}

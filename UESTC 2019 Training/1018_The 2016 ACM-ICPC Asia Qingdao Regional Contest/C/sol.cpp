#include<bits/stdc++.h>
#define ldb long double
using namespace std;
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        double l, d; scanf("%lf%lf", &l, &d);
        ldb ans = 0;
        if (l > d) ans = 1 + logl(l / d);
        printf("%.6lf\n", (double)ans);
    }
    return 0;
}
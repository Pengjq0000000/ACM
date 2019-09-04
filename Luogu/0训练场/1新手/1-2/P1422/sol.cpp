#include<bits/stdc++.h>
using namespace std;
double f(int x)
{
    return 0.4463 * x + 0.02 * max(0, x - 150) + 0.1 * max(0, x - 400);
}
int main()
{
    int x; scanf("%d", &x);
    printf("%.1lf\n", f(x));
    return 0;
}
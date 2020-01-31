#include<bits/stdc++.h>
using namespace std;
int A, B, C;
bool check(int x)
{
    int a = A - x, b = B - x, c = C;
    if (a < 0 || b < 0) return false;
    if (a + b + c >= x) return true;
    else return false;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &A, &B, &C);
        int l = 0, r = (A + B + C) / 3;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
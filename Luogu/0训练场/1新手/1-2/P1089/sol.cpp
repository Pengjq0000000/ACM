#include <bits/stdc++.h>
using namespace std;

int main()
{
    int now = 0, s = 0;
    for (int i = 1, x; i <= 12; i++)
    {
        now += 300;
        scanf("%d", &x);
        now -= x; if (now < 0) {printf("%d\n", -i); return 0;}
        s += now / 100 * 100;
        now %= 100;
    }
    printf("%d\n", now + s + s / 5);
    return 0;
}